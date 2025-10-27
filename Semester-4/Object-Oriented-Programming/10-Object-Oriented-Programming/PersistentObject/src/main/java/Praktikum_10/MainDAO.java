/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

// Nama file    : MainDAO.java
// Nama Pembuat : Mohamad Solkhan Nawawi - 24060123120020
// Tanggal      : 14/05/2025
// Deskripsi    : Implementasi PersonDAO untuk MySQL
// 

package Praktikum_10;

/**
 *
 * @author Solkhann
 */
public class MainDAO {
    public static void main(String[] args) {
        Person person = new Person("Indra");
        DAOManager m = new DAOManager();
        m.setPersonDAO(new MySQLPersonDAO());
        try {
            m.getPersonDAO().savePerson(person);
        }catch (Exception e){
            e.printStackTrace();
        }
    }
}


// Cara penggunaan DAO
// javac -cp ".;mysql-connector-j-9.3.0.jar" *.java
// java -cp ".;mysql-connector-j-9.3.0.jar" MainDAO.java

// Hasil:
// INSERT INTO person(name) VALUES ('Indra')