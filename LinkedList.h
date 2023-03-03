/*
 * LinkedList.h
 *
 *  Created on: 28 de out. de 2022
 *      Author: Marcos Macedo
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "node.h"

template<class T>
class LinkedList {
public:
	LinkedList();
	LinkedList(const LinkedList<T> &linkedList);
	void add(T item);
	void addFirst(T item);
	void remove(T item);
	T get(int index);
	T getFirst() const;
	T getLast() const;
	int indexOf(T item) const;
	int length() const;
	bool isEmpty() const;
	bool contains(T item) const;
	T& operator[](int index);
	void show() const;
	virtual ~LinkedList();
private:
	Node<T> *front, *back;
	Node<T> *search(T item) const;
	T removeFirst();

};

#endif /* LINKEDLIST_H_ */
