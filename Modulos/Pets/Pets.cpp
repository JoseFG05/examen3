#include "Pets.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

namespace Pets {
    string filename = "Archivos.csv/pets.csv";
        void crearPet() {
        Pet pets;
        cout << "Ingrese el ID de la mascota: ";
        cin >> pets.id;
        cout << "Ingrese el nombre de la mascota: ";
        cin >> pets.name;
        cout << "Ingrese la raza de la mascota: ";
        cin.ignore();
        getline(cin, pets.raza);
        cout << "Ingrese el nombre del owner: ";
       getline(cin, pets.nombreOwn);

        ofstream file(filename, ios::app);
        if (file.is_open()) {
            file << pets.id << "," << pets.name << "," << pets.raza << "," << pets.nombreOwn << "\n";
            file.close();
            cout << "Mascota registrada."<<endl<<"\n";
        } else {
            cerr << "Error al abrir el archivo " << filename << "\n";
        }
    }

    void LeerPet() {
        Pet pets;
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        cout << "Mascotas:\n\n";
        while (getline(file, line)) {
            stringstream ss(line);

            getline(ss, pets.id, ','); 
            getline(ss, pets.name, ','); 
            getline(ss, pets.raza, ',');  
            getline(ss, pets.nombreOwn, ','); 

            cout << "# Identificador: " << pets.id << "\n";
            cout << "Nombre: " << pets.name << "\n";
            cout << "Raza: " << pets.raza << "\n";
            cout << "Nombre del owner: " << pets.nombreOwn << "\n";
            cout << "\n";
        }
        file.close();
    } else {
        cerr << "Error al abrir el archivo\n";
    }
}

    void actPet() {
    string ID;
    Pet actPet;
    bool exists = false;

    cout << "Ingrese el ID de la mascota a actualizar: ";
    cin >> ID;

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo " << filename << "\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        if (line.substr(0, line.find(',')) == ID) {
            exists = true;
            break;
        }
    }
    file.close();

    if (!exists) {
        cout << "No se encontro una mascota.\n";
        return;
    }

    cout << "Ingrese el nuevo ID de la mascota: ";
    cin >> actPet.id;
    cout << "Ingrese el nuevo nombre de la mascota: ";
    cin >> actPet.name;
    cout << "Ingrese la nueva raza de la mascota: ";
    cin.ignore();
    getline(cin,actPet.raza);
    cout << "Ingrese el nombre owner: ";
    getline(cin, actPet.nombreOwn);

    string updatedData = actPet.id + "," + actPet.name + "," + actPet.raza + "," + actPet.nombreOwn;

    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error al abrir el archivo " << filename << "\n";
        return;
    }

    ofstream tempFile("Archivos.csv/file_temp.csv");
    if (!tempFile.is_open()) {
        cerr << "Error al abrir el archivo temporal\n";
        return;
    }

    bool updated = false;

    while (getline(inputFile, line)) {
        if (line.substr(0, line.find(',')) == ID) {
            tempFile << updatedData << "\n"; 
            updated = true;
        } else {
            tempFile << line << "\n";
        }
    }

    inputFile.close();
    tempFile.close();

    remove(filename.c_str());
    rename("Archivos.csv/file_temp.csv", filename.c_str());

    if (updated)
        cout << "La mascota fue actualizada.\n"<<"\n";
    else
        cout << "Hubo un error al actualizar la mascota.\n";
}


    void deletePet() {
        string petID;

        cout << "Ingrese el ID de la mascota a eliminar: ";
        cin >> petID;

        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error al abrir el archivo " << filename << "\n";
            return;
        }

        ofstream tempFile("Archivos.csv/file_temp.csv");
        if (!tempFile.is_open()) {
            cerr << "Error al abrir el archivo temporal\n";
            return;
        }

        string line;
        bool deleted = false;
        while (getline(file, line)) {
            if (line.substr(0, line.find(',')) == petID) {
                deleted = true;
            } else {
                tempFile << line << "\n";
            }
        }

        file.close();
        tempFile.close();

        remove(filename.c_str());
        rename("Archivos.csv/file_temp.csv", filename.c_str());

        if (deleted)
            cout << "La mascota fue eliminada.\n";
        else
            cout << "No se encontro una mascota.\n";
    }
};

