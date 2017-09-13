#pragma once
#include<cassert>
#include<ctime>
#include<iostream>
#include<string>

using namespace std;

namespace SortTestHelper {
	int* generatRandomArray(int n, int rangel, int rangeR) {
		assert(rangel<rangeR);
		int* arr = new int[n];

		srand(time(NULL));

		for (int i = 0; i < n; i++) {
			arr[i] = rand() % (rangeR - rangel) + rangel;
		}

		return arr;
	}

	int* generatRandomOrderedArray(int n, int swapTimes) {
		int *arr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = i;

			srand(time(NULL));
			for (int i = 0; i < swapTimes; i++) {
				int posx = rand() % n;
				int posy = rand() % n;
				swap(arr[posx], arr[posy]);
			}
		}

		return arr;
	}

	template <typename T>
	void printArray(T arr[], int n) {
		for (int i = 0; i < n; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	template <typename T>
	bool isSorted(T arr[], int n) {
		for (int i = 0; i < n-1; i++) {
			if (arr[i] > arr[i + 1]) {
				return false;
			}
		}

		return true;
	}

	template <typename T>
	void testSort(string sortName, void(*sort)(T[], int), T arr[], int n) {
		clock_t startTime = clock();
		sort(arr, n);
		clock_t endTime = clock();

		assert(isSorted(arr, n));
		cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;

		return;
	}

	template<typename T>
	T* copyarray(T arr[], int n) {
		T *narr = new int[n];
		for (int i = 0; i < n; i++) {
			narr[i] = arr[i];
		}

		return narr;
	}
}