#include "array_1d_utils.h"
#include "lab_05/utils/format_utils.h"
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
long long compute_array(int arr[], int n, char op = '+') {
    if (op='+') 
    {long long s=0;
    for (int i=1; i<n; i++) {
        s+=arr[i];
    }
    return s;}
    else 
    {long long s=0;
    for (int i=1; i<n; i++) {
        s*=arr[i];
    }
    return s;}
}

float compute_mean(int arr[], int n) {
    float r=0;
    for (int i=1; i<n; i++) {
        r+=(arr[i]/n);
    }
    return round_to_decimal(r, 2);
}

// true tang dan false giam dan
void sort(int a[], int n, bool G) {
    if (G) {
        for (int i=0; i<n-1;i++) 
            for (int j=i+1; j<n; j++) 
                if (a[i]>a[j]) {int t=a[i]; a[i]=a[j]; a[j]=t;} }
    else if (not G) {
        for (int i=0; i<n-1;i++) 
            for (int j=i+1; j<n; j++) 
                if (a[i]<a[j]) {int t=a[i]; a[i]=a[j]; a[j]=t;} }
}

float compute_median(int arr[], int n) {
    if (n%2==1) return arr[n/2+1];
    else {
        sort(arr, n, 1);
        return ((arr[n/2]+arr[n/2+1])/2);
    }
}

int get_max_min(int arr[], int n, bool max = true) {
    sort(arr, n, 1);
    if (max) return arr[n-1]; else return arr[0];
}

void sort_ascending(int arr[], int n) {
    sort(arr, n, 1);
}

void sort_descending(int arr[], int n) {
    sort(arr, n, 0);
}




