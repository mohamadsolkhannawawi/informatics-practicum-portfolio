/* 
 * Nama File    : MManusia.java
 * Nama Pembuat : Mohamad Solkhan Nawawi
 * NIM Pembuat  : 24060123120020
 * Tanggal      : 21 Maret 2025
 * Deskripsi    : MManusia merupakan main class untuk menguji class Manusia
 *                dan subclassnya.                             
*/

package TugasPelaporanPajak;

public class MManusia {
    public static void main(String[] args) {
        System.out.println("================= Percobaan Sesuai Modul ================");
        PNS p1 = new PNS("Satriyo", "01-04-2006", "Jl. Seroja", 15000000, "198302032006041002");
        Pengusaha pe1 = new Pengusaha("Adhy", "01-01-2000", "Jl.Air", 55000000, "000-556-773-212-000-5");
        Petani pt1 = new Petani("Nugraha", "09-01-1977", "Jl. Bunga 9 Tembalang", 5000000, "Wonogiri");
        PNS p2 = new PNS("Panji", "01-04-2010", "Jl. Sirojudin", 10000000, "198004212010041002");
        
        p2.setAlamat("Jl. Panorama 111 Tembalang");

        System.out.println("============== Uji getCounter setiap class ==============");
        System.out.println("Jumlah Manusia = " + Manusia.getCounterMns());
        System.out.println("Jumlah PNS = " + PNS.getCounterPNS());
        System.out.println("Jumlah Pengusaha = " + Pengusaha.getCounterPengusaha());
        System.out.println("Jumlah Petani = " + Petani.getCounterPetani());
        
        System.out.println("=================== Uji hitungPajak =====================");
        System.out.println("Pajak PNS p1 = Rp" + Manusia.formatPendapatan(p1.hitungPajak()));
        System.out.println("Pajak Pengusaha pe1 = Rp" + Manusia.formatPendapatan(pe1.hitungPajak()));
        System.out.println("Pajak Petani pt1 = Rp" + Manusia.formatPendapatan(p1.hitungPajak()));
        
        System.out.println("================= Uji hitungMasaKerja ===================");
        System.out.println("Masa Kerja p1 = " + p1.hitungMasaKerja() + " tahun");
        System.out.println("Masa Kerja pe1 = " + pe1.hitungMasaKerja() + " tahun");
        System.out.println("Masa Kerja pt1 = " + pt1.hitungMasaKerja() + " tahun");
        
        System.out.println("==================== Uji cetakInfo ======================");
        p1.cetakInfo();
        System.out.println("=========================================================");
        pe1.cetakInfo();
        System.out.println("=========================================================");
        pt1.cetakInfo();
        System.out.println("=========================================================");

        System.out.println("================= OBJEK BARU ================");
        PNS Pegawai = new PNS("Solkhan", "01-01-2020", "Jl. Kebahagiaan Nomor 1", 20000000, "198302032006041002");
        Pengusaha Wirausahawan = new Pengusaha("Solkhan", "01-01-2020", "Jl. Kebahagiaan Nomor 1", 40000000, "000-556-773-212-000-5");
        Petani PetaniMuda = new Petani("Solkhan", "01-01-2020", "Jl. Kebahagiaan Nomor 1", 50000000, "Blora");
        Pegawai.cetakInfo();
        System.out.println("=========================================================");
        Wirausahawan.cetakInfo();
        System.out.println("=========================================================");
        PetaniMuda.cetakInfo();
        System.out.println("=========================================================");
        System.out.println("Jumlah Manusia = " + Manusia.getCounterMns());
        System.out.println("Jumlah PNS = " + PNS.getCounterPNS());
        System.out.println("Jumlah Pengusaha = " + Pengusaha.getCounterPengusaha());
        System.out.println("Jumlah Petani = " + Petani.getCounterPetani());
        System.out.println("=========================================================");
    }
}