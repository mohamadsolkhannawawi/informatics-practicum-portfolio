/* 
 * Nama File    : Manusia.java
 * Nama Pembuat : Mohamad Solkhan Nawawi
 * NIM Pembuat  : 24060123120020
 * Tanggal      : 21 Maret 2025
 * Deskripsi    : Manusia merupakan superclass bertipe abstract yang memiliki 
 *                atribut nama, tgl_mulai_kerja, alamat, pendapatan.
 *                Manusia memiliki method konversiTanggal(Opsional Untuk 
 *                parsing bentuk tanggal), getCounterMns, getNama, setNama, 
 *                getTgl_mulai_kerja, setTgl_mulai_kerja
 *                getAlamat, setAlamat, getPendapatan, setPendapatan,
 *                formatPendapatan (Membuat format bilangan real menjadi Format uang
 *                contoh 1.000.000), hitungMasaKerja berupa class abstract,
 *                dan cetakInfo yang memiliki subclass 
 *                Pengusaha, PNS, Petani.               
 */

package TugasPelaporanPajak;
import java.text.DecimalFormat;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;


public abstract class Manusia {
    // Atribut Manusia
    protected String nama;
    protected LocalDate tgl_mulai_kerja;
    protected String alamat;
    protected double pendapatan;
    protected static int counterMns = 0;

    // Konstruktor Manusia tanpa parameter
    public Manusia() {
        counterMns++;
    }

    // Konstruktor Manusia
    public Manusia(String nama, String tgl_mulai_kerja, String alamat, double pendapatan) {
        this.nama = nama;
        this.tgl_mulai_kerja = konversiTanggal(tgl_mulai_kerja);
        this.alamat = alamat;
        this.pendapatan = pendapatan;
        counterMns++;
    }

    // Menggunakan bentuk string ke LocalDate, agar dalam main class tidak perlu melakukan parsing
    public static LocalDate konversiTanggal(String tanggal) { // Opsional, untuk parsing bentuk tanggal dari string ke LocalDate
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd-MM-yyyy");
        return LocalDate.parse(tanggal, formatter);
    }

    // Getter dan Setter
    public static int getCounterMns() {
        return counterMns;
    }

    public String getNama() {
        return nama;
    }

    public void setNama(String nama) {
        this.nama = nama;
    }

    public LocalDate getTgl_mulai_kerja() {
        return tgl_mulai_kerja;
    }

    public void setTgl_mulai_kerja(LocalDate tgl_mulai_kerja) {
        this.tgl_mulai_kerja = tgl_mulai_kerja;
    }

    public String getAlamat() {
        return alamat;
    }

    public void setAlamat(String alamat) {
        this.alamat = alamat;
    }

    public double getPendapatan() {
        return pendapatan;
    }

    public void setPendapatan(double pendapatan) {
        this.pendapatan = pendapatan;
    }

    // Method untuk format pendapatan agar menjadi format uang
    public static String formatPendapatan(double pendapatan) {
        DecimalFormat df = new DecimalFormat("#,###");
        return df.format(pendapatan);
    }

    // Method abstract untuk menghitung masa kerja
    public abstract int hitungMasaKerja();

    // Method untuk mencetak informasi
    public void cetakInfo() {
        DateTimeFormatter outputFormatter = DateTimeFormatter.ofPattern("dd-MM-yyyy"); // Sesuai input
        System.out.println("Nama: " + getNama());
        System.out.println("Tanggal Mulai Kerja: " + getTgl_mulai_kerja().format(outputFormatter)); // Format sama
        System.out.println("Alamat: " + getAlamat());
        System.out.println("Pendapatan: Rp" + formatPendapatan(getPendapatan()));
        System.out.println("Masa Kerja: " + hitungMasaKerja() + " tahun");
    }
    
}
