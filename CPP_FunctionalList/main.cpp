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
        Item(T v, std::shared_ptr<const Item> const & tail) : _val(v), _next(tail) {}
        T _val;
        std::shared_ptr<const Item> _next;
    };
public:
    List() {} // empty list constructor
    List(T v, List const & tail) : _head(std::make_shared<Item>(v, tail._head)) {} // x:xs recursive constructor; tail won't change ever, it's persistent

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
    std::shared_ptr<const Item> _head; // shallow constness but meant to mean deep const by recursion
};

template<class U, class T, class F>
List<U> fmap(F f, List<T> lst)
{
    static_assert(std::is_convertible<F, std::function<U(T)>>::value, "fmap requires a function type U(T)");
    if (lst.isEmpty())
        return List<U>();
    else
        return List<U>(f(lst.front()), fmap<U>(f, lst.pop_front()));
}


int main(int argc, const char * argv[]) {

    
    return 0;
}
