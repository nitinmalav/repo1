#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void output(int a[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << a[i] << " ";
  }
}

void bubbleSort(int a[], int size)
{
  for(int i=0; i<size-1; i++)
  { 
    for(int j=0; j<(size-i-1); j++)
    { 
      if(a[j]>a[j+1])
      {
        swap(a[j], a[j+1]);
      }
    }
  } 
}

int main()
{
  int a[] = {5, 2, 6, 1, 8, 4};
  int size = sizeof(a) / sizeof(int);
  bubbleSort(a, size);
  output(a, size);
  return 0;
}