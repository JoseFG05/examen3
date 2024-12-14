#include "Controller.h"
#include "../Pets/Pets.h"
#include "../Owners/Owners.h"
#include <iostream>

using namespace std;

namespace Controller {
    void menuPrincipal(){
        cout<<"1. Agregar."<<endl;
        cout<<"2. Eliminar."<<endl;
        cout<<"3. Actualizar."<<endl;
        cout<<"4. Leer."<<endl;
        cout<<"0. Salir"<<endl;
    }


    void menuAgregar() {
        cout<<"1. Agregar mascotas."<<endl;
        cout<<"2. Agregar owner."<<endl;
        cout<<"0. Volver."<<endl;
    }

    void menuEliminar(){
        cout<<"1. Eliminar mascotas."<<endl;
        cout<<"2. Eliminar owner."<<endl;
        cout<<"0. Volver"<<endl;
    }

    void menuActualizar(){
        cout<<"1. Actualizar mascota"<<endl;
        cout<<"2. Actualizar owner"<<endl;
        cout<<"o. Volver"<<endl;
    }

    void menuLeer(){
        cout<<"1. Leer mascotas"<<endl;
        cout<<"2. Leer owners"<<endl;
        cout<<"0. Volver"<<endl;
    }

    void menu(){
        int op1, op2;
        do{
        menuPrincipal();
        cin>>op1;
        if(op1 == 1){
            do{
                menuAgregar();
                cin>>op2;
                switch(op2){
                    case 1:
                    Pets::crearPet();
                    break;

                    case 2:
                    Owners::crearOwn();
                    break;

                    case 0:
                    cout<<"Volviendo al menu\n";
                    break;

                    default:
                    cout<<"Opcion invalida\n";
                }
            }while(op2 != 0);

        }else if (op1 == 2){
            do{
                menuEliminar();
                cin>>op2;
                switch(op2){
                    case 1:
                    Pets::deletePet();
                    break;

                    case 2:
                    Owners::deleteOwner();
                    break;

                    case 0:
                    cout<<"Volviendo al menu\n";
                    break;

                    default:
                    cout<<"Opcion invalida\n";
                }
            }while(op2 != 0);

        }else if(op1 == 3){
            do{
                menuActualizar();
                cin>>op2;
                switch(op2){
                    case 1:
                    Pets::actPet();
                    break;

                    case 2:
                    Owners::actOwn();
                    break;

                    case 0:
                    cout<<"Saliendo.\n";
                    break;

                    default:
                    cout<<"Opcion invalida.\n";
                }
            }while(op2 != 0);

        }else if(op1 == 4){
            do{
                menuLeer();
                cin>>op2;
                switch(op2){
                    case 1:
                    Pets::LeerPet();
                    break;

                    case 2:
                    Owners::LeerOwn();
                    break;

                    case 0:
                    cout<<"Saliendo\n";
                    break;

                    default:
                    cout<<"Opcion invalida\n";

                }

            }while(op2!=0);

        }else if (op1 == 0){
            cout<<"Saliendo.";

        }else cout<<"Opcion invalida\n";

        }while(op1 != 0);

    }

}    