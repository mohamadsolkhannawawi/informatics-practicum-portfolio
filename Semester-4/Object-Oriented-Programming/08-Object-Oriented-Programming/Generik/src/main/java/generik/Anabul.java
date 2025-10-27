// Nama file    : Anabul.java
// Nama Pembuat : Mohamad Solkhan Nawawi - 24060123120020
// Tanggal      : 30/04/2025
// Deskripsi    : Anabul merupakan superclass untuk class Anjing, Kucing dan Burung
//                dengan atribut Nama, serta method Gerak dan Suara
//                
//  

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package generik;

/**
 *
 * @author Solkhan
 */
public class Anabul {
    private String Nama;

    public Anabul(String Nama) {
        this.Nama = Nama;
    }

    public String getNama() {
        return "Nama  : " + Nama;
    }

    public void Gerak() {}

    public void Suara() {}
}
