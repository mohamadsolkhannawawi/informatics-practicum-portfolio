// Nama file    : MainAnabul.java
// Nama Pembuat : Mohamad Solkhan Nawawi - 24060123120020
// Tanggal      : 30/04/2025
// Deskripsi    : MainAnabul merupakan main class untuk menguji kelas Datum Generik dan class contohMetodeGenerik
//                
//                
//  

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package generik;

/**
 *
 * @author Solkhan
 */
public class MainAnabul {
    public static void main(String[] args) {
        System.out.println("Simulasi Program untuk class Datum: ");
        Datum<Kucing> dataKucingDatum = new Datum<>(new Kucing("Pussy"));
        Datum<Anjing> dataAnjingDatum = new Datum<>(new Anjing("Bolt"));
        Datum<Burung> dataBurungDatum = new Datum<>(new Burung("Fumikage Tokoyami"));
        
        System.out.println("Perilaku Kucing:");
        dataKucingDatum.getIsi().Suara();
        dataKucingDatum.getIsi().Gerak();
        System.out.println("Perilaku Anjing:");
        dataAnjingDatum.getIsi().Suara();
        dataAnjingDatum.getIsi().Gerak();
        System.out.println("Perilaku Burung:");
        dataBurungDatum.getIsi().Suara();
        dataBurungDatum.getIsi().Gerak();        
        
        System.out.println("===========================================");
        
        System.out.println("Simulasi Program untuk class ContohMetodeGenerik: ");
        Datum<Kucing> datumKucingMetode = new Datum<>(new Kucing("Ragdoll"));
        Datum<Anjing> datumAnjingMetode = new Datum<>(new Anjing("Hound Dog"));
        Datum<Burung> datumBurungMetode = new Datum<>(new Burung("Hawks"));

        System.out.println("Perilaku Kucing: ");
        ContohMetodeGenerik.tampilkanPerilaku(datumKucingMetode);
        System.out.println("Perilaku Anjing: ");
        ContohMetodeGenerik.tampilkanPerilaku(datumAnjingMetode);
        System.out.println("Perilaku Burung: ");
        ContohMetodeGenerik.tampilkanPerilaku(datumBurungMetode);
    }
}
