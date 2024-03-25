#include <algorithm>
#include "sorting.h"

void bubble_sort(std::span<int> array) {
    for (int i = 0; i < array.size() - 2; ++i) {
        for (int j = 0; j < array.size() - 1 - i; ++j) {
            // compare adjacent numbers
            if (array[j + 1] < array[j]) {
                // swap the numbers
                std::swap(array[j], array[j + 1]);
            }
        }
    }
}

void selection_sort(std::span<int> array) {
    for (auto i = array.begin(); i < array.end(); ++i) {
        // find the smallest number
        auto min = std::min_element(i, array.end());

        // swap the lowest
        if (*min < *i) {
            std::swap(*min, *i);
        }
    }
}

void insertion_sort(std::span<int> array) {
    for (int i = 1; i < array.size(); ++i) {
        // take the current value
        auto temp = array[i];

        // shuffle values greater than ahead of this value
        auto j = i;
        for (; j > 0 && temp < array[j - 1]; j--) {
            array[j] = array[j - 1];
        }

        // insert value in correct location
        array[j] = temp;
    }
}