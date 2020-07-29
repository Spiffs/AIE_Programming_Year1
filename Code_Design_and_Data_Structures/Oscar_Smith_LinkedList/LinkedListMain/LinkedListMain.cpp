#include <iostream>
#include "LinkedList.h"

using std::cout;
using std::endl;

int main()
{
    LinkedList list_object;

    list_object.PushFront(10);
    list_object.PushBack(14);
    list_object.PushFront(88);
    list_object.PushFront(72);
    list_object.PushBack(56);

    // 72, 88, 10, 14, 56 
    // ^^              ^^
    
    cout << "First: " << list_object.Begin() << endl;
    cout << "Last: " << list_object.End() << endl;


    return 1;
}
