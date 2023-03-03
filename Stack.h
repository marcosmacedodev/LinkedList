/*
 * Stack.h
 *
 *  Created on: 4 de nov. de 2022
 *      Author: Marcos Macedo
 */

#ifndef STACK_H_
#define STACK_H_

#include "node.h"
#include "node.cpp"

template<class T>
class Stack {
public:
	Stack();
	Stack(const Stack<T> &stack);
	void push(const T &newItem);
	T pop();
	void clear();
	bool isEmpty() const;
	Stack& operator=(const Stack<T> &stack);
	virtual ~Stack();
private:
	Node<T> *top;
};

#endif /* STACK_H_ */
