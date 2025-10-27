/* 
 * Nama File    : Main.java
 * Nama Pembuat : Mohamad Solkhan Nawawi
 * NIM Pembuat  : 24060123120020
 * Tanggal      : 7 Mei 2025
 * Deskripsi    : Main merupakan mainclass untuk menjalankan kelas koleksi generik yaitu kelas Koleksi
 *                yang dapat berisi tipe data apapun.
 */

package Koleksi;

public class Main {
    public static void main(String[] args) {
        System.out.println("=== Koleksi Karakter ===");
        Koleksi<Character> koleksi = new Koleksi<>(Character.class);
        
        for (char c = 'A'; c <= 'Z'; c++) {
            koleksi.add(c);
        }

        System.out.println("Jumlah elemen dalam koleksi: " + koleksi.getSize());
        System.out.println("Elemen pertama: " + koleksi.getIsi(0));
        System.out.println("Elemen terakhir: " + koleksi.getIsi(koleksi.getSize() - 1));
        System.out.println("Semua elemen dalam koleksi:");
        koleksi.showAll();
        System.out.println();

        System.out.println("=== Penghapusan Elemen ===");
        koleksi.delete(0);
        System.out.println("Setelah menghapus elemen pertama:");
        System.out.println("Jumlah elemen dalam koleksi: " + koleksi.getSize());
        System.out.println("Elemen pertama: " + koleksi.getIsi(0));
        System.out.println("Elemen terakhir: " + koleksi.getIsi(koleksi.getSize() - 1));
        System.out.println("Semua elemen dalam koleksi:");
        koleksi.showAll();
        System.out.println();
        
        System.out.println("=== Pengubahan Elemen ===");
        koleksi.setIsi(0, 'Z');
        System.out.println("Setelah mengubah elemen pertama menjadi 'Z':");
        System.out.println("Jumlah elemen dalam koleksi: " + koleksi.getSize());
        System.out.println("Elemen pertama: " + koleksi.getIsi(0));
        System.out.println("Elemen terakhir: " + koleksi.getIsi(koleksi.getSize() - 1));
        System.out.println("Semua elemen dalam koleksi:");
        koleksi.showAll();
        System.out.println();

        System.out.println("=== Pengubahan Ukuran Koleksi ===");
        koleksi.setSize(5);
        System.out.println("Setelah mengubah ukuran koleksi menjadi 5:");
        System.out.println("Jumlah elemen dalam koleksi: " + koleksi.getSize());
        System.out.println("Elemen pertama: " + koleksi.getIsi(0));
        System.out.println("Elemen terakhir: " + koleksi.getIsi(koleksi.getSize() - 1));
        System.out.println("Semua elemen dalam koleksi:");
        koleksi.showAll();
        System.out.println();
    }
}
