/*
	Anggota Kelompok 1: 
		1. Julius Tegar Aji Putra - 24060123130117
		2. Muhamad Sahal Annabil - 24060123130088
		3. Mohamad Solkhan Nawawi - 24060123120020
		4. Mohammad Imron Rosyadi - 24060123140204
		5. ⁠Khairiya Fatih Izzudin Emarin - 24060123140166
*/

USE bankdb;

/*
	i. Buat trigger tr_UpdateAccountBalance_BeforeTransaction ke tabel 
	transactions yang akan mencegah transaksi dilakukan jika saldo akun tidak 
	cukup. Jika saldo < jumlah amount, maka transaksi harus dibatalkan. 
	Gunakan syntax Rollback. 
*/
CREATE TRIGGER tr_UpdateAccountBalance_BeforeTransaction
ON transactions
AFTER INSERT
AS
BEGIN
    SET NOCOUNT ON;

    DECLARE @account_balance DECIMAL(18, 2);
    DECLARE @transaction_amount DECIMAL(18, 2);
    DECLARE @account_id CHAR(36);

    SELECT @account_id = account_id, @transaction_amount = amount
    FROM inserted;

    SELECT @account_balance = balance
    FROM accounts
    WHERE account_id = @account_id;

    IF @account_balance < @transaction_amount
    BEGIN
        PRINT 'Saldo tidak mencukupi untuk transaksi ini.';
        ROLLBACK TRANSACTION;
    END
END;

-- Hapus Trigger
DROP TRIGGER tr_UpdateAccountBalance_BeforeTransaction;
-- Pengaktifan Trigger
ENABLE TRIGGER tr_UpdateAccountBalance_BeforeTransaction ON transactions;
-- Penonaktifan Trigger
DISABLE TRIGGER tr_UpdateAccountBalance_BeforeTransaction ON transactions;
-- Aplikasi :
DECLARE @acc_id CHAR(36) = (SELECT TOP 1 account_id FROM accounts WHERE account_number = '1234567890'); 
INSERT INTO transactions (account_id, transaction_type_id, amount, description) 
VALUES (@acc_id, 2, 500000000.00, 'Tarik tunai');




/*
	ii. Buat trigger tr_Deposit_AfterTransaction ke tabel transactions yang aktif 
	jika ada transaksi transfer yang menambahkan transaksi baru ke akun 
	tujuan (reference_account) dengan tipe transaksi deposit dan nilai amount 
	yang sama.
*/
CREATE TRIGGER tr_Deposit_AfterTransaction
ON transactions
AFTER INSERT
AS
BEGIN
    SET NOCOUNT ON;

    INSERT INTO transactions (
        account_id,
        transaction_type_id,
        amount,
        transaction_date,
        description,
        reference_account
    )
    SELECT 
        i.reference_account,          
        1,                            
        i.amount,
        GETDATE(),
        'Auto deposit from transfer',
        i.account_id                  
    FROM inserted i
    WHERE i.transaction_type_id = 2  
      AND i.reference_account IS NOT NULL;
END;

-- Hapus Trigger
DROP TRIGGER tr_Deposit_AfterTransaction;
-- Pengaktifan Trigger
ENABLE TRIGGER tr_Deposit_AfterTransaction ON transactions;
-- Penonaktifan Trigger
DISABLE TRIGGER tr_Deposit_AfterTransaction ON transactions;
-- Aplikasi :
SELECT balance FROM accounts WHERE account_id = '9cd97ecb-58c9-4610-b4b1-d9f72bcae7f7'; --check balance akun penerima
SELECT balance FROM accounts WHERE account_id = '8a54f7b6-3ac0-4aee-88c4-ff386444e673'; --check balance akun pengirim
INSERT INTO transactions (
    account_id,             -- akun pengirim
    transaction_type_id,    -- 2 = transfer
    amount,
    description,
    reference_account       -- akun penerima
) VALUES (
    '8a54f7b6-3ac0-4aee-88c4-ff386444e673', 2, 1000, 'Transfer ke teman', '9cd97ecb-58c9-4610-b4b1-d9f72bcae7f7'
);




/*
	iii. Buat trigger tr_LimitAccountsPerCustomer yang akan mencegah 
	penambahan akun baru (accounts) jika seorang nasabah (customer_id) 
	sudah memiliki 3 akun. Trigger ini dijalankan sebelum insert ke tabel 
	accounts. Jika jumlah akun untuk customer_id >= 3, maka transaksi 
	dibatalkan. Gunakan syntax Rollback. 

*/
CREATE TRIGGER tr_LimitAccountsPerCustomer
ON accounts
INSTEAD OF INSERT
AS
BEGIN
    DECLARE @customer_id CHAR(36);
    DECLARE @jumlah_akun INT;

    -- Ambil customer_id dari data yang akan di-insert
    SELECT @customer_id = customer_id FROM inserted;

    -- Validasi account_type
    IF EXISTS (
        SELECT 1 FROM inserted
        WHERE account_type NOT IN ('credit', 'current', 'savings')
    )
    BEGIN
        PRINT 'Jenis akun tidak valid. Gunakan: credit, current, atau savings.';
        ROLLBACK;
        RETURN;
    END

    -- Hitung jumlah akun yang sudah dimiliki customer
    SELECT @jumlah_akun = COUNT(*) 
    FROM accounts 
    WHERE customer_id = @customer_id;

    IF @jumlah_akun >= 3
    BEGIN
        PRINT 'Nasabah sudah memiliki 3 akun. Tidak bisa menambah akun baru.';
        ROLLBACK;
    END
    ELSE
    BEGIN
        -- Lanjutkan insert jika syarat terpenuhi
        INSERT INTO accounts (account_id, customer_id, account_number, balance, account_type)
        SELECT account_id, customer_id, account_number, balance, account_type
        FROM inserted;
    END
