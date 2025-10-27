/* 
 * Nama File    : MBangunDatar.java
 * Nama Pembuat : Mohamad Solkhan Nawawi
 * NIM Pembuat  : 24060123120020
 * Tanggal      : 21 Maret 2025
 * Deskripsi    : MBangunDatar merupakan mainclass untuk melakukan pembuatan
 *                Objek inheritance dari BangunDatar yaitu Persegi dan Lingkaran serta interface IResize.
 */

public class MBangunDatar {

    public static void main(String[] args) {
        // Persegi p = new Persegi(5, "Merah", "Hitam");
        // p.printInfo();
        // System.out.println();
        // Lingkaran l = new Lingkaran(7, "Biru", "Putih");
        // l.printInfo();
        // System.out.println("\n");
        // BangunDatar.printCounterBangunDatar();
        // Persegi.printCounterPersegi();
        // Lingkaran.printCounterLingkaran();

        // BangunDatar B1 = new BangunDatar(); // Error karena BangunDatar merupakan kelas abstract
        // BangunDatar P1 = new Persegi(10); // Parameter 10 tidak sesuai dengan constructor Persegi
        // Persegi P2 = new Persegi(5); // Parameter 5 sesuai dengan constructor Persegi
        // BangunDatar L1 = new Lingkaran(7); // Parameter 7 sesuai dengan constructor Lingkaran
        // Lingkaran L1 = new Lingkaran (14); // Error karena Lingkaran merupakan kelas abstract

        // BangunDatar Coba = new BangunDatar();  // Error karena BangunDatar merupakan kelas abstract
        System.out.println("Inisialisasi objek Persegi dan Lingkaran");
        System.out.println("=======================================");
        System.out.println("Persegi P1 dengan sisi 5, warna Merah, border Hitam");
        System.out.println("Lingkaran L1 dengan jari-jari 7, warna Biru, border Putih");
        System.out.println("Persegi P2 dengan sisi 5, warna Merah, border Hitam");
        System.out.println("=======================================");

        BangunDatar P1 = new Persegi(5, "Merah","Hitam");
        System.out.println("Persegi P1");
        P1.printInfo();
        System.out.println("=======================================");
        BangunDatar L1 = new Lingkaran(7, "Biru", "Putih");
        System.out.println("Lingkaran L1");
        L1.printInfo();
        System.out.println("=======================================");
        Persegi P2 = new Persegi(5, "Merah", "Hitam");
        System.out.println("Persegi P2");
        P2.printInfo();
        System.out.println("=======================================");

        System.out.println("Jumlah bangun datar: ");
        BangunDatar.printCounterBangunDatar();

        System.out.println("Jumlah persegi: ");
        Persegi.printCounterPersegi();

        System.out.println("Jumlah lingkaran: ");
        Lingkaran.printCounterLingkaran();

        System.out.println("=======================================");
        System.out.println("Persegi P1");
        System.out.println("Luas Persegi: " + ((Persegi)(P1)).getSisi());
        System.out.println("Keliling Persegi: " + (P1).getKeliling());

        System.out.println("=======================================");
        System.out.println("Lingkaran L1");
        System.out.println("Luas Lingkaran: " + ((Lingkaran)(L1)).getLuas());
        System.out.println("Keliling Lingkaran: " + (L1).getKeliling());

        System.out.println("=======================================");
        System.out.println("Persegi P2");
        System.out.println("Luas Persegi: " + ((Persegi)(P2)).getLuas());
        System.out.println("Keliling Persegi: " + (P2).getKeliling());

        // System.out.println(P1.getSisi()); // Error karena BangunDatar tidak memiliki method getSisi pada bangunDatar
        System.out.println("getSisi Persegi P1: " + ((Persegi)(P1)).getSisi()); // harus dengan casting karena BangunDatar tidak memiliki method getSisi
        System.out.println("getSisi Persegi P2: " + (P2).getSisi());
        System.out.println("getJari Lingkaran L1: " + ((Lingkaran)(L1)).getJari());

        System.out.println("=======================================");
        System.out.println("Perbandingan Luas Persegi dan Lingkaran");
        System.out.println("Apakah luas Persegi P1 >= Lingkaran L1: " + P1.isEqualLuas(L1));

        System.out.println("=======================================");
        System.out.println("Implementasi IResize");
        System.out.println("Sisi Persegi P1 sebelum zoomIn: " + ((Persegi)(P1)).getSisi());
        ((Persegi)(P1)).zoomIn();
        System.out.println("Sisi Persegi P1 setelah zoomIn: " + ((Persegi)(P1)).getSisi());
        System.out.println("Jari-jari Lingkaran L1 sebelum zoomIn: " + ((Lingkaran)(L1)).getJari());
        ((Lingkaran)(L1)).zoomIn();
        System.out.println("Jari-jari Lingkaran L1 setelah zoomIn: " + ((Lingkaran)(L1)).getJari());
        System.out.println("Sisi Persegi P2 sebelum zoomOut: " + (P2).getSisi());
        ((Persegi)(P2)).zoomOut();
        System.out.println("Sisi Persegi P2 setelah zoomOut: " + (P2).getSisi());
        System.out.println("Jari-jari Lingkaran L1 sebelum zoomOut: " + ((Lingkaran)(L1)).getJari());
        ((Lingkaran)(L1)).zoomOut();
        System.out.println("Jari-jari Lingkaran L1 setelah zoomOut: " + ((Lingkaran)(L1)).getJari());
        System.out.println("Sisi Persegi P1 sebelum zoom 50%: " + ((Persegi)(P1)).getSisi());
        ((Persegi)(P1)).zoom(50);
        System.out.println("Sisi Persegi P1 setelah zoom 50%: " + ((Persegi)(P1)).getSisi());
        System.out.println("Jari-jari Lingkaran L1 sebelum zoom 50%: " + ((Lingkaran)(L1)).getJari());
        ((Lingkaran)(L1)).zoom(50);
        System.out.println("Jari-jari Lingkaran L1 setelah zoom 50%: " + ((Lingkaran)(L1)).getJari());
        System.out.println("Sisi Persegi P2 sebelum zoom 50%: " + (P2).getSisi());
        ((Persegi)(P2)).zoom(50);
        System.out.println("Sisi Persegi P2 setelah zoom 50%: " + (P2).getSisi());
    }

}

