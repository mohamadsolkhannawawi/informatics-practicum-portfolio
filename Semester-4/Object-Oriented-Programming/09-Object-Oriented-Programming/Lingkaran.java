/* 
 * Nama File    : Lingkaran.java
 * Nama Pembuat : Mohamad Solkhan Nawawi
 * NIM Pembuat  : 24060123120020
 * Tanggal      : 7 Mei 2025
 * Deskripsi    : Lingkaran adalah subclass dari class BangunDatar dengan method hitungKeliling dan hitungLuas
 *                yang mengimplementasikan method dari superclass BangunDatar.
 */

public class Lingkaran extends BangunDatar {
    // Atribut
    private double jejari;

    // Method
    public Lingkaran(double jejari) {
        this.jejari = jejari;
    }

    public double hitungKeliling() {
        return 2 * jejari * 3.14;
    }

    public double hitungLuas() {
        return 3.14 * jejari * jejari;
    }
}
    
