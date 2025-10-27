// Nama file    : MysqlMahasiswaService.java
// Nama Pembuat : Mohamad Solkhan Nawawi - 24060123120020
// Tanggal      : 21/05/2025
// Deskripsi    : Kelas untuk menyediakan layanan service atau controller bagi program utama 
//                dalam mengelola basis data sehingga interaksi dengan basis data dapat dilakukan secara
//                object oriented dengan memanfaatkan model dan database utility.

/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
*/
package jdbc.service;
import jdbc.model.Mahasiswa;
import jdbc.utilities.MysqlUtility;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;
/**
 *
 * @author Solkhann
 */
public class MysqlMahasiswaService {
    Connection koneksi = null;

    // Constructor
    public MysqlMahasiswaService() {
        this.koneksi = MysqlUtility.getConnection(); // Mendapatkan koneksi dari MysqlUtility
    }

    public Mahasiswa makeMhsObject() {
        return new Mahasiswa();
    }

    public void add(Mahasiswa mhs) {
        String sql;
        boolean useProvidedId = mhs.getId() > 0; // Cek apakah ID awal sudah diset > 0

        if (useProvidedId) {
            // Jika ID disediakan, kita akan mencoba menggunakannya.
            sql = "INSERT INTO mahasiswa (id, nama) VALUES (?, ?)";
        } else {
            // Jika ID tidak disediakan (atau <= 0), biarkan DB auto-generate
            sql = "INSERT INTO mahasiswa (nama) VALUES (?)";
        }

        try (PreparedStatement pstmt = koneksi.prepareStatement(sql, Statement.RETURN_GENERATED_KEYS)) {
            if (useProvidedId) {
                pstmt.setInt(1, mhs.getId()); // Gunakan ID yang disediakan
                pstmt.setString(2, mhs.getNama());
            } else {
                pstmt.setString(1, mhs.getNama()); // Hanya nama, ID akan auto-generated
            }

            int affectedRows = pstmt.executeUpdate(); // Eksekusi query insert

            if (affectedRows > 0) {
                // Jika insert berhasil dan ID tidak disediakan sebelumnya (auto-increment case)
                // maka kita update objek mhs dengan ID yang di-generate database.
                // Jika ID sudah disediakan (useProvidedId = true), kita asumsikan ID tersebut berhasil digunakan
                // dan tidak menimpanya dengan generatedKeys, agar ID 5 untuk Haryo tetap.
                if (!useProvidedId) {
                    try (ResultSet generatedKeys = pstmt.getGeneratedKeys()) {
                        if (generatedKeys.next()) {
                            mhs.setId(generatedKeys.getInt(1)); // Update ID pada objek mhs
                        }
                    }
                }
                System.out.println("Berhasil insert");
            } else {
                // Ini seharusnya tidak terjadi jika tidak ada SQLException, tapi sebagai jaga-jaga
                System.err.println("Insert query dieksekusi, tetapi tidak ada baris yang terpengaruh.");
            }

        } catch (SQLException e) {
            System.err.println("Gagal menambahkan mahasiswa: " + e.getMessage());
            // Biarkan e.printStackTrace() aktif selama pengembangan untuk debugging
            e.printStackTrace();
        }
    }

    public void update(Mahasiswa mhs) {
        String sql = "UPDATE mahasiswa SET nama = ? WHERE id = ?";
        try (PreparedStatement pstmt = koneksi.prepareStatement(sql)) {
            pstmt.setString(1, mhs.getNama());
            pstmt.setInt(2, mhs.getId());
            int affectedRows = pstmt.executeUpdate();
            if (affectedRows > 0) {
                System.out.println("Berhasil update"); // Sesuai contoh output
            } else {
                System.out.println("Tidak ada data yang diupdate untuk ID: " + mhs.getId());
            }
        } catch (SQLException e) {
            System.err.println("Gagal mengupdate mahasiswa: " + e.getMessage());
            e.printStackTrace();
        }
    }

