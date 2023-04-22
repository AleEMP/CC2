
#include <iostream>
#include "Colaclass.h"
int main(){

    Cola awa;
    for (int i = 1; i <= 10; i++) {
        awa.push(i);
    }
    awa.imprimir();
    for (int i = 1; i <= 3; i++) {
        cout << awa.pop() << endl;
    }
    awa.imprimir();
    for (int i = 1; i <= 2; i++) {
        awa.push(11);
    }
    awa.imprimir();
    for (int i = 1; i <= 9; i++) {
        cout << awa.pop() << endl;
    }
    awa.imprimir();
    awa.push(2);
    awa.imprimir();
}