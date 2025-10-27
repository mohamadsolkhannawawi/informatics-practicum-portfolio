/* 
 * Nama File    : Segitiga.java
 * Nama Pembuat : Mohamad Solkhan Nawawi
 * NIM Pembuat  : 24060123120020
 * Tanggal      : 7 Mei 2025
 * Deskripsi    : Segitiga adalah subclass dari class BangunDatar dengan method hitungKeliling dan hitungLuas
 *                yang mengimplementasikan method dari superclass BangunDatar.
 */

public class Segitiga extends BangunDatar { 
    // Atribut
    private double alas;
    private double tinggi;
    private double sisi1;
    private double sisi2;
    private double sisi3;

    // Method
    public Segitiga(double alas, double tinggi, double sisi1, double sisi2, double sisi3) {
        this.alas = alas;
        this.tinggi = tinggi;
        this.sisi1 = sisi1;
        this.sisi2 = sisi2;
        this.sisi3 = sisi3;
    }

    public double hitungKeliling() {
        return sisi1 + sisi2 + sisi3;
    }

    public double hitungLuas() {
        return 0.5 * alas * tinggi;
    }
}
