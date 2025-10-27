/* 
 * Nama File    : Main.java
 * Nama Pembuat : Mohamad Solkhan Nawawi
 * NIM Pembuat  : 24060123120020
 * Tanggal      : 14 Maret 2025
 * Deskripsi    : Main merupakan class utama untuk menjalankan objek yang sudah dibentuk dari class.
 */

public class Main {
    public static void main(String[] args) {
        Tanggal tanggalSekarang = new Tanggal(10, "Maret", 2025);

        // Data Dosen Tetap
        System.out.println("\n==============================\n");

        System.out.println("Informasi Detail Dosen Tetap");
        Tanggal tglLahirDosenTetap = new Tanggal(5, "Mei", 1990);
        Tanggal tmtDosenTetap = new Tanggal(1, "Januari", 2015);
        DosenTetap dosenTetap = new DosenTetap("9545647548", "78647324", "Andi", tglLahirDosenTetap, tmtDosenTetap, 5000000, "Fakultas Sains dan Matematika");
        dosenTetap.printInfo(tanggalSekarang);

        System.out.println("\n==============================\n");

        // Data Dosen Tamu
        System.out.println("Informasi Detail Dosen Tamu");
        Tanggal tglLahirDosenTamu = new Tanggal(10, "Juni", 1985);
        Tanggal tmtDosenTamu = new Tanggal(15, "Februari", 2018);
        Tanggal kontrakBerakhir = new Tanggal(10, "Juni", 2026);
        DosenTamu dosenTamu = new DosenTamu("87654321", "54321098", "Budi", tglLahirDosenTamu, tmtDosenTamu, 4000000, "Fakultas Teknik", kontrakBerakhir);
        dosenTamu.printInfo(tanggalSekarang);

        System.out.println("\n==============================\n");

        // Data Tendik
        System.out.println("Informasi Detail Tendik");
        Tanggal tglLahirTendik = new Tanggal(20, "Januari", 1980);
        Tanggal tmtTendik = new Tanggal(1, "Maret", 2010);
        Tendik tendik = new Tendik("11223344", "Citra", tglLahirTendik, tmtTendik, 3500000, "Kemahasiswaan");
        tendik.printInfo(tanggalSekarang);
    }
}