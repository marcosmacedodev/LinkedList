/*
 * Stack.cpp
 *
 *  Created on: 4 de nov. de 2022
 *      Author: Marcos Macedo
 */

#include "Stack.h"

template<class T>
void Stack<T>::push(const T &newItem){
	headInsert(top, newItem);
}

template<class T>
T Stack<T>::pop(){
	T result;
	result = top->getValue();
	deleteFirstNode(top);
	return result;
}

template<class T>
void Stack<T>::clear(){

	T next;
	while(top != NULL)
		next = pop();
}

template<class T>
bool Stack<T>::isEmpty() const{
	return top == NULL;
}

template<class T>
Stack<T>::Stack() : top(NULL){
	// TODO Auto-generated constructor stub
}

template<class T>
Stack<T>& Stack<T>::operator =(const Stack &stack)
{
	if(top == stack.top)
	{
		return *this;
	}

	clear();

	if (stack.top == NULL)
	{
		top = NULL;
	}
	else
	{
		Node<T> * pStackTop = stack.top;
		Node<T> * pTop = new Node<T>();
		top = pTop;
		pTop->setValue(pStackTop->getValue());
		pTop->setNextNode( NULL );
		pStackTop = pStackTop->getNextNode();
		while(pStackTop != NULL)
		{
			Node<T> *newNode = new Node<T>;
			newNode->setValue( pStackTop->getValue() );
			newNode->setNextNode(NULL);
			pTop->setNextNode( newNode );
			pStackTop = pStackTop->getNextNode();
			pTop = pTop->getNextNode();
		}
	}
	return *this;
}

template<class T>
Stack<T>::Stack(const Stack &stack){
	if (stack.top == NULL)
	{
		top = NULL;
	}
	else
	{
		Node<T> * pStackTop = stack.top;
		Node<T> * pTop = new Node<T>();
		top = pTop;
		pTop->setValue(pStackTop->getValue());
		pTop->setNextNode( NULL );
		pStackTop = pStackTop->getNextNode();
		while(pStackTop != NULL)
		{
			Node<T> *newNode = new Node<T>;
			newNode->setValue( pStackTop->getValue() );
			newNode->setNextNode(NULL);
			pTop->setNextNode( newNode );
			pStackTop = pStackTop->getNextNode();
			pTop = pTop->getNextNode();
		}
	}
}

template<class T>
Stack<T>::~Stack() {
	// TODO Auto-generated destructor stub
	clear();
}

