/* 
 * Nama File    : Persegi.java
 * Nama Pembuat : Mohamad Solkhan Nawawi
 * NIM Pembuat  : 24060123120020
 * Tanggal      : 7 Mei 2025
 * Deskripsi    : Persegi adalah subclass dari class BangunDatar dengan method hitungKeliling dan hitungLuas
 *                yang mengimplementasikan method dari superclass BangunDatar.
 */

public class Persegi extends BangunDatar {
    // Atribut
    private double sisi;

    // Method 
    public Persegi(double sisi) {
        this.sisi = sisi;
    }

    public double hitungKeliling() {
        return 4 * sisi;
    }

    public double hitungLuas() {
        return sisi * sisi;
    }
}
