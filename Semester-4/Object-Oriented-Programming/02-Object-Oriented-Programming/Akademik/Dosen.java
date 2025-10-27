/* Nama File   : Dosen.java
 * Deskripsi   : Berisi atribut dan method dalam class Dosen
 * Pembuat     : Mohamad Solkhan Nawawi / 24060123120020
 * Tanggal     : 26 Februari 2025
*/

package Akademik;

public class Dosen {
    // Atribut
    private String NIP;
    private String nama;
    private String prodi;

    // Method
    // Konstruktor
    public Dosen() {
        NIP = "";
        nama = "";
        prodi = "";
    }

    public Dosen(String NIP, String nama, String prodi) {
        this.NIP = NIP;
        this.nama = nama;
        this.prodi = prodi;
    }

    // Selektor
    // Mengembalikan nilai NIP Dosen
    public String getNIP() {
        return NIP;
    }

    // Mengembalikan nilai nama Dosen
    public String getNama() {
        return nama;
    }

    // Mengembalikan nilai prodi Dosen
    public String getProdi() {
        return prodi;
    }

    //Mutator
    // Mengubah nilai NIP Dosen
    public void setNIP(String NIP) {
        this.NIP = NIP;
    }

    // Mengubah nilai nama Dosen
    public void setNama(String nama){
        this.nama = nama;
    }

    // Mengubah nilai prodi Dosen
    public void setProdi(String prodi) {
        this.prodi = prodi;
    }
}
