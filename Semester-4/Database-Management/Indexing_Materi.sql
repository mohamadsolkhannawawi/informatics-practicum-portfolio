USE bankdb;

DISABLE TRIGGER ALL ON customers;

DECLARE @customer_id CHAR(36); 
DECLARE @email VARCHAR(255); 
 -- Deklarasi cursor 
DECLARE customer_cursor CURSOR FOR 
SELECT customer_id, email 
FROM customers; 
 -- Buka cursor 
OPEN customer_cursor; 
 -- Ambil baris pertama 
FETCH NEXT FROM customer_cursor INTO @customer_id, @email; 
 -- Loop selama masih ada data 
WHILE @@FETCH_STATUS = 0 
BEGIN 
    -- Cetak data (bisa diganti dengan proses lain) 
    PRINT 'Customer ID: ' + @customer_id + ' | Email: ' + @email; 
 
    -- Ambil baris berikutnya 
    FETCH NEXT FROM customer_cursor INTO @customer_id, @email; 
END; 
 -- Tutup dan hapus cursor 
CLOSE customer_cursor; 
DEALLOCATE customer_cursor;


SELECT account_number, account_type, balance
FROM accounts
WHERE customer_id = '9d78736f-df51-4622-9cb1-c4db88dca2d0';

CREATE INDEX idx_customerID_account ON accounts(customer_id);
DROP INDEX idx_customerID_account ON accounts;