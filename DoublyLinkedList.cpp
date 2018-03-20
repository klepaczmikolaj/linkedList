/*
* Klasa realizująca dwukierunkową listę przechowującą liczby całkowite.
* Umożliwia wykonywanie szereg działań na obiekcie, np. dodawanie, usuwanie elementów, dodawanie, odejmowanie list
* oraz dostarcza operatory dodawania, porównywania czy kopiowania obiektów.
*
* @author Mikołaj Klepacz
*
* Plik implementacyjny dla klasy DoublyLinkedList
*/

#include <iostream>
#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList(){
    head = NULL;
    tail = NULL;
}

void DoublyLinkedList::addNodeStart(int inputData){
    NodePointer newNode = new Node();
    newNode->data = inputData;
    newNode->previous = NULL;
    newNode->elementIndex = 0;
    newNode->next = NULL;

    if(head == NULL){
        head = newNode;
        tail = newNode;
        newNode = NULL;
    }else{
        head->previous = newNode;
        newNode->next = head;
        head = newNode;
        increaseIndexesAfterNode(head);
    }
}

void DoublyLinkedList::addNodeEnd(int inputData){
    NodePointer newNode = new Node();
    newNode->data = inputData;
    newNode->previous = NULL;
    newNode->next = NULL;

    if(head == NULL){
        newNode->elementIndex = 0;
        head = newNode;
        tail = newNode;
        newNode = NULL;
    }else{
        newNode->elementIndex = tail->elementIndex + 1;
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
    }
}

void DoublyLinkedList::addNodeAfter(NodePointer specifiedNode, int inputData){
    if(specifiedNode == NULL)
        addNodeEnd(inputData);
    else if(specifiedNode->next == NULL)
        addNodeEnd(inputData);
    else{
        NodePointer newNode = new Node();
        newNode->data = inputData;
        newNode->elementIndex = specifiedNode->elementIndex + 1;
        newNode->next = specifiedNode->next;
        newNode->previous = specifiedNode;

        specifiedNode->next->previous = newNode;
        specifiedNode->next = newNode;

        increaseIndexesAfterNode(newNode);
    }
}

void DoublyLinkedList::addNodeAfter(int specifiedNodeIndex, int inputData){
    for(NodePointer temp = head; temp != NULL; temp = temp->next)
        if(temp->elementIndex == specifiedNodeIndex){
            addNodeAfter(temp,inputData);
            return;
        }
}

void DoublyLinkedList::setData(int specifiedNodeIndex, int inputData){
    NodePointer temp = getElementByIndex(specifiedNodeIndex);
    temp->data = inputData;
}

void DoublyLinkedList::addNumberToIndexesAfterNode(NodePointer addedNode, int numberToAdd){
    NodePointer temp = addedNode->next;
    while(temp != NULL){
        temp->elementIndex += numberToAdd;
        temp = temp->next;
    }
}

void DoublyLinkedList::increaseIndexesAfterNode(NodePointer addedNode){
    addNumberToIndexesAfterNode(addedNode, 1);
}

void DoublyLinkedList::decreaseIndexesAfterNode(NodePointer addedNode){
    addNumberToIndexesAfterNode(addedNode, -1);
}

void DoublyLinkedList::deleteElement(NodePointer nodeToDelete){
    if(nodeToDelete == NULL){
        return;
    }

    else if(nodeToDelete == head && nodeToDelete == tail){

        delete nodeToDelete;
        nodeToDelete = NULL;
        head = NULL;
        tail = NULL;
    }
    else if(nodeToDelete == head){
        decreaseIndexesAfterNode(head);
        head = head->next;
        delete head->previous;
        head->previous = NULL;
    }
    else if(nodeToDelete == tail){
        tail = tail->previous;
        delete tail->next;
        tail->next = NULL;
    }
    else{
        decreaseIndexesAfterNode(nodeToDelete);
        nodeToDelete->previous->next = nodeToDelete->next;
        nodeToDelete->next->previous = nodeToDelete->previous;
        delete nodeToDelete;
        nodeToDelete = NULL;
    }
}

void DoublyLinkedList::deleteElementIndex(int specifiedNodeIndex){
    for(NodePointer temp = head; temp != NULL; temp = temp->next)
        if(temp->elementIndex == specifiedNodeIndex){
            deleteElement(temp);
            return;
        }
}

void DoublyLinkedList::deleteElementValue(int value){
    for(NodePointer temp = head; temp != NULL; temp = temp->next)
        if(temp->data == value)
            deleteElement(temp);
}

void DoublyLinkedList::deleteElementScope(int startValue, int endValue){
    for(NodePointer temp = head; temp != NULL; temp = temp->next)
        if(temp->data >= startValue && temp->data <= endValue)
            deleteElement(temp);
}

