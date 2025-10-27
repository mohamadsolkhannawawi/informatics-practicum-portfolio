// Nama file : TestPolimorfisme.java
// Nama Pembuat : Mohamad Solkhan Nawawi - 24060123120020
// Tanggal : 20/03/2023
// Deskripsi : Main class untuk menguji polimorfisme

package PostTest;

import java.util.ArrayList;

public class TestPolimorfisme {
    public static void main(String[] args) {
        Pegawai pegawai = new Programmer("Mira");
        Pegawai pegawai2 = new Manajer("Joko");
        Pegawai pegawai3 = new Manajer("Argo");

        ArrayList<Pegawai> emps = new ArrayList<>();
        emps.add(pegawai);
        emps.add(pegawai2);
        emps.add(pegawai3);

        for (Pegawai emp : emps) {
            emp.tampilData();
        }
    }
}
