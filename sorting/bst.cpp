#include <iomanip>
#include "bst.h"

BST::~BST() {
    delete_tree(_root);
}

// recursive insert function
void BST::insert(int data) {
    insert(data, _root);
}
// non-recursive delete function
void BST::remove(int data) {
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

    // see if we are dealing with a node that has two children
    if (node->_left != nullptr && node->_right != nullptr) {
        // once confirmed, locate a successor

        // start by travelling the left path of our node
        auto successor = node->_left;

        // then, take the right path as far as possible
        parent = node;
        while (successor->_right != nullptr) {
            parent = successor;
            successor = successor->_right;
        }

        // copy data from successor into the node we wanted to delete
        node->_data = successor->_data;

        // change the node we want to delete to the successor
        node = successor;
    }

    // determine which side (left or right) our child is on

    // start by assuming we have a left child
    auto child = node->_left;

    // if no left child, then assume a right child
    if (child == nullptr) {
        child = node->_right;
    }

    // is the node on the left side or right side of the parent?
    if (parent == nullptr) {
        // the root node!
        _root = child;
    } else if (parent->_left == node) {
        // the node to delete is on the parent's left side
        parent->_left = child;
    } else if (parent->_right == node) {
        // the node to delete is on the parent's right side
        parent->_right = child;
    }

    // the node is detached from the tree, so we can delete it!
    delete node;
}

void BST::save_array(std::span<int> array) {
    save_array(array, _root);
}

void BST::save_array(std::span<int> array, Node *&node) {
    static int i = 0;

    if (node != nullptr) {
        save_array(array, node->_left);
        array[i++] = node->_data;
        save_array(array, node->_right);
    }
}

// recursive insert
void BST::insert(int data, Node *&node) {
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
        //std::cout << "Node value " << node->_data << " already exists." << std::endl;
    }
}

// recursive delete
void BST::delete_tree(Node *node) {
    if (node != nullptr) {
        delete_tree(node->_left);
        delete_tree(node->_right);

        delete node;

        node = nullptr;
    }
}

void BST::print_tree(std::ostream &output, Node *&node, int indent) {
    if (node != nullptr) {
        print_tree(output, node->_right, indent + 8);
        output << std::setw(indent) << node->_data << std::endl;
        print_tree(output, node->_left, indent + 8);
    }
}

std::ostream &operator<<(std::ostream &output, BST &bst) {
    bst.print_tree(output, bst._root, 0);
    return output;
}