#ifndef PETS_H
#define PETS_H

#include <string>
using namespace std;

struct Pet {
    string id;
    string name;
    string raza;
    string nombreOwn;
};

namespace Pets {
    void crearPet();
    void LeerPet();
    void actPet();
    void deletePet();
}

#endif