    public void delete(int id) {
        String sql = "DELETE FROM mahasiswa WHERE id = ?";
        try (PreparedStatement pstmt = koneksi.prepareStatement(sql)) {
            pstmt.setInt(1, id);
            int affectedRows = pstmt.executeUpdate();
            if (affectedRows > 0) {
                System.out.println("Berhasil delete"); // Sesuai contoh output
            } else {
                System.out.println("Tidak ada data yang dihapus untuk ID: " + id);
            }
        } catch (SQLException e) {
            System.err.println("Gagal menghapus mahasiswa: " + e.getMessage());
            e.printStackTrace();
        }
    }

    public Mahasiswa getById(int id) {
        String sql = "SELECT id, nama FROM mahasiswa WHERE id = ?";
        try (PreparedStatement pstmt = koneksi.prepareStatement(sql)) {
            pstmt.setInt(1, id);
            try (ResultSet rs = pstmt.executeQuery()) {
                if (rs.next()) {
                    int mhsId = rs.getInt("id");
                    String nama = rs.getString("nama");
                    return new Mahasiswa(mhsId, nama);
                }
            }
        } catch (SQLException e) {
            System.err.println("Gagal mengambil mahasiswa by ID: " + e.getMessage());
            e.printStackTrace();
        }
        return null;
    }

    public List<Mahasiswa> getAll() {
        List<Mahasiswa> daftarMahasiswa = new ArrayList<>();
        String sql = "SELECT id, nama FROM mahasiswa";
        try (Statement stmt = koneksi.createStatement();
             ResultSet rs = stmt.executeQuery(sql)) {
            while (rs.next()) {
                int mhsId = rs.getInt("id");
                String nama = rs.getString("nama");
                daftarMahasiswa.add(new Mahasiswa(mhsId, nama));
            }
        } catch (SQLException e) {
            System.err.println("Gagal mengambil semua mahasiswa: " + e.getMessage());
            e.printStackTrace();
        }
        return daftarMahasiswa;
    }
    
    public void indexReset() {
        String sqlMaxId = "SELECT MAX(id) AS max_id FROM mahasiswa";
        String sqlAlter;

        try (Statement stmt = koneksi.createStatement()) {
            int nextId = 1; // Default jika tabel kosong
            boolean tableHasData = false;

            try (ResultSet rs = stmt.executeQuery(sqlMaxId)) {
                if (rs.next()) {
                    int maxId = rs.getInt("max_id");
                    if (!rs.wasNull()) { // Cek apakah MAX(id) mengembalikan NULL (tabel kosong)
                        nextId = maxId + 1;
                        tableHasData = true;
                    }
                }
            }

            sqlAlter = "ALTER TABLE mahasiswa AUTO_INCREMENT = " + nextId;
            stmt.executeUpdate(sqlAlter);

            if (tableHasData) {
                System.out.println("Indeks AUTO_INCREMENT tabel mahasiswa direset ke " + nextId + " (berdasarkan MAX(id)+1).");
            } else {
                System.out.println("Indeks AUTO_INCREMENT tabel mahasiswa direset ke 1 (tabel kosong).");
            }

        } catch (SQLException e) {
            System.err.println("Gagal mereset indeks tabel mahasiswa: " + e.getMessage());
            e.printStackTrace();
        }
    }
    
    public boolean isEmpty() { 
        String sql = "SELECT COUNT(*) AS row_count FROM mahasiswa";
        try (Statement stmt = koneksi.createStatement();
             ResultSet rs = stmt.executeQuery(sql)) {
            if (rs.next()) {
                return rs.getInt("row_count") == 0;
            }
        } catch (SQLException e) {
            System.err.println("Gagal memeriksa apakah tabel kosong: " + e.getMessage());
            e.printStackTrace();
            // Asumsikan tidak kosong atau error jika terjadi kesalahan,
            // atau bisa lempar exception sesuai kebutuhan aplikasi.
            return false;
        }
        // Seharusnya tidak pernah mencapai titik ini jika query berhasil
        return true;
    }
    
    public void closeConnection() { 
        try {
            if (koneksi != null && !koneksi.isClosed()) {
                koneksi.close();
                System.out.println("Koneksi ke DB ditutup.");
            } else {
                System.out.println("Koneksi ke DB sudah ditutup atau null.");
            }
        } catch (SQLException e) {
            System.err.println("Gagal menutup koneksi ke DB: " + e.getMessage());
            e.printStackTrace();
        }
    }
}