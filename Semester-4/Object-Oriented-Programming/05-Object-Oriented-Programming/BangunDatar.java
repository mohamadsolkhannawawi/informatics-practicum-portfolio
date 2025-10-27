/* 
 * Nama File    : BangunDatar.java
 * Nama Pembuat : Mohamad Solkhan Nawawi
 * NIM Pembuat  : 24060123120020
 * Tanggal      : 21 Maret 2025
 * Deskripsi    : BangunDatar merupakan superclass yang berisi atribut 
 *                jmlSisi, warna, dan border dengan tipe class abstract.
 *                BangunDatar memiliki method getJmlSisi, setJmlSisi,
 *                getWarna, setWarna, getBorder, setBorder, getLuas, getKeliling, 
 *                isEqualLuas, printInfo, dan printCounterBangunDatar. 
*/

// public final class BangunDatar { akan error pada method yang merupakan turunan dari BangunDatar.java
// Dengan final tidak bisa diturunkan pada method di  Persegi.java dan Lingkaran.java
public abstract class BangunDatar {
    // Atribut
    protected int jmlSisi;
    protected String warna;
    protected String border;
    private static int counterBangunDatar = 0;
    
    // private int jmlSisi;
    // private String warna;
    // private String border;
    // private static int counterBangunDatar = 0;

    // Konstruktor
    public BangunDatar() {
        counterBangunDatar++;
    }

    public BangunDatar(int jmlSisi, String warna, String border) {
        this.jmlSisi = jmlSisi;
        this.warna = warna;
        this.border = border;
        counterBangunDatar++;
    }

    // Method
    // Getter dan Setter
    public static void printCounterBangunDatar() {
        System.out.println("Jumlah bangun datar: " + BangunDatar.counterBangunDatar);
    }

    public int getJmlSisi() {
        return jmlSisi;
    }

    public void setJmlSisi(int jmlSisi) {
        this.jmlSisi = jmlSisi;
    }

    public String getWarna() {
        return warna;
    }

    public void setWarna(String warna) {
        this.warna = warna;
    }

    public String getBorder() {
        return border;
    }

    public void setBorder(String border) {
        this.border = border;
    }

    public abstract double getLuas();

    // public double getLuas() { // Tidak tepat karena akan inisialiasi nilai 0, sebelum dibuat di Persegi.java dan Lingkaran.java
    //     return 0;
    // }

    public abstract double getKeliling();

    // public double getKeliling() { // Tidak tepat karena akan inisialiasi nilai 0, sebelum dibuat di Persegi.java dan Lingkaran.java
    //     return 0;
    // }

    public boolean isEqualLuas(BangunDatar X){ // Membandingkan luas bangun datar
        return this.getLuas() == X.getLuas();
    }


    // public final void printInfo() { akan error padaprintInfo() di Persegi.java dan Lingkaran.java   karena
    // Dengan final tidak bisa diturunkan
    public void printInfo() {
        System.out.println("Jumlah sisi: " + jmlSisi);;
        System.out.println("Warna: " + warna);
        System.out.println("Border: " + border);
    }

}