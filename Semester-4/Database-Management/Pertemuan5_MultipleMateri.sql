USE bankdb;

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
    transaction_date >= DATEADD(day, -30, GETDATE())
    AND amount > (SELECT AVG(amount) FROM transactions);

DROP VIEW vw_recent_high_value_transactions;

SELECT * FROM vw_recent_high_value_transactions;

SELECT AVG(amount) AS average_transaction_amount
FROM transactions;


-- Nomor 2
CREATE VIEW vw_rekap_transaksi_nasabah_per_jenis AS
SELECT
    cust.customer_id,
    SUM(CASE WHEN tt.name = 'deposit' THEN 1 ELSE 0 END) AS deposit,
    SUM(CASE WHEN tt.name = 'transfer' THEN 1 ELSE 0 END) AS transfer,
    SUM(CASE WHEN tt.name = 'withdrawal' THEN 1 ELSE 0 END) AS withdrawal
FROM
    customers cust
INNER JOIN
    accounts acc ON cust.customer_id = acc.customer_id
INNER JOIN
    transactions t ON acc.account_id = t.account_id
INNER JOIN
    transaction_types tt ON t.transaction_type_id = tt.transaction_type_id
GROUP BY
    cust.customer_id;

SELECT * FROM vw_rekap_transaksi_nasabah_per_jenis;

-- Nomor 3
CREATE VIEW vw_account_card_transaction_detail AS
SELECT
    a.account_id,
    a.account_number,
    a.account_type,
    a.balance,
    c.card_number,
    c.card_type,
    t.transaction_id,
    tt.name AS transaction_type,
    t.amount
FROM
    transactions t
INNER JOIN
    accounts a ON t.account_id = a.account_id
INNER JOIN
    transaction_types tt ON t.transaction_type_id = tt.transaction_type_id
LEFT JOIN
    cards c ON a.account_id = c.account_id;

SELECT * FROM vw_account_card_transaction_detail;

-- Nomor 4
CREATE PROCEDURE sp_get_transactions_report
    @account_id CHAR(36) = NULL,
    @date_from DATETIME = NULL,
    @date_to DATETIME = NULL
AS
BEGIN
    SET NOCOUNT ON;

    DECLARE @query_date_from DATETIME;
    DECLARE @query_date_to DATETIME;

    IF @date_from IS NULL AND @date_to IS NULL
    BEGIN
        SET @query_date_to = GETDATE();
        SET @query_date_from = DATEADD(day, -30, @query_date_to); 
    END
    ELSE
    BEGIN
        SET @query_date_from = ISNULL(@date_from, '1900-01-01');

        SET @query_date_to = ISNULL(@date_to, GETDATE());

        IF @date_to IS NOT NULL AND CAST(@query_date_to AS TIME) = '00:00:00.0000000'
        BEGIN
            SET @query_date_to = DATEADD(ms, -3, DATEADD(day, 1, CAST(@query_date_to AS DATE)));
        END
    END

    SELECT
        t.transaction_id,
        a.account_id,
        a.account_number,
        cust.customer_id, 
        tt.name AS transaction_type,
        t.amount,
        t.transaction_date,
        t.description
    FROM
        transactions t
    INNER JOIN
        accounts a ON t.account_id = a.account_id
    INNER JOIN
        transaction_types tt ON t.transaction_type_id = tt.transaction_type_id
    INNER JOIN
        customers cust ON a.customer_id = cust.customer_id 
    WHERE
        (@account_id IS NULL OR a.account_id = @account_id)
        AND (t.transaction_date >= @query_date_from AND t.transaction_date <= @query_date_to)
    ORDER BY
        t.transaction_date DESC, t.transaction_id DESC; 

END

EXEC sp_get_transactions_report;

-- Nomor 5

CREATE FUNCTION fn_customer_loans_info(
    @p_customer_id CHAR(36)
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
        DATEDIFF(day, GETDATE(), l.end_date) AS SisaHari
    FROM
        loans l
    WHERE
        l.customer_id = @p_customer_id 
);

SELECT
    LoanId,
    LoanAmount,
    InterestRate,
    LoanTermsMonths,
    StartDate,
    EndDate,
    Status,
    SisaHari
FROM
    dbo.fn_customer_loans_info('079cd6ce-04a8-4c55-8c2b-b93189e9050a');


-- Nomor 6

CREATE FUNCTION fn_get_customer_account_summary(
    @p_customer_id CHAR(36) 
)
RETURNS TABLE
AS
RETURN
(
    SELECT
        @p_customer_id AS CustomerId, 
        COUNT(a.account_id) AS TotalAccounts,
        ISNULL(SUM(a.balance), 0.00) AS TotalBalance,   
        ISNULL(AVG(a.balance), 0.00) AS AverageBalance 
    FROM
        accounts a
    WHERE
        a.customer_id = @p_customer_id
);

SELECT
    CustomerId,
    TotalAccounts,
    TotalBalance,
    AverageBalance
FROM
    dbo.fn_get_customer_account_summary('079cd6ce-04a8-4c55-8c2b-b93189e9050a');


-- Nomor 7
CREATE TRIGGER trg_PreventBackdatedTransactions
ON transactions
INSTEAD OF INSERT
AS
BEGIN
    SET NOCOUNT ON;

    CREATE TABLE #AccountMaxExistingDate (
        account_id CHAR(36) PRIMARY KEY,
        max_date DATETIME NULL
    );

    INSERT INTO #AccountMaxExistingDate (account_id, max_date)
    SELECT
        i.account_id,
        MAX(t.transaction_date)
    FROM
        inserted i
    LEFT JOIN
        transactions t ON i.account_id = t.account_id
    GROUP BY
        i.account_id;

    IF EXISTS (
        SELECT 1
        FROM inserted i
        JOIN #AccountMaxExistingDate amed ON i.account_id = amed.account_id
        WHERE
            amed.max_date IS NOT NULL
            AND i.transaction_date < amed.max_date
    )
    BEGIN
        RAISERROR ('Tanggal transaksi baru tidak boleh lebih lama dari tanggal transaksi terakhir untuk akun ini.', 16, 1);
        DROP TABLE #AccountMaxExistingDate;
        RETURN;
    END

    INSERT INTO transactions (
        transaction_id,
        account_id,
        transaction_type_id,
        amount,
        transaction_date,
        description,
        reference_account
    )
    SELECT
        COALESCE(i.transaction_id, NEWID()),
        i.account_id,
        i.transaction_type_id,
        i.amount,
        i.transaction_date,
        i.description,
        i.reference_account
    FROM
        inserted i;

    DROP TABLE #AccountMaxExistingDate;

END

SELECT * FROM accounts;
SELECT * FROM transactions;
SELECT * FROM transaction_types;

INSERT INTO transactions (account_id, transaction_type_id, amount, transaction_date, description)
VALUES ('2CA48147-6DE9-4D30-9B17-CCF843421535', 2, 50.00, '2025-05-20 10:00:00', 'Setoran awal');

INSERT INTO transactions (account_id, transaction_type_id, amount, transaction_date, description)
VALUES ('2CA48147-6DE9-4D30-9B17-CCF843421535', 2, 100000.00, '2029-05-19 08:00:00', 'Setoran tambahan');





