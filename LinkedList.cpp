/*
 * LinkedList.cpp
 *
 *  Created on: 28 de out. de 2022
 *      Author: Marcos Macedo
 */

#include "LinkedList.h"
#include <cstdlib>
#include <iostream>


template<class T>
LinkedList<T>::LinkedList(): front(NULL), back(NULL){}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T> &linkedList):
front(NULL), back(NULL)
{
	Node<T> *here = linkedList.front;
	while(here != NULL) {
		add(here->getValue());
		here = here->getNextNode();
	}
}

template<class T>
void LinkedList<T>::add(T item){
	if (back == NULL)
	{
		addFirst(item);
		return;
	}
	Node<T> *newNode = new Node<T>();
	newNode->setValue(item);
	back->setNextNode(newNode);
	back = back->getNextNode();
}

template<class T>
void LinkedList<T>::addFirst(T item){
	if (front == NULL)
	{
		front = new Node<T>();
		front->setValue(item);
		back = front;
		return;
	}
	Node<T> *newNode = new Node<T>();
	newNode->setValue(item);
	newNode->setNextNode(front);
	front = newNode;
}

template<class T>
T LinkedList<T>::getFirst() const{
	return front->getValue();
}

template<class T>
T LinkedList<T>::getLast() const{
	return back->getValue();
}

template<class T>
int LinkedList<T>::indexOf(T item) const{
	int result = 0;
	Node<T> *here = front;
	while (here != NULL)
	{
		if (here->getValue() == item)
			return result;
		result++;
		here = here->getNextNode();
	}
	return -1;
}

template<class T>
bool LinkedList<T>::isEmpty() const{
	return back == NULL;
}

template<class T>
int LinkedList<T>::length() const{
	int result;
	Node<T> *here = front;
	for(result = 0 ; here != NULL ;
			here = here->getNextNode(), result++);
	return result;
}

template<class T>
bool LinkedList<T>::contains(T item) const{
	return indexOf(item) >= 0;
}

template<class T>
void LinkedList<T>::remove(T item){
	Node<T> *here = front;
	if (here->getValue()  == item)
	{
		removeFirst();
	}
	else
	{
		Node<T> *before = here;
		here = here->getNextNode();
		while(here != NULL)
		{
			if (here->getValue() == item)
			{
				before->setNextNode(here->getNextNode());
				delete here;
				return;
			}
			before = before->getNextNode();
			here = here->getNextNode();
		}
	}

}

template<class T>
Node<T> *LinkedList<T>::search(T item) const{
	Node<T> *here = front;
	if (here == NULL)
	{
		return NULL;
	}
	else
	{
		while(here->getValue() != item &&
				here->getNextNode() != NULL)
			here = here->getNextNode();

		if (here->getValue() == item)
		{
			return here;
		}
		else
		{
			return NULL;
		}
	}
}

template<class T>
T LinkedList<T>::removeFirst(){
	T tempValue = front->getValue();
	Node<T> *discard;
	discard = front;
	front = front->getNextNode();
	delete discard;
	return tempValue;
}

template<class T>
void LinkedList<T>::show() const{
	Node<T> *here = front;
	while( here != NULL )
	{
		std::cout << here->getValue() << std::endl;
		here = here->getNextNode();
	}
}

template<class T>
LinkedList<T>::~LinkedList() {
	// TODO Auto-generated destructor stub
	T next;
	while(front != NULL)
		next = removeFirst();
}

template<class T>
T& LinkedList<T>::operator [](int index){

}

template<class T>
T LinkedList<T>::get(int index){

	if (front == NULL)
	{
		std::cerr << "Erro: lista está vazio\n";
		exit(EXIT_FAILURE);
	}

	Node<T> *here = front;
	for(; here != NULL && index > 0 ;
			here = here->getNextNode(), index--);

	if(here == NULL)
	{
		std::cerr << "Erro: índice inválido\n";
		exit(EXIT_FAILURE);
	}

	return here->getValue();
}