/*
 * Catatan Abstract Class:
 * - reference type tidak boleh berupa kelas abstract, sehingga tidak bisa membuat objek dari BangunDatar
 * - Tipe BangunDatar bisa digunakan untuk membuat objek Persegi dan Lingkaran
 * - Tipe Persegi bisa digunakan untuk membuat objek Persegi
 * - Tipe Lingkaran bisa digunakan untuk membuat objek Lingkaran
 * - Parameter harus sesuai dengan constructor yang ada
 * - Casting diperlukan untuk mengakses method yang tidak ada pada BangunDatar
 * - Apabila tidak menggunakan abstract class, getLuas dan getKeliling masih bisa di implementasikan , namun tidak masuk akal
 * - Jika tidak dengan abstract class Luas dan keliing yang dibandingkan harus objek yang sama
 * - Objek berbeda tidak bisa dibandingkan
 * - IsEqualsLuas dan IsEqualKeliling bisa diimplementasikan, namum dengan return default 0
 * - Tidak masuk akal, dan tidak direkomendasikan
 * - Abstract class memiliki kelebihan lebih strict, sehingga semua method yang abstract pada class abstract harus di buat dalam subclassnya
 * - sehingga akan ada jaminan semua method abstract harus di implementasikan pada subclass
 */


/*
 * Catatan Interface :
 * Semua method pada interface IResize dapat digunakan dalam class Persegi dan Lingkaran
 * Keuntungan menggunakan interface daripada abstract yaitu pada interaface tidak memerlukan hubungan pewarisan
 * Karena dalam interface tidak memiliki atribut, semua method dalam interface dapat digunakan oleh class lain
 * Meskipun class tersebut beda jenis
 * Yang terpenting memiliki behavior yang sama seperti Bangun, Garis, Bangun3D dan lainnya
 */
