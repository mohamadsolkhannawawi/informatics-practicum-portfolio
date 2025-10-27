/* 
 * Nama File    : IResize.java
 * Nama Pembuat : Mohamad Solkhan Nawawi
 * NIM Pembuat  : 24060123120020
 * Tanggal      : 21 Maret 2025
 * Deskripsi    : IResize merupakan interface yang berisi method zoomIn, zoomOut, dan zoom.
*/

// Interface IResize yang berisi method zoomIn, zoomOut, dan zoom
// Method-method ini akan diimplementasikan pada Persegi.java dan Lingkaran.java
public interface IResize { // public final class BangunDatar { akan error pada method yang merupakan turunan dari BangunDatar.java
    public void zoomIn(); 

    public void zoomOut();

    public void zoom(int percent); 
}
