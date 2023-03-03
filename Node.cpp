/*
 * Node.cpp
 *
 *  Created on: 3 de nov. de 2022
 *      Author: Marcos Macedo
 */
#include "node.h"

template<class T>
void headInsert(Node<T> *&head, const T &newItem){
	Node<T> *newNode = new Node<T>();
	newNode->setValue(newItem);
	newNode->setNextNode(head);
	head = newNode;
}

template<class T>
void insert(Node<T> *&back, const T &newItem){

}

template<class T>
void deleteFirstNode(Node<T> *&head){
	Node<T> *discard;
	discard = head;
	head = head->getNextNode();
	delete discard;
}

template<class T>
void deleteNode(Node<T> * before){
	Node<T>* discard;
	discard = before->getNextNode();
	before->setNextNode(discard->getNextNode());
	delete discard;
}

template<class T>
Node<T>* search(Node<T> *head, T& target){
	Node<T>* here = head;
	if(here == NULL)
	{
		return NULL;
	}
	else
	{
		while(here->getValue() != target && here->getNextNode() != 0)
			here = here->getNextNode();

		if(here->getValue() == target)
			return here;
		else
			return NULL;
	}
}

