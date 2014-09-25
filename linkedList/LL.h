/* 
 * File:   LL.h
 * Author: jazmin
 *
 * Created on September 23, 2014, 7:53 PM
 */

#ifndef LL_H
#define	LL_H

#include <string>
#include <stddef.h>
#include <iostream>
using namespace std;

class LnkdLst 
{
public:
    
    LnkdLst(int);
    void append(int);
    void toString();
    virtual ~LnkdLst();
private:
    struct Node
    {
         int data;
         Node *next;
    };
    Node *head;
    Node *worker;
};


#endif	/* LL_H */

