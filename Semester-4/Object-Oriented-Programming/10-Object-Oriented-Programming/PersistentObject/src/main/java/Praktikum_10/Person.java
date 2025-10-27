/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

// Nama file    : Person.java
// Nama Pembuat : Mohamad Solkhan Nawawi - 24060123120020
// Tanggal      : 14/05/2025
// Deskripsi    : Person database model
//  

package Praktikum_10;

/**
 *
 * @author Solkhann
 */
public class Person {
    private int id;
    private String name;
    
    public Person(String n) {
        name = n;
    }
    
    public Person(int i, String n) {
        id = i;
        name = n;
    }
    
    public int getId() {
        return id;
    }
    
    public String getName() {
        return name;
    }
}
