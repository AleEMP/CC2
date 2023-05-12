
#include <iostream>
using namespace std;

bool par(int x) {
    return (x % 2) == 0;
}

bool impar(int x) {
    return (x % 2) != 0;
}
void swap_uwu(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void split(int* p, bool (*condicion)(int x)) {
    int* index = p;
    int* mov = p;
    for (; index < p + 8; index++) {
        if ((*condicion)(*index) == 1) {
            for (int* comp = index; comp != mov; comp--) {
                swap_uwu(comp - 1, comp);
            }
            mov++;
        }
    }
}

void impr(int* arr) {
    int* i = arr;
    for (; i < arr + 8; i++) {
        cout << *i << " ,";
    }
}

int main()
{
    int array[] = {1,2,3,4,5,6,7,8};
    split(array, par);
    impr(array);
}
