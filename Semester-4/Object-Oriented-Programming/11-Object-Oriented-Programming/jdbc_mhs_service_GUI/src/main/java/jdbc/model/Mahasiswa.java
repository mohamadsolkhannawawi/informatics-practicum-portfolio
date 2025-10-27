// Nama file    : Mahasiswa.java
// Nama Pembuat : Mohamad Solkhan Nawawi - 24060123120020
// Tanggal      : 21/05/2025
// Deskripsi    : Kelas untuk persistent objek yang berperan sebagai model bagi tabel mahasiswa

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
*/
package jdbc.model;

/**
 *
 * @author Solkhann
 */
public class Mahasiswa {
    // atribut
    private int id;
    private String nama;
    
    // constructor
    public Mahasiswa () {
        
    }
    
    public Mahasiswa (int id, String nama) {
        this.id = id;
        this.nama = nama;
    }
    
    public int getId() {
        return id;
    }
    
    public void setId(int id) {
        this.id = id;
    }
    
    public String getNama() {
        return nama;
    }
    
    public void setNama(String nama) {
        this.nama = nama;
    }
    
    @Override
    public String toString() {
        return "Mahasiswa{" + "id=" + id + ", nama='" + nama + '\'' + '}';
    }
}
