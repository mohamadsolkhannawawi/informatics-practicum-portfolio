/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */

// Nama file    : ReadSerializedPerson.java
// Nama Pembuat : Mohamad Solkhan Nawawi - 24060123120020
// Tanggal      : 14/05/2025
// Deskripsi    : Program untuk membaca objek Person
// 

package Praktikum_10;

/**
 *
 * @author Solkhann
 */

import java.io.*;
// Class Person
class Person implements Serializable {
    private String name;
    public Person(String n) {
        name = n;
    }
    
    public String getName() {
        return name;
    }
}

// Class ReadSerializedPerson
public class ReadSerializedPerson {
    public static void main(String[] args) {
        Person person = null;
        
        try {
            FileInputStream f = new FileInputStream("person.ser");
            ObjectInputStream s = new ObjectInputStream(f);
            person = (Person) s.readObject();
            s.close();
            System.out.println("Serialized person name = "+person.getName());
        } catch (Exception ioe) {
            ioe.printStackTrace();
        }
    }
}
