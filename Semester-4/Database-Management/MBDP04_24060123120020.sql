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
	i. Buatlah index pada tabel accounts untuk mempercepat pencarian. Pilih 
	   salah satu kolom pada table tersebut dan berikan alasan pemilihan kolom 
	   tersebut sebagai index! 
*/
-- Kueri SELECT untuk perbandingan
SELECT account_number, account_type, balance
FROM accounts
WHERE customer_id = '9d78736f-df51-4622-9cb1-c4db88dca2d0';

-- Membuat Index pada kolom customer_id, lalu ulangi kueri select
CREATE INDEX idx_customerID_account 
ON accounts(customer_id);
-- Menghapus index, lalu ulangi, dengan menggunakan index dan tanpa menggunakan index
DROP INDEX idx_customerID_account ON accounts;

/* Alasan pemilihan Kolom customer_id sebagai Index:
Kolom customer_id pada tabel accounts dipilih untuk diindeks karena kolom ini sangat mungkin sering digunakan dalam
klausa WHERE untuk mengambil data akun spesifik milik seorang nasabah
Dengan adanya indeks pada customer_id, database engine dapat dengan cepat
menemukan baris-baris yang relevan tanpa harus melakukan pemindaian keseluruhan tabel (table scan)
sehingga proses pencarian data menjadi jauh lebih efisien, terutama pada tabel dengan jumlah data yang besar
Ini umum dilakukan untuk mengindeks foreign key yang sering digunakan dalam kondisi pencarian atau join.
*/



/*
	ii. Buatlah index pada tabel transactions untuk mempercepat pencarian. Pilih 
		salah satu kolom pada table tersebut dan berikan alasan pemilihan kolom 
		tersebut sebagai index! 
*/
-- Kueri SELECT untuk perbandingan
SELECT transaction_id, transaction_type_id, amount, transaction_date, description
FROM transactions
WHERE account_id = '9cd97ecb-58c9-4610-b4b1-d9f72bcae7f7';

--Membuat Index pada kolom account_id, lalu ulangi select
CREATE INDEX idx_transactions_account_id 
ON transactions (account_id);
-- Menghapus index, lalu ulangi, dengan menggunakan index dan tanpa menggunakan index
DROP INDEX idx_transactions_account_id ON transactions;

/*
Alasan Pemilihan Kolom account_id sebagai Index:
Kolom account_id pada tabel transactions dipilih untuk diindeks karena merupakan foreign key
yang akan sangat sering digunakan dalam klausa WHERE untuk menampilkan riwayat transaksi
dari sebuah akun tertentu. Dengan adanya indeks pada account_id
database engine dapat secara efisien mengambil semua transaksi yang terkait dengan satu akun
tanpa perlu memindai seluruh tabel transaksi, yang biasanya berukuran sangat besar, untuk ukuran saat ini masih kecil
sehingga belum terlalu terlihat perbedaannya. Dengan cara ini dapat meningkatkan kecepatan kueri secara signifikan, 
terutama untuk operasi seperti pembuatan laporan rekening atau pengecekan aktivitas transaksi akun.
*/


/*
	iii. Buatlah composite index pada tabel accounts. Pilih lebih dari satu kolom 
		pada tabel tersebut dan uji performa query sebelum dan setelah 
		menggunakan index! (query pengujian berdasarkan kolom yang dipilih 
		sebagai index) 
*/

--Pengujian Tanpa Index
-- Mencari semua akun berjenis 'savings' dengan saldo lebih dari 10.000
SELECT account_id, customer_id, account_number, account_type, balance, created_at
FROM accounts
WHERE account_type = 'savings' AND balance > 10000;

--Membuat Composite Index
CREATE INDEX idx_accounts_type_balance
ON accounts(account_type, balance);

--Pengujian Setelah Index
SELECT account_id, customer_id, account_number, account_type, balance, created_at
FROM accounts
WHERE account_type = 'savings' AND balance > 10000;

-- Menghapus index
DROP INDEX idx_accounts_type_balance ON accounts




/*
	iv. Buat cursor untuk membaca semua akun dari tabel accounts, lalu periksa 
		balance masing-masing. Jika balance < 9.000, tampilkan pesan: "Saldo 
		rendah untuk account_id: [account_id]". 
*/
-- Deklarasi nama variabel
DECLARE @balance_cursor DECIMAL(18, 2); 
DECLARE @account_id_cursor CHAR(36); 

-- Deklarasi cursor
DECLARE account_check_balance_cursor CURSOR FOR
    SELECT account_id, balance
    FROM accounts;

-- Buka cursor
OPEN account_check_balance_cursor;

-- Ambil baris pertama
FETCH NEXT FROM account_check_balance_cursor INTO @account_id_cursor, @balance_cursor;

-- Loop selama masih ada data
WHILE @@FETCH_STATUS = 0
BEGIN
    IF @balance_cursor < 9000.00 -- Menggunakan 9000.00 untuk konsistensi dengan tipe data DECIMAL
        PRINT 'Saldo rendah untuk account_id: ' + @account_id_cursor; -- Disesuaikan agar tidak ada spasi sebelum titik dua

    -- Ambil baris berikutnya
    FETCH NEXT FROM account_check_balance_cursor INTO @account_id_cursor, @balance_cursor;
END;

-- Tutup cursor
CLOSE account_check_balance_cursor;

-- Hapus cursor dari memori
DEALLOCATE account_check_balance_cursor;



/*
	v. Buat cursor untuk membaca semua pelanggan (customers) dan gabungkan 
	   first_name dan last_name untuk ditampilkan dengan format: "Customer: [Nama Lengkap]".  
*/
DECLARE @first_name_cursor VARCHAR(50);
DECLARE @last_name_cursor VARCHAR(50);
DECLARE @nama_lengkap VARCHAR(101); -- Cukup untuk first_name(50) + spasi(1) + last_name(50)

 -- Deklarasi cursor 
DECLARE customer_fullname_cursor CURSOR FOR
    SELECT first_name, last_name
    FROM customers;

-- Buka cursor
OPEN customer_fullname_cursor;

 -- Ambil baris pertama 
FETCH NEXT FROM customer_fullname_cursor INTO @first_name_cursor, @last_name_cursor;

 -- Loop selama masih ada data 
WHILE @@FETCH_STATUS = 0
BEGIN
    SET @nama_lengkap = ISNULL(@first_name_cursor, '') + ' ' + ISNULL(@last_name_cursor, '');
	-- Cetak data dengan format yang diminta
    PRINT 'Customer: ' + LTRIM(RTRIM(@nama_lengkap));

    -- Ambil baris berikutnya
    FETCH NEXT FROM customer_fullname_cursor INTO @first_name_cursor, @last_name_cursor;
END;

-- Tutup cursor
CLOSE customer_fullname_cursor;

-- Hapus cursor dari memori
DEALLOCATE customer_fullname_cursor;



