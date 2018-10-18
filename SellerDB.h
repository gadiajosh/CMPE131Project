//
//  SellerDB.h
//  CmpNGO
//
//  Created by Josh Gadia on 10/17/18.
//  Copyright © 2018 Josh Gadia. All rights reserved.
//

#ifndef SellerDB_h
#define SellerDB_h

#include "Seller.h"

class SellerDB
{
private:
    Seller* dbPtr;
    int max_size;
    int size;
    
public:
    SellerDB();
    void load(string);
    void display();
    void add();
    void append();
};

#endif /* SellerDB_h */
