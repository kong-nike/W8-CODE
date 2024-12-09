#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include <string>
#include <queue>
#include "Node.h"

class BinarySearchTree {
private:
    Node* root;

    void insert(Node*& node, int newValue) {
        if (node == nullptr) {
            node = new Node(newValue);
        } else if (newValue < node->data) {
            insert(node->left, newValue);
        } else if (newValue > node->data) {
            insert(node->right, newValue);
        }
    }

    bool search(Node* node, int key) const {
        if (node == nullptr) return false;
        if (node->data == key) return true;
        if (key < node->data) return search(node->left, key);
        return search(node->right, key);
    }

    Node* findMin(Node* node) const {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    void deleteNode(Node*& node, int value) {
        if (node == nullptr) return;

        if (value < node->data) {
            deleteNode(node->left, value);
        } else if (value > node->data) {
            deleteNode(node->right, value);
        } else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                node = nullptr;
            } else if (node->left == nullptr) {
                Node* temp = node;
                node = node->right;
                delete temp;
            } else if (node->right == nullptr) {
                Node* temp = node;
                node = node->left;
                delete temp;
            } else {
                Node* temp = findMin(node->right);
                node->data = temp->data;
                deleteNode(node->right, temp->data);
            }
        }
    }

    void levelOrder(Node* node, std::string& result) const {
        if (node == nullptr) return;

        std::queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            result += std::to_string(current->data) + " ";
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
    }

    void inOrder(Node* node, std::string& result) const {
        if (node != nullptr) {
            inOrder(node->left, result);
            result += std::to_string(node->data) + " ";
            inOrder(node->right, result);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int newValue) {
        insert(root, newValue);
    }

    bool search(int key) const {
        return search(root, key);
    }

    void deleteNode(int value) {
        deleteNode(root, value);
    }

    std::string levelOrderTraverse() const {
        std::string result;
        levelOrder(root, result);
        return result;
    }

    std::string inOrderTraverse() const {
        std::string result;
        inOrder(root, result);
        return result;
    }
};

#endif
int main() {
    BinarySearchTree bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    std::cout << "In-Order Traversal: " << bst.inOrderTraverse() << std::endl;

    std::cout << "Searching for 40: " << (bst.search(40) ? "Found" : "Not Found") << std::endl;

    bst.deleteNode(50);
    std::cout << "In-Order Traversal after: " << bst.inOrderTraverse() << std::endl;
    std::cout << "Level-Order Traversal: " << bst.levelOrderTraverse() << std::endl;

    return 0;
}