/* 
 * Nama File    : Anabul.java
 * Nama Pembuat : Mohamad Solkhan Nawawi
 * NIM Pembuat  : 24060123120020
 * Tanggal      : 7 Mei 2025
 * Deskripsi    : Anabul merupakan superclass untuk class Kucing, Anjing dan Burung dengan method Gerak dan Suara .
 */
package KoleksiAnabul;

public class Anabul {
    // Atribut
    private String Nama;

    // Konstruktor
    public Anabul(String Nama) {
        this.Nama = Nama;
    }

    // Method
    public String getNama() {
        return "Nama  : " + Nama;
    }

    public void Gerak() {}

    public void Suara() {}
}
