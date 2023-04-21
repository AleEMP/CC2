
#include <iostream>
#include "Colaclass.h"
int main()
{
    Cola awa;
    awa.imprimir();
    awa.push(8);
    awa.push(5);
    awa.push(55);
    awa.push(35);
    awa.push(53);
    awa.push(50);
    awa.push(5);
    awa.imprimir();
    awa.pop();
    awa.pop();
    awa.pop();
    awa.imprimir();
    awa.push(3);
    awa.push(55);
    awa.push(35);
    awa.push(53);
    awa.push(50);
    awa.imprimir();
    awa.push(40);
    awa.imprimir();
    awa.push(3);
    awa.imprimir();
    awa.pop();
    awa.imprimir();
    awa.push(16);
    awa.imprimir();
    awa.push(1);
    awa.imprimir();
    awa.pop();
    awa.imprimir();
    awa.push(1);
    awa.imprimir();
}