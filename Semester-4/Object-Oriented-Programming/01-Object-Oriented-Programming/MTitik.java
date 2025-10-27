/* Nama File   : MTitik.java
 * Deskripsi   : Main class untuk class Titik
 * Pembuat     : Mohamad Solkhan Nawawi / 24060123120020
 * Tanggal     : 19 Februari 2025
*/

public class MTitik {
    public static void main(String[] args) {
        System.out.println("==================== Create Titik ==================");
        System.out.println("Membuat objek titik T1 dengan tanpa parameter");
        System.out.println("Membuat objek titik T2 dengan parameter");
        System.out.println("Membuat objek titik T3 dengan parameter");
        System.out.println("\n");

        // Membuat objek titik T1 dengan tanpa parameter
        Titik T1 = new Titik();
        // Membuat objek titik T2 dengan parameter
        Titik T2 = new Titik(1, 1);
        // Membuat objek titik T3 dengan
        Titik T3 = new Titik(2, 2);
        System.out.println("\n");

        // Selektor dan Mutator
        // Menampilkan absis T1
        System.out.println("==================== Getter Titik ==================");
        System.out.println("Absis T1: " + T1.getAbsis());
        // Menampilkan ordinat T1
        System.out.println("Ordinat T1: " + T1.getOrdinat());
        // Menampilkan absis T2
        System.out.println("Absis T2: " + T2.getAbsis());
        // Menampilkan ordinat T2
        System.out.println("Ordinat T2: " + T2.getOrdinat());
        // Menampilkan absis T3
        System.out.println("Absis T3: " + T3.getAbsis());
        // Menampilkan ordinat T3
        System.out.println("Ordinat T3: " + T3.getOrdinat());
        System.out.println("\n");

        // Mengatur absis T1
        System.out.println("==================== Setter Titik ==================");
        T1.setAbsis(3);
        // Mengatur ordinat T1
        T1.setOrdinat(3);
        System.out.println("Setelah diubah");
        // Menampilkan absis T1
        System.out.println("Absis T1: " + T1.getAbsis());
        // Menampilkan ordinat T1
        System.out.println("Ordinat T1: " + T1.getOrdinat());
        System.out.println("\n");

        System.out.println("==================== Method Titik ==================");
        // Mengembalikan banyaknya titik yang telah dibuat
        System.out.println("Jumlah titik yang telah dibuat: " + Titik.getCounterTitik());

        // Menggeser titik T1 sejauh 2,2
        System.out.println("Sebelum digeser");
        T1.printTitik();
        T1.geser(2, 2);
        System.out.println("Setelah digeser sejauh 2,2");
        T1.printTitik();

        // Menampilkan kuadran dari titik T1
        System.out.println("Kuadran T1: " + T1.getKuadran());
        // Menampilkan kuadran dari titik T2
        System.out.println("Kuadran T2: " + T2.getKuadran());
        // Menampilkan kuadran dari titik T3
        System.out.println("Kuadran T3: " + T3.getKuadran());

        // Menampilkan jarak titik ke pusat
        System.out.println("Jarak T1 ke pusat: " + T1.getJarakPusat());
        System.out.println("Jarak T2 ke pusat: " + T2.getJarakPusat());
        System.out.println("Jarak T3 ke pusat: " + T3.getJarakPusat());

        // Menampilkan jarak antara dua titik
        System.out.println("Jarak antara T1 dan T2: " + T1.getJarak(T2));
        System.out.println("Jarak antara T1 dan T3: " + T1.getJarak(T3));
        System.out.println("Jarak antara T2 dan T3: " + T2.getJarak(T3));

        // Menampilkan hasil refleksi titik T1 terhadap sumbu x
        System.out.println("Sebelum direfleksi terhadap sumbu x");
        T1.printTitik();
        T1.refleksiX();
        System.out.println("Setelah direfleksi terhadap sumbu x");
        T1.printTitik();
        // Menampilkan hasil refleksi titik T2 terhadap sumbu y
        System.out.println("Sebelum direfleksi terhadap sumbu y");
        T2.printTitik();
        T2.refleksiY();
        System.out.println("Setelah direfleksi terhadap sumbu y");
        T2.printTitik();
        // Menampilkan hasil refleksi
        System.out.println("Sebelum direfleksi terhadap sumbu x");
        T3.printTitik();
        T3.refleksiX();
        System.out.println("Setelah direfleksi terhadap sumbu x");
        T3.printTitik();
        System.out.println("Sebelum direfleksi terhadap sumbu y");
        T3.printTitik();
        T3.refleksiY();
        System.out.println("Setelah direfleksi terhadap sumbu y");
        T3.printTitik();

        // Mengembalikan nilai refleksi terhadap sumbu x dari titik T1
        System.out.println("Refleksi terhadap sumbu x T1: (" + T1.getRefleksiX().getAbsis() + "," + T1.getRefleksiX().getOrdinat() + ")");
        // Mengembalikan nilai refleksi terhadap sumbu x dari titik T2
        System.out.println("Refleksi terhadap sumbu x T2: (" + T2.getRefleksiX().getAbsis() + "," + T2.getRefleksiX().getOrdinat() + ")");
        // Mengembalikan nilai refleksi terhadap sumbu x dari titik T3
        System.out.println("Refleksi terhadap sumbu x T3: (" + T3.getRefleksiX().getAbsis() + "," + T3.getRefleksiX().getOrdinat() + ")");

        // Mengembalikan nilai refleksi terhadap sumbu y dari titik T1
        System.out.println("Refleksi terhadap sumbu y T1: (" + T1.getRefleksiY().getAbsis() + "," + T1.getRefleksiY().getOrdinat() + ")");
        // Mengembalikan nilai refleksi terhadap sumbu y dari titik T2
        System.out.println("Refleksi terhadap sumbu y T2: (" + T2.getRefleksiY().getAbsis() + "," + T2.getRefleksiY().getOrdinat() + ")");
        // Mengembalikan nilai refleksi terhadap sumbu y dari titik T3
        System.out.println("Refleksi terhadap sumbu y T3: (" + T3.getRefleksiY().getAbsis() + "," + T3.getRefleksiY().getOrdinat() + ")");
    }
}
