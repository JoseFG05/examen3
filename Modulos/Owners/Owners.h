#ifndef OWNERS_H
#define OWNERS_H

#include <string>
using namespace std;

struct Owner {
    int cedula;
    string name;
    string apell;
    string addrs;
};

namespace Owners {
    void crearOwn();
    void LeerOwn();
    void actOwn();
    void deleteOwner();
}

#endif
