#include <iostream>
#include <iomanip>
#include <span>
#include <chrono>
#include <numeric>
#include <random>

using clk = std::chrono::high_resolution_clock;

void track_time(auto desc, void(*f)(std::span<int>), std::span<int> nums) {
    auto t = clk::now();
    f(nums);
    const std::chrono::duration<double> span = clk::now() - t;
    std::cout << std::setw(15) << desc << ": ";
    std::cout << "time = " << span.count() << "s" << std::endl;
}

void dump_array(std::span<int> array) {
    for (int i : array) {
        std::cout << std::setw(3) << i;
    }
    std::cout << std::endl;
}

std::string join(const std::span<int> nums, auto ch) {
    return std::accumulate(
        std::next(nums.begin()),
        nums.end(),
        std::to_string(nums[0]),
        [ch](auto s, auto n) {
            return std::move(s) + ch + std::to_string(n);
        });
}

void fill_array(std::span<int> nums) {
    std::random_device rnd;
    std::default_random_engine eng(rnd());
    std::uniform_int_distribution<size_t> dist(1, nums.size());
    std::generate(nums.begin(), nums.end(), [&]() {
        return dist(eng);
    });
}

void bubble_sort(std::span<int> array) {
    for (int i = 0; i < array.size() - 2; ++i) {
        for (int j = 0; j < array.size() - 1 - i; ++j) {
            // compare adjacent numbers
            if (array[j+1] < array[j]) {
                // swap the numbers
                std::swap(array[j], array[j+1]);
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
        for (; j > 0 && temp < array[j-1]; j--) {
            array[j] = array[j-1];
        }

        // insert value in correct location
        array[j] = temp;
    }
}

int main() {

    for (size_t len = 10; len <= 10000; len *= 10) {
        std::cout << "len = " << len << std::endl;

        auto nums = new int[len];

        fill_array({nums, len});
        track_time("bubble sort", bubble_sort, {nums, len});

        fill_array({nums, len});
        track_time("selection sort", selection_sort, {nums, len});

        fill_array({nums, len});
        track_time("insertion sort", insertion_sort, {nums, len});

        delete [] nums;
    }

    return 0;
}