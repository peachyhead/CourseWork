//
//  Node.hpp
//  course_work
//
//  Created by Vasily Chalov on 18.10.2023.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>

template <typename T>
class Node {
public:
    Node* next;
    Node* prev;
    T* data;
    
    Node() {
        next = nullptr;
        prev = nullptr;
        data = nullptr;
    }
    
    Node(T* data){
        next = nullptr;
        prev = nullptr;
        this->data = data;
    }
    
    ~Node() {
        if (data != nullptr) {
            data = nullptr;
        }
    }
};

#endif /* Node_hpp */
