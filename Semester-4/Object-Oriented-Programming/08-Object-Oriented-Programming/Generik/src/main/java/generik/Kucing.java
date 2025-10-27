// Nama file    : Kucing.java
// Nama Pembuat : Mohamad Solkhan Nawawi - 24060123120020
// Tanggal      : 30/04/2025
// Deskripsi    : Kucing merupakan subclass dari Anabul

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package generik;

/**
 *
 * @author Solkhan
 */
public class Kucing extends Anabul {
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
