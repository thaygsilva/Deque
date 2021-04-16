//Thayna Gomes da Silva TIA:32092229
//Claudionor Domingues da Silva TIA:32086784
#ifndef __DEQUE_H__
#define __DEQUE_H__

const int STATIC_QUEUE_CAPACITY = 5;


struct StaticQueue {
	int front;
	int rear;
	int count;

	int values[STATIC_QUEUE_CAPACITY];

};

StaticQueue Create();


int Front(const StaticQueue& queue);


int Size(const StaticQueue& queue);


int Count(const StaticQueue& queue);


bool IsEmpty(const StaticQueue& queue);


bool Clear(StaticQueue& queue);


void PrintQueue(const StaticQueue& queue);


bool insertFront(StaticQueue& queue, int elem);


bool insertBack(StaticQueue& queue, int elem);


bool removeFront(StaticQueue& queue);


bool removeBack(StaticQueue& queue);


int Front(StaticQueue& queue);

int Back(StaticQueue& queue);


#endif // __DEQUE_H__

