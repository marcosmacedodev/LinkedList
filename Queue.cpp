/*
 * Queue.cpp
 *
 *  Created on: 4 de nov. de 2022
 *      Author: Marcos Macedo
 */
#include "Queue.h"

template<class T>
Queue<T>::Queue(): front(NULL), back(NULL){
	// TODO Auto-generated constructor stub
}

template<class T>
void Queue<T>::enqueue(const T &newItem){
	if(front == NULL)
	{
		back = new Node<T>;
		back->setValue(newItem);
		back->setNextNode(NULL);
		front = back;
		return;
	}
	Node<T> *newNode = new Node<T>;
	newNode->setValue(newItem);
	newNode->setNextNode(NULL);
	back->setNextNode(newNode);
	back = back->getNextNode();
}

template< class T>
T Queue<T>::dequeue(){
	T result;
	Node<T> *discard;
	result = front->getValue();
	discard = front;
	front = front->getNextNode();
	if (front == NULL) back = NULL;
	delete discard;
	return result;
}

template<class T>
bool Queue<T>::isEmpty() const{
	return back == NULL;
}

template<class T>
void Queue<T>::clear(){
	T next;
	while (front != NULL)
		next = dequeue();
}

template<class T>
Queue<T>::Queue(const Queue &queue){
	if(queue.front == NULL)
	{
		front = back = NULL;
	}
	else
	{
		back = new Node<T>;
		Node<T> *pFront = queue.front;
		back->setValue(pFront->getValue());
		back->setNextNode(NULL);
		front = back;
		pFront = pFront->getNextNode();
		while(pFront != NULL)
		{
			Node<T> * newNode = new Node<T>;
			newNode->setValue(pFront->getValue());
			newNode->setNextNode(NULL);
			back->setNextNode(newNode);
			pFront = pFront->getNextNode();
			back = back->getNextNode();
		}
	}
}

template<class T>
Queue<T>& Queue<T>::operator =(const Queue<T> &queue){
	if(queue.front == NULL)
	{
		return *this;
	}

	clear();

	if(queue.front == NULL)
	{
		front = back = NULL;
	}
	else
	{
		back = new Node<T>;
		Node<T> *pFront = queue.front;
		back->setValue(pFront->getValue());
		back->setNextNode(NULL);
		front = back;
		pFront = pFront->getNextNode();
		while(pFront != NULL)
		{
			Node<T> * newNode = new Node<T>;
			newNode->setValue(pFront->getValue());
			newNode->setNextNode(NULL);
			back->setNextNode(newNode);
			pFront = pFront->getNextNode();
			back = back->getNextNode();
		}
	}
	return *this;
}

template<class T>
Queue<T>::~Queue() {
	// TODO Auto-generated destructor stub
	clear();
}