END;

-- Hapus Trigger
DROP TRIGGER tr_LimitAccountsPerCustomer;
-- Pengaktifan Trigger
ENABLE TRIGGER tr_LimitAccountsPerCustomer ON accounts;
-- Penonaktifan Trigger
DISABLE TRIGGER tr_LimitAccountsPerCustomer ON accounts;
-- Aplikasi :
SELECT * FROM customers;

-- Nambah 3 akun berdasarkan customer id 079cd6ce-04a8-4c55-8c2b-b93189e9050a
INSERT INTO accounts (account_id, customer_id, account_number, balance, account_type)
VALUES 
(NEWID(), '079cd6ce-04a8-4c55-8c2b-b93189e9050a', 'AC001', 1000.00, 'savings'),
(NEWID(), '079cd6ce-04a8-4c55-8c2b-b93189e9050a', 'AC002', 1500.00, 'credit'),
(NEWID(), '079cd6ce-04a8-4c55-8c2b-b93189e9050a', 'AC003', 2000.00, 'current');
-- Lebih dari 3 error
INSERT INTO accounts (account_id, customer_id, account_number, balance, account_type)
VALUES 
(NEWID(), '079cd6ce-04a8-4c55-8c2b-b93189e9050a', 'AC005', 4000.00, 'credit');




/*
	iv. Buat trigger tr_BlockInvalidReferenceAccount pada tabel transactions 
	yang aktif jika terdapat insert transaksi transfer, sistem harus mengecek 
	apakah akun tujuan (reference_account) benar-benar ada di tabel accounts. 
	Jika tidak ditemukan, batalkan transaksi. Gunakan syntax Rollback.
*/
CREATE TRIGGER tr_BlockInvalidReferenceAccount
ON transactions
AFTER INSERT
AS
BEGIN
    SET NOCOUNT ON;

    IF EXISTS (
        SELECT 1
        FROM inserted i
        WHERE i.transaction_type_id = 3
        AND NOT EXISTS (
            SELECT 1
            FROM accounts a
            WHERE a.account_number = i.reference_account
        )
    )
    BEGIN
        RAISERROR ('Transaksi transfer gagal: Akun tujuan (reference_account) tidak valid.', 16, 1);
        ROLLBACK;
    END
END;

-- Hapus Trigger
DROP TRIGGER tr_BlockInvalidReferenceAccount;
-- Pengaktifan Trigger
ENABLE TRIGGER tr_BlockInvalidReferenceAccount ON transactions;
-- Penonaktifan Trigger
DISABLE TRIGGER tr_BlockInvalidReferenceAccount ON transactions;
-- Aplikasi :
DECLARE @acc_id CHAR(36) = (SELECT TOP 1 account_id FROM accounts WHERE account_number = '9885390599');
INSERT INTO transactions (account_id, transaction_type_id, amount, description, reference_account)
VALUES (@acc_id, 3, 50000, 'Transfer ke akun tidak valid', '0000000000');


DECLARE @acc_id CHAR(36) = (SELECT TOP 1 account_id FROM accounts WHERE account_number = '9885390599');
INSERT INTO transactions (account_id, transaction_type_id, amount, description, reference_account)
VALUES (@acc_id, 3, 50000, 'Transfer ke akun valid', '5421050024');

SELECT *
FROM transactions
WHERE reference_account = '5421050024'
ORDER BY transaction_date DESC;




/*
	v. Buat trigger tr_EnsureMinimumBalance di tabel transactions yang aktif 
	saat transaksi withdrawal atau transfer dilakukan. Trigger harus 
	memeriksa apakah saldo akun setelah transaksi memiliki minimal 
	Rp100.000. Jika tidak, transaksi dibatalkan. Gunakan syntax Rollback. 
*/
CREATE TRIGGER tr_EnsureMinimumBalance
ON transactions
AFTER INSERT
AS
BEGIN
    SET NOCOUNT ON;

    -- Cek apakah ada transaksi withdrawal atau transfer yang membuat saldo di bawah Rp 100.000
    IF EXISTS (
        SELECT 1
        FROM inserted i
        JOIN accounts a ON a.account_id = i.account_id
        WHERE i.transaction_type_id IN (2, 3)
          AND (a.balance - i.amount) < 100000
    )
    BEGIN
        PRINT 'Transaksi dibatalkan: saldo minimum Rp 100.000 harus dipertahankan.';
        ROLLBACK TRANSACTION;
        RETURN;
    END
END;

-- Hapus Trigger
DROP TRIGGER tr_EnsureMinimumBalance;
-- Pengaktifan Trigger
ENABLE TRIGGER tr_EnsureMinimumBalance ON transactions;
-- Penonaktifan Trigger
DISABLE TRIGGER tr_EnsureMinimumBalance ON transactions;
-- Aplikasi :
DECLARE @acc_id CHAR(36) = (SELECT TOP 1 account_id FROM accounts WHERE account_number = '8346813622'); 
INSERT INTO transactions (account_id, transaction_type_id, amount, description) 
VALUES (@acc_id, 2, 100000.00, 'Tarik tunai');
