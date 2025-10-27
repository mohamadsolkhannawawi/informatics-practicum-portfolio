/* Nama File   : Mahasiswa.java
 * Deskripsi   : Berisi atribut dan method dalam class Mahasiswa
 * Pembuat     : Mohamad Solkhan Nawawi / 24060123120020
 * Tanggal     : 26 Februari 2025
*/

package Akademik;
import java.util.ArrayList;

public class Mahasiswa {
    // Atribut
    private String NIM;
    private String nama;
    private String prodi;
    private ArrayList<MataKuliah> listMatkul;
    private Dosen dosenWali;
    private Kendaraan kendaraan;
    
    // Konstruktor
    public Mahasiswa() {
        NIM = "";
        nama = "";
        prodi = "";
        listMatkul = new ArrayList<>();
        dosenWali = new Dosen();
        kendaraan = new Kendaraan();
    }

    public Mahasiswa(String NIM, String nama, String prodi) {
        this.NIM = NIM;
        this.nama = nama;
        this.prodi = prodi;
        this.listMatkul = new ArrayList<>();
        this.dosenWali = new Dosen();
        this.kendaraan = new Kendaraan();
    }

    // Selektor
    // Mengembalikan nilai NIM Mahasiswa
    public String getNIM() {
        return NIM;
    }

    // Mengembalikan nilai nama Mahasiswa
    public String getNama() {
        return nama;
    }

    // Mengembalikan nilai prodi Mahasiswa
    public String getProdi() {
        return prodi;
    }

    // Mengembalikan nilai list mata kuliah Mahasiswa
    public ArrayList<MataKuliah> getListMatkul() {
        return listMatkul;
    }

    // Mengembalikan nilai dosen wali Mahasiswa
    public Dosen getDosenWali() {
        return dosenWali;
    }

    // Mengembalikan nilai kendaraan Mahasiswa
    public Kendaraan getKendaraan() {
        return kendaraan;
    }
    
    // Mutator
    // Mengubah nilai NIM Mahasiswa
    public void setNIM(String NIM) {
        this.NIM = NIM;
    }

    // Mengubah nilai nama Mahasiswa
    public void setNama(String nama) {
        this.nama = nama;
    }

    // Mengubah nilai prodi Mahasiswa
    public void setProdi(String prodi) {
        this.prodi = prodi;
    }

    // Mengubah nilai list mata kuliah Mahasiswa
    public void setListMatkul(ArrayList<MataKuliah> listMatkul) {
        this.listMatkul = listMatkul;
    }

    // Mengubah nilai dosen wali Mahasiswa
    public void setDosenWali(Dosen dosenWali) {
        this.dosenWali = dosenWali;
    }

    // Mengubah nilai kendaraan Mahasiswa
    public void setKendaraan(Kendaraan kendaraan) {
        this.kendaraan = kendaraan;
    }

    // Method
    // Menambahkan mata kuliah ke dalam list mata kuliah Mahasiswa
    public void addMatkul(MataKuliah newMatkul) {
        listMatkul.add(newMatkul);
    }

    // Mengembalikan jumlah SKS yang diambil oleh Mahasiswa
    public int getJumlahSKS() {
        int totalSKS = 0;
        int i;
        for (i = 0; i < listMatkul.size(); i++) {
            totalSKS += listMatkul.get(i).getSKS();
        }
        return totalSKS;
    }

    // Mengembalikan jumlah mata kuliah yang diambil oleh Mahasiswa
    public int getJumlahMatkul() {
        return listMatkul.size();
    }

    // Menampilkan data Mahasiswa
    public void printMhs() {
        System.out.println("NIM : " + NIM);
        System.out.println("Nama : " + nama);
        System.out.println("Prodi : " + prodi);
    }

    // Menampilkan detail data Mahasiswa
    public void printDetailMhs() {
        System.out.println("NIM : " + NIM);
        System.out.println("Nama : " + nama);
        System.out.println("Prodi : " + prodi);
        System.out.println("Daftar Mata Kuliah : ");
        int i;
        for (i = 0; i < listMatkul.size(); i++) {
            System.out.println(listMatkul.get(i).getNama());
        }
        System.out.println("Data Dosen Wali : "); // Menampilkan data dosen wali
        System.out.println("NIP : " + dosenWali.getNIP());
        System.out.println("Nama : " + dosenWali.getNama());
        System.out.println("Prodi : " + dosenWali.getProdi());
        System.out.println("Data Kendaraan : "); // Menampilkan data kendaraan
        System.out.println("Jenis : " + kendaraan.getJenis());
        System.out.println("No Plat : " + kendaraan.getNoPlat());
    }
}
