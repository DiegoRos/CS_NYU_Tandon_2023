/*
INSTRUCTIONS
In this assignment, it is required that you fill out areas under comments labeled as "TODO" appropriately based on the accompanying directions. 
You are also required to follow any directions accompanying comments such as "NOTE".
You can add/modify code anywhere, with the exception of the provided "main" (which we will use for testing).
You can use the constants RED and BLACK, instead of the ints 0 and 1, when appropriate.
*/

#include <iostream>
#include <math.h> // for asserting height
#include <queue>
#include <cassert>

using namespace std;

#define RED 0
#define BLACK 1

template <class T>
class RBT;

// swapColor swaps the color from red to black and vice versa
int swapColor(int c) {
    return (c==0)?1:0;
}

template <class T>
class RBTNode {
    RBTNode<T> *parent, *left, *right;
    T data;
    int color;

public:
    RBTNode(T data)
        : data(data),
          color(RED),
          parent(nullptr),
          left(nullptr),
          right(nullptr) {}
    friend class RBT<T>;
    void prettyPrint(int indent) const;

    template <class T1>
    friend void swapColor(RBTNode<T1> *);
    template <class T1>
    friend int getColor(RBTNode<T1> *);

    int height() const;
};

template <class T>
int RBTNode<T>::height() const {
    int left_h = 0;
    if (left != nullptr) {
        left_h = left->height();
    }
    int right_h = 0;
    if (right != nullptr) {
        right_h = right->height();
    }
    return 1 + max(left_h, right_h);
}

template <class T>
void RBTNode<T>::prettyPrint(int indent) const {
    if (right != nullptr) {
        right->prettyPrint(indent + 1);
    }
    int margin = indent * 2;
    for (int i = 0; i < margin; ++i) {
        cout << '\t';
    }
    cout << "DATA: " << data << endl;
    for (int i = 0; i < margin; ++i) {
        cout << '\t';
    }
    cout << "COLOR: " << (color == RED ? "RED" : "BLACK") << endl;
    if (left != nullptr) {
        left->prettyPrint(indent + 1);
    }
}

template <class T>
void swapColor(RBTNode<T> *node) {
    if (node != nullptr) {
        node->color = swapColor(node->color);
    }
}

// getColor handles null nodes
template <class T>
int getColor(RBTNode<T> *node) {
    if (node != nullptr) {
        return node->color;
    }
    return BLACK;
}

template <class T>
class RBT {
    RBTNode<T> *root;
    void singleCCR(RBTNode<T> *&point);
    void doubleCR(RBTNode<T> *&point);
    void singleCR(RBTNode<T> *&point);
    void doubleCCR(RBTNode<T> *&point);
    void correctRBTColors(RBTNode<T> *&point);

public:
    RBT() : root(nullptr) {}

    void insert(const T &);
    void insert(const T &, RBTNode<T> *&point, RBTNode<T> *parent);
    void prettyPrint() const { root->prettyPrint(0); }

    int height() const { return root->height(); }
};

template <class T>
void RBT<T>::doubleCCR(RBTNode<T> *&point) { // Same as right left rotation
    singleCR(point->right);
    singleCCR(point);
}

template <class T>
void RBT<T>::doubleCR(RBTNode<T> *&point) { // Same as left right rotation
    singleCCR(point->left);
    singleCR(point);
}

template <class T>
void RBT<T>::singleCR(RBTNode<T> *&point) { // Right Rotation
    RBTNode<T> *grandparent = point;
    RBTNode<T> *parent = point->left;
    // turn the parents right subtree into the grandparent's
    grandparent->left = parent->right;
    if (parent->right) // If parent has a right subtree change parent to grandparent
        parent->right->parent = grandparent;

    parent->parent = grandparent->parent; // Make parent's "parent" be the same as the grandparent
    if (!parent->parent) // If grandparent was the root, update root
        root = parent;
    else{ // If grandparent is not root update the left child of the grandparent to parent
        if (grandparent == grandparent->parent->right)
            grandparent->parent->right = parent;

        else
            grandparent->parent->left = parent;
    }
    
    // Make grandparent the new right subtree of parent
    parent->right = grandparent;
    // Update parent characteristic for grandparent to be parent
    grandparent->parent = parent;
}

template <class T>
void RBT<T>::singleCCR(RBTNode<T> *&point) { // Left Rotation
    RBTNode<T> *grandparent = point;
    RBTNode<T> *parent = point->right;
    
    // turn the parents left subtree into the grandparent's
    grandparent->right = parent->left;
    if (parent->left) // If parent has a left subtree change parent to grandparent
        parent->left->parent = grandparent;

    parent->parent = grandparent->parent; // Make parent's "parent" be the same as the grandparent
    if (!parent->parent) // If grandparent was the root, update root
        root = parent;
    else{ // If grandparent is not root update the left child of the grandparent to parent
        if (grandparent == grandparent->parent->left)
            grandparent->parent->left = parent;

        else
            grandparent->parent->right = parent;
    }

    // Make grandparent the new left subtree of parent
    parent->left = grandparent;
    // Update parent characteristic for grandparent to be parent
    grandparent->parent = parent;
}

template <class T>
void RBT<T>::correctRBTColors(RBTNode<T> *&point) {
    while ((point != root) && (getColor(point->parent) == RED)) {

        if (point->parent == point->parent->parent->left) { // Parent is a left
            RBTNode<T>* uncle = point->parent->parent->right;
            if (getColor(uncle) == RED) { // Uncle is red
                // Change the colors
                swapColor(point->parent);
                swapColor(uncle);
                swapColor(point->parent->parent);
                point = point->parent->parent;
            }
            else { // Uncle is black node.
                if (point == point->parent->right) { // point is a right child
                    // Requires a double clockwise rotation
                    point = point->parent;
                    swapColor(point->parent);
                    swapColor(point->parent->parent);
                    doubleCR(point->parent);
                }
                else { // point is a left 
                    // Requires a clockwise rotation
                    swapColor(point->parent);
                    swapColor(point->parent->parent);
                    singleCR(point->parent->parent);
                }
            }
        }
        else { // Parent is a right
            RBTNode<T>* uncle = point->parent->parent->left;
            if (getColor(uncle) == RED) { // Uncle is red
                // Change the colors
                swapColor(point->parent);
                swapColor(uncle);
                swapColor(point->parent->parent);
                point = point->parent->parent;
            }
            else { // Uncle is black node.
                if (point == point->parent->left) { // point is a left child
                    // Requires a double counterclockwise rotation
                    point = point->parent;
                    swapColor(point->parent);
                    swapColor(point->parent->parent);
                    doubleCCR(point->parent);
                }
                else { // point is a left 
                    // Requires a clockwise rotation
                    swapColor(point->parent);
                    swapColor(point->parent->parent);
                    singleCCR(point->parent->parent);
                }
            }
        }
    }
    if (getColor(root) == RED) swapColor(root);
}

template <class T>
void RBT<T>::insert(const T &toInsert, RBTNode<T> *&point, RBTNode<T> *parent) {
    if (point == nullptr) {               // leaf location is found so insert node
        point = new RBTNode<T>(toInsert); // modifies the pointer itself since *point
                                          // is passed by reference
        point->parent = parent;

        RBTNode<T> *curr_node = point; // curr_node will be set appropriately when walking up the tree
        if (!curr_node->parent) { // Tree was empty and we have to innitialize it.
            swapColor(curr_node);
            root = curr_node;
        }
        else {
            correctRBTColors(curr_node);
        }
    }

    else if (toInsert < point->data) { // recurse down the tree to left to find correct leaf location
        insert(toInsert, point->left, point);
    }

    else { // recurse down the tree to right to find correct leaf location
        insert(toInsert, point->right, point);
    }
}

template <class T>
void RBT<T>::insert(const T &toInsert) {
    insert(toInsert, root, nullptr);
}

// NOTE: DO NOT MODIFY THE MAIN FUNCTION BELOW
int main() {
    RBT<int> b;
    int count = 10;
    for (int i = 0; i < count; i++) {
        b.insert(i);
    }

    b.prettyPrint();
    /* EXPECTED OUTPUT:
                                                                    Data: 9
                                                                    COLOR: RED
                                                    Data: 8
                                                    COLOR: BLACK
                                    Data: 7
                                    COLOR: RED
                                                    Data: 6
                                                    COLOR: BLACK
                    Data: 5
                    COLOR: BLACK
                                    Data: 4
                                    COLOR: BLACK
    Data: 3
    COLOR: BLACK
                                    Data: 2
                                    COLOR: BLACK
                    Data: 1
                    COLOR: BLACK
                                    Data: 0
                                    COLOR: BLACK
    */

    // TEST
    // the below tests the validity of the height of the RBT
    // if the assertion fails, then your tree does not properly self-balance
    int height = b.height();
    assert(height <= 2 * log2(count));
}