//
//  main.cpp
//  CPP_FunctionalList
//
//  Created by Ferenc Szalma on 1/14/17.
//  Copyright © 2017 Ferenc Szalma. All rights reserved.
//

#include <iostream>


template<class T>
class List {
    struct Item
    {
        Item(T v, Item const * tail) : _val(v), _next(tail) {}
        T _val;
        Item const * _next;
    };
public:
    List() : _head(nullptr){}; // empty list constructor
    List(T v, List tail) : _head(new Item(v, tail._head)){} ; // x:xs recursive constructor; tail won't change ever, it's persistent

    bool isEmpty() const {return !_head;}
    
    T front() const
    {
        assert(!isEmpty());
        return _head->_val;
    }
    List pop_front() const
    {
        assert(!isEmpty());
        return List(_head->_next);
    }
    
    List push_front(T v) const { //returns a new list with v as head, tail is same as the original list
        return List(v, *this);
    }
    
private:
    explicit List(Item const * items) : _head(items) {} //private constructor used in pop_front()
    //may be null
    Item const * _head; // shallow constness but meant to mean deep const by recursion
};


int main(int argc, const char * argv[]) {

    
    return 0;
}
