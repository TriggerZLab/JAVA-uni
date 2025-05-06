#include<iostream>
using namespace std;
//creating node
class Node {
public:
    int value;
    Node* Next;
    Node(int value) {
        this->value = value;
        this->Next = nullptr;
    }
    ~Node() {
        int val = this->value;
        if(this->Next != NULL) {
            delete Next;
            this->Next = NULL;
        }
        cout<<"Memorry free for node with value " <<value<<endl;
    }
};

//crating linked list
class Linked_list {
public:
    Node *head;
    Node *tail;
    Linked_list() {
        head = nullptr;
        tail = nullptr;
    }

// this function used for insert a value in front
    void push_Front(int val) {
        Node *newNode = new Node(val);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->Next = head;
            head = newNode;
        }
    }

    // insert new value at back
    void push_back(int val) {
        Node *newNode = new Node(val);
        if(tail == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->Next = newNode;
            newNode->Next = NULL;
            tail = newNode;
        }
    }

    // insert new value at given position
    void insertAtpos(int pos,int val) {
        if(pos<=0) {
            cout<<"Impossible to insert value at 0"<<endl;
        }
        if(pos ==1) {
            push_Front(val);
            return;
        }
        Node *newNode = new Node(val);
        Node *temp = head;
        int cnt = 1;
        while(cnt != pos - 1) {
            temp = temp->Next;
            cnt++;
        }
        if(temp -> Next == NULL) {
            push_back(val);
            return;
        }
        newNode->Next = temp->Next;
        temp->Next =  newNode;
    }
    void DeleleNode(int pos) {

        if(pos == 1) {
            Node *temp = head;
            head = head->Next;
            temp->Next = NULL;
            delete temp;
        }
        else {
            int cnt = 1;
            Node *current = head;
            Node *previous = NULL;
            while(cnt <= pos - 1) {
                previous = current;
                current = current->Next;
                cnt++;
            }
            previous->Next = current->Next;
            current->Next = NULL;
            delete current;
        }
    }
};

// print the list item
void printList(Linked_list list) {
    Node *temp = list.head;
    while(temp != NULL) {
        cout<<temp->value<<" " ;
        temp = temp->Next;
    }
    cout<<endl;
}

// print the list size
void listSize(Linked_list list) {
    int cnt = 0;
    Node *temp = list.head;
    while(temp != NULL) {
        temp = temp->Next;
        cnt++;
    }
    cout<<"size : "<<cnt<<endl;
}

// print  the middle point of the list.
void middlepoint(Linked_list list) {
    Node *slow= list.head;
    Node *fast = list.head;
    while(fast != NULL && fast->Next != NULL) {
        slow = slow->Next;
        fast = fast->Next->Next;
    }
    cout<<slow->value<<endl;
}

// reverse the list item
void reverse(Linked_list &list) {
    Node *curr = list.head;
    Node *prev = NULL;
    Node *fowd = NULL;
    list.tail = list.head;
    if(curr->Next == NULL || curr == NULL) {
        list.head = curr;
    }
    while(curr != NULL) {
        fowd = curr->Next;
        curr -> Next = prev;
        prev = curr;
        curr = fowd;
    }
    list.head = prev;
}
int main() {
    Linked_list list;
    list.push_Front(10);
    list.push_Front(20);
    list.push_Front(30);
    list.push_back(37);
    list.push_back(46);
    list.insertAtpos(6,16);
    list.insertAtpos(7,39);
    list.push_Front(10);
    printList(list);
    cout<<list.head->value<<endl;
    cout<<list.tail->value<<endl;
    listSize(list);
    middlepoint(list);
    list.DeleleNode(7);
    printList(list);
    cout<<list.head->value<<endl;
    cout<<list.tail->value<<endl;
    listSize(list);
    middlepoint(list);
    printList(list);
    reverse(list);
    printList(list);
    cout<<list.head->value<<endl;
    cout<<list.tail->value<<endl;
}
