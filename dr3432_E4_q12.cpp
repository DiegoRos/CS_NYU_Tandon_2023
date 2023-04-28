#include <iostream>
#include <vector>

using namespace std;

template<class T>
class BST;

template<class T>
class BSTNode;

template <class T>
bool checkInOrder(BST<T>* root, vector<T> check, int& index){
    if (!root) return true;

    if (root->data != check[index++])
        return false;

    bool left = checkInOrder(root->left, check, index);
    bool right = checkInOrder(root->right, check, index);

    return (left && right);
}