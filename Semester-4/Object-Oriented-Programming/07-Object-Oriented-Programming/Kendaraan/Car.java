/* 
 * Nama File    : Car.java
 * Nama Pembuat : Mohamad Solkhan Nawawi
 * NIM Pembuat  : 24060123120020
 * Tanggal      : 23 April 2025
 * Deskripsi    : Car merupakan subclass dari Vehicle dengan method override calRent.
 */

package Kendaraan;

public class Car extends Vehicle {
    void calRent(int jarak, float harga) {
        float fare = jarak * harga;
        fare = fare - 100.00f;
        System.out.println("Harga Sewa Mobil = " + fare);
    }
    
}
