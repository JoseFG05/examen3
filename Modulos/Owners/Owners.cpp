#include "Owners.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

namespace Owners {
    string filename = "Archivos.csv/owners.csv";
    Owner owner;

void crearOwn() {
        cout << "Ingrese la cedula del owner: ";
        cin >> owner.cedula;
        cout << "Ingrese el nombre del owner: ";
        cin >> owner.name;
        cout<<"Ingrese el apellido del owner: ";
        cin>>owner.apell;
        cout << "Ingrese la direccion del owner: ";
        cin.ignore(); 
        getline(cin, owner.addrs);

        ofstream file(filename, ios::app);
        if (file.is_open()) {
            file << owner.cedula << "," << owner.name << ","<<owner.apell<<","<< owner.addrs <<"\n";
            file.close();
            cout << "Owner registrado correctamente.\n"<<"\n";
        } else {
            cerr << "Error al abrir el archivo\n";
        }
    }

void LeerOwn() {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        cout << "Owners:\n\n";
        while (getline(file, line)) {
            stringstream ss(line);

            string cedulaStr;
            getline(ss, cedulaStr, ','); 
            owner.cedula = stoi(cedulaStr); 

            getline(ss, owner.name, ','); 
            getline(ss, owner.apell, ',');  
            getline(ss, owner.addrs, ','); 

            cout << "Nombre: " << owner.name << "\n";
            cout << "Apellido: " << owner.apell << "\n";
            cout << "Cedula: " << owner.cedula << "\n";
            cout << "Direccion: " << owner.addrs << "\n";
            cout << "\n";
        }
        file.close();
    } else {
        cerr << "Error al abrir el archivo\n";
    }
}

void actOwn() {
    Owner nuevOwn;
    string cedula;
    bool exists = false;

    cout << "Ingrese la cedula del owner a actualizar: ";
    cin >> cedula;

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        string currentCedula = line.substr(0, line.find(','));
        if (currentCedula == cedula) {
            exists = true;
            break;
        }
    }
    file.close();

    if (!exists) {
        cout << "No se encontró el owner.\n";
        return;
    }

    cout << "Ingrese la nueva cedula: ";
    cin >> nuevOwn.cedula;
    cout << "Ingrese el nuevo nombre: ";
    cin >> nuevOwn.name;
    cout << "Ingrese el nuevo apellido: ";
    cin >> nuevOwn.apell;
    cout << "Ingrese la nueva direccion: ";
    cin.ignore();
    getline(cin, nuevOwn.addrs);

    stringstream updatedData;
    updatedData << nuevOwn.cedula << "," << nuevOwn.name << "," << nuevOwn.apell << "," << nuevOwn.addrs;

    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error al abrir el archivo.\n";
        return;
    }

    ofstream tempFile("Archivos.csv/file_temp.csv");
    if (!tempFile.is_open()) {
        cerr << "Error al intentar realizar cambios.\n";
        return;
    }

    bool updated = false;

    while (getline(inputFile, line)) {
        string currentCedula = line.substr(0, line.find(','));
        if (currentCedula == cedula) {
            tempFile << updatedData.str() << "\n";
            updated = true;
        } else {
            tempFile << line << "\n";
        }
    }

    inputFile.close();
    tempFile.close();

    if (remove(filename.c_str()) != 0) {
        cerr << "Error al intentar modificar.\n";
        return;
    }

    if (rename("Archivos.csv/file_temp.csv", filename.c_str()) != 0) {
        cerr << "Error al confirmar los cambios.\n";
        return;
    }

    if (updated) {
        cout << "El owner fue actualizado.\n\n";
    } else {
        cout << "Hubo un error al actualizar el owner.\n\n";
    }
}


    void deleteOwner() {
        string Cedula;

        cout << "Ingrese la cedula del owner a eliminar: ";
        cin >> Cedula;

        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error al abrir el archivo.\n";
            return;
        }

        ofstream tempFile("Archivos.csv/file_temp.csv");
        if (!tempFile.is_open()) {
            cerr << "Error al abrir el intentar modificar.\n";
            return;
        }

        string line;
        bool deleted = false;
        while (getline(file, line)) {
            if (line.substr(0, line.find(',')) == Cedula) {
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
            cout << "El owner fue eliminado correctamente.\n"<<"\n";
        else
            cout << "No se encontro un owner.\n";
    }
}   
