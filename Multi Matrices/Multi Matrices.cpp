#include <iostream>
using namespace std;

void multi(int(*a)[3][3]) {
    int* p = **a;
    int* q = **(a + 1);
    int* r = **(a + 2);
    int* fin_r = r + 3;
    while (p < **(a + 1)) {
        *r += *p * *q;
        r++;
        q++;
        if (q == **(a + 2)) {
            q = **(a + 1);
            r += 3;
            fin_r += 3;
        }
        if (r == fin_r) {
            p++;
            r -= 3;
        }
    }
}
void impr(int(*a)[3][3]) {
    int* p = **a;

    for (int i = 0; i < 27; i++) {
        if (i % 3 == 0) {
            cout << endl;
        }
        if (i % 9 == 0) {
            cout << endl;
        }
        cout << *(p + i) << " ";
    }
}

int main()
{
    int arr[3][3][3] = { {{1,2,3},{4,5,6},{7,8,9}},{{11,12,13},{14,15,16},{17,18,19}},{{0,0,0},{0,0,0},{0,0,0}}};
    multi(arr);
    impr(arr);

    return 0;
}
