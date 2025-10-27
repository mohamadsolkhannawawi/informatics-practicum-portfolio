// Nama file : Manajer.java
// Nama Pembuat : Mohamad Solkhan Nawawi - 24060123120020
// Tanggal : 20/03/2023
// Deskripsi : Kelas Manajer yang merupakan subclass dari Pegawai

package PostTest;

public class Manajer extends Pegawai {
    private static int tunjangan = 700000;

    public Manajer(String nama) {
        super.setNama(nama);
    }

    @Override
    public void tampilData() {
        super.tampilData();
        System.out.println("Tunjangan : " + tunjangan);
    }

}


    

