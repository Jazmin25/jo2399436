/* 
 * File:   main.cpp
 * Author: jazmin
 *
 * Created on September 23, 2014, 2:27 PM
 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on September 18, 2014, 1:55 PM
 * Purpose:  Explore creation of a linked list class Version 1
 */

//System Libraries
#include <iostream>
#include "linkedtemp.h"
using namespace std;


int main(int argc, char** argv) {
    //Create a linked list
    LnkdLst<int> list(0);
    //Append 3 more chains
    int clinks=3;
    for(int i=1;i<=clinks;i++){
        list.append(i);
    }
     //Print the data
    cout<<list.toString()<<endl;
    
    cout << "\n\nGoing to add 10 to the front of the linked list. \n";
    list.prepend(10);
    cout<<list.toString()<<endl;
    cout <<"\n\nGoing to insert a 9 after the 2 element.\n";
    list.insertA(9, 2);
    cout<<list.toString()<<endl;
    cout <<"\n\nGoing to append a 14 at the end of the list. \n";
    list.append(14);
   
    cout<<list.toString()<<endl;
    
    cout <<"\n\nGoing to insert a 7 before the 5 element.\n";
    list.insertB(7, 5);
    cout<<list.toString()<<endl;

    
    cout << "\nThe first number is "<< list.first();
 
   cout <<  "\nThe last number is "<<list.last();
   cout <<"\n\nGoing to extract a 2 and delete it.\n\n";
   list.extract(2);
     cout<<list.toString()<<endl;

   
    //Exit stage right!
    return 0;
}

