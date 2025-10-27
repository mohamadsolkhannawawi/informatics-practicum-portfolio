/* 
 * Nama File    : PNS.java
 * Nama Pembuat : Mohamad Solkhan Nawawi
 * NIM Pembuat  : 24060123120020
 * Tanggal      : 21 Maret 2025
 * Deskripsi    : PNS merupakan subclass yang memiliki atribut nip,
 *                counterPNS, dan A (sesuai digit ke 14 NIM). Serta method
 *                getCounterPNS, getNIP, setNIP, hitungMasaKerja, hitungPajak, cetakInfo.              
 */

package TugasPelaporanPajak;

import java.time.LocalDate;
import java.time.temporal.ChronoUnit;

public class PNS extends Manusia implements Pajak {
    private String nip;
    private static int counterPNS = 0;
    private int A = 0;

    public PNS() {
        counterPNS++;
    }

    public PNS(String nama, String tgl_mulai_kerja, String alamat, double pendapatan, String nip) {
        super(nama, tgl_mulai_kerja, alamat, pendapatan);
        this.nip = nip;
        counterPNS++;
    }

    public static int getCounterPNS() {
        return counterPNS;
    }

    public String getNIP() {
        return nip;
    }

    public void setNIP(String nip) {
        this.nip = nip;
    }

    @Override
    public int hitungMasaKerja() {
        return (int) ChronoUnit.YEARS.between(tgl_mulai_kerja, LocalDate.now()) + A;
    }

    @Override
    public double hitungPajak() {
        return 0.1 * pendapatan;
    }

    @Override
    public void cetakInfo() {
        super.cetakInfo();
        System.out.println("NIP: " + nip);
        System.out.println("Pajak: Rp" + formatPendapatan(hitungPajak()));
    }
}
