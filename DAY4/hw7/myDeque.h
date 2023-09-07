//
// Created by Reaper on 2023/9/7.
//

#ifndef HW7_MYDEQUE_H
#define HW7_MYDEQUE_H
#include "iostream"
using namespace std;

template<class T>
class myDeque {
public:
    myDeque() = default;

    ~myDeque() {
        while (head != nullptr) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    };

    myDeque(const myDeque &other) {
        //拷贝构造函数
        if (other.head != nullptr) {
            Node *temp = other.head;
            head = new Node;
            head->data = temp->data;
            head->next = nullptr;
            head->back = nullptr;
            tail = head;
            temp = temp->next;
            size++;
            while (temp != nullptr) {
                Node *newNode = new Node;
                newNode->data = temp->data;
                newNode->next = nullptr;
                newNode->back = tail;
                tail->next = newNode;
                tail = newNode;
                temp = temp->next;
                size++;
            }
        } else {
            head = nullptr;
            tail = nullptr;
        }
    };

    T &front() {
        return head->data;
    };

    T &back() {
        return tail->data;
    };

    void push_back(const T &value) {
        if (head == nullptr) {
            head = new Node;
            head->data = value;
            head->next = nullptr;
            head->back = nullptr;
            tail = head;
        } else {
            Node *newNode = new Node;
            newNode->data = value;
            newNode->next = nullptr;
            newNode->back = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    };

    void push_front(const T &value) {
        if (head == nullptr) {
            head = new Node;
            head->data = value;
            head->next = nullptr;
            head->back = nullptr;
            tail = head;
        } else {
            Node *newNode = new Node;
            newNode->data = value;
            newNode->next = head;
            newNode->back = nullptr;
            head->back = newNode;
            head = newNode;
        }
        size++;
    };

    void pop_back() {
        if (head == nullptr) {
            return;
        } else if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            Node *temp = tail;
            tail = tail->back;
            tail->next = nullptr;
            delete temp;
        }
        size--;
    };

    void pop_front() {
        if (head == nullptr) {
            return;
        } else if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            Node *temp = head;
            head = head->next;
            head->back = nullptr;
            delete temp;
        }
        size--;
    };

    int getSize() {
        return size;
    };

    void print() {
        Node *temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    };

    template<typename X>
    void assign(X first, X last) {
        while (head != nullptr) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;//清空原来的链表
        size = 0;
        while (first != last) {
            push_back(*first);
            first++;
        }
    };

private:
    struct Node {
        T data;
        Node *next;
        Node *back;
    };
    Node *head = nullptr;
    Node *tail = nullptr;
    int size = 0;
};


#endif
