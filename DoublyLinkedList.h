/*
* Klasa realizująca dwukierunkową listę przechowującą liczby całkowite.
* Umożliwia wykonywanie szereg działań na obiekcie, np. dodawanie, usuwanie elementów, dodawanie, odejmowanie list
* oraz operatory dodawania, porównywania czy kopiowania obiektu
*
* @author Mikołaj Klepacz
* 
* Plik nagłówkowy dla klasy DoublyLinkedList
*/
using std::cout;
using std::endl;

class Node{
    public:
    int data;
    int elementIndex;
    Node *next, *previous;
};

typedef Node *NodePointer;

class DoublyLinkedList{
    public:
    NodePointer head, tail;
    DoublyLinkedList();

    //add
    void addNodeStart(int);
    void addNodeEnd(int);
    void addNodeAfter(NodePointer, int);
    void addNodeAfter(int, int);

    //delete
    void deleteElement(NodePointer);
    void deleteElementIndex(int);
    void deleteElementValue(int);
    void deleteElementScope(int, int);
    void removeDuplicates();

    //get
    NodePointer getElementByIndex(int) const;
    NodePointer getFirstElementByValue(int) const;
    int getNumberOfElements() const;
    void printList();

    //operators
    DoublyLinkedList operator+(const DoublyLinkedList& lis);
    DoublyLinkedList operator-(const DoublyLinkedList& lis);
    bool operator==(const DoublyLinkedList& lis);
    DoublyLinkedList& operator=(const DoublyLinkedList& lis);
    DoublyLinkedList(const DoublyLinkedList& lis);

    private:
    void increaseIndexesAfterNode(NodePointer);
    void decreaseIndexesAfterNode(NodePointer);
    void addNumberToIndexesAfterNode(NodePointer, int);
};
