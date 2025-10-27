/* 
 * Nama File    : MainAnabul.java
 * Nama Pembuat : Mohamad Solkhan Nawawi
 * NIM Pembuat  : 24060123120020
 * Tanggal      : 23 April 2025
 * Deskripsi    : MainAnabul merupakan mainclass untuk menjalankan kelas Anabul, Anjing, Kucing dan Burung.
 */

package TugasLanjutan;

public class MainAnabul {
    public static void main(String[] args) {
        Anabul anabul1 = new Anjing("Hound Dog");
        Anabul anabul2 = new Kucing("Ragdoll");
        Anabul anabul3 = new Burung("Hawks");

        System.out.println("==========================");
        System.out.println("Anabul 1 :");
        System.out.println(anabul1.getNama());
        anabul1.Gerak();
        anabul1.Suara();
        System.out.println("==========================");
        System.out.println("Anabul 2 :");
        System.out.println(anabul2.getNama());
        anabul2.Gerak();
        anabul2.Suara();
        System.out.println("==========================");
        System.out.println("Anabul 3 :");
        System.out.println(anabul3.getNama());
        anabul3.Gerak();
        anabul3.Suara();
        System.out.println("==========================");
    }
    
}
