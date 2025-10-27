/*
	Anggota Kelompok 1: 
		1. Julius Tegar Aji Putra - 24060123130117
		2. Muhamad Sahal Annabil - 24060123130088
		3. Mohamad Solkhan Nawawi - 24060123120020
		4. Mohammad Imron Rosyadi - 24060123140204
		5. ⁠Khairiya Fatih Izzudin Emarin - 24060123140166
*/

USE bankdb;

/*	i. Buat view vw_recent_high_value_transactions yang menampilkan 
	transaksi 30 hari terakhir dengan nilai > rata-rata seluruh transaksi. 
*/
CREATE VIEW vw_recent_high_value_transactions AS
SELECT
    transaction_id,
    account_id,
    transaction_type_id,
    amount,
    transaction_date,
    description,
    reference_account
FROM
    transactions
WHERE
    transaction_date >= DATEADD(day, -30, GETDATE()) AND amount > (SELECT AVG(amount) FROM transactions);

-- Hapus View 
DROP VIEW vw_recent_high_value_transactions;

-- Memanggil View
SELECT * FROM vw_recent_high_value_transactions;

-- Menampilkan rata-rata transaksi, untuk membuktikan
SELECT AVG(amount) AS average_transaction_amount
FROM transactions;



/*
	ii. Buat view yang menampilkan jumlah transaksi per akun, dengan 
	memisahkan transaksi deposit, transfer, dan withdrawal dalam kolom 
	berbeda.
*/
CREATE VIEW vw_customer_transaction_summary AS
SELECT
    a.customer_id AS customerId,
    COUNT(CASE WHEN t.transaction_type_id = 1 THEN t.transaction_id ELSE NULL END) AS deposit,  -- ID 1 untuk Deposit
    COUNT(CASE WHEN t.transaction_type_id = 2 THEN t.transaction_id ELSE NULL END) AS transfer, -- ID 2 untuk Transfer
    COUNT(CASE WHEN t.transaction_type_id = 3 THEN t.transaction_id ELSE NULL END) AS withdrawal -- ID 3 untuk Withdrawal
FROM
    accounts AS a
LEFT JOIN
    transactions AS t ON a.account_id = t.account_id
GROUP BY
    a.customer_id;

-- Penghapusan
DROP VIEW vw_customer_transaction_summary;

-- Memanggil View
SELECT *
FROM vw_customer_transaction_summary
ORDER BY customerId;

-- Pengecekan tipe transaksi
SELECT
    transaction_type_id,
    name
FROM
    transaction_types
ORDER BY
    transaction_type_id;

/*
	iii. Buat view vw_account_card_transaction_detail yang menggabungkan data 
	akun, kartu, dan transaksi yang terkait. 
*/
CREATE VIEW vw_account_card_transaction_detail AS
SELECT
    a.account_id AS "Account Id",
    a.account_number AS "Account Number",
    a.account_type AS "Account Type",
    a.balance AS "Balance",
    c.card_number AS "Card Number",
    c.card_type AS "Card Type",
    t.transaction_id AS "Transaction Id",
    tt.name AS "Transaction Type",
    t.amount AS "Amount"
FROM
    accounts a
INNER JOIN
    transactions t ON a.account_id = t.account_id
LEFT JOIN
    cards c ON a.account_id = c.account_id
INNER JOIN
    transaction_types tt ON t.transaction_type_id = tt.transaction_type_id;

-- Penghapusan
DROP VIEW vw_account_card_transaction_detail;

-- Pemanggilan
SELECT *
FROM vw_account_card_transaction_detail
ORDER BY "Account Id", "Transaction Id";



/*
	iv. Buat procedure sp_get_transactions_report dengan parameter opsional 
	@account_id, @date_from, @date_to. Jika parameter tidak diisi, gunakan 
	default (misal 30 hari terakhir semua akun). 
*/
CREATE PROCEDURE sp_get_transactions_report
    @account_id CHAR(36)  = NULL,
    @date_from   DATETIME = NULL,
    @date_to     DATETIME = NULL
