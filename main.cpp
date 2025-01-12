#include <iostream>

#include "myVector.h"
#include "myList.h"

int main()
{
    MyVector<int> vec;
    MyList<int> list;


    for(size_t i = 0; i < 10; ++i)
    {
        vec.push_back(i);
    }
    
    // list.push_back(10);
    for(size_t i = 0; i < 10; ++i)
    {
        list.push_back(i);
    }

    vec.print();
    list.print();

    std::cout << "size vec " << vec.size() << "\n";
    std::cout << "size list " << list.size() << "\n";
    
    vec.insert(10, 0);
    list.insert(10, 0);
    vec.print();
    list.print();

    vec.insert(30, vec.size());
    list.insert(30, list.size());
    vec.print();
    list.print();

    vec.insert(20, vec.size() / 2);
    list.insert(20, list.size() / 2);
    vec.print();
    list.print();


    vec.erase(2, 4, 6);
    vec.print();

    list.erase(6);
    list.erase(4);
    list.erase(2);
    list.print();


}