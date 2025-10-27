/* 
 * Nama File    : MBangunDatar.java
 * Nama Pembuat : Mohamad Solkhan Nawawi
 * NIM Pembuat  : 24060123120020
 * Tanggal      : 14 Maret 2025
 * Deskripsi    : MBangunDatar merupakan mainclass untuk melakukan pembuatan
 *                Objek inheritance dari BangunDatar yaitu Persegi dan Lingkaran.
 */

public class MBangunDatar {

    public static void main(String[] args) {
        Persegi p = new Persegi(5, "Merah", "Hitam");
        p.printInfo();
        System.out.println();
        Lingkaran l = new Lingkaran(7, "Biru", "Putih");
        l.printInfo();
        System.out.println("\n");
        BangunDatar.printCounterBangunDatar();
        Persegi.printCounterPersegi();
        Lingkaran.printCounterLingkaran();
    }
}
