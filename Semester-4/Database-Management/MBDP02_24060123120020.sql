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
	i. function fn_GetCustomerFullName yang menerima input customer_id dan 
	mengembalikan nama lengkap customer (gabungan first_name dan 
	last_name).
*/
CREATE FUNCTION fn_GetCustomerFullName (@customer_id CHAR(36))
RETURNS VARCHAR(255)
AS
BEGIN
	-- Kamus Lokal
    DECLARE @full_name VARCHAR(255);

	--Algoritma
    SELECT @full_name = first_name + ' ' + last_name
    FROM customers
    WHERE customer_id = @customer_id;

    RETURN @full_name;
END;

-- Penggunaan 
SELECT dbo.fn_GetCustomerFullName('079cd6ce-04a8-4c55-8c2b-b93189e9050a')
AS Nama_Lengkap;

-- Hapus Fungsi
DROP FUNCTION fn_GetCustomerFullName;



/*
	ii. function fn_GetTotalBalanceByCustomer yang menerima input 
	customer_id dan mengembalikan total saldo dari semua akun milik 
	customer tersebut dari tabel accounts. 
*/
CREATE FUNCTION fn_GetTotalBalanceByCustomer (@customer_id CHAR (36))
RETURNS DECIMAL (18,2)
AS 
BEGIN
	-- Kamus Lokal
	DECLARE @total_balance DECIMAL (18, 2);

	-- Algoritma
	SELECT @total_balance = SUM(balance)
	FROM accounts as a
	WHERE @customer_id = a.customer_id;

	RETURN @total_balance;
END;

-- Penggunaan
SELECT dbo.fn_GetTotalBalanceByCustomer('9d78736f-df51-4622-9cb1-c4db88dca2d0') 
AS Total_Balance;

-- Hapus Fungsi
DROP FUNCTION dbo.fn_GetTotalBalanceByCustomer;



/*
	iii. function fn_GetActiveLoanCount yang menghitung berapa jumlah 
	pinjaman dengan status 'active' pada tabel loans. 
*/
CREATE FUNCTION fn_GetActiveLoanCount ()
RETURNS INT
AS
BEGIN
    -- Kamus Lokal
	DECLARE @count_loans INT;

	-- Algoritma
    SELECT @count_loans = COUNT(*)
    FROM loans 
    WHERE status like 'active';

    RETURN @count_loans;
END;

-- Penggunaan
SELECT dbo.fn_GetActiveLoanCount() 
AS Total_Pinjaman_Aktif;

-- Hapus Fungsi
DROP FUNCTION fn_GetActiveLoanCount;



/*
	iv. function fn_GetAccountNetFlow yang menerima account_id dan 
	mengembalikan selisih antara total transaksi masuk dan keluar. 
*/
CREATE FUNCTION fn_GetAccountNetFlow (@account_id CHAR(36))
RETURNS DECIMAL(18,2)
AS
BEGIN
	-- Kamus Lokal
    DECLARE @masuk DECIMAL(18,2) = 0;
    DECLARE @keluar DECIMAL(18,2) = 0;
    DECLARE @net_flow DECIMAL(18,2);

	-- Algoritma
    SELECT @masuk = ISNULL(SUM(t.amount), 0)
    FROM transactions t
    JOIN transaction_types tt ON t.transaction_type_id = tt.transaction_type_id
    WHERE 
        (tt.name = 'deposit' AND t.account_id = @account_id)
        OR (tt.name = 'transfer' AND t.reference_account = @account_id);

    SELECT @keluar = ISNULL(SUM(t.amount), 0)
    FROM transactions t
    JOIN transaction_types tt ON t.transaction_type_id = tt.transaction_type_id
    WHERE 
        (tt.name = 'transfer' AND t.account_id = @account_id)
        OR (tt.name = 'withdrawal' AND t.account_id = @account_id);

    SET @net_flow = @masuk - @keluar;

    RETURN @net_flow;
END;

-- Penggunaan
SELECT dbo.fn_GetAccountNetFlow('9cd97ecb-58c9-4610-b4b1-d9f72bcae7f7') 
AS Net_Flow;

--Hapus Fungsi
DROP FUNCTION fn_GetAccountNetFlow;



/*
	v. function fn_GetCustomerFinancialSummary yang menerima customer_id, 
	dan mengembalikan hasil total saldo + total pinjaman. 
*/
CREATE FUNCTION fn_GetCustomerFinancialSummary (@customer_id CHAR(36))
RETURNS DECIMAL(18, 2)
AS
BEGIN
	--Kamus
    DECLARE @total_balance DECIMAL(18, 2);
    DECLARE @total_loans DECIMAL(18, 2);
    DECLARE @financial_summary DECIMAL(18, 2);

	--Algoritma
    SELECT @total_balance = ISNULL(SUM(balance), 0)
    FROM accounts
    WHERE customer_id = @customer_id;

    SELECT @total_loans = ISNULL(SUM(loan_amount), 0)
    FROM loans
    WHERE customer_id = @customer_id AND status = 'active'; 

    SET @financial_summary = @total_balance + @total_loans;

    RETURN @financial_summary;
END;

-- Penggunaan
SELECT dbo.fn_GetCustomerFinancialSummary('b5c6a70e-f40c-43ac-9291-418539d54ae7') 
AS Customer_Financial_Summary ;

-- Hapus Fungsi
DROP FUNCTION fn_GetCustomerFinancialSummary;