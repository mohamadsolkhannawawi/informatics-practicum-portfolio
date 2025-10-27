// Nama file    : Burung.java
// Nama Pembuat : Mohamad Solkhan Nawawi - 24060123120020
// Tanggal      : 30/04/2025
// Deskripsi    : Burung merupakan subclass dari Anabul

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package generik;

/**
 *
 * @author Solkhan
 */
public class Burung extends Anabul{
    public Burung(String Nama) {
        super(Nama);
    }
    public void Gerak() {
        System.out.println("Gerak : Terbang");
    }

    public void Suara() {
        System.out.println("Suara : Cuit");
    }
}
