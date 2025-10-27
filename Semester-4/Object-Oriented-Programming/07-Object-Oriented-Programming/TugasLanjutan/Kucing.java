/* 
 * Nama File    : Kucing.java
 * Nama Pembuat : Mohamad Solkhan Nawawi
 * NIM Pembuat  : 24060123120020
 * Tanggal      : 23 April 2025
 * Deskripsi    : Kucing merupakan subclass dari Anabul dengan method Gerak dan Suara dengan Konsep Polimorfisme.
 */

package TugasLanjutan;

public class Kucing extends Anabul{
    
    public Kucing(String Nama) {
        super(Nama);
    }
    
    public void Gerak() {
        System.out.println("Gerak : Melata");
    }

    public void Suara() {
        System.out.println("Suara : Meong");
    }

}
