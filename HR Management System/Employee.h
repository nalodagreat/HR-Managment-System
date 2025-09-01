#pragma once
#include <string>

// Per evitare di scrivere sempre "std::" prima di string, cout, ecc.
using namespace std;

/*
 * Classe Base Astratta Employee
 * Rappresenta un dipendente generico.
 * "Astratta" significa che non possiamo creare un oggetto di tipo "Employee",
 * ma la usiamo come "stampo" per le altre classi (Technician, Manager, ...).
*/
class Employee {
protected:
    // Dati protetti: accessibili da questa classe e dalle classi figlie.
    string taxCode;
    string firstName;
    string lastName;
    string hireDate;

public:
    // Costruttore: serve a creare un oggetto Employee con i suoi dati base.
    Employee(const string& tc, const string& fn, const string& ln, const string& hd) {
        taxCode = tc;
        firstName = fn;
        lastName = ln;
        hireDate = hd;
    }

    // Distruttore virtuale: fondamentale nei design con ereditarieta.
    // Garantisce che, quando eliminiamo un puntatore a Employee, venga chiamato
    // anche il distruttore della classe figlia (es. Technician).
    virtual ~Employee() {}

    /*
     * Metodo virtuale puro: questo "= 0" rende la classe astratta.
     * Obbliga ogni classe figlia (Technician, Manager, ...) a scrivere la propria
     * versione di "calculateSalary". Non c'e un'implementazione di default qui.
    */
    virtual double calculateSalary() = 0;

    // Metodi "getter": servono a leggere i valori delle variabili protette dall'esterno.
    string getTaxCode() const { return taxCode; }
    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
    string getHireDate() const { return hireDate; }
};