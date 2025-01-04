#pragma once
#include "header.h"
#include "utils.h"
#include "sortingAlgorithms.h"

class Functions {
private:
	// Function to measure runtime and comparisons of an algorithm
	pair<long long, long long> measureAlgorithm(int* arr, int n, string algorithmName) {
		long long comparisons = 0;
		Algorithms algorithm;
		auto start_time = steady_clock::now();

		if (algorithmName == "insertion-sort") {
			algorithm.insertionSort(arr, n, comparisons);
		}
		else if (algorithmName == "bubble-sort") {
			algorithm.bubbleSort(arr, n, comparisons);
		}
		else if (algorithmName == "selection-sort") {
			algorithm.selectionSort(arr, n, comparisons);
		}
		else if (algorithmName == "shaker-sort") {
			algorithm.shakerSort(arr, n, comparisons);
		}
		else if (algorithmName == "shell-sort") {
			algorithm.shellSort(arr, n, comparisons);
		}
		else if (algorithmName == "heap-sort") {
			algorithm.heapSort(arr, n, comparisons);
		}
		else if (algorithmName == "merge-sort") {
			algorithm.mergeSort(arr, 0, n - 1, comparisons);
		}
		else if (algorithmName == "quick-sort") {
			algorithm.quickSort(arr, 0, n - 1, comparisons);
		}
		else if (algorithmName == "counting-sort") {
			algorithm.countingSort(arr, n, comparisons);
		}
		else if (algorithmName == "radix-sort") {
			algorithm.radixSort(arr, n, comparisons);
		}
		else if (algorithmName == "flash-sort") {
			algorithm.flashSort(arr, n, comparisons);
		}
		else
		{
			cout << "Algorithm is not valid\n";
		}

		auto end_time = steady_clock::now();
		auto duration = duration_cast<milliseconds>(end_time - start_time).count();
		return make_pair(duration, comparisons);
	}

	// Function to print runtime and comparisons of one algorithm
	void printOneAlgorithm(pair <long long, long long> runtime_comparison, string requiredOutput) {
		if (requiredOutput == "-both")
		{
			cout << "Running time: " << runtime_comparison.first << endl;
			cout << "Comparisons: " << runtime_comparison.second << endl;
		}
		else if (requiredOutput == "-comp")
		{
			cout << "Comparisons: " << runtime_comparison.second << endl;
		}
		else if (requiredOutput == "-time") {
			cout << "Runnung Time: " << runtime_comparison.first << endl;
		}
	}

	// Function to print runtime and comparisons of two algorithms
	void printTwoAlgorithm(pair <long long, long long> runtime_comparison_1, pair <long long, long long> runtime_comparison_2, string requiredOutput) {
		if (requiredOutput == "-both")
		{
			cout << "Running time: " << runtime_comparison_1.first << " | " << runtime_comparison_2.first << endl;
			cout << "Comparisons: " << runtime_comparison_1.second << " | " << runtime_comparison_2.second << endl;
		}
		else if (requiredOutput == "-comp")
		{
			cout << "Comparisons: " << runtime_comparison_1.second << " | " << runtime_comparison_2.second << endl;
		}
		else if (requiredOutput == "-time") {
			cout << "Runnung Time: " << runtime_comparison_1.first << " | " << runtime_comparison_2.first << endl;
		}
	}

	// Function to generate array with required size and order
	int* generateArrayRequired(int inputSize, string inputOrder, int* currentArray = NULL) {
		Algorithms algorithm;
		int comparison = 0;
		// Allocate memory for array 
		int* arr = new int[inputSize];
		// Generate random array
		GenerateRandomData(arr, inputSize);
		// if it require a random array
		if (inputOrder == "-rand") {
			return arr;
		}
		// if it require a sorted array, then sort array and return 
		else if (inputOrder == "-sorted") {
			GenerateSortedData(arr, inputSize);
			return arr;
		}
		// if it require a nearly sorted array, then sort array and swap some of couple of index in array
		else if (inputOrder == "-nsorted") {
			GenerateNearlySortedData(arr, inputSize);
			return arr;
		}
		// if it require a descending array, then sort array and reverse it 
		else if (inputOrder == "-rev") {
			GenerateReverseData(arr, inputSize);
			return arr;
		}
		else
		{
			cout << "Input order is not valid\n";
			return NULL;
		}
	}

