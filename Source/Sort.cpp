/*
 * =====================================================================================
 *
 *       Filename:  Sort.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  Saturday 04 February 2017 12:56:50  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Premvir (https://github.com/keenprogrammer), psc.manit@gmail.com
 *   Organization:  KeenProgrammer
 *
 * =====================================================================================
 */
#include<iostream>

using namespace std;


class Sort {
private :
  int *arr;
  int N;
public :
  Sort(){
    arr = NULL;
    N = 0;
  }
  Sort(int size) {
    arr = new int[size];
    N = size;
    cout<<"Enter "<<N<<" Numbers "<<endl;
    for (int i = 0; i < N; i ++) {
      cin>>arr[i];
    }
  }
  void selectionSort() {
    for (int i = 0; i < N - 1; i ++) {
      for (int j = i + 1; j < N; j++) {
        if (arr[i] > arr[j]) {swap(&arr[i], &arr[j]);}
      }
    }
  }

  void bubbleSort() {
    for (int i = 0; i < N - 1; i ++) {
      for (int j = 0; j < N - i; j++) {
        if (arr[j] > arr[j + 1]) {swap(&arr[j], &arr[j + 1]);}
      }
    }
  }


  void quickSort() {
     quickSort1(0, N);
  }
  void swap(int *val1, int * val2){
   int temp = *val1;
   *val1 = *val2;
   *val2 = temp;
  }
  void print () {
    cout<<endl;
    for (int i = 0; i < N; i ++) cout<<arr[i]<<endl;
  }
private :
  void quickSort1(int low, int high) {
    int indx = 0;
    if (low < high) {
      indx = doPartition(low, high);
      quickSort1(low, indx - 1);
      quickSort1(indx + 1, high);
    }
  }
  int doPartition(int low, int high) {
    int pivot = low;
    int low_i = low;
    int frnt = low + 1; /*start from low + 1 bcz low is pivot*/
    int back = high;

    while (frnt < back) {
      while ((frnt < back) && (arr[frnt] < arr[pivot])) {
          low_i = frnt;
          frnt ++;
      }
      while ((frnt < back) && (arr[back] > arr[pivot])) {
          back --;
      }
      if (frnt < back) {
        swap(&arr[frnt], &arr[back]);
      }
    }
    swap(&arr[low_i], &arr[pivot]);
    return low_i;
  }
};

int main()
{
  Sort obj(10); 
  //obj.selectionSort();
  obj.bubbleSort();
  //obj.quickSort();
  obj.print(); 
 return 0;
}

