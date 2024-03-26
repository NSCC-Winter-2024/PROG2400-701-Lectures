#ifndef _BST_H
#define _BST_H

#include <iostream>
#include <span>

struct Node {
    int _data{0};
    Node *_left{nullptr};
    Node *_right{nullptr};
};

class BST {
    Node *_root{nullptr};
 public:
    ~BST();

    void insert(int data);
    void remove(int data);
    void save_array(std::span<int> array);
 private:

    void save_array(std::span<int> array, Node *&node);
    void insert(int data, Node *&node);
    void delete_tree(Node *node);

    void print_tree(std::ostream &output, Node *&node, int indent);

    friend std::ostream &operator<<(std::ostream &output, BST &bst);
};

std::ostream &operator<<(std::ostream &output, BST &bst);

#endif