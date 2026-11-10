#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* prev= nullptr;
    Node* next= nullptr;
};

class Doubly{
    public:
    Node* head=nullptr;

    void insert(int data){
        Node* n= new Node;
        n->data=data;
        if (head==nullptr){
            head=n;
            return;
        }
        Node* temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=n;
        n->prev= temp;
    }
    Node* reverse(){
        if (head==NULL){
            cout<<"EMPTY LIST!";
            return nullptr;
        }
        if(head->next==NULL){
            return head;
        }
        Node* temp= head;
        Node* x=nullptr;
        Node* newHead=nullptr;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        newHead=temp;
        while(temp!=NULL){
            x=temp->prev;
            temp->prev=temp->next;
            temp->next=x;
            temp=temp->next;
        }
        head=newHead;
        return head;
    }
    void print(){
        Node* temp= head;
        while(temp!=NULL){
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL"<< endl;
    }
};
int main(){
    Doubly dl;
    dl.insert(1);
    dl.insert(2);
    dl.insert(3);
    dl.print();
    dl.reverse();
    dl.print();
}