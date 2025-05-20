//
// Created by th3oth3rjak3 on 5/19/25.
//

#ifndef MEMORY_H
#define MEMORY_H

#include "common.h"
#include "object.h"

/**
 * @brief Calculate the new capacity given its current capacity.
 *
 * This macro assumes a minimum value of 8, and increases subsequently
 * by doubling the current capacity.
 *
 * @param capacity The current capacity.
 */
#define GROW_CAPACITY(capacity) ((capacity) < 8 ? 8 : (capacity)*2)

/**
 * @brief Grow an array by copying elements to a larger array.
 * @param type The type of element in the array.
 * @param pointer The pointer to the start of the array.
 * @param oldCount The current capacity of the array.
 * @param newCount The desired capacity of the new array.
 */
#define GROW_ARRAY(type, pointer, oldCount, newCount)   \
(type *)reallocate(pointer, sizeof(type) * (oldCount),  \
sizeof(type) * (newCount))

/**
 * @brief Free an array and its contents.
 * @param type The type of element in the array.
 * @param pointer The pointer to the start of the array.
 * @param oldCount The capacity of the current array.
 */
#define FREE_ARRAY(type, pointer, oldCount)             \
reallocate(pointer, sizeof(type) * (oldCount), 0)

/**
 * @brief Allocate memory for the given type.
 * @param type The type of element.
 * @param count The number of elements to allocate.
 */
#define ALLOCATE(type, count)                           \
(type *)reallocate(NULL, 0, sizeof(type) * (count))

/**
 * @brief Free allocated memory associated with an element.
 * @param type The type of element to free.
 * @param pointer The pointer to the element.
 */
#define FREE(type, pointer) reallocate(pointer, sizeof(type), 0)

/**
 * @brief Reallocate memory and copy existing elements to a new location.
 * @param pointer The pointer to the item to reallocate.
 * @param oldSize The existing capacity.
 * @param newSize The desired capacity.
 * @return A pointer to the newly allocated memory.
 */
void *reallocate(void *pointer, size_t oldSize, size_t newSize);

/**
 * Free allocated memory associated with objects.
 */
void freeObjects();

#endif //MEMORY_H
