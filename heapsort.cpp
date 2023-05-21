#include<iostream>
using namespace std;
void add_heap(int tree[],int n, int item)
{
    int ptr,par;
    ptr=n;

    while (ptr>0)
    {
        par=(ptr-1)/2;
        if(tree[par]>=item)
        {
            tree[ptr]=item;
            return;
        }
        tree[ptr]=tree[par];
        ptr=par;
    }
    tree[0]=item;
   
}
int del_heap(int tree[],int n)
{
    int item=tree[0];
    int last=tree[n];
    n--;
    int ptr=0,left=1,right=2;
    while(right<=n)
    {
        if(last>=tree[left]  and last >= tree[right])
        {
            tree[ptr]=last;
            return item;
        }
        if(tree[left]>tree[right])
        {
            tree[ptr]=tree[left];
            ptr=left;
        }
        else
        {
            tree[ptr]=tree[right];
            ptr=right;
        }
        left=ptr*2+1;
        right=left+1;
    }
    if(left==n and tree[left]>=last)
    {
        tree[ptr]=tree[left];
        ptr=left;
    }
    tree[ptr]=last;
    return item;
}
void heap_sort(int a[], int n)
{
    for(int i=1;i<n;i++)
    {
        add_heap(a,i,a[i]);
    }
    for(int i=n-1;i>0;i--)
    {
        int item=del_heap(a,i);
        a[i]=item;
    }
}
void output(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int a[]={5,2,3,4,6,1,7};
    int n=sizeof(a)/sizeof(int);
    heap_sort(a,n);
    output(a,n);

}