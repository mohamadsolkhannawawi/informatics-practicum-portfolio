/* Nama File   : MataKuliah.java
 * Deskripsi   : Berisi atribut dan method dalam class MataKuliah
 * Pembuat     : Mohamad Solkhan Nawawi / 24060123120020
 * Tanggal     : 26 Februari 2025
*/

package Akademik;

public class MataKuliah {
    // Atribut
    private String idMatkul;
    private String nama;
    private int sks;

    // Konsktruktor
    public MataKuliah() {
        idMatkul = "";
        nama = "";
        sks = 0;
    }

    public MataKuliah(String idMatkul, String nama, int sks) {
        this.idMatkul = idMatkul;
        this.nama = nama;
        this.sks = sks;
    }

    // Selektor
    // Mengembalikan nilai id matakuliah
    public String getIdMatkul() {
        return idMatkul;
    }

    // Mengembalikan nilai nama matakuliah
    public String getNama() {
        return nama;
    }

    // Mengembalikan nilai sks matakuliah
    public int getSKS() {
        return sks;
    }

    // Mutator
    // Mengubah nilai id matakuliah
    public void setIdMatkul(String idMatkul) {
        this.idMatkul = idMatkul;
    }

    // Mengubah nilai nama matakuliah
    public void setNama(String nama) {
        this.nama = nama;
    }

    // Mengubah nilai sks matakuliah
    public void setSKS(int sks) {
        this.sks = sks;
    }
}
