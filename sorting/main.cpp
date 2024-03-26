#include <iostream>
#include <iomanip>
#include <span>
#include <chrono>
#include <numeric>
#include <random>
#include <queue>
#include "sorting.h"

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

std::ostream &operator<<(std::ostream &output, std::queue<int> queue) {
    if (queue.empty()) return output;
    while (queue.size() > 1) {
        auto num = queue.front();
        queue.pop();
        output << num << ",";
    }
    output << queue.front();
    return output;
}

void split(std::queue<int> &in, std::queue<int> &out1, std::queue<int> &out2) {
    auto num_subfiles = 0;

    auto prev = -1;
    while (!in.empty()) {
        // read in record
        auto curr = in.front();
        in.pop();

        // new subfile?
        if (curr < prev) num_subfiles++;

        // write odds and evens
        if (num_subfiles % 2 == 0) {
            out1.push(curr);
        } else {
            out2.push(curr);
        }

        prev = curr;
    }
}

bool elements_in_sublist(auto first, auto second, auto last) {
    return !first.empty() && (first.front() >= last);
}

bool elements_in_column(auto first, auto second, auto last) {
    return !first.empty() && (first.front() >= last) &&
        (second.empty() || (second.front() < last) || (first.front() < second.front()));
}

bool elements_not_in_current_list(auto first, auto second, auto last) {
    return first.empty() || !second.empty() &&
        ((first.front() < last) ||
            ((first.front() >= last) && (second.front() < first.front())));
}

auto merge(std::queue<int> &out, std::queue<int> &in1, std::queue<int> &in2) {
    auto num_subfiles = 0;

    // who starts the process?
    auto &first = in2.empty() || (in1.front() < in2.front()) ? in1 : in2;
    auto &second = first == in1 ? in2 : in1;

    // keep merging while there are records left in either file
    while (!in1.empty() || !in2.empty()) {

        auto last = -1;
        while (elements_in_sublist(first, second, last)) {

            // continue reading from current while part of the same sublist
            do {
                last = first.front();
                first.pop();
                out.push(last);
            } while (elements_in_column(first, second, last));

            // should I switch to other file??
            if (elements_not_in_current_list(first, second, last)) {
                std::swap(first, second);
            }
        }

        num_subfiles++;
    }

    return num_subfiles;
}

void merge_sort(std::span<int> array) {
    // copy array into a queue (the queue simulates a file)
    std::queue<int> merged;
    for (auto num : array) {
        merged.push(num);
    }

    // merge sort
    std::queue<int> split1, split2;
    auto subfiles = 0;
    do {
        // split
        split(merged, split1, split2);

        std::cout << "Split" << std::endl;
        std::cout << "temp1:" << split1 << std::endl;
        std::cout << "temp2:" << split2 << std::endl;

        // merge
        subfiles = merge(merged, split1, split2);

        std::cout << "Merge" << std::endl;
        std::cout << merged << std::endl;

    } while (subfiles != 1);

    // copy back into array (only needed for this demo code)
    auto i = 0;
    while (!merged.empty()) {
        array[i++] = merged.front();
        merged.pop();
    }
}

int main() {

    for (size_t len = 10; len <= 10; len *= 10) {
        std::cout << "len = " << len << std::endl;

        auto nums = new int[len];

//        fill_array({nums, len});
//        track_time("bubble sort", bubble_sort, {nums, len});
//
//        fill_array({nums, len});
//        track_time("selection sort", selection_sort, {nums, len});
//
//        fill_array({nums, len});
//        track_time("insertion sort", insertion_sort, {nums, len});
//        fill_array({nums, len});
//        track_time("bubble sort", bubble_sort, {nums, len});
//
//        fill_array({nums, len});
//        track_time("selection sort", selection_sort, {nums, len});
//
//        fill_array({nums, len});
//        track_time("insertion sort", insertion_sort, {nums, len});

//        fill_array({nums, len});
//        track_time("shell sort", shell_sort, {nums, len});

//        fill_array({nums, len});
//        track_time("quick sort", quick_sort, {nums, len});

        fill_array({nums, len});
        std::cout << join({nums, len}, ',') << std::endl;
        merge_sort({nums, len});
        std::cout << join({nums, len}, ',') << std::endl;

        delete[] nums;
    }

    return 0;
}