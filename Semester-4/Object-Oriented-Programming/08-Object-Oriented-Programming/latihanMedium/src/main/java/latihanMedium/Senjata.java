// Nama file    : Senjata.java
// Nama Pembuat : Mohamad Solkhan Nawawi - 24060123120020
// Tanggal      : 30/04/2025
// Deskripsi    : Senjata merupakan class yang memiliki atribut bunyi, menusuk, dan peluru serta berisi method 
//                getBunyi, getPeluru, isMenusuk,  menembak, setBunyi, setMenusuk, dan setPeluru.
//  

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package latihanMedium;

/**
 *
 * @author Solkhan
 */
public class Senjata {
    // Atribut
    private String bunyi;
    private boolean menusuk;
    private int peluru;
    
    //Konstruktor
    public Senjata(String bunyi) {
        this.bunyi = bunyi;
        this.menusuk = false;
        this.peluru = 0;
    }
    
    // Method 
    public String getBunyi() {
        return bunyi;
    }
    
    public int getPeluru() {
        return peluru;
    }
    
    public boolean isMenusuk() {
        return menusuk;
    }
    
    public void setBunyi(String bunyi) {
        this.bunyi = bunyi;
    }
    
    public void setMenusuk(boolean menusuk) {
        this.menusuk = true;
    }
    
    public void setPeluru(int peluru) {
        this.peluru = peluru;
    }
}
