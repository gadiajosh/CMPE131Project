//
//  main.cpp
//  CmpNGO
//
//  Created by Josh Gadia on 10/17/18.
//  Copyright © 2018 Josh Gadia. All rights reserved.
//

#include <iostream>
using namespace std;

#include "Seller.h"
#include "SellerDB.h"

int main()
{
    SellerDB em;
    int choice;
    string email;
    string file = "Seller.txt";
    
    cout << "Please provide your SJSU E-mail" << endl;
    cin >> email;
    
    if (email.compare(6,5,"sjsu.edu") == 0)
        cout << "still, " << email << " is an apple\n";
       // cout << "This a valid email. \n\n";
    //else
      //  cout << "ERROR. This is not a valid email.\n\n";

    
    do
    {
        
        cout << "\n What would you like to do? \n" << endl;
        cout << "1. Sell an Item." << endl;
        cout << "2. Buy an Item." << endl;
       /* cout << "1: Load information" << endl;
        cout << "2: Display list of items." << endl;
        cout << "3: Add an item to be sold" << endl;
        cout << "4: Post item(s)" << endl;
        cout << "0: Exit program" << endl; */
        
        cout << "\nEnter number from menu: ";
        cin >> choice;
        
        switch (choice)
        {
            case 1:
                em.add();
                em.append();
                break;
                
            case 2:
                em.display();
                break;
               
                
            /*case 1:
                em.load(file);
                break;
                
            case 2:
                em.display();
                break;
                
            case 3:
                em.add();
                break;
                
            case 4:
                em.append();
                break; */
        }
    }while (choice != 0);
    
    return 0;
}
