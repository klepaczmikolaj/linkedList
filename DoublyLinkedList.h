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
    void addNodeStart(int);
    void addNodeEnd(int);
    void addNodeAfter(NodePointer, int);
    void addNodeAfter(int, int);

    void deleteElement(NodePointer);
    void deleteElementIndex(int);
    void deleteElementValue(int);
    void deleteElementScope(int, int);
    void removeDuplicates();

    NodePointer getElementByIndex(int);
    NodePointer getFirstElementByValue(int);
    int getNumberOfElements();
    void printList();

    //operators
    DoublyLinkedList operator+(const DoublyLinkedList& lis);
    DoublyLinkedList operator-(const DoublyLinkedList& lis);

    private:
    void increaseIndexesAfterNode(NodePointer);
    void decreaseIndexesAfterNode(NodePointer);
    void addNumberToIndexesAfterNode(NodePointer, int);
};
