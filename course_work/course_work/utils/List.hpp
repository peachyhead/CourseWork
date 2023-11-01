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
    void swap(int index1, int index2);
    int getCount();
    Node<T>* getBack();
    
    T& operator[](size_t index) {
        Node<T>* q;
        int iter = 0;
        for (q = getBack(); q != nullptr; q = q->next)
        {
            if (iter == index)
                return *q->data;
            
            iter++;
        }
        
        return *q->data;
    }

private:
    Node<T>* _front;
    Node<T>* _back;

    int _count;
};

template <typename T>
void List<T>::add(T* value) {
    Node<T>* newNode = new Node<T>(value);

    if (!_back) {
        _front = newNode;
        _back = newNode;
    }
    else {
        newNode->prev = _front;
        _front->next = newNode;
        _front = newNode;
    }

    _count++;
}

template <typename T>
void List<T>::remove(T* value) {

    Node<T>* q;
    for (q = _back; q != nullptr; q = q->next)
    {
        if (q->data != value)
            continue;

        if (q == _back){
            _back = q->next;
        }

        if (q->next){
            q->next->prev = q->prev;
        }
        if (q->prev){
            q->prev->next = q->next;
        }
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
void List<T>::swap(int index1, int index2) {


    if (index1 < 0 || index2 < 0 ||
        index1 >= _count || index2 >= _count) {
        return;
    }

    if (index1 == index2) {
        return;
    }

    Node<T> *node1, *node2;

    Node<T>* q;
    int i = 0;
    int foundFlag = 0;
    for (q = _back; q != nullptr; q = q->next){

        if (foundFlag == 2)
            break;

        if (i == index1){
            node1 = q;
            foundFlag++;
        }
        else if (i == index2){
            node2 = q;
            foundFlag++;
        }

        i++;
    }

    if (node1 == _back)
        _back = node2;
    else if (node2 == _back)
        _back = node1;
    if (node1 == _front)
        _front = node2;
    else if (node2 == _front)
        _front = node1;

    Node<T>* temp = node1->next;
    node1->next = node2->next;
    node2->next = temp;

    if (node1->next)
        node1->next->prev = node1;
    if (node2->next)
        node2->next->prev = node2;

    temp = node1->prev;
    node1->prev = node2->prev;
    node2->prev = temp;

    if(node1->prev){
        node1->prev->next = node1;
    }
    if (node2->prev){
        node2->prev->next = node2;
    }
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