AS
BEGIN
    SET NOCOUNT ON;
    DECLARE 
        @start_date DATETIME, 
        @end_date   DATETIME;

    SET @start_date = ISNULL(@date_from, DATEADD(DAY, -30, GETDATE()));
    SET @end_date   = ISNULL(@date_to,   GETDATE());

    SELECT
        t.transaction_id,
        t.account_id,
        a.account_number,
        tt.name            AS transaction_type,
        t.amount,
        t.transaction_date,
        t.description
    FROM dbo.transactions AS t
    LEFT JOIN dbo.accounts AS a
        ON t.account_id = a.account_id
    LEFT JOIN dbo.transaction_types AS tt
        ON t.transaction_type_id = tt.transaction_type_id
    WHERE 
        t.transaction_date BETWEEN @start_date AND @end_date
        AND (
            @account_id IS NULL 
            OR t.account_id = @account_id
        )
    ORDER BY
        t.transaction_date DESC;
END
--Aplikasi--
-- Pemanggilan
EXEC sp_get_transactions_report;   --(hasilnya bakalan null karena ssmsnya ngitung berdasarkan 30 hari terakhir yg berpacu hari ini)--


EXEC sp_get_transactions_report
    @date_from = '2025-03-01',
    @date_to   = '2025-04-30';

-- Penghapusan
DROP PROCEDURE sp_get_transactions_report;



/*
	v. Buat function fn_customer_loans_info yang mengembalikan list semua 
	pinjaman customer lengkap dengan status dan selisih antara end_date dan 
	GETDATE(). 
*/
CREATE FUNCTION dbo.fn_customer_loans_info
(
    @customer_id CHAR(36)
)
RETURNS TABLE
AS
RETURN
(
    SELECT
        l.loan_id AS LoanId,
        l.loan_amount AS LoanAmount,
        l.interest_rate AS InterestRate,
        l.loan_terms_months AS LoanTermsMonths,
        l.start_date AS StartDate,
        l.end_date AS EndDate,
        l.status AS Status,
        DATEDIFF(DAY, GETDATE(), l.end_date) AS SisaHari
    FROM dbo.loans AS l
    WHERE l.customer_id = @customer_id
);

--Aplikasi--
-- Pemanggilan
SELECT *FROM dbo.fn_customer_loans_info('1b056bda-e6c8-46bb-a706-8db8c2e53061');

-- Penghapusan
DROP FUNCTION dbo.fn_customer_loans_info;



/*
	vi. Buat function yang mengembalikan statistik berikut dalam satu record: 
	total akun, total saldo, rata-rata saldo untuk customer_id tertentu (gunakan 
	RETURN table). 
*/
CREATE FUNCTION fn_GetCustomerAccountStats(
    @customerId CHAR(36)
)
RETURNS TABLE
AS
RETURN
(
    SELECT
        a.customer_id AS CustomerId,
        COUNT(a.account_id) AS TotalAccounts,
        SUM(a.balance) AS TotalBalance,
        ROUND(AVG(a.balance), 2) AS AverageBalance
    FROM
        accounts AS a
    WHERE
        a.customer_id = @customerId
    GROUP BY
        a.customer_id
);

-- Pemanggilan
SELECT *
FROM dbo.fn_GetCustomerAccountStats('0ca06e8d-a7a2-40c4-893b-128336ffdf54');

-- Penghapusan
DROP FUNCTION dbo.fn_GetCustomerAccountStats;


/*
	vii. Cegah transaksi baru yang memiliki transaction_date lebih lama dari 
	transaksi terakhir untuk akun yang melakukan transaksi tersebut.  
*/
IF OBJECT_ID('dbo.trg_prevent_old_transactions', 'TR') IS NOT NULL
    DROP TRIGGER dbo.trg_prevent_old_transactions;
GO

