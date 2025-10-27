/* 
 * Nama File    : Vehicle.java
 * Nama Pembuat : Mohamad Solkhan Nawawi
 * NIM Pembuat  : 24060123120020
 * Tanggal      : 23 April 2025
 * Deskripsi    : Vehicle merupakan superclass untuk class Car dan Bus yang berisi method calRent.
 */

package Kendaraan;

public class Vehicle {
    void calRent(int distance, float price) {
        float fare = distance * price;
        System.out.println("Vehicle price = " + fare);
    }
}
