#include <iostream>

class DynamicArray {
    int* _nums {nullptr};
    int _size {0};
    int _capacity {0};
public:
    DynamicArray(std::initializer_list<int> nums) {
        for (auto num: nums) {
            // add these numbers to the array
            add(num);
        }
    }
    virtual ~DynamicArray() {
        delete [] _nums;
    }

    void add(int num) {

        // re-allocate some memory to account for new element, if needed
        auto temp = _nums;
        if (_capacity == _size) {
            _nums = new int[_capacity * 2];
        }

        // copy old array elements into new memory block
        for (int i = 0; i < _size; ++i) {
            _nums[i] = temp[i];
        }

        // add the new element to the end of the new memory block
        _nums[_size] = num;

        // delete the old block of memory
        if (_capacity == _size) {
            delete [] temp;
        }
        _size++;
    }

    friend std::ostream& operator<<(std::ostream& output, DynamicArray& array);
};

std::ostream& operator<<(std::ostream& output, DynamicArray& array) {
    for (int i = 0; i < array._size; ++i) {
        std::cout << array._nums[i] << ' ';
    }
    return output;
}

int main() {

    // test 1 - create an array
    DynamicArray nums {1, 2, 3, 4, 5};
    std::cout << nums << std::endl;

    // test 2 - add a number to the array
    nums.add(6);
    std::cout << nums << std::endl;

    return 0;
}