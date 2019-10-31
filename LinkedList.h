
#ifndef BINARYINSERTIONSORT_LINKEDLIST_H
#define BINARYINSERTIONSORT_LINKEDLIST_H
#include "Node.h"

class LinkedList {
public:
    LinkedList(); //Constructor
    LinkedList(const LinkedList &origList); //Copy Constructor
    ~LinkedList(); //Destructor
    bool IsItem(int item) const;
    void Append(int item);
    bool Remove(int item);
    LinkedList &operator= (LinkedList rhs);
    void PrintList() const;
    void ListInsertionSort();
private:
    Node* head = new Node;
};

#endif //BINARYINSERTIONSORT_LINKEDLIST_H
