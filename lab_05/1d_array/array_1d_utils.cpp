#include "array_1d_utils.h"
#include <iostream>
#include <cmath>
using namespace std;

void input_array(int arr[], int n) {
    for (int i=0; i<n; i++) cin>>arr[i];
}

void print_array(int arr[], int n) {
    for (int i=0; i<n; i++) cout<<arr[i]<<" ";
}

int search(int arr[], int n, int value) {
    for (int i=0; i<n; i++) if (arr[i]==value) return i;
    return -1;
}

bool add_at_index(int arr[], int& n, int value, int index) {
    if ((0>index)||(index>n)) return false;
    for (int i=n; i>index; i--) arr[i]=arr[i-1];
    arr[index]=value; n++;
    return true;
}

bool remove_at_index(int arr[], int& n, int index) {
    if ((0>index)||(index>=n)) return false;
    for (int i=index; i<n-1; i++) arr[i]=arr[i+1];
    n--;
    return true;
}
