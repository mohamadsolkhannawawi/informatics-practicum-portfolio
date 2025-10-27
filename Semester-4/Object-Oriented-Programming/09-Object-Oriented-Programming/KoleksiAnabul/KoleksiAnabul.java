/* 
 * Nama File    : KoleksiAnabul.java
 * Nama Pembuat : Mohamad Solkhan Nawawi
 * NIM Pembuat  : 24060123120020
 * Tanggal      : 7 Mei 2025
 * Deskripsi    : KoleksiAnabul merupakan class koleksi generik yang berisi atribut wadah dan nbElm, serta kapasitas untuk batasan panjang array.
 *               yang berfungsi untuk menampung objek-objek dari class Anabul, Kucing, Anjing dan Burung.
 */

package KoleksiAnabul;

import java.lang.reflect.Array;
public class KoleksiAnabul<T> {
    // Atribut
    private T[] wadah;
    private int nbElm;
    private final int kapasitas = 100;

    // Konstruktor
    @SuppressWarnings("unchecked") // Untuk menghindari peringatan unchecked cast, tapi tanggung jawab ada pada programmer
    public KoleksiAnabul(Class<T> kelasT) {
        this.wadah = (T[]) Array.newInstance(kelasT, kapasitas);
        this.nbElm = 0;
    }

    // Method
    public void add(T elemenBaru) {
        if (nbElm < kapasitas) {
            wadah[nbElm] = elemenBaru;
            nbElm++;
        } else {
            System.out.println("Koleksi sudah penuh");
        }
    }

    public void showAll() {
        for (int i = 0; i < nbElm; i++) {
            T elemen = wadah[i];
            if (elemen instanceof Anabul) {
                Anabul koleksiAnabul = (Anabul) elemen;
                int posisi = i + 1;
                System.out.println("Anabul ke-" + posisi + ": ");
                System.out.println(koleksiAnabul.getNama());
                koleksiAnabul.Gerak();
                koleksiAnabul.Suara();
                System.out.println("==========================");
            }
        }
    }


}
