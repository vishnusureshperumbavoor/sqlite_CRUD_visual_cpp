#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"

static int callback(void* NotUsed, int argc, char** argv, char** azColName) {
    int i;
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

int insertData() {
    sqlite3* db;
    char* zErrMsg = 0;
    int rc;
    const char* sql;

    /* Open database */
    rc = sqlite3_open("test.db", &db);

    /* Create SQL statement */
    sql = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) VALUES "  \
        "(9, 'Vishnu', 32, 'California', 20000.00 ), " \
        "(10, 'Suresh', 25, 'Texas', 15000.00 ), "     \
        "(11, 'Elon', 23, 'Norway', 20000.00 )," \
        "(12, 'Musk', 25, 'Rich-Mond ', 65000.00 );";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else {
        fprintf(stdout, "Records created successfully\n");
    }
    sqlite3_close(db);
    return 0;
}