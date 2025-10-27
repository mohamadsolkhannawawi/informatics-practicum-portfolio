/* 
 * Nama File    : MainKoleksiAnabul.java
 * Nama Pembuat : Mohamad Solkhan Nawawi
 * NIM Pembuat  : 24060123120020
 * Tanggal      : 7 Mei 2025
 * Deskripsi    : MainKoleksiAnabul merupakan mainclass untuk menjalankan kelas koleksi generik yang 
 *                berisi objek dengan kelas Anabul, Anjing, Kucing dan Burung.
 */

package KoleksiAnabul;

public class MainKoleksiAnabul {
    public static void main(String[] args) {
        System.out.println("=== Koleksi Anabul ===");
        KoleksiAnabul<Anabul> koleksiAnabul = new KoleksiAnabul<>(Anabul.class);
        koleksiAnabul.add(new Anjing("Doggo")); //1
        koleksiAnabul.add(new Kucing("Kitty")); //2
        koleksiAnabul.add(new Burung("Tweety"));  //3
        koleksiAnabul.add(new Anjing("Bobby")); //4
        koleksiAnabul.add(new Kucing("Mimi")); //5
        koleksiAnabul.add(new Burung("Chirp")); //6
        koleksiAnabul.add(new Anjing("Rex")); //7
        koleksiAnabul.add(new Kucing("Luna")); //8
        koleksiAnabul.add(new Burung("Sky")); //9
        koleksiAnabul.add(new Anjing("Max")); //10

        koleksiAnabul.showAll();
    }
    
}
