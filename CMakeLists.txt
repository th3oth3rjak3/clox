cmake_minimum_required(VERSION 3.31)
project(clox C)

set(CMAKE_C_STANDARD 11)

add_executable(clox main.c
        common.h
        compiler.h
        debug.h
        memory.h
        object.h
        scanner.h
        table.h
        value.h
        vm.h
        chunk.h
        chunk.c
        memory.c
        debug.c
        value.c
        vm.c
        compiler.c
        scanner.c
        object.c
        table.c)
