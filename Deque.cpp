//Thayna Gomes da Silva TIA:32092229
//Claudionor Domingues da Silva TIA:32086784
#include "Deque.h"
#include <string.h>
#include <iostream>
using namespace std;

StaticQueue Create() {
	StaticQueue queue = {
		0, // int front;                                        
		0, // int rear;
		0, // int count;
		{ 0 }, // char values[STATIC_QUEUE_CAPACITY];
	};
	return queue;
}

bool insertFront(StaticQueue& queue, int elem) {

	if (queue.count == Size(queue)) {
		cout << "Fila Cheia!" << endl;  
		return false;
	}
																	
	if (queue.front == 0) {
		queue.front = Size(queue) - 1; // Se o primeiro da fila ainda nao for preenchido retorna o anterior
	}
	else {
		queue.front--; //Decrementa o indice da fila
	}

	cout << "Insira um elemento na primeira posi��o: " << endl;
	cout << "Resposta: ";
	cin >> elem;
	cout << '\n';

	// Insere elem no final da fila (vetor da queue).
	queue.values[queue.front] = elem;

	// "Vetor circular": se chegou no final do vetor (no limite/capacidade do vetor),
	// a vari�vel rear, que � usada para indicar o �ndice correto para um novo elemento da fila,
	// volta pro in�cio do vetor.
	

	++queue.count;

	return true;
}

bool insertBack(StaticQueue& queue, int elem) {  

	cout << "Insira um elemento na �ltima posi��o: " << endl;
	cout << "Resposta: ";
	cin >> elem;
	cout << '\n';

	if (queue.count == Size(queue)) {
		cout << "Fila Cheia!" << endl;
		return false;
	}

	// Insere elem no final da fila (vetor da queue).
	queue.values[queue.rear] = elem;

	// "Vetor circular": se chegou no final do vetor (no limite/capacidade do vetor),
	// a vari�vel rear, que � usada para indicar o �ndice correto para um novo elemento da fila,
	// volta pro in�cio do vetor.
	queue.rear = (queue.rear + 1) % Size(queue); // Mant�m queue.rear no intervalo 0 <= queue.rear < Size(queue).

	// A linha acima equivale �:
	// ++queue.rear;
	// if (queue.rear == Size(queue))
	// {
	// 	queue.rear = 0;
	// }

	++queue.count;

	return true;
}

bool removeFront(StaticQueue& queue) { 
	if (IsEmpty(queue)) {
		return {'\0'};
	}

	// Como remover e retornar o primeiro elemento da fila
	int value = queue.values[queue.front];
	queue.values[queue.front] = {'\0'};

	// "Vetor circular": se chegou no final do vetor (no limite/capacidade do vetor),
	// a vari�vel front, que � usada para indicar o �ndice correto do primeiro elemento da fila,
	// volta pro in�cio do vetor.
	queue.front = (queue.front + 1) % Size(queue); // Mant�m queue.front no intervalo 0 <= queue.front < Size(queue).

	// A linha acima equivale �:
	// ++queue.front;
	// if (queue.front == Size(queue))
	// {
	// 	queue.front = 0;
	// }

	--queue.count;

	return value;
}

bool removeBack(StaticQueue& queue) {
	if (IsEmpty(queue)) {
		return {'\0'};
	}

	if (queue.rear == 0) { 
		queue.rear = Size(queue) - 1; // Se o ultimo da fila ainda nao tiver sido preenchido, ele retornara o penultimo
	}
	else {
		queue.rear--; //Decrementa -1 do rear
	}

	// Como remover e retornar o �ltimo elemento da fila
	int value = queue.values[queue.rear];
	queue.values[queue.rear] = {'\0'};

	// "Vetor circular": se chegou no final do vetor (no limite/capacidade do vetor),
	// a vari�vel rear, que � usada para indicar o �ndice correto do �ltimo elemento da fila,
	// volta pro final do vetor.

	--queue.count;

	return value;
}


int Front(const StaticQueue& queue) {
	if (IsEmpty(queue) == 1) {
		return {'\0'};
	}
	else {
		return  queue.values[queue.front];
	}
}


int Back(const StaticQueue& queue) {
	if (IsEmpty(queue) == 1) {
		return {'\0'};
	}
	// se o rear chegar a capacidade da fila, volta para o �ndice 0
	if (queue.rear == 0) {
		// se o "�ltima" posi��o estiver ocupada, ele pega a penultima posi��o
		return queue.values[Size(queue) - 1];
	}
	else {
		return queue.values[queue.rear-1];
	}

}

int Size(const StaticQueue& queue) {
	return sizeof(queue.values) / sizeof(queue.values[0]); // return STATIC_QUEUE_CAPACITY;
}


int Count(const StaticQueue& queue) {
	return queue.count;
}


bool IsEmpty(const StaticQueue& queue) {
	return queue.count == 0;
}


bool Clear(StaticQueue& queue) { 
	while (!IsEmpty(queue)) { 
		removeFront(queue); //Sempre remove do front
	}

	return IsEmpty(queue);
}


void PrintQueue(const StaticQueue& queue) {
	
	cout << endl;
	cout << "Primeiro elemento: " << Front(queue) << endl;
	cout << "�ltimo elemento " << Back(queue) << endl;
	cout << "Ocupa��o: " << "(" << Count(queue) << "/" << Size(queue) << ")" << endl;
	cout << "Est� vazio?" << IsEmpty(queue) << endl;

}
