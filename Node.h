/*
 * Node.h
 *
 *  Created on: 28 de out. de 2022
 *      Author: Marcos Macedo
 */
#ifndef NODE_H_
#define NODE_H_

#include <cstddef>

template <class T>
class Node{
public:
	Node(): nextNode(NULL){}
	Node<T>* getNextNode() const {return nextNode;}
	void setNextNode(Node<T> * newNode) {nextNode = newNode;}
	T getValue() const { return value;}
	void setValue(const T& newValue) { value = newValue;}
	//virtual ~Node(){  };
private:
	Node * nextNode;
	T value;
};

template<class T>
void headInsert(Node<T> *&head, const T &newItem);

template<class T>
void insert(Node<T> *after, const T &newItem);

template<class T>
void deleteFirstNode(Node<T> *&head);

template<class T>
void deleteNode(Node<T> *before);

template<class T>
Node<T>* search(Node<T> *head, const T &item);

#endif /* NODE_H_ */
