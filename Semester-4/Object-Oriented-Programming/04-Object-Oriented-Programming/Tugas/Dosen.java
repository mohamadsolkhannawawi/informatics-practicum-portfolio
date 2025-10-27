/* 
 * Nama File    : Dosen.java
 * Nama Pembuat : Mohamad Solkhan Nawawi
 * NIM Pembuat  : 24060123120020
 * Tanggal      : 14 Maret 2025
 * Deskripsi    : Dosen merupakan subclass dari Pegawai
 *                yang berisi atribut tambahan yaitu fakultas serta menjadi 
 *                Superclass untuk class DosenTetap dan DosenTamu *                .
 */

 public class Dosen extends Pegawai {
    protected String fakultas;

    public Dosen(String NIP, String nama, Tanggal tanggalLahir, Tanggal TMT, double gajiPokok, String fakultas) {
        super(NIP, nama, tanggalLahir, TMT, gajiPokok);
        this.fakultas = fakultas;
    }

    @Override
    public void printInfo(Tanggal tanggalSekarang) {
        super.printInfo(tanggalSekarang);
        System.out.println("Fakultas      : " + fakultas);
    }
}

