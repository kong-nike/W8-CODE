#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include <string>
#include <queue>
#include "Node.h"

class BinarySearchTree {
private:
    Node* root;

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int newValue) {
        insert(root, newValue);
    }

    std::string levelOrderTraverse() const {
        if (root == nullptr) return "";

        std::string result;
        std::queue<Node*> q; 
        q.push(root);        

        while (!q.empty()) {
            Node* current = q.front(); 
            q.pop();                  
            result += std::to_string(current->data) + " "; 

           
            if (current->left != nullptr) {
                q.push(current->left);
            }

            if (current->right != nullptr) {
                q.push(current->right);
            }
        }

        return result;
    }

private:
    void insert(Node*& node, int newValue) {
        if (node == nullptr) {
            node = new Node(newValue);
        } else if (newValue < node->data) {
            insert(node->left, newValue);
        } else if (newValue > node->data) {
            insert(node->right, newValue);
        }
    }
};

#endif 
int main() {
    BinarySearchTree bst;

    bst.insert(7);
    bst.insert(5);
    bst.insert(9);
    bst.insert(1);
    bst.insert(6);
    bst.insert(8);
    bst.insert(11);

    std::cout << "Level-Order Traversal: " << bst.levelOrderTraverse() << std::endl;

    return 0;
}