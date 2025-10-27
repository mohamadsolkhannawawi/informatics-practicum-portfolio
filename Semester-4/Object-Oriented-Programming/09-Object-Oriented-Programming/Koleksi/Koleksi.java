/* 
 * Nama File    : Koleksi.java
 * Nama Pembuat : Mohamad Solkhan Nawawi
 * NIM Pembuat  : 24060123120020
 * Tanggal      : 7 Mei 2025
 * Deskripsi    : Koleksi adalah kelas generik yang dapat menyimpa elemen dari tipe data apapun.
 *                Kelas ini memiliki atribut wadah yang merupakan array dari tipe data generik T,
 *                serta atribut nbElm yang menyimpan jumlah elemen yang ada dalam wadah.
 * *              Kelas ini juga memiliki kapasitas maksimum wadah yang ditentukan oleh variabel kapasitas.
 */

package Koleksi;

import java.lang.reflect.Array;
public class Koleksi<T>{
    // Atribut
    private int nbElm;
    private T[] wadah;
    private final int kapasitas = 100;

    // Konstruktor
    @SuppressWarnings("unchecked") // Untuk menghindari peringatan unchecked cast, tapi tanggung jawab ada pada programmer
    public Koleksi(Class<T> kelasT) {
        this.wadah = (T[]) Array.newInstance(kelasT, kapasitas);
        this.nbElm = 0;
    }

    // Method
    public T getIsi(int i) {
        if (i >= 0 && i < nbElm) {
            return wadah[i];
        } else {
            throw new IndexOutOfBoundsException("Index di luar batas");
        }
    }

    public void setIsi(int i, T isi) {
        if (i >= 0 && i < nbElm) {
            wadah[i] = isi;
        } else {
            throw new IndexOutOfBoundsException("Index di luar batas");
        }
    }

    public int getSize() {
        return nbElm;
    }

    public void setSize(int size) {
        if (size >= 0 && size <= kapasitas) {
            this.nbElm = size;
        } else {
            throw new IllegalArgumentException("Invalid size");
        }
    }

    public void add(T elemenBaru) {
        if (nbElm < kapasitas) {
            wadah[nbElm] = elemenBaru;
            nbElm++;
        } else {
            System.out.println("Array sudah penuh");
        }
    }

    public void delete(int index) {
        if (index >= 0 && index < nbElm) {
            for (int i = index; i < nbElm - 1; i++) {
                wadah[i] = wadah[i + 1];
            }
            wadah[nbElm - 1] = null;
            nbElm--;
        } else {
            throw new IndexOutOfBoundsException("Index di luar batas");
        }
    }

    public void showAll() {
        for (int i = 0; i < nbElm; i++) {
            System.out.print(wadah[i] + " ");
        }
    }
}
