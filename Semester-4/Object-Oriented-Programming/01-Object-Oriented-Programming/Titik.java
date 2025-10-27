/* Nama File   : Titik.java
 * Deskripsi   : Berisi atribut dan method dalam class Titik
 * Pembuat     : Mohamad Solkhan Nawawi / 24060123120020
 * Tanggal     : 19 Februari 2025
*/


public class Titik {
    //Atribut
    double absis;
    double ordinat;
    static int counterTitik = 0;

    //Method
    // Konstruktor untuk membuat titik (0,0)
    // Titik() {
    //     absis = 0;
    //     ordinat = 0;
    //     counterTitik++;
    // }

    // Titik(double x, double y) {
    //     absis = x;
    //     ordinat = y;
    //     counterTitik++;
    // }

    // Keyword This
    Titik(double absis, double ordinat) {
        this.absis = absis;
        this.ordinat = ordinat;
        counterTitik++;
    }

    Titik() {
        this(0, 0);
        // tidak perlu menggunakan counterTitik++ karena sudah diatur di konstruktor lain
    }

    // Mengembalikan jumlah titik yang telah dibuat
    static int getCounterTitik() {
        return counterTitik;
    }

    // Mengembalikan nilai absis
    double getAbsis() {
        return absis;
    }

    // Mengembalikan nilai ordinat
    double getOrdinat() {
        return ordinat;
    }

    // Mengeset absis titk dengan nilai baru x
    void setAbsis(double x) {
        absis = x;
    }

    // Mengeset ordinat titik dengan nilai baru y
    void setOrdinat(double y) {
        ordinat = y;
    }

    // Mencetak koordinat titik
    void printTitik() {
        System.out.println("Titik (" + absis + ", " + ordinat + ")");
    }

    // Menggeser nilai absis dan ordinat titik masing masing sejauh x dan y
    void geser(double x, double y) {
        absis += x;
        ordinat += y;
    }

    // Mendapatkan kuadran dari titik
    int getKuadran() {
        if (absis > 0 && ordinat > 0) {
            return 1;
        } else if (absis < 0 && ordinat > 0) {
            return 2;
        } else if (absis < 0 && ordinat < 0) {
            return 3;
        } else if (absis > 0 && ordinat < 0) {
            return 4;
        } else {
            return -999;
        }
    }

    // Menghitung jarak titik ke titik pusat
    double getJarakPusat() {
        return Math.sqrt(absis * absis + ordinat * ordinat);
    }

    // Menghitung jarak titik ke titik lain
    double getJarak(Titik T) {
        return Math.sqrt((absis - T.absis) * (absis - T.absis) + (ordinat - T.ordinat) * (ordinat - T.ordinat));
    }

    // Menghasilkan refleksi terhadap sumbu x
    void refleksiX() {
        ordinat = -ordinat;
    }

    // Menghasilkan refleksi terhadap sumbu y
    void refleksiY() {
        absis = -absis;
    }

    // Mengambil refleksi terhadap sumbu X
    Titik getRefleksiX() {
        Titik Temp = new Titik(absis, -ordinat);
        return Temp;   
    }

    // Mengambil refleksi terhadap sumbu Y
    Titik getRefleksiY() {
        Titik Temp = new Titik(-absis, ordinat);
        return Temp;
    }
}
