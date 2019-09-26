#ifndef BSTREE_H
#define BSTREE_H

#include "node.h"
#include "iterator.h"

template <typename T> 
class BSTree {
    Node<T> *root;
    size_t treeSize;

    public:
        BSTree() : root(nullptr), treeSize(0) {};

        bool find(T data) { 
            auto temp = root;
            while(temp != nullptr){
                if(temp->data == data)
                    return true;
                else
                    if(data > temp->data)
                        temp = temp->right;
                    else
                        temp = temp->left;
            }
            return false;
        }

        Node<T> * newNode(T data){
            auto * newNode = new Node<T>(data);
            treeSize++;
            return newNode;
        }

        void insert(T data) {
            Node<T> * current = root;
            Node<T> * parent = nullptr;

            if(root == nullptr){
                root = newNode(data);
                return;
            }

            while(current != nullptr){
                parent = current;
                if(data > current->data)
                    current = current->right;
                else
                    current = current->left;
            }

            if(data > parent->data)
                parent->right = newNode(data);
            else
                parent->left = newNode(data);
        }

        void searchNodeandUpdateParrentandCurrent(Node<T> * &current, Node<T> * &parent, T data){
            while (current != nullptr && current->data != data)
            {
                parent = current;
                if (data < current->data)
                    current = current->left;
                else
                    current = current->right;
            }
        }

        void deleteSpecificNode(Node<T> * &NodeToDelete){
            delete NodeToDelete;
            NodeToDelete->right = nullptr;
            NodeToDelete->left = nullptr;
            treeSize--;
        }

        Node<T>* minimoDerecho(Node<T>* current){
            while(current->right != nullptr){
                current = current->right;
            }
            return current;
        }

        bool remove(T data) {
            return removeNodeRecursive(root, data);
        }

        bool removeNodeRecursive(Node<T> * &root , T data) {
            Node<T> * current = root;
            Node<T> * parent = nullptr;
            searchNodeandUpdateParrentandCurrent(current, parent, data);

            if(current == nullptr) return false;

            if(current->right == nullptr and current->left == nullptr){ //En caso de eliminar una hoja
                if(current != root){
                    if(parent->right == current)
                        parent->right = nullptr;
                    else
                        parent->left = nullptr;
                } else {
                    root = nullptr;
                }
                deleteSpecificNode(current);
                return true;
            }

            else if(current->right and current->left) { //En caso de tener 2 hijos
                Node<T>* sucesor  = minimoDerecho(current->left);
                auto temp = sucesor->data;
                removeNodeRecursive(root, sucesor->data);
                current->data = temp;
                return true;
            }
            else{ //En caso de tener un solo hijo
                Node<T>* child = (current->left)? current->left: current->right;
                if (current != root)
                {
                    if (current == parent->left)
                        parent->left = child;
                    else
                        parent->right = child;
                }
                else
                    root = child;
                deleteSpecificNode(current);
                return true;
            }
        }

        size_t size() {
            return treeSize;
        }

        int heightRecursiveCalc(Node<T> * node){
            if(node)
                return heightRecursiveCalc(node->right) > heightRecursiveCalc(node->left) ? heightRecursiveCalc(node->right) + 1 : heightRecursiveCalc(node->left) + 1;
            return 0;
        }

        size_t height() {
            if(root == nullptr)
                return 0;
            else{
                return heightRecursiveCalc(root);
            }
        }

        void traversePreOrder(Node<T> *root) {
            if(root == nullptr) return;
            cout << root->data << " ";
            traverseInOrder(root->left);
            traverseInOrder(root->right);
        }

        void traverseInOrder(Node<T> *root) {
            if(root == nullptr) return;
            traverseInOrder(root->left);
            cout << root->data << " ";
            traverseInOrder(root->right);
        }

        void traversePostOrder(Node<T> *root) {
            if(root == nullptr) return;
            traversePostOrder(root->left);
            traversePostOrder(root->right);
            cout << root->data << " ";
        }

        Iterator<T> begin() {
            return Iterator(root, false);
        }

        Iterator<T> end() {
            return Iterator(root, true);
        }

        Node<T> * getRoot(){
            return this->root;
        }
        ~BSTree() {
            root->killSelf();
        }
};

template<typename T>
Node<T>::Node(T data):left(nullptr), right(nullptr), data(data) {}

#endif
