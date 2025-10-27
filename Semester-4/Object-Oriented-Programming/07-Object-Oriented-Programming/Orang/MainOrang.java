/* 
 * Nama File    : MainOrang.java
 * Nama Pembuat : Mohamad Solkhan Nawawi
 * NIM Pembuat  : 24060123120020
 * Tanggal      : 23 April 2025
 * Deskripsi    : MainOrang merupakan mainclass untuk menjalankan kelas Person dan kelas Student.
 */

package Orang;

public class MainOrang {
    public static void main(String[] args) {
        Person p;
        p = new Student("Sally");
        p.status(1);
    }
}

// Output yang dihasilkan yaitu : Now online: Sally
// Penjelasan:
// Pendefinisian objek p dengan tipe Person, tetapi diintansiasi dengan Student.
// Hal ini menunjukkan bahwa p dapat mengakses method yang ada di class Person.
// Ketika method status dipanggil, method isAsleep yang ada di class Student yang akan dieksekusi.
// Hal ini karena method status tidak dioverride dalam class Student, namun method isAsleep dioverride.
// Sehingga method isAsleep yang dieksekusi adalah method isAsleep yang ada di class Student, pada saat this.isAsleep(hr) dipanggil.
// Pada saat p.status(1) dipanggil, maka method status akan memanggil method isAsleep dengan parameter 1.
// Pada method isAsleep yang ada di class Student, 1 tidak memenuhi syarat 2 < hr && 8 > hr.
// Sehingga method isAsleep akan mengembalikan nilai false.
// Dan pada method status akan mencetak "Now online: " diikuti dengan nama yang ada di class Person, yaitu "Sally".
// Sehingga output yang dihasilkan adalah "Now online: Sally".
// Jika p.status(1) diganti dengan p.status(3), maka output yang dihasilkan adalah "Now offline: Sally".
// Hal ini karena pada saat p.status(3) dipanggil, method status akan memanggil method isAsleep dengan parameter 3.
// Pada method isAsleep yang ada di class Student, 3 memenuhi syarat 2 < hr && 8 > hr.
// Sehingga method isAsleep akan mengembalikan nilai true.
// Dan pada method status akan mencetak "Now offline: " diikuti dengan nama yang ada di class Person, yaitu "Sally".
// Sehingga output yang dihasilkan adalah "Now offline: Sally".
// this dalam java bekerja secara runtime bukan compile time, sehingga walaupun status dipanggil dari class Person, 
// tetapi yang dieksekusi adalah method isAsleep yang ada di class Student yang dijalankan saat runtime.
