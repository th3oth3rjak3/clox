//
// Created by th3oth3rjak3 on 5/19/25.
//

#ifndef CHUNK_H
#define CHUNK_H

#include "value.h"
#include <stdint.h>

/**
 * @brief Operation Codes
 */
typedef enum {
    OP_CONSTANT,
    OP_NIL,
    OP_TRUE,
    OP_FALSE,
    OP_POP,
    OP_GET_LOCAL,
    OP_SET_LOCAL,
    OP_GET_GLOBAL,
    OP_DEFINE_GLOBAL,
    OP_SET_GLOBAL,
    OP_EQUAL,
    OP_GREATER,
    OP_LESS,
    OP_ADD,
    OP_SUBTRACT,
    OP_MULTIPLY,
    OP_DIVIDE,
    OP_NOT,
    OP_NEGATE,
    OP_PRINT,
    OP_JUMP_IF_FALSE,
    OP_JUMP,
    OP_LOOP,
    OP_RETURN,
} OpCode;

/**
 * @brief Represents a chunk of bytecode for the virtual machine
 *
 * A Chunk contains executable bytecode along with associated metadata.
 * It manages its own memory growth and maintains constant pools.
 */
typedef struct {
    /**
     * @brief Current number of instructions in the bytecode array
     *
     * This represents the actual used portion of the code array.
     * Always less than or equal to capacity.
     */
    int count;
    /**
    * @brief Total allocated size of the bytecode array
    *
    * When count reaches this value, the array will grow.
    * Always greater than or equal to count.
    */
    int capacity;
    /**
     * @brief Dynamic array containing the bytecode instructions
     *
     * Each byte represents either an opcode or operand.
     * Owned exclusively by this Chunk (must be freed on destruction).
     */
    uint8_t *code;
    /**
     * @brief Pool of constant values referenced by the bytecode
     *
     * Stores literals and other immutable data used by instructions.
     * Contains its own count/capacity management.
     */
    ValueArray constants;

    /**
     * @brief Line number information for debugging
     *
     * Parallel array to code where each element indicates
     * the source line that generated the corresponding bytecode.
     * Indexes match 1:1 with the code array.
     */
    int *lines;
} Chunk;

/**
 * @brief Initializes a new bytecode chunk
 *
 * Prepares a Chunk structure for use by:
 * - Setting all counters to zero
 * - Allocating initial capacity
 * - Initializing substructures
 *
 * @param[out] chunk Pointer to uninitialized Chunk memory
 *
 * @warning Does not free existing content if chunk was previously used.
 *          Use freeChunk() first for reinitialization.
 */
void initChunk(Chunk *chunk);

/**
 * @brief Frees a previously allocated bytecode chunk.
 *
 * @param[out] chunk Pointer to chunk which must be freed.
 */
void freeChunk(Chunk *chunk);

/**
 * @brief Write bytecode into the chunk.
 *
 * Writes bytecode information to the chunk including
 * the line number where the information originated
 * for error reporting.
 *
 * @param chunk The chunk to write to.
 * @param byte The byte to be written.
 * @param line The line number for the originating source code.
 */
void writeChunk(Chunk *chunk, uint8_t byte, int line);

/**
 * @brief Add a constant value to the chunk.
 * @param chunk The chunk to write the constant to.
 * @param value The value to save in the chunk.
 * @return The index of the newly written value.
 */
int addConstant(Chunk *chunk, Value value);

#endif //CHUNK_H
