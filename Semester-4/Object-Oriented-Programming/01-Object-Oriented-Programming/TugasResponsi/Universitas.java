/* 
 * Nama File    : Universitas.java
 * Nama Pembuat : Mohamad Solkhan Nawawi
 * NIM Pembuat  : 24060123120020
 * Tanggal      : 28 Maret 2025
 * Deskripsi    : Universitas merupakan class yang mewadahi seluruh 
 *                fakultas dan civitas akademika.
 */

import java.util.ArrayList;

public class Universitas {
    private String nama;
    private ArrayList<Fakultas> listFakultas;

    public Universitas(String nama) {
        this.nama = nama;
        listFakultas = new ArrayList<>();
    }

    public void tambahFakultas(Fakultas fakultas) {
        this.fakultas.add(fakultas);
    }

    public void tampilkanInfo() {
        System.out.println("Universitas " + nama);
        System.out.println("Daftar Fakultas:");
        for (Fakultas fakultas : fakultas) {
            fakultas.tampilkanInfo();
        }
    }
}