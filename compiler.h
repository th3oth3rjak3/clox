//
// Created by th3oth3rjak3 on 5/19/25.
//

#ifndef COMPILER_H
#define COMPILER_H

#include "vm.h"

/**
 * @brief Compile source code into runnable clox code.
 * @param source Source code provided by the user.
 * @param chunk The chunk to write to.
 * @return True when compilation is successful, otherwise false.
 */
bool compile(const char *source, Chunk *chunk);

#endif //COMPILER_H
