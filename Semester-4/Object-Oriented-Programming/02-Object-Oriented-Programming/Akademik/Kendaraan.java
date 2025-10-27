/* Nama File   : Kendaraan.java
 * Deskripsi   : Berisi atribut dan method dalam class Kendaraan
 * Pembuat     : Mohamad Solkhan Nawawi / 24060123120020
 * Tanggal     : 26 Februari 2025
*/

package Akademik;

public class Kendaraan {
    // Atriibut
    private String noPlat;
    private String jenis;
    
    // Konstruktor
    public Kendaraan() {
        noPlat = "";
        jenis = "";
    }

    public Kendaraan(String noPlat, String jenis) {
        this.noPlat = noPlat;
        this.jenis = jenis;
    }

    // Selektor
    // Mengembalikan nilai nomor plat kendaraan
    public String getNoPlat() {
        return noPlat;
    }

    // Mengembalikan nilai jenis kendaraan
    public String getJenis() {
        return jenis;
    }

    // Mutator
    // Mengubah nilai nomor plat kendaraan
    public void setNoPlat(String noPlat) {
        this.noPlat = noPlat;
    }

    // Mengubah nilai jenis kendaraan
    public void setJenis(String jenis) {
        this.jenis = jenis;
    }
}
