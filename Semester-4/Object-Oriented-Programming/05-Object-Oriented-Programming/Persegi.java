/* 
 * Nama File    : Persegi.java
 * Nama Pembuat : Mohamad Solkhan Nawawi
 * NIM Pembuat  : 24060123120020
 * Tanggal      : 21 Maret 2025
 * Deskripsi    : Lingkaran merupakan subclass dari bangun, dengan atribut tambahan jari serta overide
 *                implementasi interface.
 */

public class Persegi extends BangunDatar implements IResize {
    // Atribut
    private double sisi;
    private static int counterPersegi = 0;

    // Konstruktor
    public Persegi() {
        setJmlSisi(4);
        counterPersegi++;
    }

    public Persegi(double sisi, String warna, String border) {
        super(4, warna, border); // Menggunakan super untuk mengakses atribut dari superclass
        this.sisi = sisi;
        // setWarna(warna);
        // setBorder(border);
        // setJmlSisi(4);
        // this.border = border;
        // this.warna = warna;
        // this.jmlSisi = 4;
        counterPersegi++;
    }

    // Method
    // Getter dan Setter
    public static void printCounterPersegi() {
        System.out.println("Jumlah persegi: " + Persegi.counterPersegi);
    }

    public double getSisi() {
        return sisi;
    }

    public void setSisi(double sisi) {
        this.sisi = sisi;
    }

    public double getLuas() {
        return sisi*sisi;
    }

    public double getKeliling() {
        return 4*sisi;
    }

    public double getDiagonal() {
        return Math.sqrt(2) * sisi;
    }

    // Method Overriding
    @Override
    public void printInfo() {
        System.out.println("Persegi");
        super.printInfo();
        // System.out.println("Jumlah sisi: " + getJmlSisi());
        // System.out.println("Warna: " + getWarna());
        // System.out.println("Border: " + getBorder());
        System.out.println("Luas : " + getLuas());
        System.out.println("Keliling: " + getKeliling());
        System.out.println("Diagonal: " + getDiagonal());
    }

    // Method dari interface IResize
    @Override
    public void zoomIn() {
        sisi = sisi * 1.1;
    }

    @Override
    public void zoomOut() {
        sisi = sisi * 0.9;
    }

    @Override
    public void zoom(int percent) {
        sisi = sisi * (1 + percent/100.0);
    }

}