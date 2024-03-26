#include <algorithm>
#include "bst.h"
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

void shell_sort(std::span<int> array) {
    // determine the gap size
    for (auto gap = array.size() / 2; gap > 0; gap /= 2) {

        // start each smaller array sort
        for (auto start = 0; start < gap; ++start) {

            // perform insertion sort on elements
            for (auto i = start + gap; i < array.size(); i += gap) {
                // take the current value
                auto temp = array[i];

                // shuffle values greater than ahead of this value
                auto j = i;
                for (; j >= gap && temp < array[j - gap]; j -= gap) {
                    array[j] = array[j - gap];
                }

                // insert value in correct location
                array[j] = temp;
            }
        }
    }
}

auto split(std::span<int> array) {
    // choose a pivot point
    auto pivot = array[0];

    // start searching for numbers less than and greater than the pivot
    auto left = 0;
    auto right = array.size() - 1;

    // keep searching until all elements are in their correct spots
    while (left < right) {
        // find an element less than the pivot
        while (right > 0 && pivot < array[right]) right--;

        // find an element greater than the pivot
        while (left < right && pivot >= array[left]) left++;

        // if two were found out of place, swap them
        if (left < right) {
            std::swap(array[left], array[right]);
        }
    }

    // now move the pivot point between the two sublists
    array[0] = array[right];
    array[right] = pivot;

    return right;
}

void quick_sort(std::span<int> array) {
    // assume the array is sorted if it has only 1 element
    if (array.size() <= 1) return;

    // split the array into two sublists
    // returns the index of the pivot
    auto pivot = split(array);

    // sort the left sublist
    quick_sort(array.subspan(0, pivot));

    // sort the right sublist
    quick_sort(array.subspan(pivot + 1, array.size() - pivot - 1));
}

void bst_sort(std::span<int> array) {
    BST bst;

    for (auto num : array) {
        bst.insert(num);
    }

    bst.save_array(array);
}