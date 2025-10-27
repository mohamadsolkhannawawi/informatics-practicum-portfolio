/* 
 * Nama File    : Pengusaha.java
 * Nama Pembuat : Mohamad Solkhan Nawawi
 * NIM Pembuat  : 24060123120020
 * Tanggal      : 21 Maret 2025
 * Deskripsi    : Pengusaha merupakan subclass yang memiliki atribut
 *                npwp, counterPengusaha, B (sesuai digit ke 13 NIM).
 *                serta method getCounterPengusaha, getNPWP, setNPWP, 
 *                hitungMasaKerja, hitungPajak, cetakInfo.              
*/

package TugasPelaporanPajak;
import java.time.LocalDate;
import java.time.temporal.ChronoUnit;

public class Pengusaha extends Manusia implements Pajak {
    private String npwp;
    private static int counterPengusaha = 0;
    private int B = 2;

    public Pengusaha() {
        counterPengusaha++;
    }

    public Pengusaha(String nama, String tgl_mulai_kerja, String alamat, double pendapatan, String npwp) {
        super(nama, tgl_mulai_kerja, alamat, pendapatan);
        this.npwp = npwp;
        counterPengusaha++;
    }

    public static int getCounterPengusaha() {
        return counterPengusaha;
    }

    public String getNPWP() {
        return npwp;
    }

    public void setNPWP(String npwp) {
        this.npwp = npwp;
    }

    @Override
    public int hitungMasaKerja() {
        return (int) ChronoUnit.YEARS.between(tgl_mulai_kerja, LocalDate.now()) + B;
    }
    
    @Override
    public double hitungPajak() {
        return 0.15 * pendapatan;
    }

    @Override
    public void cetakInfo() {
        super.cetakInfo();
        System.out.println("NPWP: " + npwp);
        System.out.println("Pajak: Rp" + formatPendapatan(hitungPajak()));
    }
}
