//
// Created by th3oth3rjak3 on 5/19/25.
//

#ifndef TABLE_H
#define TABLE_H


#include "common.h"
#include "value.h"

typedef struct {
    ObjString *key;
    Value value;
} Entry;

typedef struct {
    int count;
    int capacity;
    Entry *entries;
} Table;

/**
 * @brief Initialize a new table.
 * @param table The table to initialize.
 */
void initTable(Table *table);

/**
 * @brief Free the associated memory from the table.
 * @param table The table to free.
 */
void freeTable(Table *table);

/**
 * @brief Write a key, value pair into the table.
 * @param table The table with the value to be set.
 * @param key The key associated with the value.
 * @param value The value to be written with the key.
 * @return True when set is successful, otherwise false.
 */
bool tableSet(Table *table, ObjString *key, Value value);

void tableAddAll(Table *from, Table *to);

ObjString *tableFindString(Table *table, const char *chars, int length, uint32_t hash);

bool tableGet(Table *table, ObjString *key, Value *value);

bool tableDelete(Table *table, ObjString *key);

#endif //TABLE_H
