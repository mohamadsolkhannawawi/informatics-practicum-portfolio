/* 
 * Nama File    : Kucing.java
 * Nama Pembuat : Mohamad Solkhan Nawawi
 * NIM Pembuat  : 24060123120020
 * Tanggal      : 7 Mei 2025
 * Deskripsi    : Kucing merupakan subclass dari Anabul dengan method Gerak dan Suara dengan Konsep Polimorfisme.
 */

package KoleksiAnabul;

public class Kucing extends Anabul{
    
    // Konstruktor
    public Kucing(String Nama) {
        super(Nama);
    }
    
    // Method
    public void Gerak() {
        System.out.println("Gerak : Melata");
    }

    public void Suara() {
        System.out.println("Suara : Meong");
    }

}
