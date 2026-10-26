#include <iostream>
#include <cmath>
using namespace std;

void input_array(int &arr, int &n) {
    for (int i=0; i<n; i++) {
        cin>>arr[i];
    }
}
void print_array(int arr, int n) {
    for (int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
}
int search(int arr, int n, int value) {
    for (int i=0; i<n; i++) {
        if (arr[i]=value) return i;
    }
}


