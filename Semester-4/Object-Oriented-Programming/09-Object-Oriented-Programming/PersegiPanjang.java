/* 
 * Nama File    : PersegiPanjang.java
 * Nama Pembuat : Mohamad Solkhan Nawawi
 * NIM Pembuat  : 24060123120020
 * Tanggal      : 7 Mei 2025
 * Deskripsi    : PersegiPanjang adalah subclass dari class BangunDatar dengan method hitungKeliling dan hitungLuas
 *                yang mengimplementasikan method dari superclass BangunDatar.
 */

public class PersegiPanjang extends BangunDatar {
    // Atribut
    private double panjang;
    private double lebar;

    // Method
    public PersegiPanjang(double panjang, double lebar) {
        this.panjang = panjang;
        this.lebar = lebar;
    }

    public double hitungKeliling() {
        return 2 * (panjang + lebar);
    }

    public double hitungLuas() {
        return panjang * lebar;
    }   
}
