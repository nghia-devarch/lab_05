#ifndef ARRAY_1D_UTILS_H
#define ARRAY_1D_UTILS_H

void input_array(int arr[], int n);

void print_array(int arr[], int n);

int search(int arr[], int n, int value);

bool add_at_index(int arr[], int& n, int value, int index);

bool remove_at_index(int arr[], int& n, int index);

#endif