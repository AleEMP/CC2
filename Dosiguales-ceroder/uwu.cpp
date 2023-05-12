
#include <iostream>
using namespace std;

void swap_uwu(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void split(int* p) {
    int* index = p;
    int* mov = p+7;

    for (; index < p + 8; index++) {
        if (*index==*(index+1)) {
            *index = 0;
            *(index + 1) = 0;
            for (int* comp = index; comp < mov; comp++) {
               swap_uwu(comp, comp + 1);
            }
            mov--;
            for (int* comp = index; comp < mov; comp++) {
                swap_uwu(comp, comp + 1);
            }
            mov--;
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
    int array[] = {4,2,2,4,5,1,7,8};
    split(array);
    impr(array);
}