CREATE TRIGGER trg_prevent_old_transactions
ON dbo.transactions
INSTEAD OF INSERT
AS
BEGIN
    SET NOCOUNT ON;

    IF EXISTS (
        SELECT 1
        FROM INSERTED i
        INNER JOIN (
            SELECT t.account_id, MAX(t.transaction_date) AS last_transaction_date
            FROM dbo.transactions t
            WHERE t.account_id IN (SELECT DISTINCT ins.account_id FROM INSERTED ins)
            GROUP BY t.account_id
        ) AS last_trans ON i.account_id = last_trans.account_id
        WHERE i.transaction_date < last_trans.last_transaction_date
    )
    BEGIN
        RAISERROR('Satu atau lebih transaksi yang dimasukkan memiliki tanggal yang lebih lama dari transaksi terakhir untuk akun terkait.', 16, 1);
        RETURN;
    END
    ELSE
    BEGIN
        IF EXISTS (
            SELECT 1
            FROM INSERTED i
            WHERE EXISTS (
                SELECT 1
                FROM INSERTED i2
                WHERE i2.account_id = i.account_id
                  AND i2.transaction_date < i.transaction_date
                  AND NOT EXISTS (SELECT 1 FROM dbo.transactions t_exists WHERE t_exists.account_id = i.account_id)
            )
        )
        BEGIN
            RAISERROR('Dalam batch transaksi baru untuk akun yang belum memiliki riwayat, ditemukan transaksi dengan tanggal yang tidak berurutan (ada yang lebih lama setelah yang lebih baru).', 16, 1);
            RETURN;
        END

        INSERT INTO dbo.transactions (transaction_id, account_id, transaction_type_id, amount, transaction_date, description, reference_account)
        SELECT transaction_id, account_id, transaction_type_id, amount, transaction_date, description, reference_account
        FROM INSERTED;
    END
END

-- Aplikasi
INSERT INTO transactions (transaction_id, account_id, transaction_type_id, amount, transaction_date, description, reference_account)
VALUES (NEWID(), 'fe716f26-3b0e-4fe5-bc40-4663f4fa66c0', 1, 500.00, '2000-05-28 10:00:00', 'Pemindahan Dana', NULL);

-- Penghapusan
IF OBJECT_ID('dbo.trg_prevent_old_transactions', 'TR') IS NOT NULL
    DROP TRIGGER dbo.trg_prevent_old_transactions;
GO



/*	viii. Buat cursor yang membaca semua akun credit, lalu kurangi saldo mereka 
	2% sebagai biaya bulanan. 
*/
DECLARE @account_id CHAR(36);
DECLARE @current_balance DECIMAL(18,2);
DECLARE @fee_amount DECIMAL(18,2);

-- Deklarasi Cursor
DECLARE credit_accounts_cursor CURSOR FOR
SELECT account_id, balance
FROM accounts
WHERE account_type = 'credit';

-- Buka Cursor
OPEN credit_accounts_cursor;

-- Ambil Baris Pertama
FETCH NEXT FROM credit_accounts_cursor INTO @account_id, @current_balance;

-- Proses dan ambil baris berikutnya 
WHILE @@FETCH_STATUS = 0
BEGIN
	SET @fee_amount = @current_balance * 0.02;
	
	-- Update accouunt balance
	UPDATE accounts
	SET balance = balance - @fee_amount
	WHERE account_id = @account_id;

	FETCH NEXT FROM credit_accounts_cursor INTO @account_id, @current_balance;
END;

-- Tutup Cursor
CLOSE credit_accounts_cursor; 

-- Hapus alokasi memori untuk Cursor
DEALLOCATE credit_accounts_cursor;

-- Melihat saldo akun kredit sebelum eksekusi
SELECT account_id, account_number, balance AS balance_before_fee
FROM dbo.accounts
WHERE account_type = 'credit'
ORDER BY account_id;

-- Melihat saldo akun kredit setelah eksekusi
SELECT account_id, account_number, balance AS balance_after_fee
FROM dbo.accounts
WHERE account_type = 'credit'
ORDER BY account_id;