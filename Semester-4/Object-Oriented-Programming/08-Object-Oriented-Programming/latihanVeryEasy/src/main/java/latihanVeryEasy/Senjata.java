// Nama file    : Senjata.java
// Nama Pembuat : Mohamad Solkhan Nawawi - 24060123120020
// Tanggal      : 30/04/2025
// Deskripsi    : Senjata merupakan class yang memiliki atribut bunyi, peluru serta berisi method 
//                getBunyi, getPeluru, menembak, setBunyi, dan setPeluru.
//  

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package latihanVeryEasy;

/**
 *
 * @author Solkhan
 */
public class Senjata {
    // Atribut 
    private String bunyi;
    private int peluru;
    
    // Konstruktor
    public Senjata(String bunyi) {
        this.bunyi = bunyi;
        this.peluru = 0;
    }
    
    public String getBunyi() {
        return bunyi;
    }
    
    public int getPeluru() {
        return peluru;
    }
    
    public void menembak() {
        System.out.println(getBunyi());
        int sisaPeluru = getPeluru() - 1;
        System.out.println("Sisa Peluru: " + sisaPeluru);
    }
    
    public void setBunyi(String bunyi) {
        this.bunyi = bunyi;
    }
    
    public void setPeluru(int peluru) {
        this.peluru = peluru;
    }
}
