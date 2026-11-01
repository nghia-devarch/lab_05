#include "array_2d_utils.h"
#include "format_utils.h"
#include <iostream>
#include <cmath>
using namespace std;

void input_2d(int arr[][MAX_COLS], int rows, int cols) {
    for (int i=0; i<rows; i++)
        for (int j=0; j<cols; j++) {
            cin>>arr[i][j];
        }
}

void print_2d(int arr[][MAX_COLS], int rows, int cols) {
    for (int i=0; i<rows; i++)
        for (int j=0; j<cols; j++) {
            cout<<arr[i][j]<<' ';
        }
}

bool check_exist(int arr[][MAX_COLS], int rows, int cols, int value) {
    for (int i=0; i<rows; i++)
        for (int j=0; j<cols; j++) {
            if (arr[i][j]==value) return 1;
        }
    return 0;
}

long long compute_2d(int arr[][MAX_COLS], int rows, int cols, char op) {
    if (op=='+') {
        int r=0;
        for (int i=0; i<rows; i++)
            for (int j=0; j<cols; j++) {
                r+=arr[i][j];
            }
        return r;
    } else if (op=='*') {
        int r=1;
        for (int i=0; i<rows; i++)
            for (int j=0; j<cols; j++) {
                r*=arr[i][j];
            }
        return r;
    }
    return 1;
}

float compute_mean_2d(int arr[][MAX_COLS], int rows, int cols) {
        int r=0;
        for (int i=0; i<rows; i++)
            for (int j=0; j<cols; j++) {
                r+=arr[i][j];
            }
        return round_to_decimal((float(r)/(rows*cols)),2);
}

int get_max_min_2d(int arr[][MAX_COLS], int rows, int cols, bool max) {
    if (max) {
        int r=arr[0][0];
        for (int i=0; i<rows; i++)
            for (int j=0; j<cols; j++) {
                if (arr[i][j]>r) r=arr[i][j];
            }
        return r;
    } else if (!max) {
        int r=arr[0][0];
        for (int i=0; i<rows; i++)
            for (int j=0; j<cols; j++) {
                if (arr[i][j]<r) r=arr[i][j];
            }
        return r;
    }
    return arr[0][0];
}