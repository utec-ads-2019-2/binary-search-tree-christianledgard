#ifndef ITERATOR_H
#define ITERATOR_H

#include <stack>
#include "node.h"

template <typename T> 
class Iterator {
    private:
        Node<T> *current;
        std::stack<Node<T>*> stack;

    public:
        Iterator(): current(nullptr) {
        }

        Iterator(Node<T> *node, bool condition) : current(node){
            if (condition)
                while (node) node = node->right;
            else {
                while (node) {
                    stack.push(node);
                    node = node->left;
                }
            }
        }

        Iterator<T>& operator=(const Iterator<T> &other) {
            current = other.current;
            return *this;
        }

        bool operator!=(Iterator<T> other) {
            return current != other.current;
        }

        Iterator<T>& operator++() {
            Node<T> * upperNode = stack.top();
            stack.pop();
            if (upperNode->right) {
                stack.push(upperNode->right);
                while (stack.top()->left) stack.push(stack.top()->left);
            }
            if (stack.empty()){
                current = nullptr;
            } else{
                current = stack.top();
            }

            // No estás retornando el iterador
        }

        Iterator<T>& operator--() {
            // TODO
        }

        T operator*() {
            // Tienes que controlar el caso null con throw
            if (current) return current->data;
        }
};

#endif
