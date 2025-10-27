USE bankdb; 
CREATE TRIGGER tr_UpdateAccountBalance_AfterTransaction 
ON transactions 
AFTER INSERT 
AS 
BEGIN     
  SET NOCOUNT ON;     
  UPDATE accounts     
  SET balance =          
      CASE              
           WHEN t.transaction_type_id = 1 THEN a.balance + 
t.amount -- deposit             
           WHEN t.transaction_type_id = 2 THEN a.balance - 
t.amount -- withdrawal             
           WHEN t.transaction_type_id = 3 THEN a.balance - 
t.amount -- transfer             
           ELSE a.balance         
      END     
  FROM accounts a     
  INNER JOIN inserted t ON a.account_id = t.account_id; 
END
GO;

-- Tambahkan 1 customer dan 1 akun 
INSERT INTO customers (first_name, last_name, email, phone_number, address) 
VALUES ('Budi', 'Santoso', 'budi@example.com', '08123456789', 'Jakarta'); 
 
DECLARE @cust_id CHAR(36) = (SELECT TOP 1 customer_id FROM customers WHERE first_name = 'Budi'); 
INSERT INTO accounts (customer_id, account_number, account_type, balance) 
VALUES (@cust_id, '1234567890', 'savings', 100000.00);

DECLARE @acc_id CHAR(36) = (SELECT TOP 1 account_id FROM 
accounts WHERE account_number = '1234567890'); 
INSERT INTO transactions (account_id, transaction_type_id, amount, description) 
VALUES (@acc_id, 1, 50000.00, 'Setoran tunai');

DECLARE @acc_id CHAR(36) = (SELECT TOP 1 account_id FROM 
accounts WHERE account_number = '1234567890'); 
INSERT INTO transactions (account_id, transaction_type_id, amount, description) 
VALUES (@acc_id, 2, 20000.00, 'Tarik tunai'); 

DECLARE @acc_id CHAR(36) = (SELECT TOP 1 account_id FROM 
accounts WHERE account_number = '1234567890'); 
SELECT account_number, balance  
FROM accounts  
WHERE account_id = @acc_id;