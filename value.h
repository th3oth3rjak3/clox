//
// Created by th3oth3rjak3 on 5/19/25.
//

#ifndef VALUE_H
#define VALUE_H
#include <stdbool.h>


typedef enum {
    VAL_BOOL,
    VAL_NIL,
    VAL_NUMBER,
    VAL_OBJ,
} ValueType;

typedef struct Obj Obj;
typedef struct ObjString ObjString;

typedef struct {
    ValueType type;

    union {
        bool boolean;
        double number;
        Obj *obj;
    } as;
} Value;

#define IS_OBJ(value) ((value).type == VAL_OBJ)
#define IS_BOOL(value) ((value).type == VAL_BOOL)
#define IS_NIL(value) ((value).type == VAL_NIL)
#define IS_NUMBER(value) ((value).type == VAL_NUMBER)

/**
 * @brief Cast the value to an object.
 * @param value The value to cast to an object.
 */
#define AS_OBJ(value) ((value).as.obj)

/**
 * @brief Cast the value to a boolean.
 * @param value The value to cast as a boolean.
 */
#define AS_BOOL(value) ((value).as.boolean)

/**
 * @brief Cast the value to a number.
 * @param value The value to cast to a number.
 */
#define AS_NUMBER(value) ((value).as.number)

#define OBJ_VAL(object) ((Value){VAL_OBJ, {.obj = (Obj *)object}})
#define BOOL_VAL(value) ((Value){VAL_BOOL, {.boolean = value}})
#define NIL_VAL ((Value){VAL_NIL, {.number = 0}})
#define NUMBER_VAL(value) ((Value){VAL_NUMBER, {.number = value}})

/**
 * @brief ValueArray is a dynamic array of Value types.
 */
typedef struct {
    /**
     * @brief The capacity of the array.
     */
    int capacity;
    /**
     * The number of items in the array.
     */
    int count;
    /**
     * The pointer to the actual items in the array.
     */
    Value *values;
} ValueArray;

/**
 * @brief Initialize the dynamic array.
 * @param array The array to initialize.
 */
void initValueArray(ValueArray *array);

/**
 * @brief Write to the value array.
 * @param array The array to write to.
 * @param value The value to write.
 */
void writeValueArray(ValueArray *array, Value value);

/**
 * @brief Free memory associated with a ValueArray.
 * @param array The array to free.
 */
void freeValueArray(ValueArray *array);

/**
 * @brief Print the representation of a value to the console.
 * @param value The value to print.
 */
void printValue(Value value);

/**
 * @brief Compare two values for equality.
 * @param a The first value to compare.
 * @param b The second value to compare.
 * @return True when both values are equal, otherwise false.
 */
bool valuesEqual(Value a, Value b);

#endif //VALUE_H
