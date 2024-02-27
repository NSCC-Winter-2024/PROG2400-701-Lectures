#include <iostream>
#include <iomanip>

struct Node {
    int _data {0};
    Node* _left {nullptr};
    Node* _right {nullptr};
};

class BST {
    Node* _root {nullptr};
 public:
    // recursive insert function
    void insert(int data) {
        insert(data, _root);
    }
    // non-recursive delete function
    void remove(int data) {
        // find the node to delete
        auto node = _root;
        auto parent = (Node *) nullptr;

        // search for the node
        while (node != nullptr) {
            if (data < node->_data) {
                parent = node;
                node = node->_left;
            } else if (data > node->_data) {
                parent = node;
                node = node->_right;
            } else {
                // found the node to delete
                break;
            }
        }

        // did we find the node?
        // if no, exit the function as there is nothing to delete
        if (node == nullptr) return;

        // is the node on the left side or right side of the parent?
        if (parent->_left == node) {
            // the node to delete is on the parent's left side
            parent->_left = nullptr;
        } else if (parent->_right == node) {
            // the node to delete is on the parent's right side
            parent->_right = nullptr;
        }

        // the node is detached from the tree, so we can delete it!
        delete node;

    }
 private:
    // recursive insert
    void insert(int data, Node*& node) {
        if (node == nullptr) {
            node = new Node({data});
        } else if (data < node->_data) {
            // go left in the tree
            insert(data, node->_left);
        } else if (data > node->_data) {
            // go right in the tree
            insert(data, node->_right);
        } else {
            // redundant value
            std::cout << "Node value " << node->_data << " already exists." << std::endl;
        }
    }

    void print_tree(std::ostream& output, Node*& node, int indent) {
        if (node != nullptr) {
            print_tree(output, node->_right, indent + 8);
            output << std::setw(indent) << node->_data << std::endl;
            print_tree(output, node->_left, indent + 8);
        }
    }

    friend std::ostream& operator<<(std::ostream& output, BST& bst);
};

std::ostream& operator<<(std::ostream& output, BST& bst) {
    bst.print_tree(output, bst._root, 0);
    return output;
}

int main() {

    BST bst;

    // Test 1 - insert some nodes
    std::cout << "Test 1 - insert some nodes" << std::endl;
    std::cout << "--------------------------" << std::endl;

    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(2);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);

    std::cout << bst << std::endl;

    // Test 2 - delete a node with no child

    std::cout << "Test 2 - delete a node with no child" << std::endl;
    std::cout << "------------------------------------" << std::endl;

    bst.remove(2);

    std::cout << bst << std::endl;

    return 0;
}