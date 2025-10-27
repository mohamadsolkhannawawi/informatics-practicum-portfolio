/* 
 * Nama File    : ArrayListTest.java
 * Nama Pembuat : Mohamad Solkhan Nawawi
 * NIM Pembuat  : 24060123120020
 * Tanggal      : 7 Mei 2025
 * Deskripsi    : ArrayListTest merupakan kelas yang digunakan untuk menguji ArrayList dengan tipe data String.
 *                ArrayList adalah kelas yang digunakan untuk menyimpan sekumpulan objek dengan ukuran yang dapat berubah.  
*/

import java.util.ArrayList;
public class ArrayListTest {
    public static void main(String[] args) {
        //Inisialisasi ArrayList yang hanya dapat berisi objek String
        ArrayList<String> strings = new ArrayList<String>();
        // Menambahkan elemen ke dalam ArrayList
        strings.add("praktikum");
        strings.add("collection");
        strings.add("dan generics");
        // Mengahpus elemen pertama
        strings.remove("praktikum");
        // Iterasi keseluruhan elemen dalam ArrayList
        for (String s : strings) {
            System.out.println(s + " ");
        }
    }
}
