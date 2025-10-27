/* 
 * Nama File    : Tendik.java
 * Nama Pembuat : Mohamad Solkhan Nawawi
 * NIM Pembuat  : 24060123120020
 * Tanggal      : 14 Maret 2025
 * Deskripsi    : Tendik merupakan subclass dari Pegawai yang berisi atribut
 *                tambahan Bidang dan batasUsiaPensiun (BUP).
 */


public class Tendik extends Pegawai {
    private String bidang;
    private static final int BUP = 55;

    public Tendik(String NIP, String nama, Tanggal tanggalLahir, Tanggal TMT, double gajiPokok, String bidang) {
        super(NIP, nama, tanggalLahir, TMT, gajiPokok);
        this.bidang = bidang;
    }

    public double hitungTunjangan(Tanggal tanggalSekarang) {
        int masaKerja = tanggalSekarang.getTahun() - TMT.getTahun();
        return 0.01 * masaKerja * gajiPokok;
    }

    public Tanggal hitungBUP() {
        return super.hitungBUP(BUP);
    }

    @Override
    public void printInfo(Tanggal tanggalSekarang) {
        super.printInfo(tanggalSekarang);
        System.out.println("Bidang        : " + bidang);
        System.out.println("Jabatan       : Tendik");
        System.out.println("BUP           : " + hitungBUP().getHari() + " " + hitungBUP().getBulan() + " " + hitungBUP().getTahun());
        System.out.println("Tunjangan     : Rp " + String.format("%,.0f", hitungTunjangan(tanggalSekarang)) + ",00");
    }
}
