/* 
 * File:   emName.cpp
 * Author: jazmin
 * 
 * Created on November 09, 2014, 4:43 PM
 */

#include "emName.h"
#include <iostream>
#include <map>
using namespace std;


emName::emName() 
{
    name.insert("Jane Helen");
    name.insert("Gerald Qunez");
    name.insert("Lucille Ford");
}

void emName::insertName(string n)
{
    name.insert(n);
}

void emName::print()
{
    set<string>::iterator iter;
    for ( iter =name.begin(); iter != name.end(); iter++)
    {
        cout << *iter<< endl;
    }
}

void emName::del(string n)
{
    set<string>::iterator iter;
    iter = name.find(n); 
    name.erase(iter);
    
}

menu::menu()
{
    
    app["chips and salsa" ] = 5.99;
    app["Chicken wings" ] = 9.99;
    app["Stuffed Mushrooms" ] = 5.99;
    
    mainD["Steak and Potatoes" ] = 12.99;
    mainD["Blackened Tilapia" ] =15.99;
    mainD["Pork Roast" ] = 13.99;
    
    dess["Ice cream Sunday"] = 7.99;
    dess["Creme Brulee"] = 11.99;
    dess["Cheesecake (slice)" ] = 5.99;
}

 void menu::addApp(string a, float b)
 {
     app[a]= b;
 }
 
 void menu::addMai(string c, float d)
 {
     mainD[c] = d;
 }
 
 void menu::addDess(string e, float f)
 {
     dess[e]=f;
 }
 
 void menu::dis()
 {
     map<string, float>::iterator iter;
     cout << "Appetizers: \n";
     for ( iter =app.begin(); iter != app.end(); iter++)
    {
        cout <<  iter -> first<< "\t\t " << iter->second <<endl ;
     
    }
      cout << "Main Dishes \n";
     for ( iter =mainD.begin(); iter != mainD.end(); iter++)
    {
        cout << iter -> first<< "\t\t " << iter->second <<endl ;
    }
      
     cout << "Desserts: \n";
     for ( iter =dess.begin(); iter != dess.end(); iter++)
    {
        cout << iter -> first<< "\t\t " << iter->second <<endl ;
    }
     
 }