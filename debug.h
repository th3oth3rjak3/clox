//
// Created by th3oth3rjak3 on 5/19/25.
//

#ifndef DEBUG_H
#define DEBUG_H

#include "chunk.h"

/**
 * @brief Print out disassembly information during debugging.
 * @param chunk The chunk to print details for.
 * @param name The name of the chunk.
 */
void disassembleChunk(Chunk *chunk, const char *name);

/**
 * @brief Disassemble an instruction at the provided offset for debugging.
 * @param chunk The chunk to disassemble.
 * @param offset The offset for the instruction to be disassembled.
 * @return The next offset to disassemble.
 */
int disassembleInstruction(const Chunk *chunk, int offset);

#endif //DEBUG_H
