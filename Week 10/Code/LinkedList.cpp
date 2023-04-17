#include <iostream>

using namespace std;

template <class T>
class LListNode;

template <class T>
class LList; //class pre-definition


int main(){

}


template <class T>
class LListNode {
	T data;
	LListNode<T>* next;
public:
	LListNode(const T& newData = T(), LListNode<T>* newNext=nullptr) :data(newData), next(newNext) {}
	friend class LList<T>; //ok becuase the class was pre-defined
    // Used so all instances can have access to member functions.
};

template <class T>
class LList {
	LListNode<T>* head;
    int numberOfElements;

public:
    LList() :head(nullptr), numberOfElements(0){}
    LList(const LList &rhs) :head(nullptr){ *this = rhs; }
    ~LList() { clear(); }
    void insertAtHead(T newData);
    bool isEmpty() const{ return head == nullptr; }
    void clear();
    void insertAtEnd(T newData);
    T pop_front();
    T pop_back();


    void insertAtPoint(LListNode<T> *ptr, T newData);
    int size() const {return numberOfElements; }
};


template <class T>
void LList<T>::insertAtHead(T newData){
    LListNode<T> *temp;
    temp = new LListNode<T>(newData);

    temp->next = head;
    head = temp;
    numberOfElements++;
}

template <class T>
void LList<T>::insertAtEnd(T newData){
    if (isEmpty()) {
        insertAtHead(newData);
        return;
    }

    LListNode<T>* temp = new LListNode<T>(newData);
    LListNode<T>* end = head;
    while (end->next != nullptr) end = end->next;

    end->next = temp;
    numberOfElements++;
}

template <class T>
T LList<T>::pop_front(){
    if (isEmpty()) {
        return T();
    }

    T temp = head->data;
    LListNode<T>* oldHead = head;
    head = head->next;

    delete oldHead;
    numberOfElements--;

    return temp;
}

template <class T>
T LList<T>::pop_back(){
    if (isEmpty()) {
        return T();
    }

    LListNode<T>* prev = head;
    LListNode<T>* end = head;
    while (end->next != nullptr) {
        prev = end;
        end = end->next;
    }

    prev->next = nullptr;
    delete end;
    numberOfElements--;
    
    return temp;
}

template <class T>
void LList<T>::clear() {
    if (isEmpty()) return;

    LListNode<T> *temp = head;
    LListNode<T> *deletedNode;
    while (temp != nullptr){
        deletedNode = temp;
        temp = temp->next;

        delete deletedNode;
        numberOfElements--;
    }
    head = nullptr;
}