#include <iostream>
#include "LinkedList.h"
using namespace std;

// constructor
LinkedList::LinkedList() {
    head = nullptr;
}

//Copy Constructor
LinkedList::LinkedList(const LinkedList &origList) {
    Node* constant = origList.head;
    while(constant != nullptr) {
        Append(constant ->value);
        constant = constant ->next;
    }
}

//default constructor
LinkedList::~LinkedList() {
    Node* constant = head;
    while(constant != nullptr) {
        constant = constant ->next;
        head ->next = nullptr;
        delete head;
        head = constant;
    }
}


bool LinkedList::IsItem(int item) const {
    Node* constant = head;
    while (constant != nullptr) {
        if (constant ->value == item) {
            cout << "Item Is Found" << endl;
            return true;
        }
        constant = constant ->next;
    }
    return false;
}

void LinkedList::Append(int item) {
    if (head == nullptr) {
        head = new Node(item);
    }
    else {
        Node* constant = head; //Otherwise
        while (constant ->next != nullptr) //Traverse to end of list
          constant  = constant ->next;
         constant ->next = new Node(item); //Create new node
    }
}


LinkedList& LinkedList::operator=(LinkedList rhs) {
    cout << " Assignment Operator" << endl;
    swap(head, rhs.head);
    return *this;
}

bool LinkedList::Remove(int item) {
    //Case 1: the list is empty
    if (head == nullptr) {
        return false;
    }

    Node* current = head;
    Node* previous;

    //Case 2:
    if (head ->value == item) {
        head = head ->next;
        current ->next = nullptr;
        delete current; //Delete
        return true;
    }

    //case 3: if it is not the head of the list
    while (current) {
        if (current ->value == item) {
            previous ->next = current ->next;
            current ->next = nullptr;
            delete current; //Delete
            return true;
        }
        previous = current;
        current = current -> next;
    }

    cout << " Failed"<< endl;
    return false; //If item not in list, do nothing
}

void LinkedList::PrintList() const {
    Node* cursor = head;
    if (!cursor)
        cout << "The List is Empty" << endl;
    else {
        while (cursor) {
            cout << cursor ->value << " ";
            cursor = cursor ->next;
        }
    }
}

void LinkedList::ListInsertionSort() {
    Node* current = head;
    current = current ->next;
    Node* previous = head;
    Node* tempCurrent;

    while (current != nullptr) {
        if (current ->value < previous ->value) {
            tempCurrent = head;

            if (current -> value < head ->value) {
                previous ->next = current ->next;
                current ->next = nullptr;
                current ->next = head;
                head = current;
                current = previous ->next;
            }

            else {
                while (tempCurrent ->next ->value < current ->value) {
                    //is less than cursor
                    tempCurrent = tempCurrent ->next;
                }
                previous ->next = current ->next;
                current ->next = nullptr;
                current ->next = tempCurrent ->next;
                tempCurrent ->next = current;
                current = previous ->next;
            }
        }

        else {
            current = current ->next;
            previous = previous ->next;
        }
    }
}//
// Created by 刘颖恒 on 2019/10/31.
//

