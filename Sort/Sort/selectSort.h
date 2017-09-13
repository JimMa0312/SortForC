#pragma once

#include <iostream>

using namespace std;

template <typename T>
void selectSort(T arr[], int n) {
	for (int i = 0; i < n; i++) {
		int index = i;
		for (int j = i+1; j < n; j++) {
			if (arr[index] > arr[j]) {
				index = j;
			}
		}

		swap(arr[i], arr[index]);
	}
}