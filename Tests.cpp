/*
* Klasa realizuj¹ca dwukierunkow¹ listê przechowuj¹c¹ liczby ca³kowite.
* Umo¿liwia wykonywanie szereg dzia³añ na obiekcie, np. dodawanie, usuwanie elementów, dodawanie, odejmowanie list
* oraz operatory dodawania, porównywania czy kopiowania obiektu
*
* @author Miko³aj Klepacz
*
* Plik implementacyjny pliku testowego
*/

#include <iostream>
#include "DoublyLinkedList.h"
#include "Tests.h"

bool testAddStart() {
    DoublyLinkedList A;
    A.addNodeStart(5);
    A.addNodeStart(1);

    return A.getFirstElementByValue(5) && A.getFirstElementByValue(1);
}

bool testAddEnd() {
    DoublyLinkedList A;
    A.addNodeEnd(5);
    A.addNodeEnd(1);
    A.addNodeEnd(8);

    return A.getElementByIndex(0)->data == 5 && A.getElementByIndex(1)->data == 1 && A.getElementByIndex(2)->data == 8;
}

bool testAddNodeAfter(){
    DoublyLinkedList A;
    A.addNodeEnd(5);
    A.addNodeEnd(1);
    A.addNodeEnd(8);
    A.addNodeAfter(0,4);
    A.addNodeAfter(2,10);

    return A.getElementByIndex(1)->data == 4 && A.getElementByIndex(3)->data == 10 && A.getElementByIndex(4)->data == 8;
}

bool testDeleteElement(){
    DoublyLinkedList A;
    A.addNodeEnd(5);
    A.addNodeEnd(1);
    A.addNodeEnd(8);
    A.addNodeEnd(10);

    A.deleteElement(A.getElementByIndex(1));
    A.deleteElement(A.getElementByIndex(2));

    return A.getElementByIndex(0)->data == 5 && A.getElementByIndex(1)->data == 8;
}

bool testDeleteElementValue(){
    DoublyLinkedList A;
    A.addNodeEnd(2);
    A.addNodeEnd(9);
    A.addNodeEnd(15);
    A.addNodeEnd(-2);

    A.deleteElementValue(-2);
    A.deleteElementValue(2);

    return A.getElementByIndex(0)->data == 9 && A.getElementByIndex(1)->data == 15;

}

bool testDeleteElementScope(){
    DoublyLinkedList A;
    A.addNodeEnd(5);
    A.addNodeEnd(1);
    A.addNodeEnd(8);
    A.addNodeEnd(2);
    A.addNodeEnd(12);
    A.addNodeEnd(10);

    A.deleteElementScope(4,11);

    return A.getElementByIndex(0)->data == 1 && A.getElementByIndex(1)->data == 2 && A.getElementByIndex(2)->data == 12;
}

bool testEqualToOperator(){
    DoublyLinkedList A;
    A.addNodeEnd(5);
    A.addNodeEnd(-12);
    A.addNodeEnd(8);

    DoublyLinkedList B;
    B.addNodeEnd(5);
    B.addNodeEnd(-12);
    B.addNodeEnd(8);

    return A == B;
}

bool testPlusOperator(){
    DoublyLinkedList A;
    A.addNodeEnd(5);

    DoublyLinkedList B;
    B.addNodeEnd(3);
    B.addNodeEnd(-2);
    B.addNodeEnd(9);

    DoublyLinkedList C;

    C = A+B;

    return C.getElementByIndex(0)->data == 5 && C.getElementByIndex(1)->data == 3 && C.getElementByIndex(2)->data == -2 &&
            C.getElementByIndex(3)->data == 9;
}

bool testMinusOperator(){
    DoublyLinkedList B;
    B.addNodeEnd(3);
    B.addNodeEnd(-2);
    B.addNodeEnd(9);
    B.addNodeEnd(12);

    DoublyLinkedList A;
    A.addNodeEnd(3);
    A.addNodeEnd(2);
    A.addNodeEnd(9);
    A.addNodeEnd(12);

    DoublyLinkedList C;
    C = A-B;

    return C.getElementByIndex(0)->data == 2;
}

bool testCopyConstructor(){
    DoublyLinkedList A;
    bool output;
    A.addNodeEnd(3);
    A.addNodeEnd(2);
    A.addNodeEnd(9);

    DoublyLinkedList *B = new DoublyLinkedList(A);

    B->setData(1,30);

    output = A.getElementByIndex(0)->data == B->getElementByIndex(0)->data && A.getElementByIndex(1)->data == 2 &&
        B->getElementByIndex(1)->data == 30 && A.getElementByIndex(2)->data == B->getElementByIndex(2)->data;

    delete B;
    return output;
}

bool testAssignmentOperator(){
    DoublyLinkedList A;
    A.addNodeEnd(3);
    A.addNodeEnd(2);
    A.addNodeEnd(9);

    DoublyLinkedList B;

    B = A;

    B.setData(1,30);

    return A.getElementByIndex(0)->data == B.getElementByIndex(0)->data && A.getElementByIndex(1)->data == 2 &&
        B.getElementByIndex(1)->data == 30 && A.getElementByIndex(2)->data == B.getElementByIndex(2)->data;
}

bool testGetElementOperator(){
    DoublyLinkedList A;
    A.addNodeEnd(3);
    A.addNodeEnd(12);
    A.addNodeEnd(9);
    A.addNodeEnd(4);

    return A[2]->data == A.getElementByIndex(2)->data;
}
