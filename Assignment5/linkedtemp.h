/* 
 * File:   linkedtemp.h
 * Author: jazmin
 *
 * Created on October 7, 2014, 7:52 PM
 */

#ifndef LINKEDTEMP_H
#define	LINKEDTEMP_H

#include <string>
#include <stddef.h>
#include <iostream>
#include <sstream>
using namespace std;

template <class T>
class LnkdLst {
public:
    LnkdLst(T);
    string first();
    string  last();
    void prepend(T);
    void append(T);
    void insertA(T, T);
    void insertB(T, T);
    void extract(T);

    string toString();
    virtual ~LnkdLst();
private:
    struct Node{
         T data;
         Node *next;
    };
    Node *head;
    Node *worker;
};


template <class T>
LnkdLst<T>::LnkdLst(T n) {
    Node *clink = new Node;
    clink->data = n;
    clink->next = NULL;
    head = clink;
}

template <class T>
string LnkdLst<T>::first() {
        
    stringstream ss;
    string build="";
    worker=head;
    ss<<worker->data;
    string data;
    ss>>data;
    build=data;
    return data;

}

template <class T>
string LnkdLst<T>::last()
{
     stringstream ss;
    string build="";
    if(head){
        worker=head;
        do{
            if(worker->next==NULL)
            {
                
                ss<<worker->data;
                string data;
                ss>>data;
                build=data;
                return data;
            }
        }while(worker=worker->next);
    } 
}

template <class T>
void LnkdLst<T>::prepend(T n) 
{
    Node *prev = new Node;
    prev -> data = n;
    prev->next = head;
    head = prev;
}

template <class T>
void LnkdLst<T>::append(T n) {
    Node *prev;
    if (head) {
        worker = head;
        do {
            prev = worker;
        } while (worker = worker->next);
        Node *clink = new Node;
        clink->data = n;
        clink->next = NULL;
        prev->next = clink;
    } else {
        Node *clink = new Node;
        clink->data = n;
        clink->next = NULL;
        head = clink;
    }
}

template <class T>
void LnkdLst<T>::insertA(T num, T position) 
{
    Node *node1 = new Node;
    node1->data = num;
    node1->next =  NULL;
    if(position == 1)
    {
        node1->next = head;
        head = node1;
        return;
    }
        Node *node2 = head;

    for(int i=0; i< position-1; i++)
    {
        node2=node2->next;
    }
    node1->next = node2->next;
    node2->next= node1;
    
}

template <class T>
void LnkdLst<T>::insertB(T num, T position)
{
     Node *node1 = new Node;
    node1->data = num;
    node1->next =  NULL;
    if(position == 1)
    {
        node1->next = head;
        head = node1;
        return;
    }
        Node *node2 = head;

    for(int i=0; i< position-3; i++)
    {
        node2=node2->next;
    }
    node1->next = node2->next;
    node2->next= node1;
    
}

template <class T>
string LnkdLst<T>::toString() {
    string build = "";
    char counter = 48;
    if (head) {
        worker = head;
        do {
            build += ("Data element in the list ->");
            stringstream ss;
            ss << worker->data;
            string data;
            ss>>data;
            build += data;
            build += "\n";
        } while (worker = worker->next);
    }
    return build;
}

template <class T>
LnkdLst<T>::~LnkdLst() {
    if (head) {
        do {
            worker = head;
            head = head->next;
            delete worker;
        } while (head);
    }
}

template <class T>
void LnkdLst<T>::extract(T num) {
    Node *prev;

    if (!head)
        return;

    // Determine if the first node is the one.
    if (head->data == num) {
        worker = head->next;
        delete head;
        head = worker;
    } else {
        // Initialize nodePtr to head of list
        worker = head;
        // Skip all nodes whose value member is
        // not equal to num.
        while (worker != NULL && worker->data != num) {
            prev = worker;
            worker = worker->next;
        }

        //If nodePtr is not at the end of the list,
        //link the previous node to the node after
        //nodePtr, then delete nodePtr.
        if (worker) {
            prev->next = worker->next;
            delete worker;
        }
    }
}


#endif	/* LINKEDTEMP_H */

