/* 
 * Nama File    : Anabul.java
 * Nama Pembuat : Mohamad Solkhan Nawawi
 * NIM Pembuat  : 24060123120020
 * Tanggal      : 23 April 2025
 * Deskripsi    : Anabul merupakan superclass untuk class Kucing, Anjing dan Burung dengan method Gerak dan Suara .
 */package TugasLanjutan;

public class Anabul {
    private String Nama;

    public Anabul(String Nama) {
        this.Nama = Nama;
    }

    public String getNama() {
        return "Nama  : " + Nama;
    }

    public void Gerak() {}

    public void Suara() {}
}
