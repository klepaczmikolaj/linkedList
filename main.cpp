#include <iostream>
#include "DoublyLinkedList.h"



int main()
{
    DoublyLinkedList myList;
    myList.addNodeStart(5);
    myList.addNodeStart(5);
    myList.addNodeStart(5);
    myList.addNodeStart(1);
    myList.addNodeStart(1);
    myList.addNodeEnd(1);


    myList.printList();

    DoublyLinkedList secondList;
    secondList.addNodeStart(10);
    secondList.addNodeStart(12);
    secondList.addNodeStart(10);

    secondList.printList();

    DoublyLinkedList sumList;


    sumList = myList + secondList;

    sumList.printList();
    cout << "el numbers: " << sumList.getNumberOfElements() << endl;

    sumList = sumList - secondList;
    sumList.printList();

    return 0;
}
