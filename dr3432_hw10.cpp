#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

template <class T>
class DLListNode;

template <class T>
class DLList;

class Employee{
private:
    unsigned int employeeID;
    double payRate;
    int hoursWorked;
    double payroll;
    string fullName;

public:
    Employee(int newEmployeeID = 0, double newPayRate = 0.0, string newName = ""): 
        employeeID(newEmployeeID), payRate(newPayRate), hoursWorked(0), payroll(0), fullName(newName){}
    
    Employee(const Employee &rhs):
        employeeID(rhs.employeeID), payRate(rhs.payRate), hoursWorked(rhs.hoursWorked), payroll(rhs.payroll), fullName(rhs.fullName){}
    
    void setEmployeeID(int &id) { employeeID = id; }
    void setPayRate(double &pay) { payRate = pay; }
    void setFullName(string &name) { fullName = name; }

    unsigned int getEmployeeID(){ return employeeID; }
    double getpayRate(){ return payRate; }
    int getHoursWorked(){ return hoursWorked; }
    double getpayroll() { return payroll; }

    void calculatePayroll(){ payroll = payRate * hoursWorked; }
    void addHours(int t) { hoursWorked += ((t >= 0) ? t : 0); calculatePayroll(); }

    friend bool operator==(const Employee &lhs, const Employee &rhs){ return (lhs.employeeID == rhs.employeeID); };
    friend bool operator<=(const Employee &lhs, const Employee &rhs){ return (lhs.payroll <= rhs.payroll); }
    friend bool operator>=(const Employee &lhs, const Employee &rhs){ return (lhs.payroll >= rhs.payroll); }
    friend bool operator<(const Employee &lhs, const Employee &rhs){ return (lhs.payroll < rhs.payroll); }
    friend bool operator>(const Employee &lhs, const Employee &rhs){ return (lhs.payroll > rhs.payroll); }

    friend ostream& operator<<(ostream& os, const Employee &e); // If the instance is passed as a normal variable
    friend ostream& operator<<(ostream& os, const Employee* e); // If the instance is passed as a pointer

};

ostream& operator<<(ostream& os, const Employee &e){
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    os << e.fullName << ", $" << setprecision(2) << e.payroll << endl;
    
    return os;
}

ostream& operator<<(ostream& os, const Employee* e){
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
     os << e->fullName << ", $" << setprecision(2) << e->payroll << endl;
    
    return os;
}


template <class T>
class DLListNode {
	T data;
	DLListNode<T>* next;
    DLListNode<T>* prev;
public:
	DLListNode(T& newData = T(), DLListNode<T>* newNext=nullptr, DLListNode<T>* newPrev=nullptr) :data(newData), next(newNext), prev(newPrev) {}
	friend class DLList<T>; //ok becuase the class was pre-defined
    // Used so all instances can have access to member functions.

    T* getDataPtr() { return &data; }
};

template <class T>
class DLList {
private:
	DLListNode<T>* head;
    int numberOfElements;
    DLListNode<T>* split(DLListNode<T>* &newHead);
    DLListNode<T>* merge(DLListNode<T>* &first, DLListNode<T>* &second);
    DLListNode<T>* mergeSortHelper(DLListNode<T>* &newHead);

public:
    DLList() :head(nullptr), numberOfElements(0){}
    DLList(const DLList &rhs): head(nullptr){ *this = rhs; }
    ~DLList() { clear(); }
    void insertAtHead(T& newData);
    bool isEmpty() const{ return head == nullptr; }
    void clear();
    void insertAtEnd(T& newData);
    T pop_front();
    T pop_back();
    int size() const { return numberOfElements; }
    void mergeSort(){head = mergeSortHelper(head); };
    bool isSorted();
    void printListForward();  
    void printListBackward();
    DLListNode<T>* find(T val);
};

// Implement functions to read and write to file
void readEmployees(DLList<Employee>& employees, string employeeFile = "emps.txt");
void readHours(DLList<Employee>& employees, string hoursFile = "hours.txt");
void printPayroll(DLList<Employee>& employees);


int main(){
    DLList<Employee> employees;
    readEmployees(employees);
    readHours(employees);
    printPayroll(employees);
    return 0;
}


template <class T>
void DLList<T>::insertAtHead(T& newData){
    DLListNode<T> *temp;
    temp = new DLListNode<T>(newData);

    temp->next = head;
    temp->prev = nullptr;
    if (head)
        head->prev = temp;
    head = temp;
    numberOfElements++;
}

template <class T>
void DLList<T>::insertAtEnd(T& newData){
    if (isEmpty()) {
        insertAtHead(newData);
        return;
    }

    DLListNode<T>* temp = new DLListNode<T>(newData);
    DLListNode<T>* end = head;
    while (end->next != nullptr) { end = end->next; }
    end->next = temp;
    temp->prev = end;
    numberOfElements++;
}

