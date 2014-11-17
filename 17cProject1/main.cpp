/* 
 * File:   main.cpp
 * Author: jazmin
 *
 * Created on November 8, 2014, 2:13 PM
 */

#include <cstdlib>
#include <iostream>
#include <set>
#include <map>
#include <utility>
#include <cctype>
#include <stack>
#include <queue>
#include "emName.h"
using namespace std;


//Function Prototypes
void Manager(emName&, menu&);
void Customer(menu&);
void Menu();
void manMenu();         // the manager menu
void cusMenu();         // the customer menu
void def(int);
int getN();
void addEm(emName&);
void fireEm(emName&);
void viewEm(emName&);
void addMen(menu&);
void displayMen(menu&);
void order(menu&);
void recc();
void pay();



int main(int argc, char** argv) 
{
    emName em;
    menu m;
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
        case 1:    Manager(em, m);break;
        case 2:    Customer(m);break;

        default:   def(inN);}
    }while(inN>=1&&inN<=2);
    
    
    
    
    return 0;
}

void Menu()
{
    cout<<"\nMenu for the Project"<<endl;
    cout<<"Type 1 to play the Manager. "<<endl;
    cout<<"Type 2 to play a Customer. "<<endl;
    cout<<"Type anything else to exit \n"<<endl;
}

void manMenu()
{
    cout << "\nManager Menu : \n";
    cout << "________________________________________\n";
    cout << "Type 1 to Add an Employee \n";    
    cout << "Type 2 to Fire an Employee \n";
    cout << "Type 3 to View the Employee Roster \n";
    cout << "Type 4 to Add a Menu Item \n";
    cout << "Type 5 to View the Restaurant Menu\n";
    

}

void cusMenu()
{
    cout << "\nCustomer Menu : \n";
    cout << "___________________________________________\n";
    cout << "Type 1 to Display the Restaurant Menu \n";
    cout << "Type 2 to Display the Recommendations \n";
    cout << "Type 3 to Order. \n";

}

int getN()
{
        int inN;
        cin>>inN;
        return inN;
}

void def(int inN)
{
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}

void Manager(emName &em, menu &m)
{
    cout << "Welcome Manager, \n";
    cout << "What would you like to do? \n\n";
    
    
    int inN;
    do{
        manMenu();
        inN=getN();
        switch(inN)
        {
        case 1:    addEm(em);break;
        case 2:    fireEm(em);break;
        case 3:    viewEm(em);break;
        case 4:    addMen(m); break;
        case 5:    displayMen(m);break;

        default:  def(inN);}
    }while(inN>=1&&inN<=5);
    
    cout << "\nPress anything else to go back to the main menu.\n";
    
}
void Customer(menu &m)
{
    cout << "Welcome Customer, \n";
    cout << "What would you like to do? \n\n";
    
    int inN;
    do{
        cusMenu();
        inN=getN();
        switch(inN)
        {
        case 1:    displayMen(m);break;
        case 2:    recc();break;
        case 3:    order(m);break;

        default:  def(inN);}
    }while(inN>=1&&inN<=3);
}

void addEm(emName &em)
{
    
    string name;
    cout <<"Adding an Employee : \n";
    cout << "________________________\n";
    cout <<"Enter the name of the new Employee" << endl << endl;
    cin.ignore();
    getline(cin, name);
   
    em.insertName(name);
  
    
}

void fireEm(emName &em)
{
    
    string name;
    cout <<"Firing an Employee : \n";
    cout << "________________________\n";
    cout <<"Enter the name of the Employee to be fired. \n";
    cin.ignore();
    getline(cin, name);
    em.del(name);
    
    
    
}

void viewEm(emName &em)
{
    
    em.print();
}

void addMen(menu &m)
{
    
    float price;
    string dish;
    int ans;
    cout <<"Adding a menu Dish : \n";
    cout << "________________________\n";
    cout <<"Enter the name dish. \n";
    cin.ignore();
    getline(cin,dish);
    cout << "\nEnter the price of the dish.\n";
    cin.ignore();
    cin >> price;
    cout << "Is this dish an appetizers? 1 = yes and 2 = no \n";
    cin >> ans;
    if ( ans == 1)
        m.addApp(dish,price);
    else if ( ans == 2)
    {
        cout << "Is this dish a main dish? 1 = yes and 2 = no\n";
        cin >> ans;
        if ( ans == 1)
            m.addMai(dish, price);
        else if (ans == 2)
        {
            cout << "Is this dish a dessert? 1 = yes and 2 = no \n";
            if ( ans == 1)
            m.addDess(dish, price);
            else
                cout << "We do not have any other categories.\n ";
        }
    }
     else 
            cout <<" That is not a correct response. \n";
    
    
     
    
    
}

void displayMen(menu &m)
{
  
    m.dis();
    
}


void order(menu &m)
{
    queue<int> q;
    int o, o1;
     srand(static_cast<unsigned int>(time(0)));
     displayMen(m);
     
     cout << "\n An appetizer and main dish have been ordered for you on the house.\n";
     cout << "How many orders would you like? \n";
     cin >> o;
     q.push(o);
     cout << "How many more orders would you like?\n";
     cin >> o1;
     cout << "Your " << o << " dish/s took "<<rand()%30+1 << " minutes to be served";
     cout << "Your " << o1 << " dish/s took "<<rand()%40+1 << " minutes to be served";
    
}

void recc()
{
    stack<string> s;
    string recc;
    cout << "Recommend us your favorite dish  or any suggestions. \n";
    cin >> recc;
    s.push(recc);
    cout << "Recommendations from customers: \n";
    for (int i=0; i < s.size(); i++)
    {
        cout << s.top() << endl;
        s.pop();
    }

}
