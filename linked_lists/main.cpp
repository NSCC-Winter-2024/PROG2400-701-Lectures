#include <iostream>

class LinkedList {
    struct LinkedListNode {
        int _data{-1};
        LinkedListNode *_next{nullptr};
    };

    LinkedListNode *_start{nullptr};
    size_t _size{0};

public:
    [[nodiscard]] size_t size() const { return _size; }

    void add(int data) {
        // create a new node for the chain
        auto new_node = new LinkedListNode();
        new_node->_data = data;

        // is this the first node in the chain?
        if (_start == nullptr) {
            // it is the first!
            // link it to the start pointer
            _start = new_node;
        } else {
            // not the first.

            // look for the end of the chain
            auto node = _start;
            auto prev = (LinkedListNode *) nullptr;

            while (node != nullptr) {
                prev = node;
                node = node->_next;
            }

            // attach new node to the end of the chain
            if (prev != nullptr) {
                prev->_next = new_node;
            }
        }
        // increase the number of total nodes
        _size++;
    }

    /// inserts a node in an existing chain
    /// \param data the data to insert
    /// \param index the location to insert to
    void insert(int data, int index) {

        if (index > _size) throw std::invalid_argument("invalid index");

        // if inserting at the end of the chain, send to the 'add' function
        if (index == _size) return add(data);

        // create the new node
        auto node = new LinkedListNode();
        node->_data = data;

        // find the position to insert the node
        auto curr = _start;
        auto prev = (LinkedListNode *) nullptr;

        for (auto i = 0; curr != nullptr && i < index; ++i) {
            prev = curr;
            curr = curr->_next;
        }

        // insert the node
        if (prev == nullptr) {
            // inserting at the start of the chain
            node->_next = _start;
            _start = node;
        } else {
            // inserting somewhere else in the chain
            node->_next = prev->_next;
            prev->_next = node;
        }
        // increase the total number of nodes
        _size++;
    }

    /// delete a node in the chain
    /// \param data delete the node with data as its value
    void remove(int data) {

        auto node = _start;
        auto prev = (LinkedListNode *) nullptr;

        // find the node to delete
        while (node != nullptr && node->_data != data) {
            prev = node;
            node = node->_next;
        }

        // did I find the node to delete?
        if (node != nullptr) {
            // we found it!

            // am I deleting the first node?
            if (prev == nullptr) {
                // yes I am!
                _start = node->_next;
            } else {
                // nope. it's a node in the middle
                prev->_next = node->_next;
            }

            delete node;
            _size--;
        }
    }

    friend std::ostream &operator<<(std::ostream &output, LinkedList &list);
};

std::ostream &operator<<(std::ostream &output, LinkedList &list) {
    auto node = list._start;

    while (node != nullptr) {
        std::cout << node->_data << " ";
        node = node->_next;
    }
    return output;
}

int main() {

    auto list = LinkedList();

    // test 1 - add some numbers to the linked list
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);

    std::cout << "Test 1 - adding nodes" << std::endl;
    std::cout << "---------------------" << std::endl;
    std::cout << list << std::endl;

    // test 2 - insert node at the start of an existing chain
    list.insert(0, 0);

    std::cout << "Test 2 - insert node at the start" << std::endl;
    std::cout << "---------------------------------" << std::endl;
    std::cout << list << std::endl;

    // test 3 - insert node at the start of an existing chain
    list.insert(6, 1);

    std::cout << "Test 3 - insert node in the middle" << std::endl;
    std::cout << "----------------------------------" << std::endl;
    std::cout << list << std::endl;

    // test 4 - insert node at the end of an existing chain
    list.insert(7, 7);

    std::cout << "Test 4 - insert node at the end" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    std::cout << list << std::endl;

    // test 5 - delete node at the start of the chain
    list.remove(0); // remove the first zero in the chain

    std::cout << "Test 5 - delete the first node" << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << list << std::endl;

    // test 6 - delete node in the middle of the chain
    list.remove(3);

    std::cout << "Test 6 - delete a middle node" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << list << std::endl;

    // test 7 - delete node at the end of the chain
    list.remove(7);

    std::cout << "Test 7 - delete end node" << std::endl;
    std::cout << "------------------------" << std::endl;
    std::cout << list << std::endl;

    return 0;
}