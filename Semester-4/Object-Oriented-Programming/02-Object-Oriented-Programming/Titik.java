/* Nama File   : Titik.java
 * Deskripsi   : Berisi atribut dan method dalam class Titik
 * Pembuat     : Mohamad Solkhan Nawawi / 24060123120020
 * Tanggal     : 26 Februari 2025
*/


public class Titik {
    //Atribut
    private double absis;
    private double ordinat;
    private static int counterTitik = 0;

    //Method
    // Konstruktor untuk membuat titik (0,0)
    // public Titik() {
    //     absis = 0;
    //     ordinat = 0;
    //     counterTitik++;
    // }

    // public Titik(double x, double y) {
    //     absis = x;
    //     ordinat = y;
    //     counterTitik++;
    // }

    // Keyword This
    public Titik(double absis, double ordinat) {
        this.absis = absis;
        this.ordinat = ordinat;
        counterTitik++;
    }

    public Titik() {
        this(0, 0);
        // tidak perlu menggunakan counterTitik++ karena sudah diatur di konstruktor lain
    }

    // Mengembalikan jumlah titik yang telah dibuat
    public static int getCounterTitik() {
        return counterTitik;
    }

    // Mengembalikan nilai absis
    // Saat methode ini diubah menjadi private maka akan terjadi error ketika menjalankan MTitik.java
    public double getAbsis() {
        return absis;
    }

    // Mengembalikan nilai ordinat
    public double getOrdinat() {
        return ordinat;
    }

    // Mengeset absis titk dengan nilai baru x
    public void setAbsis(double x) {
        absis = x;
    }

    // Mengeset ordinat titik dengan nilai baru y
    public void setOrdinat(double y) {
        ordinat = y;
    }

    // Mencetak koordinat titik
    public void printTitik() {
        System.out.println("Titik (" + absis + ", " + ordinat + ")");
    }

    // Menggeser nilai absis dan ordinat titik masing masing sejauh x dan y
    public void geser(double x, double y) {
        absis += x;
        ordinat += y;
    }

    // Mendapatkan kuadran dari titik
    public int getKuadran() {
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
    public double getJarakPusat() {
        return Math.sqrt(absis * absis + ordinat * ordinat);
    }

    // Menghitung jarak titik ke titik lain
    public double getJarak(Titik T) {
        return Math.sqrt((absis - T.absis) * (absis - T.absis) + (ordinat - T.ordinat) * (ordinat - T.ordinat));
    }

    // Menghasilkan refleksi terhadap sumbu x
    public void refleksiX() {
        ordinat = -ordinat;
    }

    // Menghasilkan refleksi terhadap sumbu y
    public void refleksiY() {
        absis = -absis;
    }

    // Mengambil refleksi terhadap sumbu X
    public Titik getRefleksiX() {
        Titik Temp = new Titik(absis, -ordinat);
        return Temp;   
    }

    // Mengambil refleksi terhadap sumbu Y
    public Titik getRefleksiY() {
        Titik Temp = new Titik(-absis, ordinat);
        return Temp;
    }
}
