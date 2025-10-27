/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

// Nama file    : SerializePerson.java
// Nama Pembuat : Mohamad Solkhan Nawawi - 24060123120020
// Tanggal      : 14/05/2025
// Deskripsi    : Program untuk serialiasi objek person
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

// Class SerializePerson
public class SerializePerson {
    public static void main(String[] args) {
        Person person = new Person("Panji");
        try {
            FileOutputStream f = new FileOutputStream("person.ser");
            ObjectOutputStream s = new ObjectOutputStream(f);
            s.writeObject(person);
            System.out.println("Selesai menulis objek person.");
            s.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
