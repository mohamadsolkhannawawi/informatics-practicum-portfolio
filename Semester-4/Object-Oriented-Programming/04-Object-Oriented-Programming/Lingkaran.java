/* 
 * Nama File    : Lingkaran.java
 * Nama Pembuat : Mohamad Solkhan Nawawi
 * NIM Pembuat  : 24060123120020
 * Tanggal      : 14 Maret 2025
 * Deskripsi    : Lingkaran merupakan subclass dari bangun, dengan atribut tambahan jari.
 */

public class Lingkaran extends BangunDatar{
    private double jari;
    private static int counterLingkaran = 0;

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

}
