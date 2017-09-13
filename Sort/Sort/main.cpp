#include<iostream>
#include"TestHelper.h"
#include"selectSort.h"
#include"InsertSort.h"
#include"bubbleSort.h"
#include"mergeSort.h"
#include"quickSort.h"
using namespace std;

int main() {
	int n = 100000;
	int *arr = SortTestHelper::generatRandomArray(n, 0, n);
	int *arr1 = SortTestHelper::copyarray(arr, n);
	int *arr2 = SortTestHelper::copyarray(arr, n);
	int *arr3 = SortTestHelper::copyarray(arr, n);
	/*
	cout << "有重复排序" << endl;
	SortTestHelper::testSort("Merge Sort", mergeSort, arr, n);
	SortTestHelper::testSort("Quick Sort", quickSort::quickSort, arr1, n);
	SortTestHelper::testSort("Quick Sort2", quickSort2::quickSort, arr2, n);
	SortTestHelper::testSort("Quick Sort3", quickSort3::quickSort, arr3, n);
	*/
	delete[] arr;
	delete[] arr1;
	delete[] arr2;
	delete[] arr3;

	cout << "无重复排序" << endl;
	arr = SortTestHelper::generatRandomOrderedArray(n, 1000);
	arr1 = SortTestHelper::copyarray(arr, n);
	arr2 = SortTestHelper::copyarray(arr, n);
	arr3 = SortTestHelper::copyarray(arr, n);
	SortTestHelper::testSort("Merge Sort", mergeSort, arr, n);
	SortTestHelper::testSort("Quick Sort", quickSort::quickSort, arr1, n);
	SortTestHelper::testSort("Quick Sort2", quickSort2::quickSort, arr2, n);
	SortTestHelper::testSort("Quick Sort3", quickSort3::quickSort, arr3, n);
	delete[] arr;
	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	system("pause");
	return 0;
}