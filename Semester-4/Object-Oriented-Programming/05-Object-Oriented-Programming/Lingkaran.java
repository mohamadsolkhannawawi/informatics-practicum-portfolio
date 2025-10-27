/* 
 * Nama File    : Lingkaran.java
 * Nama Pembuat : Mohamad Solkhan Nawawi
 * NIM Pembuat  : 24060123120020
 * Tanggal      : 21 Maret 2025
 * Deskripsi    : Lingkaran merupakan subclass dari bangun, dengan atribut tambahan jari serta
 *                implementasi interface Iresize.
 */

public class Lingkaran extends BangunDatar implements IResize {
    // Atribut
    private double jari;
    private static int counterLingkaran = 0;

    // Konstruktor
    public Lingkaran() {
        setJmlSisi(1);
        counterLingkaran++;
    }

    public Lingkaran(double jari, String warna, String border) {
        super(1, warna, border);
        this.jari = jari;
        // setBorder(border);
        // setJmlSisi(1);
        // setWarna(warna);
        counterLingkaran++;
    }

    // Method
    // Getter dan Setter
    public static void printCounterLingkaran() {
        System.out.println("Jumlah lingkaran: " + Lingkaran.counterLingkaran);
    }

    public void setJari(double jari) {
        this.jari = jari;
    }

    public double getLuas() {
        return Math.PI * jari * jari;
    }

    public double getKeliling() {
        return 2 * Math.PI * jari;
    }

    public double getJari() {
        return jari;
    }

    // Method Overriding
    @Override
    public void printInfo() {
        System.out.println("Lingkaran");
        super.printInfo();
        // System.out.println("Jumlah sisi: " + getJmlSisi());
        // System.out.println("Warna: " + getWarna());
        // System.out.println("Border: " + getBorder());
        System.out.println("Luas :" + getLuas());
        System.out.println("Keliling: " + getKeliling());
        System.out.println("Jari-jari: " + jari);
    }

    // Method dari interface IResize
    @Override
    public void zoomIn() {
        jari = jari * 1.1;
    }

    @Override
    public void zoomOut() {
        jari = jari * 0.9;
    }

    @Override
    public void zoom(int percent) {
        jari = jari * (1 + percent / 100.0);
    }

}
