#pragma once
#include<iostream>
#include"InsertSort.h"
using namespace std;
namespace quickSort {
	template <typename T>
	int  __partition(T arr[], int l, int r) {
		swap(arr[rand() % (r - l + 1) + l], arr[l]);
		T v = arr[l];
		int j = l;
		for (int i = l + 1; i <= r; i++) {
			if (arr[i] < v) {
				swap(arr[++j], arr[i]);
			}
		}
		swap(arr[j], arr[l]);

		return j;
	}

	template <typename T>
	void __quickSort(T arr[], int l, int r) {
		if (l >= r) {
			return;
		}
		int p = __partition(arr, l, r);
		__quickSort(arr, l, p - 1);
		__quickSort(arr, p + 1, r);
	}

	template <typename T>
	void quickSort(T arr[], int n) {
		srand(time_t(NULL));
		__quickSort(arr, 0, n - 1);
	}
}

namespace quickSort2 {
	template <typename T>
	int __partition(T arr[], int l, int r) {
		swap(arr[rand() % (r - l + 1) + l], arr[l]);
		T v = arr[l];
		//arr[l+1,i)<=v,arr(j,r]>=v
		int i=l+1, j=r;
		while(true) {
			while (i<=r && arr[i]<v)
			{
				i++;
			}
			while (j >= l+1 &&arr[j] > v)
			{
				j--;
			}

			if (i > j) {
				break;
			}

			swap(arr[i], arr[j]);
			i++;
			j--;
		}

		swap(arr[l], arr[j]);

		return j;
	}
	template <typename T>
	void __quickSort(T arr[], int l, int r) {
		if (r - l <= 15) {
			insertionSort(arr, l, r);
			return;
		}
		int p = __partition(arr, l, r);
		__quickSort(arr, l, p - 1);
		__quickSort(arr, p + 1, r);
	}

	template <typename T>
	void quickSort(T arr[], int n) {
		srand(time_t(NULL));
		__quickSort(arr, 0, n - 1);
	}
}

namespace quickSort3 {

	//三路快速排序
	//arr[l...r]分为<v,=v,>v；
	template <typename T>
	void __quickSort(T arr[], int l, int r) {
		if (r - l <= 15) {
			insertionSort(arr, l, r);
			return;
		}
		//partation
			swap(arr[l], arr[rand() % (r - l + 1) + l]);
			T v = arr[l];
			int lt = l;//arr[l+1,lt]<v
			int gt = r + 1;//arr[gt..r]>v
			int i = l + 1;//arr[lt+1....i]=v

			while (i<gt)
			{
				if (arr[i]<v)
				{
					swap(arr[i], arr[lt+1]);
					i++;
					lt++;
				}
				else if (arr[i]>v)
				{
					swap(arr[i], arr[gt - 1]);
					gt--;
				}
				else
				{
					i++;
				}
			}

			swap(arr[l], arr[lt]);

		__quickSort(arr, l, lt-1);
		__quickSort(arr, gt, r);
	}

	template <typename T>
	void quickSort(T arr[], int n) {
		srand(time_t(NULL));
		__quickSort(arr, 0, n - 1);
	}
}