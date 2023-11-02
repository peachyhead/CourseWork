//
//  List.hpp
//  course_work
//
//  Created by Vasily Chalov on 18.10.2023.
//

#ifndef List_hpp
#define List_hpp

#include "Node.hpp"
#include <stdio.h>
#include <iostream>

using namespace std;

template <typename T>
class List {
public:
    List() {
        _front = nullptr;
        _back = nullptr;
        _count = 0;
    }

    ~List(){
        Node<T>* q = _back;
        while(q != nullptr){
            Node<T>* nextNode = q->next;
            delete q;
            q = nextNode;
        }
    }

    void add(T* value);
    void remove(T* value);
    bool isEmpty();
    int indexOf(T* value);
    void swap(int index1, int index2);
    int getCount();
    Node<T>* getBack();
    
    T& operator[](size_t index) {
        return *elementAt(index)->data;
    }

private:
    Node<T>* _front;
    Node<T>* _back;

    int _count;
    Node<T>* elementAt(size_t index);
};

template <typename T>
void List<T>::add(T* value) {
    Node<T>* newNode = new Node<T>(value);

    if (!_back) {
        _front = newNode;
        _back = newNode;
        
        newNode->next = _front;
        newNode->prev = _back;
    }
    else {
        newNode->prev = _back;
        newNode->next = _front;
        _back->next = newNode;
        _front->prev = newNode;
        _back = newNode;
    }

    _count++;
}

template <typename T>
void List<T>::remove(T* value) {

    Node<T>* q;
    int iter = 0;
    for (q = _back; iter < _count; q = q->next)
    {
        if (q->data != value) {
            iter++;
            continue;
        }

        if (q == _back) {
            _back = q->prev;
        }

        if (q->next) {
            q->next->prev = q->prev;
        }
        if (q->prev) {
            q->prev->next = q->next;
        }
        
        if (_front)
            _front->prev = _back;
        
        _count--;
        
        break;
    }

    if (q == nullptr)
    {
        cout << "No item found!" << endl;
        return;
    }

    delete q;
}

template <typename T>
int List<T>::indexOf(T* value) {
    Node<T>* q;
    int iter = 0;
    for (q = _front; iter < _count; q = q->next)
    {
        if (q->data != value) {
            iter++;
            continue;
        }
        
        return iter;
    }
    
    return iter;
}

template <typename T>
void List<T>::swap(int index1, int index2) {

    if (index1 < 0 || index2 < 0 ||
        index1 >= _count || index2 >= _count) {
        return;
    }

    if (index1 == index2) {
        return;
    }

    Node<T>* node1 = elementAt(index1);
    Node<T>* node2 = elementAt(index2);

    Node<T> temp = *node1;
    node1->data = node2->data;
    node2->data = temp.data;
}

template <typename T>
Node<T>* List<T>::elementAt(size_t index) {
    Node<T>* requiredData = nullptr;
    Node<T>* q = _front;
    for (int iter = 0; iter < _count; q = q->next, iter++)
    {
        if (iter == index)
            return q;
    }
    
    return requiredData;
}

template <typename T>
bool List<T>::isEmpty(){
    return _count == 0;
}

template <typename T>
int List<T>::getCount() {
    return _count;
}

template <typename T>
Node<T>* List<T>::getBack() {
    return _back;
}

#endif /* List_hpp */
