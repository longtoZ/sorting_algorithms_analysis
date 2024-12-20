#pragma once
#include "Header.h"
#include "utils.h"
#include "Algorithms_Sort.h"
pair<long long,long long> MeasureAlgorithm(int* arr, int n, string Algorithm_Name) {
	long long comparisons = 0;
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
	auto duration = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();
	//cout << comparisons << "debug" << endl;
	return make_pair(duration, comparisons);
}


void printOutputVer_1(pair <long long,long long> runtime_comparison, string Output_Require) {
	if (Output_Require == "-both") 
	{
		cout << "Running time: " << runtime_comparison.first << endl;
		cout << "Comparisons: " << runtime_comparison.second << endl;
	}
	else if (Output_Require == "-comp")
	{
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

	// Open file to read array
	int n = 0;
	int* array = NULL;
	array = readInputArray(n, File_Name);
	// Print input on CMD
	cout << "Algorithm: " << Algorithm_Name << endl;
	cout << "Input file: " << File_Name << endl;
	cout << "Input size: " << n << endl;
	cout << "------------------------------------\n";

	// Measure runtime and comparisons
	pair<int,int> runtime_comparison =  MeasureAlgorithm(array, n, Algorithm_Name);

	// Print runtime and comparison if they are required
	printOutputVer_1(runtime_comparison, Output_Require);

	// Write sorted array into file output.txt
	writeOutputArray(array, n, "output.txt");
	
	// Release memory
	delete[] array;
}

int* generateArrayRequired(int Input_Size, string Input_Order, int* currentArray = NULL) {
	srand(time(NULL));
	Algorithms algorithm;
	int comparison = 0;
	// Allocate memory for array 
	int* arr = new int[Input_Size];
	// Generate random array
	GenerateRandomData(arr, Input_Size);
	// if it require a random array
	if (Input_Order == "-rand") {
		return arr;
	}
	// if it require a sorted array, then sort array and return 
	else if (Input_Order == "-sorted") {
		GenerateSortedData(arr, Input_Size);
		return arr;
	}
	// if it require a nearly sorted array, then sort array and swap some of couple of index in array
	else if (Input_Order == "-nsorted") {
		GenerateNearlySortedData(arr, Input_Size);
		return arr;
	}
	// if it require a descending array, then sort array and reverse it 
	else if (Input_Order == "-rev") {
		GenerateReverseData(arr, Input_Size);
		return arr;
	}
}

void Command_2(int arvc, char* arvg[]) {
	// convert to string arguments
	string Algorithm_Name = arvg[2];
	int Input_Size = stoi((string)(arvg[3]));
	string Input_Order = arvg[4];
	string Output_Require = arvg[5];

	// Print input on CMD
	cout << "Algorithm: " << Algorithm_Name << endl;
	cout << "Input size: " << Input_Size << endl;
	cout << "Input order: " << Input_Order << endl;
	cout << "------------------------------------\n";

	// Create array with size and order input
	int* array = generateArrayRequired(Input_Size, Input_Order);
	int n = Input_Size;

	// Write a newly generated array into file input.txt
	writeOutputArray(array, n, "input.txt");

	// Measure running time and comparison with created array
	pair<int, int> runtime_comparison = MeasureAlgorithm(array, n, Algorithm_Name);

	// Print runtime and comparison if they are required
	printOutputVer_1(runtime_comparison, Output_Require);

	// Write sorted array into file output.txt
	writeOutputArray(array, n, "output.txt");

	// Release memory
	delete[] array;
}

void Command_3(int arvc, char* arvg[]) {
	// convert to string arguments
	string Algorithm_Name = arvg[2];
	int Input_Size = stoi((string)(arvg[3]));
	string Output_Require = arvg[4];

	// Print input on CMD
	cout << "Algorithm: " << Algorithm_Name << endl;
	cout << "Input size: " << Input_Size << endl<<endl;

	// Creat 4 arrays in order as Random array, Nearly Sorted array, Sorted array and Reversed array
	int* array_1 = generateArrayRequired(Input_Size, "-rand");
	int* array_2 = creatNewArrayFromGivenArrayAsRequired(array_1, Input_Size, "-nsort");
	int* array_3 = creatNewArrayFromGivenArrayAsRequired(array_1, Input_Size, "-sort");
	int* array_4 = creatNewArrayFromGivenArrayAsRequired(array_1, Input_Size, "-rev");

	// Write 4 kind of arrays into input_1.txt,...,input_4.txt
	writeOutputArray(array_1, Input_Size, "input_1.txt");
	writeOutputArray(array_2, Input_Size, "input_2.txt");
	writeOutputArray(array_3, Input_Size, "input_3.txt");
	writeOutputArray(array_4, Input_Size, "input_4.txt");

	// Measure running time and comparison with created array
	pair<long long, long long> runtime_comparison_1 = MeasureAlgorithm(array_1, Input_Size, Algorithm_Name);
	pair<long long, long long> runtime_comparison_2	= MeasureAlgorithm(array_2, Input_Size, Algorithm_Name);
	pair<long long, long long> runtime_comparison_3 = MeasureAlgorithm(array_3, Input_Size, Algorithm_Name);
	pair<long long, long long> runtime_comparison_4 = MeasureAlgorithm(array_4, Input_Size, Algorithm_Name);

	// Print result on CMD
	cout << "Input order: Randomize\n";
	cout << "------------------------------------\n";
	printOutputVer_1(runtime_comparison_1, Output_Require);
	cout << "\n";
	cout << "Input order: Nearly Sorted\n";
	cout << "------------------------------------\n";
	printOutputVer_1(runtime_comparison_2, Output_Require);
	cout << "\n";
	cout << "Input order: Sorted\n";
	cout << "------------------------------------\n";
	printOutputVer_1(runtime_comparison_3, Output_Require);
	cout << "\n";
	cout << "Input order: Reversed\n";
	cout << "------------------------------------\n";
	printOutputVer_1(runtime_comparison_4, Output_Require);

	// Release memory
	delete[] array_1;
	delete[] array_2;
	delete[] array_3;
	delete[] array_4;
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