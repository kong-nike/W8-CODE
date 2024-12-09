#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Node.h"
#include <queue>
class BinarySearchTree {
private:
    Node* root;
public:
    BinarySearchTree() : root(nullptr) {}
    BinarySearchTree(int value) {
        root = new Node(value);
    }
    int calculateHeight() {
        return calculateHeight(root);
    }
    Node* getroot() {
        return root;
    }
    std::string printTree() {
        std::string result = "";
        printTree(root, 0, result);
        return result;
    }

public:
    //exercise 1
    bool search(Node* root, int key){
        //your code here
        if(root == NULL || root->data == key){
            return root;
        }
        if(root->data>key){
            return search(root->left,key);
        }
        if(root->data<key){
            return search(root->right,key);
        }
    }
    void insert(Node* root, int newValue) {
        //your code here
        if(root == NULL){
            Node* root = new Node(newValue);
        }
        if(root->data>newValue){
           return insert(root->left,newValue);
        }
        else if (newValue > root->data) {
           return insert(root->right, newValue);
        }
    }
void findAndReplace(Node*& root, Node*& target) {
    if (root->left != nullptr) {
        findAndReplace(root->left, target);
    } else {
        target->data = root->data; 
        Node* temp = root;        
        root = root->right;      
        delete temp;              
    }
}

void deleteNode(Node*& root, int value) {
    if (root == nullptr) {
        return;
    }

    if (value < root->data) {
        deleteNode(root->left, value); 
    } else if (value > root->data) {
        deleteNode(root->right, value); 
    } else {
  
        if (root->left == nullptr && root->right == nullptr) {
     
            delete root;
            root = nullptr;
        } else if (root->left == nullptr) {
       
            Node* temp = root;
            root = root->right;
            delete temp;
        } else if (root->right == nullptr) {
       
            Node* temp = root;
            root = root->left;
            delete temp;
        } else {
          
            findAndReplace(root->right, root);
        }
    }
}

    std::string levelOrderTraverse() {
        if (root == NULL) {
            return "";
        }
        std::string result = "";
        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            result += std::to_string(current->data) + " ";
            if (current->left != NULL) {
                q.push(current->left);
            }
            if (current->right != NULL) {
                q.push(current->right);
            }
        }
        return result;
    }
private:
    void printTree(Node* node, int depth, std::string& result) {
        if (node == nullptr) return;
        for (int i = 0; i < depth; ++i) {
            result += "- ";
        }
        result += std::to_string(node->data) + "\n";
        printTree(node->left, depth + 1, result);
        printTree(node->right, depth + 1, result);
    }

    int calculateHeight(Node* node) {
        if (node == nullptr) return 0;
        int leftHeight = calculateHeight(node->left);
        int rightHeight = calculateHeight(node->right);
        return std::max(leftHeight, rightHeight) + 1;
    }

};

#endif // BINARYTREE_H