/* 
 * Nama File    : BangunDatarGenericTest.java
 * Nama Pembuat : Mohamad Solkhan Nawawi
 * NIM Pembuat  : 24060123120020
 * Tanggal      : 7 Mei 2025
 * Deskripsi    : BangunDatarGenericTest adalah class untuk menguji class BangunDatarGeneric dengan menggunakan generic
 *                dan menampilkan hasil perhitungan luas dan keliling dari bangun datar yang diinputkan.
 */


public class BangunDatarGenericTest {
    public static void main(String[] args) {
        System.out.println("=== Bangun Datar Generic ===");
        // Test Untuk Soal 3.3
        Lingkaran l = new Lingkaran(2);
        BangunDatarGeneric<Lingkaran> bdg = new BangunDatarGeneric<Lingkaran>();
        bdg.set(l);
        System.out.println("Luas Lingkaran    : " + bdg.hitungLuas());
        System.out.println("Keliling Lingkaran: " + bdg.hitungKeliling());
        System.out.println("Tipe Generic      : " + bdg.get().getClass().getName());

        System.out.println("=============================");
        // Test Untuk Soal 3.4
        // Persegi
        Persegi p = new Persegi(4);
        BangunDatarGeneric<Persegi> bdg2 = new BangunDatarGeneric<Persegi>();
        bdg2.set(p);
        System.out.println("Luas Persegi    : " + bdg2.hitungLuas());
        System.out.println("Keliling Persegi: " + bdg2.hitungKeliling());
        System.out.println("Tipe Generic    : " + bdg2.get().getClass().getName());

        System.out.println("=============================");
        // Persegi Panjang
        PersegiPanjang pp = new PersegiPanjang(4, 5);
        BangunDatarGeneric<PersegiPanjang> bdg3 = new BangunDatarGeneric<PersegiPanjang>();
        bdg3.set(pp);
        System.out.println("Luas Persegi Panjang    : " + bdg3.hitungLuas());
        System.out.println("Keliling Persegi Panjang: " + bdg3.hitungKeliling());
        System.out.println("Tipe Generic    : " + bdg3.get().getClass().getName());
        
        System.out.println("=============================");
        // Segitiga
        Segitiga s = new Segitiga(4, 5, 3, 4, 5);
        BangunDatarGeneric<Segitiga> bdg4 = new BangunDatarGeneric<Segitiga>();
        bdg4.set(s);
        System.out.println("Luas Segitiga    : " + bdg4.hitungLuas());
        System.out.println("Keliling Segitiga: " + bdg4.hitungKeliling());
        System.out.println("Tipe Generic     : " + bdg4.get().getClass().getName());
        System.out.println("=============================");
    } 
}
