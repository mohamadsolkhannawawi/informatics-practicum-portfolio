// Nama file : Programmer.java
// Nama Pembuat : Mohamad Solkhan Nawawi - 24060123120020
// Tanggal : 20/03/2023
// Deskripsi : Kelas Programmer yang merupakan subclass dari Pegawai

package PostTest;

public class Programmer extends Pegawai {
    private static int bonus = 450000;

    public Programmer(String nama) {
        super.setNama(nama);
    }

    @Override
    public void tampilData() {
        super.tampilData();
        System.out.println("Bonus : " + bonus);
    }
}


