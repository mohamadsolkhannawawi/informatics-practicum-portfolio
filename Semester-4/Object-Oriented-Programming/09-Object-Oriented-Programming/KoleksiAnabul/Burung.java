/* 
 * Nama File    : Burung.java
 * Nama Pembuat : Mohamad Solkhan Nawawi
 * NIM Pembuat  : 24060123120020
 * Tanggal      : 7 Mei 2025
 * Deskripsi    : Burung merupakan subclass dari Anabul dengan method Gerak dan Suara dengan Konsep Polimorfisme.
 */

package KoleksiAnabul;

public class Burung extends Anabul{
    
    // Konstruktor
    public Burung(String Nama) {
        super(Nama);
    }

    // Method
    public void Gerak() {
        System.out.println("Gerak : Terbang");
    }

    public void Suara() {
        System.out.println("Suara : Cuit");
    }
}
