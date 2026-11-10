#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* prev= nullptr;
    Node* next= nullptr;
};
class circ_Doubly{
    public:
    Node* head= nullptr;
    void insert_at_begin(int data){
        Node* n= new Node;
        n->data=data;
        if(head==nullptr){
            n->prev=n;
            n->next=n;
            head=n;
            return;
        }
        else{
            Node*tail=head->prev;
            n->next= head;
            n->prev=tail;
            head->prev=n;
            tail->next=n;
            head=n;
            return;
        }
    }
    void insert_at_end(int data){
        Node* n= new Node;
        n->data=data;
        if(head==nullptr){
            n->prev=n;
            n->next=n;
            head=n;
            return;
        }
        else{
            Node*tail=head->prev;
            n->next= head;
            n->prev=tail;
            head->prev=n;
            tail->next=n;
            return;
        }
    }
    void insert_at_pos(int pos, int data){
        if (pos!=0 && head==nullptr){
            cout<<"INVALID POSITION!";
            return;
        }
        else if(pos==0 && head==nullptr){
            Node* n= new Node;
            n->data=data;
            n->prev=n;
            n->next=n;
            head=n;
            return;
        }
        if(pos==0 && head!=nullptr){
            insert_at_begin(data);
            return;
        }
        if(pos!=0 && head!=nullptr){
            Node* temp=head;
            int count=0;
            while(count<pos-1){
                temp=temp->next;
                count++;
                if(temp==head){
                    cout<<"INVALID POSITION!";
                    return;
                }
            }
                Node* n= new Node;
                n->data=data;
                Node* pre=temp;
                Node* nex=temp->next;
                n->next= nex;
                n->prev=pre;
                pre->next=n;
                nex->prev=n;
                return;
                }   
            }
    void display(){
        if (head==nullptr){
            cout<<"List is empty!";
            return;
        }
        Node* temp=head;
        cout<<"CIRCULAR LINKED LIST:"<<endl;
        cout<<temp->data<<"(head)"<< " -> ";
        temp=temp->next;
        while(temp!=head){
            cout<<temp->data<< " -> ";
            temp=temp->next;
        }
        cout<<temp->data<<"(head)"<<endl;
    }
    ~circ_Doubly(){
        if (head==nullptr) return;
        Node* temp=head->next;
        while(temp!=head){
            Node*del=temp;
            temp=temp->next;
            delete del;
        }
        delete head;
        head=nullptr;
    }
};
int main(){
    circ_Doubly l;
    l.insert_at_pos(2,10);
    l.display();
    l.insert_at_pos(0,20);
    l.display();
    l.insert_at_pos(0,10);
    l.display();
    l.insert_at_pos(1,30);
    l.display();
    l.insert_at_pos(3,40);
    l.display();
    l.insert_at_pos(2,50);
    l.display();
    l.insert_at_pos(2,100);
    l.display();
}