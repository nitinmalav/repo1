#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> a)
{
    for(int i=0; i<a.size(); i++)
     {
         cout<<a[i]<<" ";
     }
     cout<<endl;
}

void insertionSort(int n, vector<int> arr) {
     for(int i=1; i<n; i++)
     {  if(arr[i]<arr[i-1]) 
        {   swap(arr[i], arr[i-1]);
            for(int j=i; j>0; j--)
               { 
                 if(arr[j]<arr[j-1]) swap(arr[j],arr[j-1]);
               }
        }
        printArray(arr);   
     }   
}

int main(){
    vector<int> a = {3,4,7,5,6,2,1}; 
    int n = a.size();
    insertionSort(n,a);
}