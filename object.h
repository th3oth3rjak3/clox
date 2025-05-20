//
// Created by th3oth3rjak3 on 5/19/25.
//

#ifndef OBJECT_H
#define OBJECT_H

#include "chunk.h"
#include "common.h"
#include "value.h"

#define OBJ_TYPE(value) (AS_OBJ(value)->type)

#define IS_STRING(value) isObjType(value, OBJ_STRING)
#define IS_FUNCTION(value)     isObjType(value, OBJ_FUNCTION)

#define AS_FUNCTION(value)     ((ObjFunction*)AS_OBJ(value))
#define AS_STRING(value) ((ObjString *)AS_OBJ(value))
#define AS_CSTRING(value) (((ObjString *)AS_OBJ(value))->chars)

typedef enum {
    OBJ_FUNCTION,
    OBJ_STRING,
} ObjType;

struct Obj {
    ObjType type;
    Obj *next;
};

typedef struct {
    Obj obj;
    int arity;
    Chunk chunk;
    ObjString* name;
} ObjFunction;

ObjFunction* newFunction();

struct ObjString {
    Obj obj;
    int length;
    char *chars;
    uint32_t hash;
};

/**
 * @brief Copy a string.
 * @param chars The pointer to the start of the string.
 * @param length The length of the string.
 * @return The copied string.
 */
ObjString *copyString(const char *chars, int length);

/**
 * @brief Print an object's representation to the console.
 * @param value The value which has been determined to be an object.
 */
void printObject(Value value);

ObjString *takeString(char *chars, int length);

static inline bool isObjType(Value value, ObjType type) {
    return IS_OBJ(value) && AS_OBJ(value)->type == type;
}


#endif //OBJECT_H
