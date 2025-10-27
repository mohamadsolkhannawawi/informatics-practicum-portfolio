/* 
 * Nama File    : Student.java
 * Nama Pembuat : Mohamad Solkhan Nawawi
 * NIM Pembuat  : 24060123120020
 * Tanggal      : 23 April 2025
 * Deskripsi    : Student merupakan subclass dari Person berisi method yang sama dengan superclass yaitu isAsleep dengan implementasi berbeda.
 */

package Orang;

public class Student extends Person{
    public Student(String name) {
        super(name);
    }
    
    public boolean isAsleep(int hr) {
        return 2 < hr && 8 > hr;
    }
}