	// Function to execute command 1
	void command1(int arvc, char* arvg[]) {
		// convert to string arguments
		string algorithmName = arvg[2];
		string fileName = arvg[3];
		string requiredOutput = arvg[4];

		// Open file to read array
		int n = 0;
		int* array = NULL;
		array = readInputArray(n, fileName);
		// Print input on CMD
		cout << "Algorithm: " << algorithmName << endl;
		cout << "Input file: " << fileName << endl;
		cout << "Input size: " << n << endl;
		cout << "------------------------------------\n";

		// Measure runtime and comparisons
		pair<long long, long long> runtime_comparison = measureAlgorithm(array, n, algorithmName);

		// Print runtime and comparison if they are required
		printOneAlgorithm(runtime_comparison, requiredOutput);

		// Write sorted array into file output.txt
		writeOutputArray(array, n, "output.txt");

		// Release memory
		delete[] array;
	}
	
	// Function to execute command 2
	void command2(int arvc, char* arvg[]) {
		// convert to string arguments
		string algorithmName = arvg[2];
		int inputSize = stoi((string)(arvg[3]));
		string inputOrder = arvg[4];
		string requiredOutput = arvg[5];

		// Print input on CMD
		cout << "Algorithm: " << algorithmName << endl;
		cout << "Input size: " << inputSize << endl;
		cout << "Input order: " << inputOrder << endl;
		cout << "------------------------------------\n";

		// Create array with size and order input
		int* array = generateArrayRequired(inputSize, inputOrder);
		int n = inputSize;

		// Write a newly generated array into file input.txt
		writeOutputArray(array, n, "input.txt");

		// Measure running time and comparison with created array
		pair<long long, long long> runtime_comparison = measureAlgorithm(array, n, algorithmName);

		// Print runtime and comparison if they are required
		printOneAlgorithm(runtime_comparison, requiredOutput);

		// Write sorted array into file output.txt
		writeOutputArray(array, n, "output.txt");

		// Release memory
		delete[] array;
	}

	// Function to execute command 3
	void command3(int arvc, char* arvg[]) {
		// convert to string arguments
		string algorithmName = arvg[2];
		int inputSize = stoi((string)(arvg[3]));
		string requiredOutput = arvg[4];

		// Print input on CMD
		cout << "Algorithm: " << algorithmName << endl;
		cout << "Input size: " << inputSize << endl << endl;

		// Creat 4 arrays in order as Random array, Nearly Sorted array, Sorted array and Reversed array
		int* array_1 = generateArrayRequired(inputSize, "-rand");
		int* array_2 = creatNewArrayFromGivenArrayAsRequired(array_1, inputSize, "-nsort");
		int* array_3 = creatNewArrayFromGivenArrayAsRequired(array_1, inputSize, "-sort");
		int* array_4 = creatNewArrayFromGivenArrayAsRequired(array_1, inputSize, "-rev");

		// Write 4 kind of arrays into input_1.txt,...,input_4.txt
		writeOutputArray(array_1, inputSize, "input_1.txt");
		writeOutputArray(array_2, inputSize, "input_2.txt");
		writeOutputArray(array_3, inputSize, "input_3.txt");
		writeOutputArray(array_4, inputSize, "input_4.txt");

		// Measure running time and comparison with created array
		pair<long long, long long> runtime_comparison_1 = measureAlgorithm(array_1, inputSize, algorithmName);
		pair<long long, long long> runtime_comparison_2 = measureAlgorithm(array_2, inputSize, algorithmName);
		pair<long long, long long> runtime_comparison_3 = measureAlgorithm(array_3, inputSize, algorithmName);
		pair<long long, long long> runtime_comparison_4 = measureAlgorithm(array_4, inputSize, algorithmName);

		// Print result on CMD
		cout << "Input order: Randomize\n";
		cout << "------------------------------------\n";
		printOneAlgorithm(runtime_comparison_1, requiredOutput);
		cout << "\n";
		cout << "Input order: Nearly Sorted\n";
		cout << "------------------------------------\n";
		printOneAlgorithm(runtime_comparison_2, requiredOutput);
		cout << "\n";
		cout << "Input order: Sorted\n";
		cout << "------------------------------------\n";
		printOneAlgorithm(runtime_comparison_3, requiredOutput);
		cout << "\n";
		cout << "Input order: Reversed\n";
		cout << "------------------------------------\n";
		printOneAlgorithm(runtime_comparison_4, requiredOutput);

		// Release memory
		delete[] array_1;
		delete[] array_2;
		delete[] array_3;
		delete[] array_4;
	}

