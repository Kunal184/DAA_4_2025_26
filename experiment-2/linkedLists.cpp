#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

Node* head = NULL;

void insert(int val){
    Node *newNode = new Node(val);
    if(head == NULL){
        head = newNode;
        return;
    }
    Node *temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = newNode;
}

void display(){
    Node *current = head;
    while(current){
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void deleteNode(int val){
    if(head == NULL) return;

    if(head->data == val){
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node *previous = head;
    Node *current = head->next;

    while(current && current->data != val){
        previous = current;
        current = current->next;
    }

    if(current == NULL) return;

    previous->next = current->next;
    delete current;
}

struct DNode {
    int data;
    DNode* prev;
    DNode* next;

    DNode(int val){
        data = val;
        prev = NULL;
        next = NULL;
    }
};

DNode* dhead = NULL;

void insertD(int val){
    DNode* newNode = new DNode(val);
    if(dhead == NULL){
        dhead = newNode;
        return;
    }
    DNode* temp = dhead;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void displayD(){
    DNode* temp = dhead;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteD(int val){
    if(dhead == NULL) return;

    if(dhead->data == val){
        DNode* temp = dhead;
        dhead = dhead->next;
        if(dhead) dhead->prev = NULL;
        delete temp;
        return;
    }

    DNode* current = dhead->next;
    while(current && current->data != val){
        current = current->next;
    }

    if(current == NULL) return;

    current->prev->next = current->next;
    if(current->next) current->next->prev = current->prev;
    delete current;
}

int main(){
    insert(1);
    insert(2);
    insert(3);
    deleteNode(2);
    display();

    insertD(10);
    insertD(20);
    insertD(30);
    deleteD(20);
    displayD();

    return 0;
}
