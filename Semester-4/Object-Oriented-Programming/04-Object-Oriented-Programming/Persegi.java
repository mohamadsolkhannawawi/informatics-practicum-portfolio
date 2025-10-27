public class Persegi extends BangunDatar{
    private double sisi;
    private static int counterPersegi = 0;

    public Persegi() {
        setJmlSisi(4);
        counterPersegi++;
    }

    public Persegi(double sisi, String warna, String border) {
        super(4, warna, border);
        this.sisi = sisi;
        // setWarna(warna);
        // setBorder(border);
        // setJmlSisi(4);
        // this.border = border;
        // this.warna = warna;
        // this.jmlSisi = 4;
        counterPersegi++;
    }

    public static void printCounterPersegi() {
        System.out.println("Jumlah persegi: " + Persegi.counterPersegi);
    }

    public double getSisi() {
        return sisi;
    }

    public void setSisi(double sisi) {
        this.sisi = sisi;
    }

    public double getLuas() {
        return sisi*sisi;
    }

    public double getKeliling() {
        return 4*sisi;
    }

    public double getDiagonal() {
        return Math.sqrt(2) * sisi;
    }

    @Override
    public void printInfo() {
        System.out.println("Persegi");
        super.printInfo();
        // System.out.println("Jumlah sisi: " + getJmlSisi());
        // System.out.println("Warna: " + getWarna());
        // System.out.println("Border: " + getBorder());
        System.out.println("Luas : " + getLuas());
        System.out.println("Keliling: " + getKeliling());
        System.out.println("Diagonal: " + getDiagonal());
    }

}