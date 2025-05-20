//
// Created by th3oth3rjak3 on 5/19/25.
//

#ifndef VM_H
#define VM_H

#include "chunk.h"
#include "table.h"
#include "value.h"

/**
 * The maximum number of values that can be stored in the
 * stack at any given time.
 */
#define STACK_MAX 256

/**
 * @brief The virtual machine that will execute program instructions.
 */
typedef struct {
    /**
     * @brief The chunk which contains bytecode instructions.
     */
    Chunk chunk;
    /**
     * @brief The instruction pointer.
     */
    uint8_t *ip;
    /**
     * @brief The virtual machine stack.
     */
    Value stack[STACK_MAX];
    /**
     * @brief The current top of the stack.
     */
    Value *stackTop;
    /**
     * @brief Global variables declarations.
     */
    Table globals;
    /**
     * @brief Interned strings.
     */
    Table strings;

    // TODO: update this comment later.
    Obj *objects;
} VM;

typedef enum {
    INTERPRET_OK, // Everything was successful.
    INTERPRET_COMPILE_ERROR, // There was a compilation error in the scanner/parser/compiler.
    INTERPRET_RUNTIME_ERROR // There was a runtime error in the vm.
} InterpretResult;

/**
 * A global virtual machine used for all bytecode interpretation.
 */
extern VM vm;

/**
 * @brief Initialize the virtual machine.
 */
void initVM();

/**
 * @brief Free the memory associated with the virtual machine.
 */
void freeVM();

/**
 * @brief Interpret the input source code and run the program.
 * @param source The user supplied source code.
 * @return The result of running the code.
 */
InterpretResult interpret(const char *source);


/**
 * @brief Push a new value to the virtual machine stack.
 * @param value The value to push to the stack.
 */
void push(Value value);

/**
 * @brief Pop the top value from the stack.
 * @return The popped value from the top of the stack.
 */
Value pop();

#endif //VM_H
