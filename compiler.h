//
// Created by th3oth3rjak3 on 5/19/25.
//

#ifndef COMPILER_H
#define COMPILER_H

#include "object.h"
#include "vm.h"

/**
 * @brief Compile source code into runnable clox code.
 * @param source Source code provided by the user.
 * @return True when compilation is successful, otherwise false.
 */
ObjFunction* compile(const char* source);

#endif //COMPILER_H
