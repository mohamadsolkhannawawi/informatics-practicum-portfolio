/* 
 * Nama File    : Person.java
 * Nama Pembuat : Mohamad Solkhan Nawawi
 * NIM Pembuat  : 24060123120020
 * Tanggal      : 23 April 2025
 * Deskripsi    : Person merupakan superclass untuk class Student yang berisi atribut name, dengan method isAsleep, toString, dan status.
 */

package Orang;

public class Person {
    private String name;

    public Person(String name) {
        this.name = name;
    }

    public boolean isAsleep(int hr) {
        return 22 < hr || 7 > hr;
    }
    
    public String toString() {
        return name;
    }

    public void status(int hr) {
        if (this.isAsleep(hr)) {
            System.out.println("Now offline: " + this);
        } else {
            System.out.println("Now online: " + this);
        }
    }
}
