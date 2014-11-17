/* 
 * File:   emName.h
 * Author: jazmin
 *
 * Created on November 09, 2014, 4:43 PM
 */
#include<set>
#include<string>
#include <map>
#include <utility>
#ifndef EMNAME_H
#define	EMNAME_H
using namespace std;

class emName 
{
private:
    set<string> name;
    

    
public:
    emName();
    void insertName(string );
    void print();
    void del(string);
    
};

class menu 
{
private:
    map<string, float> app;
    map<string, float> mainD;
    map<string, float> dess;
    

    
public:
    menu();
    void addApp(string, float);
    void addMai(string, float);
    void addDess(string, float);
    void dis();
    
};

#endif	/* EMNAME_H */

