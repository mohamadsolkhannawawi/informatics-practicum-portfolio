// Nama file    : Program.java
// Nama Pembuat : Mohamad Solkhan Nawawi - 24060123120020
// Tanggal      : 21/05/2025
// Deskripsi    : Kelas sebagai program utama untuk mensimulasikan CRUD masih dalam bentuk terminal.


/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
*/
package jdbc.program;
import jdbc.model.Mahasiswa;
import jdbc.service.MysqlMahasiswaService;
import java.util.ArrayList;
import java.util.List;
/**
 *
 * @author Solkhann
 */
public class Program {
    static MysqlMahasiswaService service = new MysqlMahasiswaService();

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        List<Mahasiswa> listMhs = new ArrayList<>();
        System.out.println(""); 
        
        // --- Operasi Insert ---
        System.out.println("===insert===");
        Mahasiswa mhsAdd = new Mahasiswa(5, "Haryo");
        service.add(mhsAdd); // Menambahkan mahasiswa ke database
        System.out.println("berhasil insert: " + mhsAdd); // Menampilkan hasil insert
        displayAll(); // Menampilkan semua data setelah insert
        
        // --- Operasi Update ---
        System.out.println("\n===update===");
        Mahasiswa mhsUpdate = service.getById(5);
        System.out.println("Akan diupdate data lama: " + mhsUpdate); // Menampilkan data lama
        mhsUpdate.setNama("Dinaya");
        System.out.println("dengan data baru: " + mhsUpdate);
        service.update(mhsUpdate); // Melakukan update ke database
        displayAll();
        
        // --- Operasi Delete ---
        System.out.println("\n===delete===");
        System.out.println("akan di delete: " + service.getById(5)); // Menampilkan data yang akan dihapus
        service.delete(5); // Melakukan delete dari database
        displayAll(); // Menampilkan semua data setelah delete
    }
    public static void displayAll() {
            System.out.println("===displayAll==="); // Header untuk display
            List<Mahasiswa> listMahasiswa = service.getAll(); // Mengambil semua data mahasiswa
            if (listMahasiswa.isEmpty()) {
                System.out.println("Tidak ada data mahasiswa.");
            } else {
                for (Mahasiswa mhs : listMahasiswa) {
                System.out.println(mhs); // Mencetak setiap objek mahasiswa (menggunakan toString())
            }
        }
    }
}
