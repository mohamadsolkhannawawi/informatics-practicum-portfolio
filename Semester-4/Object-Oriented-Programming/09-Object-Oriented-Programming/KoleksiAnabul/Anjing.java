/* 
 * Nama File    : Anjing.java
 * Nama Pembuat : Mohamad Solkhan Nawawi
 * NIM Pembuat  : 24060123120020
 * Tanggal      : 7 Mei 2025
 * Deskripsi    : Anjing merupakan subclass dari Anabul dengan method Gerak dan Suara dengan Konsep Polimorfisme.
 */

 package KoleksiAnabul;

public class Anjing extends Anabul {
    
    // Konstruktor
    public Anjing(String Nama) {
        super(Nama);
    }

    // Method
    public void Gerak() {
        System.out.println("Gerak : Melata");
    }

    public void Suara() {
        System.out.println("Suara : Guk-guk");
    }
}
