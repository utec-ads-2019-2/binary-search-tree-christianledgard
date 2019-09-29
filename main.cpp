#include <iostream>
#include "tester/tester.h"

using namespace std;

int main(int argc, char *argv[]) {
    cout << "===========================================================" << endl;
    cout << "Binary Search Tree Practice" << endl;
    cout << "===========================================================" << endl << endl;

    Tester::execute();
    /*auto tree = new BSTree<int>();

    int nums[] = {45,25,15,35,75};

    for(int i : nums)
        tree->insert(i);

    tree->traversePostOrder(tree->getRoot());

    
    tree->remove(45);
    tree->remove(25);
    tree->remove(15);
   //tree->remove(35);
   //tree->remove(75);


    tree->traversePostOrder(tree->getRoot());

    cout << endl << "Tree Size: " << tree->size() << endl;
    cout << "Tree Height: " << tree->height();*/

    return EXIT_SUCCESS;
}