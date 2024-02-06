#include <iostream>

struct Node {
    int _data {-1};
    Node* _next {nullptr};
};

class Queue final {
    Node* _front {nullptr};
    Node* _back {nullptr};
    size_t _size {0};
public:
    void push_back(int num) {
        auto node = new Node({num});

        // are we adding to an empty queue?
        if (_front == nullptr) {
            // yes, the queue is empty
            _front = node;
        } else {
            // no, there are existing nodes
            _back->_next = node;
        }
        _back = node;

        _size++;
    }

    [[nodiscard]] int peek() const {
        return _front != nullptr ? _front->_data : -1;
    }

    [[nodiscard]] size_t size() const {
        return _size;
    }

    void pop_front() {

        if (_size == 0) return;
#if _DEBUG
        if (_size < 0) throw std::range_error("_size is less than zero!");
#endif
        auto node = _front;

        _front = node->_next;

        if (_front == nullptr) _back = nullptr;

        delete node;

        _size--;
    }

    friend std::ostream& operator<<(std::ostream& output, const Queue& queue);
};
std::ostream& operator<<(std::ostream& output, const Queue& queue) {

    auto node = queue._front;
    while (node != nullptr) {
        output << node->_data << " ";
        node = node->_next;
    }
    return output;
}

int main() {

    Queue queue;

    // test 1 : add nodes to the queue
    std::cout << "Test 1: Pushing Nodes" << std::endl;
    std::cout << "---------------------" << std::endl;

    queue.push_back(1);
    queue.push_back(2);
    queue.push_back(3);
    queue.push_back(4);
    queue.push_back(5);

    std::cout << queue << std::endl;

    // test 2 : look at the front of the queue
    std::cout << "Test 2: Peek at a node" << std::endl;
    std::cout << "----------------------" << std::endl;

    std::cout << queue.peek() << std::endl;

    // test 3 : remove a node from the front of the queue
    std::cout << "Test 3: Pop off the first node" << std::endl;
    std::cout << "------------------------------" << std::endl;

    queue.pop_front();
    std::cout << queue << std::endl;

    // test 4 : remove all nodes from the queue
    std::cout << "Test 4: Remove all nodes from the queue" << std::endl;
    std::cout << "---------------------------------------" << std::endl;

    while (queue.size() > 0) {
        std::cout << queue << std::endl;
        queue.pop_front();
    }

    return 0;
}