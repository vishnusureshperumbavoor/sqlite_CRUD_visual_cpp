#include <iostream>
#include "sqlite3.h"
using namespace std;

int createConnection()
{
    sqlite3* db;
    char* zErrMsg = 0;
    int rc;

    rc = sqlite3_open("test.db", &db);

    if (rc) {
        cout << "Can't open database: " << endl << sqlite3_errmsg(db);
        return(0);
    }
    else {
        cout << "Opened database successfully\n";
        return 1;
    }
    //sqlite3_close(db);
}