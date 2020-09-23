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
    
    cout << "First: " << list_object.First() << endl;
    cout << "Last: " << list_object.Last() << endl;

    list_object.PopFront();

    cout << endl;
    cout << "First: " << list_object.First() << endl;
    cout << "Last: " << list_object.Last() << endl;

    list_object.Insert(3, 90);

    // 88, 10, 90, 14, 56 
    // ^^              ^^

    list_object.PopBack();

    // 88, 10, 90, 14 
    // ^^          ^^

    list_object.PopBack();

    // 88, 10, 90 
    // ^^      ^^

    cout << endl;
    cout << "First: " << list_object.First() << endl;
    cout << "Last: " << list_object.Last() << endl;

    list_object.PushBack(26);
    list_object.PushFront(12);
    list_object.PushFront(76);

    // 76, 12 ,88, 10, 90, 26 
    // ^^                  ^^

    cout << endl;
    if (list_object.Search(90) == -1) { cout << "90 is not in the list!" << endl; }
    else { cout << "90 is at position: " << list_object.Search(90) << endl; }
    
    cout << "Last: " << list_object.Last() << endl;

    list_object.Erase(5);
   
    // 76, 12 ,88, 10, 26 
    // ^^              ^^

    cout << endl;
    cout << "First: " << list_object.First() << endl;
    cout << "Last: " << list_object.Last() << endl;

    list_object.Remove(26);

    // 76, 12 ,88, 10 
    // ^^          ^^

    cout << endl;
    cout << "First: " << list_object.First() << endl;
    cout << "Last: " << list_object.Last() << endl;
    cout << "Length: " << list_object.Count() << endl;

    list_object.Sort();

    // 10, 12, 76, 88 
    // ^^          ^^

    cout << endl;
    cout << "First: " << list_object.First() << endl;
    cout << "Last: " << list_object.Last() << endl;

    list_object.Clear();

    // empty list
    // returns -1 on value return fail
    cout << endl;
    cout << "First: " << list_object.First() << endl;
    cout << "Last: " << list_object.Last() << endl;


    return 1;
}
