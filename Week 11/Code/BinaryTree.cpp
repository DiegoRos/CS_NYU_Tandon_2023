#include <iostream>
#include <queue>


using namespace std;

template <class T>
class BinaryTree;


template <class T>
class BinaryTreeNode {
private:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;
    BinaryTreeNode<T>* parent;

public:
    BinaryTreeNode(T& newData = T(), BinaryTreeNode<T>* newParent=nullptr, BinaryTreeNode<T>* newLeft=nullptr, BinaryTreeNode<T>* newRight=nullptr): data(newData), left(newLeft), right(newRight), parent(newParent) {}
    friend class BinaryTree<T>;
    int getSize() const {
        int cont = 1;
        if (left != nullptr) count += left->getSize();
        if (right != nullptr) count += right->getSize();
        return cont;
    }
};

template <class T>
class BinaryTree {
private:
    BinaryTreeNode<T> *root;

public:
    BinaryTree(): root(nullptr){}
    BinaryTree(const BinaryTree &rhs) { root = rhs.root; }
    ~BinaryTree() { clear(); }
    bool isEmpty() const{ return root == nullptr; }
    void insert(T& newData);
    void clear();
    void printInOrderHelper(BinaryTreeNode<T>* root);
    void printInOrder() {printInOrderHelper(root);}
    void printPreOrderHelper(BinaryTreeNode<T>* root);
    void printPreOrder() {printPreOrderHelper(root);}
    void printPostOrderHelper(BinaryTreeNode<T>* root);
    void printPostOrder() {printPostOrderHelper(root);}
    void printLevelOrder();
    BinaryTreeNode<T>* find(T val);
    void remove(T val);
    void remove(BinaryTreeNode<T>*& val);
};

template <class T>
void BinaryTree<T>::insert(T& newData){
    if (!root) {
        root = new BinaryTreeNode(newData);
        return;
    }
    BinaryTreeNode<T>* temp = root;
    BinaryTreeNode<T>* parent;

    while (temp != nullptr) {
        prev = temp;
        if (newData < temp->data) temp = temp->left;
        else temp = temp->right;
    }

    if (newData < prev->data)
        prev->left = new BinaryTreeNode(newData, prev);

    else
        prev->right = new BinaryTreeNode(newData, prev);
}

template <class T>
void BinaryTree<T>::clear(){

}

template <class T>
void BinaryTree<T>::printInOrderHelper(BinaryTreeNode<T>* root) {
    if (!node) return;
    printInOrderHelper(root->left);
    cout << root->data << ", ";
    printInOrderHelper(root->right);
}

template <class T>
void BinaryTree<T>::printPreOrderHelper(BinaryTreeNode<T>* root) {
    if (!node) return;
    cout << root->data << ", ";
    printPreOrderHelper(root->left);
    printPreOrderHelper(root->right);
}

template <class T>
void BinaryTree<T>::printPostOrderHelper(BinaryTreeNode<T>* root) {
    if (!node) return;
    printPostOrderHelper(root->left);
    printPostOrderHelper(root->right);
    cout << root->data << ", ";
}

template <class T>
void BinaryTree<T>::printLevelOrder(){
    queue<BinaryTreeNode<T>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<T>* tmep = q.front();
        q.pop();
        cout << temp->data << ", ";
        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::find(T val){
    BinaryTreeNode<T>* temp = root;
    while (temp) {
        if (val < temp->data)
            temp = temp->left;

        else if (val > temp->data)
            temp = temp->right;
        
        else 
            return temp;
    }

    return temp;
}

template <class T>
void BinaryTree<T>::remove(BinaryTreeNode<T>*& temp){
    if (!temp->left && !temp->right) { //No children
        if (!temp->parent) root = nullptr;
        else if (temp->parent->left == temp) temp->parent->left = nullptr;
        else temp->parent->right = nullptr;

        delete temp;
    }
    else if (temp->left == nullptr) { //No left children
        BinaryTreeNode<T>* toDelete = temp->right;
        temp->data = toDelete->data;

        temp->left = toDelete->left;
        if (temp->left)
            temp->left->parent = temp;

        temp->right = toDelete->right;
        if (temp->right)
            temp->right->parent = temp;

        delete toDelete;
    }
    else if (temp->right == nullptr) { //No left children
        BinaryTreeNode<T>* toDelete = temp->left;
        temp->data = toDelete->data;
        
        temp->left = toDelete->left;
        if (temp->left)
            temp->left->parent = temp;
            
        temp->right = toDelete->right;
        if (temp->right)
            temp->right->parent = temp;

        delete toDelete;
    }
    else {
        BinaryTreeNode<T>* minOfRight = temp->right;
        while (!minOfRight->left) minOfRight = minOfRight->left;

        temp->data = minOfRight->data;
        remove(minOfRight);
    }
}

template <class T>
void BinaryTree<T>::remove(T val){
    BinaryTreeNode<T>* node = find(val);
    remove(node);
}