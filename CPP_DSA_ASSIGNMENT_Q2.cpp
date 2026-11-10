#include <iostream>
using namespace std;

class Stack{
    public:
    int top=-1;
    string stack[10000];
    bool isEmpty(){
        if(top==-1)
        return true;
        else return false;
    }
    bool isFull(){
        if(top==9999){
            return true;
        }
        else return false;
    }
    void push(string temp){
        if(isFull()){
            cout<<"STACK IS FULL!!";
            return;
        }
        top++;
        stack[top]= temp;
    }
    void pop(){
        if(isEmpty()){
            return;
        }
        top--;
    }
    string peek(){
         if(isEmpty()){
            return "\0";
        }
        return stack[top];
    }
};
string simp_path(string path){
    Stack s;
    string r;
    for(int i=0; i<path.size(); i++){
        if(path[i]=='/'){
            continue;
        }
        string temp;
        while(i<path.size() && path[i]!='/'){
            temp+=path[i];
            i++;
        }
        if(temp=="."){
            continue;
        }
        if (temp==".."){
            if(!s.isEmpty()){
                s.pop();
            }
        }
        else s.push(temp);
    }
    while (!s.isEmpty()){
        r="/"+s.peek()+r;
        s.pop();
    }
    if (r.size()==0){
        return "/";
    }
    return r; 
}
int main(){
    string path;
    cout<<"Enter the path : ";
    cin>>path;
    string result= simp_path(path);
    cout<<"Simplified path: "<<result;
}