#include <iostream>
using namespace std;
void SubArr_minNmax(int n, int k, int arr[], int minimum[], int maximum[]){
    for(int i=0; i<=n-k; i++){
        int mini=arr[i];
        int maxi=arr[i];
        for (int j=i; j<i+k; j++){
            if(arr[j]>maxi){
                maxi=arr[j];
            }
            if (arr[j]<mini){
                mini=arr[j];
            }
        }
        minimum[i]=mini;
        maximum[i]=maxi;
    }
}
int main(){
    int size, k;
    cout<<"Enter size of your array : ";
    cin>>size;
    cout<<"Enter size of sub-arrays : ";
    cin>>k;
    int *array=new int[size];
    cout<<"Enter elements of your array (separated by spaces "  "): ";
    for(int i=0; i<size; i++){
        cin>>array[i];
    }
    int *Min=new int [size-k+1];
    int *Max=new int [size-k+1];
    SubArr_minNmax(size, k, array, Min, Max);
    for (int i=0; i<=size-k; i++){
        cout<<"Minimum of sub-array number "<<i+1<<" is: "<<Min[i]<<endl;
        cout<<"Maximum of sub-array number "<<i+1<<" is: "<<Max[i]<<endl;
        cout<<"\n\n";
    }
    delete[]array;
    delete[]Min;
    delete[]Max;
    return 0;
}