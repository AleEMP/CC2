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
struct LE {
    Nodo<T>* head = NULL;

    bool find(T x, Nodo <T>*& pos) {
        bool res = 0;
        pos = 0;
        for (Nodo<T>* p = head; p && p->valor <= x; pos = p, p = p->next)
            if (p->valor == x) {
                res = 1;
                break;
            }
        return res;
    }
    void add(T x) {
        Nodo<T>* pos;
        if (!find(x, pos)) {
            if (pos)
                pos->next = new Nodo<T>(x, pos->next);
            else
                head = new Nodo<T>(x, head);
        }
    }
    bool del(T x) {
        Nodo<T>* pos, * tmp;
        bool res = find(x, pos);
        if (res) {
            if (pos) {
                tmp = pos->next;
                pos->next = tmp->next;
            }
            else {
                tmp = head;
                head = tmp->next;
            }
            delete tmp;
        }
        return res;
    }
    void print() {
        cout << "Head->";
        for (Nodo<T>* p = head; p; p = p->next)
            cout << p->valor << "->";
        cout << "NULL" << endl;
    }
};

template<class T>
void Merge(Nodo<T>*& h1, Nodo<T>*& h2) {
    Nodo<T>* p, * q, * ant;
    p = h1;
    q = h2;
    ant = nullptr;
    h2 = nullptr;
    while (p && q) {
        if (p->valor <= q->valor) {
            /*if (ant->next != p) {
                ant->next = p;
            }*/
            ant = p;
            p = p->next;
        }
        else {
            if (!ant) {
                h1 = q;
                ant = q;
                q = q->next;
            }
            else {
                ant->next = q;
                ant = q;
                q = q->next;
                ant->next = p;
            }
        }
    }
    if (!(p) && q)
        ant->next = q;
}

template <class T>
struct Cola
{
    Nodo<T>* head = 0, * tail = 0;
    bool pop(T& v) {
        v = 0;
        Nodo<T>* tmp;
        if (!head) {
            return false;
        }
        else
        {
            v = head->valor;
            tmp = head;
            head = head->next;
            delete tmp;
            return 1;
        }
    }
    void push(T v) {
        if (!head) {
            head = new Nodo<T>(v);
            tail = head;
        }
        else {
            tail->next = new Nodo<T>(v);
            tail = tail->next;
        }
    }
};
int main()
{
    /*Cola<int> owo;
    owo.push(1);
    owo.push(2);
    owo.push(3);
    owo.push(4);
    int ewe;
    while (owo.pop(ewe))
        cout << ewe << " ";*/

    LE<int> uwu, owo;
    uwu.add(1);
    uwu.add(3);
    uwu.add(4);
    uwu.add(8);
    uwu.print();
    owo.add(2);
    owo.add(5);
    owo.add(9);
    owo.print();
    cout << endl;
    Merge<int>(uwu.head, owo.head);
    uwu.print();
    owo.print();

    /*uwu.add(2);
    uwu.add(4);
    uwu.add(6);
    uwu.add(8);
    uwu.add(10);
    uwu.print();
    owo.add(3);
    owo.add(6);
    owo.add(9);
    owo.print();
    cout << endl;
    Merge<int>(uwu.head, owo.head);
    uwu.print();
    owo.print();*/

    /*uwu.add(5);
    uwu.add(7);
    uwu.add(9);
    uwu.add(15);
    uwu.print();
    owo.add(3);
    owo.add(4);
    owo.add(10);
    owo.print();
    cout << endl;
    Merge<int>(uwu.head, owo.head);
    uwu.print();
    owo.print();*/
}