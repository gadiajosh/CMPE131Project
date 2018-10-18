//
//  Seller.cpp
//  CmpNGO
//
//  Created by Josh Gadia on 10/17/18.
//  Copyright © 2018 Josh Gadia. All rights reserved.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include <ctime>

using namespace std;

#include "Seller.h"
#include "SellerDB.h"

SellerDB::SellerDB()
{
    max_size = 100;
    size = 0;
    dbPtr = new Seller[max_size];
}

void SellerDB::load(string list)
{
    string items, times, line;
    int prices, conditions;
    ifstream fin;
    
    // Declaring argument for time()
    time_t tt;
    
    // Declaring variable to store return value of
    // localtime()
    struct tm * ti;
    
    // Applying time()
    time (&tt);
    
    // Using localtime()
    ti = localtime(&tt);
    
    // cout << "Current Day, Date and Time is = "
    times = asctime(ti);
    

    
    // open file
    fin.open(list);
    if (!fin.good()) throw "I/O Error";
    
    // goes through file while input is valid
    while (fin.good())
    {
        // gets lines from file
        getline(fin, line);
        if(line.empty()) break;
        
        stringstream(line) >> items >> prices >> conditions >> times;
        
        // initialize database with file info
        dbPtr[size].item = items;
        dbPtr[size].price = prices;
        dbPtr[size].condition = conditions;
        dbPtr[size].time = asctime(ti);
        size++;
        
        // checks if database is full
        if (size == max_size)
        {
            cout << "Database is full.\n";
            break;
        }
    }
    
    // close file
    fin.close();
    
    cout << "Load successful!\n";
    
}

void SellerDB::display()
{
    for (int i = 0; i < size; i++)
        cout <<"Item Name:" << "\t" << dbPtr[i].item << "\n" "Price: " << "\t" << dbPtr[i].price << "\n" << "Condition: " << "\t" << dbPtr[i].condition << "/10" << endl << "Date Posed: " << dbPtr[i].time << "----------------------------------\n" << endl;

}

/*void EmployeeDB::Delete(int em)
{
    int index = -1;
    
    // find index where employee name is located
    for (int i = 0; i < size; i++)
    {
        // checks if input name matches employee in database
        if (dbPtr[i].ID == em)
        {
            index = i;
            break;
        }
    }
    
    // return if employee not found
    if (index == -1)
    {
        cout << "ID#: " << em << " was not found in database.\n";
        return;
    }
    
    // moves employees down array
    for (int i = index; i < size; i++)
        dbPtr[i] = dbPtr[i + 1];
    
    // decrease size by 1
    size--;
    
    cout << "Employee successfully deleted.\n";
    
}

void EmployeeDB::increaseSalary(int em)
{
    int index = -1;
    
    // find index where employee name is located
    for (int i = 0; i < size; i++)
    {
        // checks if input name matches employee in database
        if (dbPtr[i].ID == em)
        {
            index = i;
            break;
        }
    }
    
    // return if employee not found
    if (index == -1)
    {
        cout << "ID#: " << em << " was not found in database.\n";
        return;
    }
    
    // increase employees salary by $1000
    dbPtr[index]++;
    
    cout << "Salary raise complete.\n";
}
 */

void SellerDB::add()
{
    string items, times;
    int prices, conditions;
    
    cout << "Enter name of item: ";
    cin >> items;
    cout << "Enter price: ";
    cin >> prices;
    cout << "Enter the condition of the item (out of ten): ";
    cin >> conditions;
    
    // Declaring argument for time()
    time_t tt;
    
    // Declaring variable to store return value of
    // localtime()
    struct tm * ti;
    
    // Applying time()
    time (&tt);
    
    // Using localtime()
    ti = localtime(&tt);
    
   // cout << "Current Day, Date and Time is = "
    times = asctime(ti);
    
    
    
    
    dbPtr[size].item = items;
    dbPtr[size].price = prices;
    dbPtr[size].condition = conditions;
    dbPtr[size].time = times;
    size++;

}

void SellerDB::append()
{
    ofstream fout;
    fout.open("Seller.txt");
    
    for (int i = 0; i < size; i++)
        fout << dbPtr[i].item << '\t' << dbPtr[i].price << '\t' << dbPtr[i].condition << '\t' << dbPtr[i].time << '\n'  ;
    
    cout << "\n Item(s) posted.\n";
}
