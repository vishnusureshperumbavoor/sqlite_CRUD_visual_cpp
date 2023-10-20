#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"

static int callback(void* data, int argc, char** argv, char** azColName) {
    int i;

    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }

    printf("\n");
    return 0;
}


int readData() {
    sqlite3* db;
    char* zErrMsg = 0;
    int rc;
    const char* sql;
    const char* data = "";

    /* Open database */
    rc = sqlite3_open("test.db", &db);

    /* Create SQL statement */
    sql = "SELECT * from COMPANY";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, (void*)data, &zErrMsg);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else {
        fprintf(stdout, "Operation done successfully\n");
    }
    sqlite3_close(db);
    return 0;
}