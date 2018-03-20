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
#include "Tests.h"


int main()
{

    if (!testAddStart()) std::cout << "Error in testAddStart" << endl;
    else cout << "testAddStart passed" << endl;

    if (!testAddEnd()) std::cout << "Error in testAddEnd" << endl;
    else cout << "testAddEnd passed" << endl;

    if (!testAddNodeAfter()) std::cout << "Error in testAddNodeAfter" << endl;
    else cout << "testAddNodeAfter passed" << endl;

    if (!testAddNodeAfter()) std::cout << "Error in testAddNodeAfter" << endl;
    else cout << "testAddNodeAfter passed" << endl;

    if (!testDeleteElement()) std::cout << "Error in testDeleteElement" << endl;
    else cout << "testDeleteElement passed" << endl;

    if (!testDeleteElementValue()) std::cout << "Error in testDeleteElementValue" << endl;
    else cout << "testDeleteElementValue passed" << endl;

    if (!testDeleteElementScope()) std::cout << "Error in testDeleteElementScope" << endl;
    else cout << "testDeleteElementScope passed" << endl;

    if (!testEqualToOperator()) std::cout << "Error in testEqualToOperator" << endl;
    else cout << "testEqualToOperator passed" << endl;

    if (!testPlusOperator()) std::cout << "Error in testPlusOperator" << endl;
    else cout << "testPlusOperator passed" << endl;

    if (!testMinusOperator()) std::cout << "Error in testMinusOperator" << endl;
    else cout << "testMinusOperator passed" << endl;

    if (!testCopyConstructor()) std::cout << "Error in testCopyConstructor" << endl;
    else cout << "testCopyConstructor passed" << endl;

    if (!testAssignmentOperator()) std::cout << "Error in testAssignmentOperator" << endl;
    else cout << "testAssignmentOperator passed" << endl;

    if (!testGetElementOperator()) std::cout << "Error in testGetElementOperator" << endl;
    else cout << "testGetElementOperator passed" << endl;

    return 0;
}
