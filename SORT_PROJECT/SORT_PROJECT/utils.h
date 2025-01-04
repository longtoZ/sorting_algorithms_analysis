#pragma once
#include "header.h"
#include "sortingAlgorithms.h"

void writeOutputArray(int* arr, int n, string filename) {
	ofstream output(filename);
	if (!output.is_open()) {
		cout << "Can not open file\n";
	}

	output << n << "\n";
	for (int i = 0; i < n; i++) {
		output << arr[i] << " ";
	}
	output.close();
}

int* readInputArray(int& n, string fileName) {
	ifstream input(fileName);
	if (!input.is_open()) {
		cout << "Can not open file\n";
		return NULL;
	}
	input >> n;
	int* array = new int[n];
	for (int i = 0; i < n; i++)
	{
		input >> array[i];
	}
	input.close();
	return array;
}

void GenerateRandomData(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % MAX_VALUE;
	}
}

void GenerateSortedData(int* arr, int n) {
	long long comparison = 0;
	Algorithms algorithm;
	algorithm.heapSort(arr, n, comparison);
}

void GenerateReverseData(int* arr, int n) {
	long long comparison = 0;
	Algorithms algorithm;
	algorithm.heapSort(arr, n, comparison);
	for (int i = 0; i <= n / 2; i++) {
		swap(arr[i], arr[n - i - 1]);
	}
}

void GenerateNearlySortedData(int* arr, int n) {
	long long comparison = 0;
	Algorithms algorithm;
	algorithm.heapSort(arr, n, comparison);
	for (int i = 0; i < 10; i++) {
		int r1 = rand() % n;
		int r2 = rand() % n;
		swap(arr[r1], arr[r2]);
	}
}

int* creatNewArrayFromGivenArrayAsRequired(int* arr, int n, string demand) {
	int* p = new int[n];
	for (int i = 0; i < n; i++) {
		p[i] = arr[i];
	}
	if (demand == "-rand") {
		for (int i = 0; i < n; i++) {
			int r1 = rand() % n;
			int r2 = rand() % n;
			swap(p[r1], p[r2]);
		}
		return p;
	}
	else if (demand == "-sort") {
		GenerateSortedData(p, n);
		return p;
	}
	else if (demand == "-nsort") {
		GenerateNearlySortedData(p, n);
		return p;
	}
	else if (demand == "-rev") {
		GenerateReverseData(p, n);
		return p;
	}
}