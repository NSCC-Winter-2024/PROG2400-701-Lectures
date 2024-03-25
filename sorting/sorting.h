#ifndef _SORTING_H
#define _SORTING_H

#include <span>

void bubble_sort(std::span<int> array);
void selection_sort(std::span<int> array);
void insertion_sort(std::span<int> array);

#endif