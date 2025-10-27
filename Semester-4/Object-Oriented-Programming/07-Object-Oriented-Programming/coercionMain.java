/* 
 * Nama File    : CoercienMain.java
 * Nama Pembuat : Mohamad Solkhan Nawawi
 * NIM Pembuat  : 24060123120020
 * Tanggal      : 23 April 2025
 * Deskripsi    : CoercionMain merupakan mainclass untuk membuktikan hasil dari penerapan konsep casting.
 */

public class coercionMain {
    public static void main(String[] args) {
        // Coba char ke int
        int  outputCharA = 'a';
        System.out.println("Hasil konversi karakter 'a' ke int: " + outputCharA);

        // Coba double ke int
        double output = 15.5;
        int outputInt = (int) output;
        System.out.println("Hasil konversi double 15.5 ke int: " + outputInt);

        // Coba int ke double
        int y = 25;
        double outputDouble = y;
        System.out.println("Hasil konversi double 25 ke double: " + outputDouble);

        // Coba int ke char
        int z = 78;
        char outputCharZ = (char) z;
        System.out.println("Hasil konversi int 78 ke char: " + outputCharZ);

        // Coba char ke double
        char a = 'a';
        double outputDoubleA = a;
        System.out.println("Hasil konversi char 'a' ke double: " + outputDoubleA);
    }
}