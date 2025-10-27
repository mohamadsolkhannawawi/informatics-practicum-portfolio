/* 
 * Nama File    : BangunDatarGeneric.java
 * Nama Pembuat : Mohamad Solkhan Nawawi
 * NIM Pembuat  : 24060123120020
 * Tanggal      : 7 Mei 2025
 * Deskripsi    : BangunDatarGeneric merupakan kelas generik yang didalamnya terdapat pembatasan
 *                bahwa tipe data yang bisa digunakan adalah turunan dari kelas BangunDatar.
 */

public class BangunDatarGeneric<T extends BangunDatar> { 
    // Atribut 
    private T BangunDatar;

    // Method 
    public void set(T tipeBangunDatar) {
        BangunDatar = tipeBangunDatar;
    }

    public T get() {
        return BangunDatar;
    }
    public double hitungKeliling() {
        return BangunDatar.hitungKeliling();
    }
    
    public double hitungLuas() {
        return BangunDatar.hitungLuas();
    }
}

// Karakter T merupakan parameger tipe dalam generic java.
// Nama tersebut hanyalah penamaan simbolik yang digunakan dalam deklarasi kelas generic
// dapat diganti dengan nama lain.
// Misal T1, T2, T3, dst.
// Dengan syarat konsisten untuk seluruh kelas.
// Mengikuti aturan penamaan variabel dalam java.
// T merupakan singkatan  Type yang sering digunakan dalam penamaan generic.
// Namun bukan merupakan keharusan.