void DoublyLinkedList::removeDuplicates(){
    if(head == NULL)
        return;

    NodePointer temp = head;
    NodePointer iter;

    while(temp->next != NULL){
        for(iter = temp->next; iter != NULL; iter = iter->next)
            if(temp->data == iter->data){
                iter = iter->previous;
                deleteElement(iter->next);
            }
        temp = temp->next;

        if(temp == NULL)
            break;
    }
}

NodePointer DoublyLinkedList::getElementByIndex(int specifiedNodeIndex) const{
    for(NodePointer temp = head; temp != NULL; temp = temp->next)
        if(temp->elementIndex == specifiedNodeIndex)
            return temp;

    return NULL;
}

NodePointer DoublyLinkedList::getFirstElementByValue(int value) const{
    for(NodePointer temp = head; temp != NULL; temp = temp->next)
        if(temp->data == value)
            return temp;

    return NULL;
}

int DoublyLinkedList::getNumberOfElements() const{
    int sizeCounter = 0;
    NodePointer temp = head;
    while(temp != NULL){
        sizeCounter++;
        temp = temp->next;
    }
    return sizeCounter;
}

void DoublyLinkedList::printList(){
    if(head == NULL){
        cout << "The list is Empty" << endl;
        return;
    }
    for(NodePointer temp = head; temp != NULL; temp = temp->next){
        cout << "index: " << temp->elementIndex << "   stored number: " << temp->data << endl;
    }
    cout << endl;
}

DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& lis){
    if(lis.head == NULL)
        return;

    for(NodePointer temp = lis.head; temp != NULL; temp = temp->next)
        this->addNodeEnd(temp->data);
}

DoublyLinkedList DoublyLinkedList::operator+(const DoublyLinkedList& lis){
    DoublyLinkedList outputList;

    for(NodePointer temp = this->head; temp != NULL; temp = temp->next)
        outputList.addNodeEnd(temp->data);

    for(NodePointer temp = lis.head; temp != NULL; temp = temp->next)
        outputList.addNodeEnd(temp->data);

    return outputList;
}

DoublyLinkedList DoublyLinkedList::operator-(const DoublyLinkedList& lis){
    DoublyLinkedList outputList;

    for(NodePointer temp = this->head; temp != NULL; temp = temp->next)
        outputList.addNodeEnd(temp->data);

    for(NodePointer temp = outputList.head; temp != NULL; temp = temp->next)
        for(NodePointer iter = lis.head; iter != NULL; iter = iter->next)
            if(temp->data == iter->data){
                if(temp->next == NULL){
                    outputList.deleteElement(temp);
                    return outputList;
                }
                temp = temp->next;
                outputList.deleteElement(temp->previous);
            }

    return outputList;
}

bool DoublyLinkedList::operator==(const DoublyLinkedList& lis){

    if(this->getNumberOfElements() != lis.getNumberOfElements())
        return false;

    for(NodePointer temp = this->head; temp != NULL; temp = temp->next){
        int currentIndex = temp->elementIndex;
        NodePointer firstToCompare = this->getElementByIndex(currentIndex);
        NodePointer secondToCompare = lis.getElementByIndex(currentIndex);

        if(firstToCompare->data != secondToCompare->data)
            return false;
    }
    return true;
}

DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& lis){
    if(&lis == this){
        return *this;
    }

    for(NodePointer temp = this->head; temp != NULL; temp = temp->next)
        deleteElement(temp);

    for(NodePointer temp = lis.head; temp != NULL; temp = temp->next)
        this->addNodeEnd(temp->data);

    return *this;
}

/*DoublyLinkedList::~DoublyLinkedList(){
    for(NodePointer temp = this->head; temp != NULL; temp = temp->next)
        deleteElement(temp);
}*/

DoublyLinkedList& DoublyLinkedList::operator+=(const DoublyLinkedList& lis){
    for(NodePointer temp = lis.head; temp != NULL; temp = temp->next)
        this->addNodeEnd(temp->data);

    return *this;
}

DoublyLinkedList& DoublyLinkedList::operator-=(const DoublyLinkedList& lis){
    for(NodePointer temp = this->head; temp != NULL; temp = temp->next)
        for(NodePointer iter = lis.head; iter != NULL; iter = iter->next)
            if(temp->data == iter->data){
                if(temp->next == NULL){
                    this->deleteElement(temp);
                    return *this;
                }
                temp = temp->next;
                this->deleteElement(temp->previous);
            }

    return *this;
}

NodePointer DoublyLinkedList::operator[](const int& index){
    return this->getElementByIndex(index);
}
