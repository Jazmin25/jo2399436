/* 
 * File:   LL.cpp
 * Author: jazmin
 *
 * Created on September 24, 2014, 11:43 AM
 */
//implementation file file

#include "LL.h"


LnkdLst::LnkdLst(int d)
{
    d = NULL;
}

void LnkdLst::toString()
{
    
    if(head)
    {
        worker=head;
        do
        {
             cout<<"Data element in the list ->"<<worker->data<<endl;
        }while(worker=worker->next);
    }
}

LnkdLst::~LnkdLst()
{
    int i;
    head = NULL;
    if(head){
        do{
            worker=head;
            head=head->next;
            delete worker;
            cout<<"Destroying Link "<<i++<<endl;
        }while(head);
    }
 
}

void LnkdLst::append(int num)
{
    Node *newNode;   //to ppint to a new nodeand to move through the list
    //Node *nodePtr;
   
    //allocate a new node and store num
    newNode = new Node;
    newNode->data = num;
    newNode->next = NULL;
    
    // if there arw no nodes in the list
    // make newNode the first node
    if (!head)
        head = newNode;
    else   // else insert new node at end
    {
        // initialize node Ptr
        worker = head;
        //find the last node
        while(worker->next)
            worker = worker->next;
        //insert newnode as the last node
        worker->next = newNode;
    }
}
