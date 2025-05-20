cmake_minimum_required(VERSION 3.31)
project(clox C)

set(CMAKE_C_STANDARD 11)

# Set custom compiler flags
set(CMAKE_C_FLAGS_RELEASE "-O3 -DNDEBUG -s")

# Add your executable
add_executable(clox
        main.c
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
        table.c
)

# Remove debug macros in Release
target_compile_definitions(clox
        PRIVATE
        $<$<CONFIG:Debug>:DEBUG_PRINT_CODE;DEBUG_TRACE_EXECUTION>
)
