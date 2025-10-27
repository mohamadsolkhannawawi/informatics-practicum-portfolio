/* 
 * Nama File    : Anjing.java
 * Nama Pembuat : Mohamad Solkhan Nawawi
 * NIM Pembuat  : 24060123120020
 * Tanggal      : 23 April 2025
 * Deskripsi    : Anjing merupakan subclass dari Anabul dengan method Gerak dan Suara dengan Konsep Polimorfisme.
 */

 package TugasLanjutan;

public class Anjing extends Anabul {
    
    public Anjing(String Nama) {
        super(Nama);
    }

    public void Gerak() {
        System.out.println("Gerak : Melata");
    }

    public void Suara() {
        System.out.println("Suara : Guk-guk");
    }
}
