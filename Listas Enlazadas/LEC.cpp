
#include <iostream>
using namespace std;
template <class T>
struct Nodo
{
    T valor;
    Nodo<T>* next;
    Nodo(T v, Nodo<T>* n = 0) {
        valor = v;
        next = n;
    }
};
template <class T>
struct LEC {
    Nodo<T>* head = NULL;
    Nodo<T>* last = NULL;
    bool find(T x, Nodo <T>*& pos) {
        bool res = 0;
        pos = 0;
        for (Nodo<T>* p = head; p && p->valor <= x; pos = p, p = p->next){
            if (p->valor == x) {
                res = 1;
                break;
            }
            if (p==last){
                pos = last;
                break;
            }
        }
        return res; 
    }
    void add(T x) {
        Nodo<T>* pos;
        if (!find(x, pos)) {
            if (!head) {
                head = new Nodo<T>(x, head);
                last = head;
            }
            else {
                if(!pos) {
                    head = new Nodo<T>(x, head);
                    last->next = head;
                }
                else {
                    if (pos == last) {
                        last = new Nodo<T>(x, head);
                        pos->next = last;
                    }
                    else {
                        pos->next= new Nodo<T>(x, pos->next);
                    }
                }
            }
        }
    }
    void del(T x) {
        Nodo<T>* pos,*tmp;
        if (find(x, pos)) {
            if (!pos) {
                if (head == last) {
                    delete head;
                    head = nullptr;
                    last = nullptr;
                }
                else {
                    tmp = head;
                    head = head->next;
                    last->next = head;
                    delete tmp;
                }
            }
            else {
                if (pos->next == last) {
                    tmp = last;
                    last = pos;
                    last->next = head;
                    delete tmp;
                }
                else {
                    tmp = pos->next;
                    pos->next = tmp->next;
                    delete tmp;
                }
            }  
        }
    }
    void print() {
        cout << "Head->";
        for (Nodo<T>* p = head; p; p = p->next) {
            cout << p->valor << "->";
            if (p == last) {
                cout << p->next->valor;
                break;
            }
        }
        cout << endl;
    }
};
int main(){
    LEC<int>owo;
    owo.add(8);
    owo.add(3);
    owo.add(1);
    owo.add(5);
    owo.add(9);
    owo.print();
    owo.del(69);
    owo.del(9);
    owo.del(3);
    owo.print();
    owo.del(1);
    owo.del(8);
    owo.del(5);
    owo.print();
}