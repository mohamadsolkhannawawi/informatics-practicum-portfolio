public class AngkaSial {
    public void cobaAngka(int angka) throws AngkaSialException {
        if (angka == 13) {
            throw new AngkaSialException();
        } else {
            System.out.println(angka + " bukan angka sial");
        }
    } 

    public static void main(String[] args) {
        AngkaSial as = new AngkaSial();
        try {
            as.cobaAngka(10);
            as.cobaAngka(13);
            as.cobaAngka(12);
        } catch (AngkaSialException ase) {
            // method getMessage() telah ada pada kelas Exception
            System.out.println(ase.getMessage());
            System.err.println("hati-hati dalam memasukan angka!!!");
        }
    }
}

// Baris 12, System.out.println(angka + " bukan angka sial");,  akan diekseskusi jika angka yang dimasukkan bukan 13.
// Baris 21, catch (AngkaSialException ase), akan dieksekusi jika angka yang dimasukkan adalah 13., lalu akan memanggil method getMessage() yang ada pada kelas Exception.
// getMessage() akan mengembalikan pesan yang sudah didefinisikan pada kelas Exception, sehingga akan menghasilkan output "jangan memasukan angka 13 karena angka sial !!!".
// dan akan menampilkan output "hati-hati dalam memasukan angka!!!".
// hal ini karena pada blok try terdapat pemanggilan as.cobaAngka(13);, yang akan memanggil method cobaAngka() dengan parameter 13.
// method cobaAngka() akan melempar exception AngkaSialException() jika angka yang dimasukkan adalah 13.
// sehingga, program akan menangkap exception tersebut dan menampilkan pesan yang sudah didefinisikan pada kelas AngkaSialException.
// Lalu baris kode pada blok catch akan dieksekusi.

// baris dengan kode as.cobaAngka(12); tidak akan dieksekusi, karena baris kode sebelumnya as.cobaAngka(13); sudah melempar exception.
// sehingga program akan langsung mengeksekusi blok catch. dan berhenti pada baris kode tersebut.
// Sehingga, output yang dihasilkan ketika program dijalankan adalah :
// 10 bukan angka sial
// jangan memasukan angka 13 karena angka sial !!!
// hati-hati dalam memasukan angka!!!
