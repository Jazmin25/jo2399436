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
#include "LL.h"
using namespace std;


int main(int argc, char** argv) {
    //Create a linked list
    LnkdLst list(0);
    //Append 3 more chains
    int clinks=3;
    for(int i=1;i<=clinks;i++){
        list.append(i);
    }
    //Print the data
    list.toString();
    //Exit stage right!
    list.~LnkdLst();
    return 0;
}