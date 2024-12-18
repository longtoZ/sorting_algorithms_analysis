#pragma once
#include "Header.h"

pair<int,int> MeasureAlgorithm(int* arr, int n, string Algorithm_Name) {
	int comparisons = 0;
	Algorithms algorithm;
	auto start_time = std::chrono::steady_clock::now();
	if (Algorithm_Name == "insertion-sort") {
		algorithm.insertionSort(arr, n, comparisons);
	}
	else if(Algorithm_Name == "bubble-sort") {
		algorithm.bubbleSort(arr, n, comparisons);
	}
	else if (Algorithm_Name == "selection-sort") {
		algorithm.selectionSort(arr, n, comparisons);
	}
	else if (Algorithm_Name == "shaker-sort") {
		algorithm.shakerSort(arr, n, comparisons);
	}
	else if (Algorithm_Name == "shell-sort") {
		algorithm.shellSort(arr, n, comparisons);
	}
	else if (Algorithm_Name == "heap-sort") {
		algorithm.heapSort(arr, n, comparisons);
	}
	else if (Algorithm_Name == "merge-sort") {
		algorithm.mergeSort(arr, 0, n - 1,comparisons);
	}
	else if (Algorithm_Name == "quick-sort") {
		algorithm.quickSort(arr, 0, n - 1, comparisons);
	}
	else if (Algorithm_Name == "counting-sort") {
		algorithm.countingSort(arr, n, comparisons);
	}
	else if (Algorithm_Name == "radix-sort") {
		algorithm.radixSort(arr, n, comparisons);
	}
	else if (Algorithm_Name == "flash-sort") {
		algorithm.flashSort(arr, n, comparisons);
	}
	auto end_time = std::chrono::steady_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
	return make_pair(duration, comparisons);
}

int* readInputArray(int& n, string File_Name) {
	ifstream input(File_Name);
	if (!input.is_open()) {
		cout << "Can not open file\n";
		return NULL;
	}
	input >> n;
	int * array = new int[n];
	for (int i = 0; i < n; i++)
	{
		input >> array[i];
		//cout << array[i] << " ";
	}
	cout << endl;
	input.close();
	return array;
}

void printOutputVer_1(pair<int, int> runtime_comparison, string Output_Require) {
	if (Output_Require == "-both") {
		cout << "Running time: " << runtime_comparison.first << endl;
		cout << "Comparisons: " << runtime_comparison.second << endl;
	}
	else if (Output_Require == "-comp") {
		cout << "Comparisons: " << runtime_comparison.second << endl;
	}
	else if (Output_Require == "-time") {
		cout << "Runnung Time: " << runtime_comparison.first << endl;
	}
}

void Command_1(int arvc, char* arvg[]) {
	// convert to string arguments
	string Algorithm_Name = arvg[2];
	string File_Name = arvg[3];
	string Output_Require = arvg[4];

	// open file to read array
	int n = 0;
	int* array = NULL;
	array = readInputArray(n, File_Name);
	// Print input on CMD
	cout << "Input file: " << File_Name << endl;
	cout << "Input size: " << n << endl;
	cout << "------------------------------------\n";
	// Measure runtime and comparisons
	pair<int,int> runtime_comparison =  MeasureAlgorithm(array, n, Algorithm_Name);
	// Print runtime and comparison if they are required
	printOutputVer_1(runtime_comparison, Output_Require);
}

void Command_2(int arvc, char* arvg[]) {

}

void Command_3(int arvc, char* arvg[]) {

}

void AlgorithmsMode(int arvc ,char* arvg[]) {
	cout << "ALGORITHM MODE\n";
	if (arvc == 5 && string(arvg[3]).find(".txt") != string::npos)
	{
		Command_1(arvc, arvg);
	}
	else if(arvc == 5 && string(arvg[3]).find(".txt") == string::npos)
	{
		Command_3(arvc, arvg);
	}
	else if (arvc == 6)
	{
		Command_2(arvc, arvg);
	}
}