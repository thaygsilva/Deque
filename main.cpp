//Thayna Gomes da Silva TIA:32092229
//Claudionor Domingues da Silva TIA:32086784
#include <iostream>
#include "Deque.h"
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "pt_BR");

	StaticQueue deque = Create();

	int option = -1;
	int elem = 0;
	while (option != 0) {

		cout << "~~~~~~~~~~ Menu ~~~~~~~~~~" << endl << "0 - Sair" << endl << "1 - Inserir elemento no início " << endl << "2 - Inserir elemento no final"
		<< endl << "3 - Remover elemento no início" << endl << "4 - Remover elemento no final" << endl << "5 - Limpar fila" << "\n\n";

		cout << "Resposta: ";
		cin >> option;
		cout << '\n';

		if (option == 1) {
			insertFront(deque, elem);

		}
		if (option == 2) {
			insertBack(deque, elem);

		}
		if (option == 3) {
			removeFront(deque);

		}
		if (option == 4) {
			removeBack(deque);

		}
		if (option == 5) {
			Clear(deque);

		}
		cout << "Se o rear e/ou o front chegar a capacidade da fila, volta para o índice 0" << endl;
		cout << "Front : " << deque.front << endl;
		cout << "Rear : " << deque.rear << endl;

		PrintQueue(deque);
	}
}