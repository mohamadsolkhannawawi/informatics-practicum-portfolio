// Nama file : Pegawai.java
// Nama Pembuat : Mohamad Solkhan Nawawi - 24060123120020
// Tanggal : 20/03/2023
// Deskripsi : Kelas Pegawai yang merupakan superclass dari Programmer dan Manajer

package PostTest;

public class Pegawai {
    private String nama;
    private static int gajiPokok = 5000000;

    public void setNama(String nama) {
        this.nama = nama;
    }

    public void tampilData() {
        System.out.println("Nama : " + nama + ", Gaji pokok : " + gajiPokok);
    }

}


