#include <iostream>

template<int ROWS, int COLS>
struct Grid {
    int _rows{ROWS};
    int _cols{COLS};
    char _grid[ROWS][COLS]{};

    struct Row {
        char *_array{nullptr};

        char &operator[](int index) const {
            return _array[index];
        }
    };

    Row operator[](int index) const {
        return {const_cast<char *>(&_grid[index][0])};
    }
};

int main() {

    auto grid = Grid<51, 51>();

    for (int row = 0; row < grid._rows; ++row) {
        for (int col = 0; col < grid._cols; ++col) {
            grid[row][col] = '.';
        }
    }

    for (int col = 0; col < grid._cols; ++col) {
        grid[0][col] = '-';
    }

    for (int row = 0; row < grid._rows; ++row) {
        grid[row][0] = '|';
    }

    for (int row = 0; row < grid._rows; ++row) {
        for (int col = 0; col < grid._cols; ++col) {
            std::cout << grid[row][col];
        }
        std::cout << std::endl;
    }

    return 0;
}