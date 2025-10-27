/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

// Nama file    : DAOManager.java
// Nama Pembuat : Mohamad Solkhan Nawawi - 24060123120020
// Tanggal      : 14/05/2025
// Deskripsi    : Pengelola DAO dalam program
// 

package Praktikum_10;

/**
 *
 * @author Solkhann
 */
public class DAOManager {
    private PersonDAO personDAO;
    
    public void setPersonDAO(PersonDAO person) {
        personDAO = person;
    }
    
    public PersonDAO getPersonDAO() {
        return personDAO;
    }
}
