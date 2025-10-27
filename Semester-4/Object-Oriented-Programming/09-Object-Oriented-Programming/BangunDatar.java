/* 
 * Nama File    : BangunDatar.java
 * Nama Pembuat : Mohamad Solkhan Nawawi
 * NIM Pembuat  : 24060123120020
 * Tanggal      : 7 Mei 2025
 * Deskripsi    : BangunDatar adalah superclass dari class Lingkaran, Persegi, PersegiPanjang dan Segitiga dengan method hitungKeliling dan hitungLuas
 *                yang bersifat abstract.
 */

public abstract class BangunDatar {

    // Method
    // Method ini bersifat abstract, sehingga harus diimplementasikan pada subclass
    public abstract double hitungKeliling();
    public abstract double hitungLuas();
}
