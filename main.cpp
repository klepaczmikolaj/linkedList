/*
* Klasa realizująca dwukierunkową listę przechowującą liczby całkowite.
* Umożliwia wykonywanie szereg działań na obiekcie, np. dodawanie, usuwanie elementów, dodawanie, odejmowanie list
* oraz dostarcza operatory dodawania, porównywania czy kopiowania obiektów.
*
* @author Mikołaj Klepacz
*
*/

#include <iostream>
#include "DoublyLinkedList.h"

bool testAdd() {
    DoublyLinkedList A;
    A.addNodeStart(5);
    A.addNodeStart(1);

    return A.getFirstElementByValue(5) && A.getFirstElementByValue(1);
}
//Todo: test: all ADD, all DELETE, operator == + =(najlepiej wszystkie), copy constructor

int main()
{

    if (!testAdd()) std::cout << "Error in testAdd";
    DoublyLinkedList A;
    A.addNodeStart(5);
    A.addNodeStart(5);
    A.addNodeStart(5);
    A.addNodeStart(1);
    A.addNodeStart(1);
    A.addNodeEnd(1);
    A.addNodeEnd(6);

    NodePointer D = A.getFirstElementByValue(5);

    A.printList();
    cout << D->elementIndex << endl;

    DoublyLinkedList B;
    B.addNodeStart(10);
    B.addNodeStart(12);
    B.addNodeStart(10);

    B.printList();


    DoublyLinkedList C;


    C = B;

    C.addNodeStart(10);
    B.addNodeStart(25);

    B.printList();
    C.printList();

    DoublyLinkedList lista;
    lista = C;




    return 0;
}
