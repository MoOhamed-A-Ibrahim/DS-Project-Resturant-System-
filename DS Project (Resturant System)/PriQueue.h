#pragma once
#include "priNode.h"
#include <iostream>
#include <sstream>
using namespace std;
//This class impelements the priority queue as a sorted list (Linked List)
//The item with highest priority is at the front of the queue
template <typename T>
class priQueue
{
    priNode<T>* head;
public:
    int count = 0;
    priQueue() : head(nullptr) {}

    ~priQueue() {
        T tmp;
        int p;
        while (dequeue(tmp, p));
    }

    //insert the new node in its correct position according to its priority
    void enqueue(const T& data, int priority) {
        priNode<T>* newNode = new priNode<T>(data, priority);

        if (head == nullptr || priority > head->getPri()) {

            newNode->setNext(head);
            head = newNode;
            return;
        }

        priNode<T>* current = head;
        while (current->getNext() && priority <= current->getNext()->getPri()) {
            current = current->getNext();
        }
        newNode->setNext(current->getNext());
        current->setNext(newNode);
    }

    bool dequeue(T& topEntry, int& pri) {
        if (isEmpty())
            return false;

        topEntry = head->getItem(pri);
        priNode<T>* temp = head;
        head = head->getNext();
        delete temp;
        return true;
    }

    bool peek(T& topEntry, int& pri) {
        if (isEmpty())
            return false;

        topEntry = head->getItem();
        pri = head->getPri();
        return true;
    }

    bool isEmpty() const {
        return head == nullptr;
    }
    void printQueue() const {
        priNode<T>* current = head;

        if (isEmpty()) {
            cout << "-------------\n|   EMPTY   |\n-------------\n";
            return;
        }

        while (current != nullptr) {
            int pri;
            stringstream ss;
            ss << *(current->getItem(pri)); 
            string content = ss.str();
            cout << content << endl;
            current = current->getNext();
        }
    }
    void printQueueRTBased(int& currentTime) const {
        priNode<T>* current = head;

        while (current != nullptr) {
            int pri;
            T item = current->getItem(pri);  
            if (item->getRT() <= currentTime) {
                stringstream ss;
                ss << *item;  
                cout << ss.str();
            }
            current = current->getNext();  
        }
    }
    int numberOfElements(int& currentTime) {
        priNode<T>* current = head;
        while (current != nullptr) {
            int pri;
            T item = current->getItem(pri);
            if (item->getRT() == currentTime) {
                count++;
            }
            current = current->getNext();
            
        }
        return count;
    }
};
