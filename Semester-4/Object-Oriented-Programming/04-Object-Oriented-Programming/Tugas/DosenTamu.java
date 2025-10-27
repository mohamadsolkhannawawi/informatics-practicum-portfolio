/* 
 * Nama File    : DosenTamu.java
 * Nama Pembuat : Mohamad Solkhan Nawawi
 * NIM Pembuat  : 24060123120020
 * Tanggal      : 14 Maret 2025
 * Deskripsi    : DosenTamu merupakan subclass dari Dosen yang berisi atribut
 *                tambahan NIDK dan tanggalBerakhirKontrak.
 */

 public class DosenTamu extends Dosen {
    private String NIDK;
    private Tanggal tanggalBerakhirKontrak;

    public DosenTamu(String NIP, String NIDK, String nama, Tanggal tanggalLahir, Tanggal TMT, double gajiPokok, String fakultas, Tanggal tanggalBerakhirKontrak) {
        super(NIP, nama, tanggalLahir, TMT, gajiPokok, fakultas);
        this.NIDK = NIDK;
        this.tanggalBerakhirKontrak = tanggalBerakhirKontrak;
    }

    public double hitungTunjangan() {
        return 0.025 * gajiPokok;
    }

    public int hitungLamaKontrak(Tanggal tanggalSekarang) {
        int tahun = tanggalBerakhirKontrak.getTahun() - tanggalSekarang.getTahun();
        int bulan = tanggalBerakhirKontrak.konversiBulanDalamInteger(tanggalBerakhirKontrak.getBulan()) - tanggalSekarang.konversiBulanDalamInteger(tanggalSekarang.getBulan());
        
        if (bulan < 0) {
            tahun--;
            bulan += 12;
        }
        return (tahun * 12) + bulan;
    }

    @Override
    public void printInfo(Tanggal tanggalSekarang) {
        super.printInfo(tanggalSekarang);
        System.out.println("NIDK          : " + NIDK);
        System.out.println("Jabatan       : Dosen Tamu");
        System.out.println("Lama Kontrak  : " + hitungLamaKontrak(tanggalSekarang) + " bulan");
        System.out.println("Tunjangan     : Rp " + String.format("%,.0f", hitungTunjangan()) + ",00");
    }
}