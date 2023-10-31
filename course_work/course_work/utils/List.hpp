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

template <typename T>
class List {
public:
    List() {
        _front = nullptr;
        _back = nullptr;
        _items = new Node<T>[1];
        _count = 0;
    }
    
    ~List() {
        delete _front;
        delete _back;
        delete _items;
    }
    
    void add(T* value);
    void remove(T* value);
    bool isEmpty();
    void swap(int index1, int index2);
    int getCount();
    
    T& operator[](size_t index) {
        return *_items[index].data;
    }
    
private:
    Node<T>* _front;
    Node<T>* _back;
    
    int _count;
    Node<T>* _items;
};

template <typename T>
void List<T>::add(T* value) {
    Node<T>* newNode = new Node<T>(value);
    if (isEmpty()) {
        _front = newNode;
        _back = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    }
    else {
        newNode->next = _front;
        newNode->prev = _back;
        _back->next = newNode;
        _front->prev = newNode;
        _back = newNode;
    }

    int newSize = _count + 1;
    Node<T>* newItems = new Node<T>[newSize];
    for (int i = 0; i < _count; ++i) {
        // Create a new node and copy the data from the old node
        newItems[i].data = new T(*_items[i].data);
    }

    // Create a new node and copy the data from the new node
    newItems[_count].data = new T(*newNode->data);

    // Deallocate the old memory
    for (int i = 0; i < _count; ++i) {
        //delete _items[i].data;
    }
    delete[] _items;

    // Update _items and _count
    _items = newItems;
    _count = newSize;
}

template <typename T>
void List<T>::remove(T* value) {
    for (int i = 0; i < _count; i++) {
        Node<T>* currentNode = &_items[i];
        if (currentNode->data != value) {
            currentNode = currentNode->next;
            continue;
        }

        Node<T>* nextNode = currentNode->next;
        Node<T>* prevNode = currentNode->prev;

        if (currentNode == _front)
            _front = nextNode;

        if (currentNode == _back)
            _back = prevNode;

        if (nextNode)
            nextNode->prev = prevNode;

        if (prevNode)
            prevNode->next = nextNode;

        // Deallocate the memory
        delete currentNode->data;
        //delete currentNode;

        // Update the _items array
        int indexToRemove = -1;
        for (int i = 0; i < _count; ++i) {
            if (&_items[i] == currentNode) { // Compare addresses
                indexToRemove = i;
                break;
            }
        }
        
        if (indexToRemove >= 0) {
            // Shift elements to remove the deleted node
            for (int i = indexToRemove; i < _count - 1; ++i) {
                _items[i] = _items[i + 1];
            }
            _count -= 1;
        }

        currentNode = nextNode;
    }
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

    Node<T>* node1 = &_items[index1];
    Node<T>* node1Next = node1->next;
    Node<T>* node1Prev = node1->prev;

    Node<T>* node2 = &_items[index2];
    Node<T>* node2Next = node2->next;
    Node<T>* node2Prev = node2->prev;

    if (node1 == _front) {
        _front = node2;
    } else if (node2 == _front) {
        _front = node1;
    }

    if (node1 == _back) {
        _back = node2;
    } else if (node2 == _back) {
        _back = node1;
    }

    if (node1 && node2) {
        Node<T>* temp = node1;

        if (node1Prev) {
            node1Prev->next = node2;
        }
        if (node1Next) {
            node1Next->prev = node2;
        }

        if (node2Prev) {
            node2Prev->next = node1;
        }
        if (node2Next) {
            node2Next->prev = node1;
        }

        node1->data = node2->data;
        node1->next = node2->next;
        node1->prev = node2->prev;

        node2->data = temp->data;
        node2->next = node1->next;
        node2->prev = node1->prev;
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

#endif /* List_hpp */
