
#include <iostream>
using namespace std;

bool is_zero(int x) {
    return x == 0;
}

void swap_uwu(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void split(int* p, bool (*condicion)(int x)) {
    int* index = p;
    int* mov = p+7;
    for (; index < p + 8; index++) {
        if ((*condicion)(*index) == 1) {
            for (int* comp = index; comp < mov; comp++) {
                swap_uwu(comp +1, comp);
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
    int array[] = {1,2,0,4,5,0,7,8};
    split(array, is_zero);
    impr(array);
}
