/* Nama File   : MGaris.java
 * Deskripsi   : Main class untuk class Garis
 * Pembuat     : Mohamad Solkhan Nawawi / 24060123120020
 * Tanggal     : 26 Februari 2025
*/

public class MGaris {
    public static void main(String[] args) {
        System.out.println("==================== Create Garis ==================");
        System.out.println("Membuat objek garis G1 dengan tanpa parameter");
        System.out.println("Membuat objek garis G2 dengan parameter");
        System.out.println("Membuat objek garis G3 dengan parameter");

        // Membuat objek garis G1 dengan tanpa parameter
        Garis G1 = new Garis();
        // Membuat objek garis G2 dengan parameter
        Garis G2 = new Garis(new Titik(1,1), new Titik(3,3));
        // Membuat objek garis G3 dengan parameter
        Garis G3 = new Garis(new Titik(2,2), new Titik(3,1));
        System.out.println("\n");
        
        // Selektor dan Mutator
        // Menampilkan titik awal G1
        System.out.println("==================== Getter Garis ==================");
        System.out.println("Titik Awal G1: (" + G1.getTitikAwal().getAbsis() + "," + G1.getTitikAwal().getOrdinat() + ")");
        // Menampilkan titik akhir G1
        System.out.println("Titik Akhir G1: (" + G1.getTitikAkhir().getAbsis() + "," + G1.getTitikAkhir().getOrdinat() + ")");

        // Menampilkan titik awal G2
        System.out.println("Titik Awal G2: (" + G2.getTitikAwal().getAbsis() + "," + G2.getTitikAwal().getOrdinat() + ")");
        // Menampilkan titik akhir G2
        System.out.println("Titik Akhir G2: (" + G2.getTitikAkhir().getAbsis() + "," + G2.getTitikAkhir().getOrdinat() + ")");

        // Menampilkan titik awal G3
        System.out.println("Titik Awal G3: (" + G3.getTitikAwal().getAbsis() + "," + G3.getTitikAwal().getOrdinat() + ")");
        // Menampilkan titik akhir G3
        System.out.println("Titik Akhir G3: (" + G3.getTitikAkhir().getAbsis() + "," + G3.getTitikAkhir().getOrdinat() + ")");
        System.out.println("\n");

        // Mengatur titik awal G1
        System.out.println("==================== Setter Garis ==================");
        G1.setTitikAwal(new Titik(2,2));
        // Mengatur titik akhir G1
        G1.setTitikAkhir(new Titik(4,4));
        System.out.println("Setelah diubah");
        // Menampilkan titik awal G1
        System.out.println("Titik Awal G1: (" + G1.getTitikAwal().getAbsis() + "," + G1.getTitikAwal().getOrdinat() + ")");
        // Menampilkan titik akhir G1
        System.out.println("Titik Akhir G1: (" + G1.getTitikAkhir().getAbsis() + "," + G1.getTitikAkhir().getOrdinat() + ")");
        System.out.println("\n");

        // Mengembalikan banyaknya garis yang telah dibuat
        System.out.println("==================== Method Garis ==================");
        System.out.println("Jumlah garis yang telah dibuat: " + Garis.getCounterGaris());

        // Method
        // Mengembalikan panjang garis G1
        System.out.println("Panjang garis G1: " + G1.panjangGaris());
        // Mengembalikan panjang garis G2
        System.out.println("Panjang garis G2: " + G2.panjangGaris());
        // Mengembalikan panjang garis G3
        System.out.println("Panjang garis G3: " + G3.panjangGaris());

        // Mengembalikan gradien dari garis G1
        // Penggunaan try-catch untuk menangani exception jika terjadi pembagian dengan 0
        try {
            System.out.println("Gradien garis G1: " + G1.gradienGaris());
        } catch (ArithmeticException e) {
            System.out.println("G1: Garis vertikal (gradien tidak terdefinisi)");
        }
        // Mengembalikan gradien dari garis G2
        try {
            System.out.println("Gradien garis G2: " + G2.gradienGaris());
        } catch (ArithmeticException e) {
            System.out.println("G2: Garis vertikal (gradien tidak terdefinisi)");
        }
        // Mengembalikan gradien dari garis G3
        try {
            System.out.println("Gradien garis G3: " + G3.gradienGaris());
        } catch (ArithmeticException e) {
            System.out.println("G3: Garis vertikal (gradien tidak terdefinisi)");
        }

        // Mengembalikan nilai titik tengah dari garis G1
        System.out.println("Titik tengah garis G1: (" + G1.titikTengah().getAbsis() + "," + G1.titikTengah().getOrdinat() + ")");
        // Mengembalikan nilai titik tengah dari garis G2
        System.out.println("Titik tengah garis G2: (" + G2.titikTengah().getAbsis() + "," + G2.titikTengah().getOrdinat() + ")");
        // Mengembalikan nilai titik tengah dari garis G3
        System.out.println("Titik tengah garis G3: (" + G3.titikTengah().getAbsis() + "," + G3.titikTengah().getOrdinat() + ")");
        System.out.println("\n");
        
        System.out.println("==================== Predikat Garis ==================");
        // Mengecek apakah garis G1 sejajar dengan garis G2
        System.out.println("Garis G1 sejajar dengan garis G2: " + G1.sejajar(G2));

        // Mengecek apakah garis G1 tegak lurus dengan garis G2
        System.out.println("Garis G1 tegak lurus dengan garis G2: " + G1.tegakLurus(G2));

        // Mengecek apakah garis G1 sejajar dengan garis G3
        System.out.println("Garis G1 sejajar dengan garis G3: " + G1.sejajar(G3));

        // Mengecek apakah garis G1 tegak lurus dengan garis G3
        System.out.println("Garis G1 tegak lurus dengan garis G3: " + G1.tegakLurus(G3));
        System.out.println("\n");

        System.out.println("==================== Method Lainnya Garis ==================");
        // Menampilkan titik awal dan akhir dari garis G1
        System.out.println("Titik Awal dan Akhir G1");
        G1.titikAwalAkhir();
        // Menampilkan titik awal dan akhir dari garis G2
        System.out.println("Titik Awal dan Akhir G2");
        G2.titikAwalAkhir();
        // Menampilkan titik awal dan akhir dari garis G3
        System.out.println("Titik Awal dan Akhir G3");
        G3.titikAwalAkhir();

        // Menampilkan persamaan garis G1
        System.out.println("Persamaan garis G1");
        G1.persamaanGaris();
        // Menampilkan persamaan garis G2
        System.out.println("Persamaan garis G2");
        G2.persamaanGaris();
        // Menampilkan persamaan garis G3
        System.out.println("Persamaan garis G3");
        G3.persamaanGaris();

        // Saat salah satu method dalam class Titik diubah
        // pada main class MGaris.java akan terjadi error
        // karena method tersebut dipanggil di dalam method persamaanGaris()
    }
}
