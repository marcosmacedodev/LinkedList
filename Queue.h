/*
 * Queue.h
 *
 *  Created on: 4 de nov. de 2022
 *      Author: Marcos Macedo
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "node.h"
#include "node.cpp"

template<class T>
class Queue {
public:
	Queue();
	Queue(const Queue<T> &queue);
	void enqueue(const T &newItem);
	T dequeue();
	void clear();
	bool isEmpty() const;
	Queue& operator=(const Queue &queue);
	virtual ~Queue();
private:
	Node<T> *front, *back;
};

#endif /* QUEUE_H_ */