	// Function to execute command 4
	void command4(int arvc, char* arvg[]) {
		// Convert arguments to string
		string algorithm1 = arvg[2];
		string algorithm2 = arvg[3];
		string input_file = arvg[4];

		// Read the input file and create 2 arrays
		int inputSize = 0;
		int* array1 = readInputArray(inputSize, input_file);
		int* array2 = readInputArray(inputSize, input_file);

		// Print the input on CMD
		cout << "Algorithm: " << algorithm1 << " | " << algorithm2 << endl;
		cout << "Input file: " << input_file << endl;
		cout << "Input size: " << inputSize << endl;
		cout << "------------------------------------\n";

		// Measure the runtime and comparison of 2 algorithms
		pair<long long, long long> runtime_comparison_1 = measureAlgorithm(array1, inputSize, algorithm1);
		pair<long long, long long> runtime_comparison_2 = measureAlgorithm(array2, inputSize, algorithm2);

		// Print the runtime and comparison of 2 algorithms
		printTwoAlgorithm(runtime_comparison_1, runtime_comparison_2, "-both");

		// Release memory
		delete[] array1;
		delete[] array2;
	}

	// Function to execute command 5
	void command5(int arvc, char* arvg[]) {
		// Convert arguments to string
		string algorithm1 = arvg[2];
		string algorithm2 = arvg[3];
		int inputSize = stoi(arvg[4]);
		string inputOrder = arvg[5];

		// Create two arrays with given size and order
		int* array1 = generateArrayRequired(inputSize, inputOrder);
		int* array2 = generateArrayRequired(inputSize, inputOrder);

		// Print the input on CMD
		cout << "Algorithm: " << algorithm1 << " | " << algorithm2 << endl;
		cout << "Input size: " << inputSize << endl;
		cout << "Input order: " << inputOrder << endl;
		cout << "------------------------------------\n";

		// Measure the runtime and comparison of 2 algorithms
		pair<long long, long long> runtime_comparison_1 = measureAlgorithm(array1, inputSize, algorithm1);
		pair<long long, long long> runtime_comparison_2 = measureAlgorithm(array2, inputSize, algorithm2);

		// Print the runtime and comparison of 2 algorithms
		printTwoAlgorithm(runtime_comparison_1, runtime_comparison_2, "-both");

		// Release memory
		delete[] array1;
		delete[] array2;
	}

public:
	// Function to run algorithm mode
	void algorithmMode(int arvc, char* arvg[]) {
		cout << "ALGORITHM MODE\n";

		if (arvc == 5 && string(arvg[3]).find(".txt") != string::npos)
		{
			command1(arvc, arvg);
		}
		else if (arvc == 5 && string(arvg[3]).find(".txt") == string::npos)
		{
			command3(arvc, arvg);
		}
		else if (arvc == 6)
		{
			command2(arvc, arvg);
		}
	}

	// Function to run comparison mode
	void comparisonMode(int arvc, char* arvg[]) {
		cout << "COMPARE MODE\n";

		if (arvc == 5 && string(arvg[4]).find(".txt") != string::npos)
		{
			command4(arvc, arvg);
		}
		else if (arvc == 6)
		{
			command5(arvc, arvg);
		}
	}
};