#include <iostream>
using namespace std;
class Cola{

	int lista[10];
	int* inicio=lista;
	int* fin=lista+10;
	int* head = nullptr;
	int* tail = nullptr;
public:
	int pop();
	void push(int);
	void imprimir();
};
int Cola::pop() {
	int temp;
	if (!tail) {
		cout << "La cola está vacia"<<endl;
	}
	else {
		if (head == fin) {
			head = inicio;
			cout << "Entra uwu" << endl;
		}
		temp= *head;
		if (head+1 == tail or (head == fin and tail == inicio)) { //UWU LISTO :3
			tail= nullptr;
			cout << "head rebaso tail,La cola se vacio" << endl;
		}
		//cout << head << endl; //direccion de memoria uwu
		*head = 0;
		head++;
	}
	return temp;
}

void Cola::push(int n) {
	if (tail == fin) {
		tail = inicio;
	}
	if (head == tail and head) {
		cout << "La cola esta llena" << endl;
		if (head == inicio) {
			tail = fin - 1;
		}
		tail--;
	}	
	else {
		if (!head or !tail){
				head = inicio;
				tail = inicio;
				cout << "inicializando" << endl;
			}
		*tail = n;
	}
	tail++;
	//cout << tail << endl;//direccion de memoria uwu
	cout << "tail esta en uno mas que= " << *tail << endl;
	
}	
void Cola::imprimir() {
	int* temp = lista;
	cout << "[";
	for (; temp < fin; temp++) {
		cout << *temp<<",";
	}
	cout << "]" << endl;
	//cout << "Inicio"<<lista << endl;
}