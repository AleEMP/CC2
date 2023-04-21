#include <iostream>
using namespace std;
class Cola{

	int lista[10];
	int* inicio=lista;
	int* fin=lista+10;
	int* head = nullptr;
	int* tail = nullptr;
public:
	void pop();
	void push(int);
	void imprimir();
};
void Cola::pop() {
	if (!tail) {
		cout << "La cola está vacia";
	}
	else {
		*head = 0;//solo pa ver que la head se mueve ugu
		head++;
		
	}
}

void Cola::push(int n) {
	
	if (head == tail and head) {
		cout << "La cola esta llena" << endl;
		tail--;
	}	
	else {
		if (!head){
				head = inicio;
				tail = inicio;
			}
		else{
			if (tail == fin) {
					tail = inicio;
			}
		}	
		*tail = n;
	}
	tail++;
}
void Cola::imprimir() {
	int* temp = lista;
	cout << "[";
	for (; temp < fin; temp++) {
		cout << *temp<<",";
	}
	cout << "]" << endl;
}