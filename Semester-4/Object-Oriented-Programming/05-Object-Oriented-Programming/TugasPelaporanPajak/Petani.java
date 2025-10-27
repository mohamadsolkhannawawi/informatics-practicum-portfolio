/* 
 * Nama File    : Petani.java
 * Nama Pembuat : Mohamad Solkhan Nawawi
 * NIM Pembuat  : 24060123120020
 * Tanggal      : 21 Maret 2025
 * Deskripsi    : Petani merupakan subclass yang memiliki atribut asal_kota,
 *                counterPetani, C (sesuai digit ke 12 NIM). Serta method
 *                getCounterPetani, getAsalKota, setAsalKota, hitungMasaKerja, 
 *                hitungPajak, cetakInfo.              
 */

package TugasPelaporanPajak;

import java.time.LocalDate;
import java.time.temporal.ChronoUnit;

public class Petani extends Manusia implements Pajak{
    // Atribut
    private String asal_kota;
    private static int counterPetani = 0;
    private int C = 0;

    // Konstruktor tanpa parameter
    public Petani() {
        counterPetani++;
    }

    // Konstruktor dengan parameter
    public Petani(String nama, String tgl_mulai_kerja, String alamat, double pendapatan, String asal_kota) {
        super(nama, tgl_mulai_kerja, alamat, pendapatan);
        this.asal_kota = asal_kota;
        counterPetani++;
    }

    // Getter dan Setter
    public static int getCounterPetani() {
        return counterPetani;
    }

    public String getAsalKota() {
        return asal_kota;
    }

    public void setAsalKota(String asal_kota) {
        this.asal_kota = asal_kota;
    }

    // Method
    // Menghitung masa kerja
    // Menggunakan ChronoUnit untuk menghitung selisih tahun antara tgl_mulai_kerja dengan LocalDate.now()
    @Override
    public int hitungMasaKerja() {
        return (int) ChronoUnit.YEARS.between(tgl_mulai_kerja, LocalDate.now()) + C;
    }

    // Menghitung pajak
    // Pajak petani adalah 0
    @Override
    public double hitungPajak() {
        return 0 * pendapatan;
    }

    // Mencetak informasi petani
    @Override
    public void cetakInfo() {
        super.cetakInfo();
        System.out.println("Asal Kota: " + getAsalKota());
        System.out.println("Pajak: Rp" + formatPendapatan(hitungPajak()));
    }
}
