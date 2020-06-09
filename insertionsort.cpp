#include <iostream>
using namespace std;
void print(int arr[], int r){
  int i;
  for(i = 0; i <r; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}
void insertionSort(int arr[], int size){
  int i,j,temp;
  for(i=0; i < size; i++){
    j=i;
    while(j>0&&arr[j-1]>arr[j]){
      temp = arr[j];
      arr[j] = arr[j-1];
      arr[j-1] = temp;
      j--;
      print(arr,size);
    }
  }
}

int main(){
  int arr[] = {5,3,4,2,1};
  int size = sizeof(arr)/sizeof(arr[0]);
  cout<<"Before: ";
  print(arr,size);
  cout<<endl;
  insertionSort(arr,size);
  cout<<"Final: ";
  print(arr,size);
  return 0;
}
