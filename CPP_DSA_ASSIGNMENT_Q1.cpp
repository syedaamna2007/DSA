#include <iostream>
using namespace std;
void next_greater_freq(int arr[], int size){
    int unique=0;
    int num[size];
    int freq[size];
    for (int i=0;i<size; i++){
        bool found=false;
        for (int j=0; j<unique; j++){
            if(arr[i]==num[j] && freq[j]!=0){
                freq[j]++;
                found=true;
            }
        }
        if (found==false){
            num[unique]=arr[i];
            freq[unique]=1;
            unique++;
        }
    }
    for(int i=0; i<unique; i++){
        int ret=-1;
        for(int j=0; j<unique; j++){
            if(freq[j]>freq[i]){
                if (ret==-1 || freq[j]<ret){
                    ret=freq[j];
                }
            }
        }
        if(ret==-1){
            cout<<"No greater frequency exists than frequency of "<<num[i]<<" exist"<<endl;
        }
        else cout<<"Next greater frequency then frequency of "<<num[i]<<" is "<< ret<<endl;
    }
}
int main(){
    cout<<"Enter the sire of your array: ";
    int size;
    cin>>size;
    int* array= new int [size];
    cout<<"Enter the elements of your array (separated by spaces): ";
    for (int i=0; i<size; i++){
        cin>>array[i];
    }
    next_greater_freq(array,size);
    return 0;
}