template <class T>
T DLList<T>::pop_front(){
    if (isEmpty()) {
        return T();
    }

    T temp = head->data;
    DLListNode<T> *oldHead = head;
    head = head->next;
    head->prev = nullptr;

    delete oldHead;
    numberOfElements--;

    return temp;
}

template <class T>
T DLList<T>::pop_back(){
    if (isEmpty()) {
        return T();
    }

    DLListNode<T>* prev = head;
    DLListNode<T>* end = head;
    while (end->next != nullptr) {
        prev = end;
        end = end->next;
    }
    T temp = end->data;
    end->prev = nullptr;
    prev->next = nullptr;
    delete end;
    numberOfElements--;
    
    return temp;
}

template <class T>
void DLList<T>::clear() {
    if (isEmpty()) return;

    DLListNode<T> *temp = head;
    DLListNode<T> *deletedNode;
    while (temp != nullptr){
        deletedNode = temp;
        temp = temp->next;
        if (temp) temp->prev = nullptr;

        delete deletedNode;
        numberOfElements--;
    }
    head = nullptr;
}

template <class T>
DLListNode<T>* DLList<T>::split(DLListNode<T>* &newHead){
    if (!newHead) return nullptr;
    DLListNode<T>* slow = newHead;
    DLListNode<T>* fast = newHead;
    while (fast->next && fast->next->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    DLListNode<T>* temp = slow->next;
    slow->next = nullptr;
    temp->prev = nullptr;
    return temp; 
}

template <class T>
DLListNode<T>* DLList<T>::merge(DLListNode<T>* &first, DLListNode<T>* &second) {
    if (!first) return second;
    if (!second) return first;

    if ((first->data) < second->data) {
        first->next = merge(first->next, second);
        first->next->prev = first;
        first->prev = nullptr;
        return first;
    }
    else {
        second->next = merge(first, second->next);
        second->next->prev = second;
        second->prev = nullptr;
        return second;
    }

}

template <class T>
DLListNode<T>* DLList<T>::mergeSortHelper(DLListNode<T>* &newHead){
    if (!newHead || !newHead->next) return newHead; // Check if list is empty or if it is
    DLListNode<T>* secondHalf = split(newHead);

    newHead = mergeSortHelper(newHead);
    secondHalf = mergeSortHelper(secondHalf);

    return merge(newHead, secondHalf);
}

template <class T>
bool DLList<T>::isSorted() {
    DLListNode<T>* temp = head;
    while (temp && temp->next) {
        if (temp->data > temp->next->data)
            return false;
        
        temp = temp->next;
    }


    return true;
}

template <class T>
void DLList<T>::printListForward() {
    DLListNode<T>* temp = head;
    while (temp) {
        cout << temp->data;
        temp = temp->next;
    }
    cout << endl;
}

template <class T>
void DLList<T>::printListBackward() {
    DLListNode<T>* temp = head;
    while (temp->next) temp = temp->next;
    while (temp) {
        cout << temp->data;
        temp = temp->prev;
    }
    cout << endl;
}

template<class T>
DLListNode<T>* DLList<T>::find(T val) {
    DLListNode<T>* temp = head;

    while (temp) {
        if (temp->data == val) return temp;

        temp = temp->next;
    }

    return nullptr;
}

void readEmployees(DLList<Employee>& employees, string employeeFile) {
    int employeeID;
    double payRate;
    string fullName;
    ifstream infile(employeeFile);

    while (!infile) {
        string newFilename;
		cout << "BAD FILENAME!" << endl;
		cout << "Enter a filename: ";
		cin >> newFilename;
		infile.clear(); // VERY IMPORTANT!
		infile.open(newFilename);
	}

    while (infile >>  employeeID >> payRate) {
        getline(infile, fullName);
        Employee temp (employeeID, payRate, fullName);
        employees.insertAtHead(temp);
    }

}

void readHours(DLList<Employee>& employees, string hoursFile){
    int employeeID, hoursWorked;
    ifstream infile(hoursFile);

    while (!infile) {
        string newFilename;
		cout << "BAD FILENAME!" << endl;
		cout << "Enter a filename: ";
		cin >> newFilename;
		infile.clear(); // VERY IMPORTANT!
		infile.open(newFilename);
	}

    while (infile >> employeeID >> hoursWorked){
        DLListNode<Employee>* temp = employees.find(employeeID);
        if (temp == nullptr) continue;

        Employee* dataTemp = temp->getDataPtr();
        dataTemp->addHours(hoursWorked);
        
    }

}
    
void printPayroll(DLList<Employee>& employees) {
    if (!employees.isSorted()) employees.mergeSort();

    cout << "*********Payroll Information*********" << endl;
    employees.printListBackward();
    cout << "********* End payroll **************" << endl << endl;
}
        // first check if the list is already sorted, if it is print and return immediately.
        // If it is not sorted call employees.mergeSort() then print in backwards order.