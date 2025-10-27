/* 
 * Nama File    : MapTest.java
 * Nama Pembuat : Mohamad Solkhan Nawawi
 * NIM Pembuat  : 24060123120020
 * Tanggal      : 7 Mei 2025
 * Deskripsi    : MapTest adalah class yang berisi main program untuk menguji implementasi Map
 *                dengan menggunakan HashMap.
 */

import java.util.*;

public class MapTest {
    public static void main(String[] args) {
        // Kunci --> integer, nilai --> string
        Map<Integer, String> map = new HashMap<Integer, String>();
        // Menempatkan elemen kunci dan nilai
        map.put(1, "satu");
        map.put(2, "dua");
        // Mengambil elemen pertama
        System.out.println(map.get(1));
        // Mengambil keseluruhan kunci sebagai objek collection set
        Set<Integer> key = map.keySet();
        // Iterasi keseluruhan kunci dalam Map
        for (Integer i : key) {
            // Mengambil nilai dari kunci yang bersangkutan
            System.out.println("Kunci: " + i + ", Nilai: " + map.get(i));
        }
    }
}
