#include <iostream>
#include <memory>
#include <optional>

//#define _DBG_PRINT(x) ( \
//    #ifdef _DEBUG\
//        std::cout << x << std::endl;\
//    #endif)

struct Data {
    int _id{0};
    float _val{0.0};

    static Data invalid_data() { return {-1, -1.0}; }
};
std::ostream &operator<<(std::ostream &output, const Data &data) {
    output << "ID: " << data._id << ", VAL: " << data._val;
    return output;
}

struct Node {
    Data _data;
    std::unique_ptr<Node> _next{nullptr};
};

class Stack {
    std::unique_ptr<Node> _top{nullptr};
 public:
    void push(Data data) {
        auto node = std::make_unique<Node>(data);
        node->_next = std::move(_top);
        _top = std::move(node);
    }
    std::optional<Data> peek() {
        if (_top == nullptr) return std::nullopt;
        return std::make_optional<Data>(_top->_data);
    }
    void pop() {
        if (_top != nullptr) {
            _top = std::move(_top->_next);
        }
        //_DBG_PRINT("Shouldn't be here...");
    }

    friend std::ostream &operator<<(std::ostream &output, const Stack &stack);
};

std::ostream &operator<<(std::ostream &output, const Stack &stack) {
    auto node = stack._top.get();
    while (node != nullptr) {
        output << node->_data << std::endl;
        node = node->_next.get();
    }
    return output;
}

int main() {

    Stack stack;

    // test 1 - add a node to the stack
    std::cout << "Test 1 - add a node" << std::endl;
    std::cout << "-------------------" << std::endl;
    stack.push({1, 6.67});

    std::cout << stack << std::endl;

    // test 2 - add some more nodes to the stack
    std::cout << "Test 2 - add more nodes" << std::endl;
    std::cout << "-----------------------" << std::endl;
    stack.push({2, 1.1});
    stack.push({3, 2.2});
    stack.push({4, 3.3});
    stack.push({5, 4.4});

    std::cout << stack << std::endl;

    // test 3 - get data from the top of the stack
    std::cout << "Test 3 - get data from top of stack" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << stack.peek().value_or(Data{-1, -1.0}) << std::endl;

    // test 4 - remove a node from the stack
    std::cout << "Test 4 - remove node from stack" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    stack.pop();
    std::cout << stack << std::endl;

    // test 5 - remove all nodes from the stack
    std::cout << "Test 4 - remove node from stack" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    while (stack.peek() != std::nullopt) {
        std::cout << stack << std::endl;
        stack.pop();
    }

    return 0;
}