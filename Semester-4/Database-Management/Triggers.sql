USE bankdb;

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


select balance from accounts where account_id = '9cd97ecb-58c9-4610-b4b1-d9f72bcae7f7'
select balance from accounts where account_id = '8a54f7b6-3ac0-4aee-88c4-ff386444e673'
INSERT INTO transactions (
    account_id,             -- akun pengirim
    transaction_type_id,    -- 2 = transfer
    amount,
    description,
    reference_account       -- akun penerima
) VALUES (
    '8a54f7b6-3ac0-4aee-88c4-ff386444e673', 2, 1000, 'Transfer ke teman', '9cd97ecb-58c9-4610-b4b1-d9f72bcae7f7'
);



