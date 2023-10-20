// SQLite_CRUD.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Header.h"

int main()
{
    createConnection();
    //createTable();
    insertData();
    readData();
    updateData();
    deleteData();
}