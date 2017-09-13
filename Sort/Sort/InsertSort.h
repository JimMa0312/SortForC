#pragma once
#include<iostream>
using namespace std;

//���ݶ���ʵ��
template <typename T>
void insertSort(T arr[], int n) {
	for (int i = 0; i < n; i++) {
		T v = arr[i];
		int j;
		for (j = i; j >0&&arr[j-1]>v; j--)
		{
			arr[j] = arr[j - 1];
		}

		arr[j] = v;
	}
}

//ϣ������(ѡ�������Ż�)
template <typename T>
void shellSort(T arr[], int n) {
	int gap = n / 2;

	while (gap>=1)
	{
		for (int i = gap; i < n; i++) {
			T v = arr[i];
			int j;
			for (j = i; j - gap >= 0 && arr[j-gap] > v; j -= gap) {
				arr[j] = arr[j - gap];
			}

			arr[j] = v;
		}
		gap /= 2;
	}
}

template<typename T>
void insertionSort(T arr[], int l, int r) {

	for (int i = l + 1; i <= r; i++) {

		T e = arr[i];
		int j;
		for (j = i; j > l && arr[j - 1] > e; j--)
			arr[j] = arr[j - 1];
		arr[j] = e;
	}

	return;
}
