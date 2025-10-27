USE bankdb;
GO

-- Jika prosedur sudah ada, hapus dulu (opsional)
IF OBJECT_ID('dbo.sp_gget_account_balance', 'P') IS NOT NULL
    DROP PROCEDURE dbo.sp_gget_account_balance;
GO

-- Membuat prosedur
CREATE PROCEDURE sp_gget_account_balance(
	@account_id CHAR(36),
	@balance_out DECIMAL(18,2) OUTPUT
)
AS
BEGIN
	SELECT @balance_out = balance 
	FROM accounts
	WHERE account_id = @account_id;
END;
GO

-- Pemanggilan prosedur (pisahkan dengan GO)
DECLARE @account_id CHAR(36);
DECLARE @balance DECIMAL(18,2);

SET @account_id = '07a36a4b-7943-4634-b17a-7c7eb4407cd3';

EXEC dbo.sp_gget_account_balance 
    @account_id = @account_id, 
    @balance_out = @balance OUTPUT;

SELECT @balance AS balance;
GO
