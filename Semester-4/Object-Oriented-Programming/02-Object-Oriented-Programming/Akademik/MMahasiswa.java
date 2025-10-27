/* Nama File   : MMahasiswa.java
 * Deskripsi   : Berisi main class MMahasiswa
 * Pembuat     : Mohamad Solkhan Nawawi / 24060123120020
 * Tanggal     : 26 Februari 2025
*/

package Akademik;

public class MMahasiswa {
    public static void main(String[] args) {
        // Test sesuai modul praktikum
        System.out.println("============== Test sesuai modul praktikum ==============");
        MataKuliah PBO = new MataKuliah("PBO", "Pemrograman Berorientasi Objek", 3);
        MataKuliah MBD = new MataKuliah("MBD", "Manajemen Basis Data", 3);
        Mahasiswa M1 = new Mahasiswa("234", "Citra", "Informatika");
        Dosen D1 = new Dosen("123", "Andi", "Informatika");
        Kendaraan K1 = new Kendaraan("H1234AB", "motor");
        M1.setDosenWali(D1);
        M1.setKendaraan(K1);
        M1.addMatkul(PBO);
        M1.addMatkul(MBD);
        M1.printDetailMhs();
        System.out.println("Jumlah Mata Kuliah :" + M1.getJumlahMatkul());
        System.out.println("Jumlah SKS Mata Kuliah :" + M1.getJumlahSKS());
        System.out.println("=========================================================");

        // Test tambahan
        System.out.println("======================= Test tambahan ===================");
        MataKuliah PPL = new MataKuliah("PPL", "Pemrograman Perangkat Lunak", 3);
        MataKuliah BASDAT = new MataKuliah("BASDAT", "Basis Data", 4);
        Mahasiswa M2 = new Mahasiswa("235", "Dewi", "Informatika");
        Dosen D2 = new Dosen("124", "Budi", "Informatika");
        Kendaraan K2 = new Kendaraan("H1234AC", "mobil");
        M2.setDosenWali(D2);
        M2.setKendaraan(K2);
        M2.addMatkul(PPL);
        M2.printDetailMhs();
        System.out.println("Jumlah Mata Kuliah :" + M2.getJumlahMatkul());
        System.out.println("Jumlah SKS Mata Kuliah :" + M2.getJumlahSKS());
        System.out.println("=========================================================");

        // Mahasiswa M1 menambah mata kuliah PPL dan BASDAT
        System.out.println("============= Test Modifikasi Mahasiswa M1 ==============");
        System.out.println("Mahasiswa M1 menambah mata kuliah PPL dan BASDAT");
        System.out.println("Mahasiswa M1 mengganti dosen wali menjadi D2");
        M1.setDosenWali(D2);
        M1.addMatkul(PPL);
        M1.addMatkul(BASDAT);
        M1.printDetailMhs();
        System.out.println("Jumlah Mata Kuliah :" + M1.getJumlahMatkul());
        System.out.println("Jumlah SKS Mata Kuliah :" + M1.getJumlahSKS());
        System.out.println("=========================================================");
    }
}
