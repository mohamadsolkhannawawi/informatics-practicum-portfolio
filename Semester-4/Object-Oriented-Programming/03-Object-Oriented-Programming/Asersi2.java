class Lingkaran {
    private double jariJari;
    public Lingkaran(double jariJari) {
        this.jariJari = jariJari;
    }
    public double hitungKeliling() {
        double Keliling = 2 * Math.PI * jariJari;
        return Keliling;
    }
}

public class Asersi2 {
    public static void main(String[] args) {
        double jariJari = 0;
        assert (jariJari > 0) : "jari jari tidak boleh nol!!!";
        Lingkaran l = new Lingkaran (jariJari);
        double kelilingLingkaran = l.hitungKeliling();
        System.out.println("Keliling Lingkaran = " + kelilingLingkaran);
    }
}

// Secara konsep, terdapat kesalahan dalam kode diatas. 
// Saat kode dijalankan, jika jariJari di assign dengan nilai 0, maka program akan tetap berjalan dan menghasilkan output "Keliling Lingkaran = 0.0".
// Hal ini tidak sesuai dengan asersi yang didefinisikan pada kode tersebut, dimana jariJari tidak boleh bernilai 0.
// Karena saat eksekusi kode, harus mengaktifkan asersi, maka perlu menambahkan -ea pada saat eksekusi kode.
// Sehingga, jika jariJari di assign dengan nilai 0, maka program akan berhenti dan menghasilkan output "Exception in thread "main" java.lang.AssertionError: jari jari tidak boleh nol!!!".
// Solusi dari kesalahan konsep tersebut adalah dengan penggunaan if else statement untuk mengecek apakah jariJari bernilai 0 atau tidak.
// Hal ini akan lebih memudahkan user, karena tidak perlu mengaktifkan asersi pada saat eksekusi kode.
// Contoh perbaikan kodenya adalah sebagai berikut:
// public class Asersi2 {
//     public static void main(String[] args) {
//         double jariJari = 0;
//         if (jariJari > 0) {
//             Lingkaran l = new Lingkaran (jariJari);
//             double kelilingLingkaran = l.hitungKeliling();
//             System.out.println("Keliling Lingkaran = " + kelilingLingkaran);
//         } else {
//             System.out.println("jari jari tidak boleh nol!!!");
//         }
//     }
// }
