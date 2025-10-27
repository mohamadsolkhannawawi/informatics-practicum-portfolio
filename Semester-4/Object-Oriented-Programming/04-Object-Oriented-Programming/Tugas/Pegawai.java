/* 
 * Nama File    : Pegawai.java
 * Nama Pembuat : Mohamad Solkhan Nawawi
 * NIM Pembuat  : 24060123120020
 * Tanggal      : 14 Maret 2025
 * Deskripsi    : Pegawai merupakan superclass yang berisi atribut
 *                NIP, nama, tanggalLahir, TMT, dan gajiPokok.
 */

 public class Pegawai {
    protected String NIP;
    protected String nama;
    protected Tanggal tanggalLahir;
    protected Tanggal TMT;
    protected double gajiPokok;

    public Pegawai(String NIP, String nama, Tanggal tanggalLahir, Tanggal TMT, double gajiPokok) {
        this.NIP = NIP;
        this.nama = nama;
        this.tanggalLahir = tanggalLahir;
        this.TMT = TMT;
        this.gajiPokok = gajiPokok;
    }

    public Tanggal hitungBUP(int batasUsiaPensiun) {
        int tahunBUP = tanggalLahir.getTahun() + batasUsiaPensiun;
        int bulanBUP = tanggalLahir.konversiBulanDalamInteger(tanggalLahir.getBulan()) + 1;
        if (bulanBUP > 12) {
            bulanBUP = 1;
            tahunBUP++;
        }
        return new Tanggal(1, getNamaBulan(bulanBUP), tahunBUP);
    }
    
    private String getNamaBulan(int bulan) {
        String[] namaBulan = {"Januari", "Februari", "Maret", "April", "Mei", "Juni", "Juli", "Agustus", "September", "Oktober", "November", "Desember"};
        return namaBulan[bulan - 1];
    }

    public String hitungMasaKerja(Tanggal tanggalSekarang) {
        int tahun = tanggalSekarang.getTahun() - TMT.getTahun();
        int bulan = tanggalSekarang.konversiBulanDalamInteger(tanggalSekarang.getBulan()) - TMT.konversiBulanDalamInteger(TMT.getBulan());
        
        if (bulan < 0) {
            tahun--;
            bulan += 12;
        }
        return tahun + " tahun " + bulan + " bulan";
    }

    public void printInfo(Tanggal tanggalSekarang) {
        System.out.println("NIP           : " + NIP);
        System.out.println("Nama          : " + nama);
        System.out.println("Tanggal Lahir : " + tanggalLahir.getHari() + " " + tanggalLahir.getBulan() + " " + tanggalLahir.getTahun());
        System.out.println("TMT           : " + TMT.getHari() + " " + TMT.getBulan() + " " + TMT.getTahun());
        System.out.println("Masa Kerja    : " + hitungMasaKerja(tanggalSekarang));
        System.out.println("Gaji Pokok    : Rp " + String.format("%,.0f", gajiPokok) + ",00");
    }
}