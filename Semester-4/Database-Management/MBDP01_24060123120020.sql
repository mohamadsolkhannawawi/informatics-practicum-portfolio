-- Nama : Mohamad Solkhan Nawawi
-- NIM  : 24060123120020
-- Kelas: C
-- LAB  : C2

USE bankdb;

-- i. View v_customer_all : Menampilkan semua isi dari tabel customers.
CREATE VIEW v_customer_all AS
SELECT *
FROM customers;

-- Pemanggilan
SELECT * FROM v_customer_all;

-- ii. View v_deposit_transaction : Menampilkan semua transaksi dengan tipe deposit.
CREATE VIEW v_deposit_transaction AS
SELECT t.*
FROM transactions t
JOIN transaction_types tt ON t.transaction_type_id = tt.transaction_type_id
WHERE tt.name = 'deposit';

-- Pemanggilan
SELECT * FROM v_deposit_transaction;

-- iii. View v_transfer_transaction : Menampilkan semua transaksi dengan tipe transfer.
CREATE VIEW v_transfer_transaction AS
SELECT t.*
FROM transactions t
JOIN transaction_types tt ON t.transaction_type_id = tt.transaction_type_id
WHERE tt.name = 'transfer';

-- Pemanggilan 
SELECT * FROM v_transfer_transaction;
