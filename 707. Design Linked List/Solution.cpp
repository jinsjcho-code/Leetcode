#include <bits/stdc++.h>
using namespace std;

class MyLinkedList {
private:
    struct Node {
        int val;
        Node* prev;
        Node* next;
        Node(int v): val(v), prev(nullptr), next(nullptr) {}
    };
    Node* head;
    int size;

public:
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }
    
    int get(int index) {
        if (index <0 || index >= size) return -1;
        
        Node* current = head;

        for (int i=0 ; i <index ; i++) {
            current = current->next;
        }

        return current->val;
    }
    
    void addAtHead(int val) {
        Node* newnode = new Node(val);
        
        newnode->next = head;

        if (head) {
            head->prev = newnode;
        }
        head=newnode;
        size++;
    }
    
    void addAtTail(int val) {
        Node* newnode = new Node(val);

        if (!head) {
            head = newnode;
            size++;
            return;
        }

        Node* current = head;
        
        while (current->next!=nullptr) {
            current = current->next;
        } 

        newnode->prev = current;
        current->next = newnode;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > size) return;

        else if (index==0) addAtHead(val);
        else if (index==size) addAtTail(val);
        else {
            Node* newnode = new Node(val);
            Node* current = head;
            
            for (int i = 0 ; i<index-1 ; i++) {
                current = current->next;
            }
            newnode->next = current->next;
            newnode->prev = current;
            current->next->prev = newnode;
            current->next = newnode;
            size++;
        }
    }
    
    void deleteAtIndex(int index) {
        if (index <0 || index >= size) return;
        
        Node* current = head;

        for (int i=0 ; i <index ; i++) {
            current = current->next;
        }

        if (current->prev) { // current is not head
            current->prev->next = current->next;
        }
        else // current is head
            head = current->next;

        if (current->next) { 
            current->next->prev = current->prev;
        }
  
        delete current;
        size--;
    }
};

int main() {
    MyLinkedList lst;
    lst.addAtHead(10);        // [10]
    lst.addAtTail(20);        // [10, 20]
    lst.addAtTail(30);        // [10, 20, 30]
    lst.addAtIndex(1, 15);    // [10, 15, 20, 30]
    cout << lst.get(0) << " " << lst.get(1) << " "
         << lst.get(2) << " " << lst.get(3) << endl;  // 10 15 20 30

    lst.deleteAtIndex(0);     // [15, 20, 30]  (head 삭제)
    cout << lst.get(0) << endl;                       // 15

    lst.deleteAtIndex(2);     // [15, 20]      (마지막 삭제)
    cout << lst.get(0) << " " << lst.get(1) << endl;  // 15 20

    cout << lst.get(5) << endl;                       // -1 (범위 밖)
    return 0;
}


/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */