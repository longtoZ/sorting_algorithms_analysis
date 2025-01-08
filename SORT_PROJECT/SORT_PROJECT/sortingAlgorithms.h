#pragma once
#include "header.h"

class Algorithms {
private:
    // Helper function for heap sort
    void heapify(int* arr, int n, int i, long long& comparison) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // If the left child is larger than the root
        if (left < n && arr[left] > arr[largest]) {
            comparison += 2;
            largest = left;
        }
        else if (left >= n) {
            comparison += 1;
        }
        else if (left < n && arr[left] <= arr[largest]) {
            comparison += 2;
        }

        // If the right child is larger than the largest so far
        if (right < n && arr[right] > arr[largest]) {
            comparison += 2;
            largest = right;
        }
        else if (right >= n) {
            comparison += 1;
        }
        else if (right < n && arr[right] <= arr[largest]) {
            comparison += 2;
        }

        // If the largest is not the root
        if (largest != i) {
            swap(arr[i], arr[largest]);

            // Recursively heapify the affected sub-tree
            heapify(arr, n, largest, comparison);
        }
        comparison++;
    }

    // Helper function for merge sort
    void merge(int* arr, int l, int m, int r, long long& comparison) {
        int n1 = m - l + 1;
        int n2 = r - m;

        // Create temporary arrays
        int* L = new int[n1];
        int* R = new int[n2];

        // Copy data to temporary arrays L[] and R[]
        for (int i = 0; i < n1; i++) {
            L[i] = arr[l + i];
        }
        comparison += n1 + 1;

        for (int j = 0; j < n2; j++) {
            R[j] = arr[m + 1 + j];
        }
        comparison += n2 + 1;

        // Merge the temporary arrays back into arr[l..r]
        int i = 0;
        int j = 0;
        int k = l;

        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
            comparison += 3;
            k++;
        }
        if (i >= n1) {
            comparison++;
        }
        else if (i < n1 && j >= n2) {
            comparison += 2;
        }
        // Copy the remaining elements of L[], if there are any
        while (i < n1) {
            comparison++;
            arr[k] = L[i];
            i++;
            k++;
        }

        // Copy the remaining elements of R[], if there are any
        while (j < n2) {
            comparison++;
            arr[k] = R[j];
            j++;
            k++;
        }
        comparison += 2;
        // Delete temporary arrays
        delete[] L;
        delete[] R;
    }

    // Helper function for quick sort using Hoare Partitioning
    int partition(int* arr, int low, int high, long long& comparison) {
		// Use the middle element as the pivot
		int pivot = arr[(low + high) / 2];

		// Move the left pointer to the right until it finds an element >= pivot
        int i = low - 1;
        int j = high + 1;

        while (true) {
            // Move i to the right until arr[i] >= pivot
            do {
                i++;
                comparison++;
            } while (arr[i] < pivot);
			comparison++;

            // Move j to the left until arr[j] <= pivot
            do {
                j--;
                comparison++;
            } while (arr[j] > pivot);
			comparison++;

            // If indices cross, partitioning is complete
            if (i >= j) {
                return j;
            }
            comparison++;

            // Swap elements at i and j
            swap(arr[i], arr[j]);
        }
    }

    // Helper function for radix sort
    void countingSortByDigit(int* arr, int n, int exp, long long& comparison) {
        int* output = new int[n];
        int count[10] = { 0 };

        // Store count of occurrences in count[]
        for (int i = 0; i < n; i++, comparison++) {
            count[(arr[i] / exp) % 10]++;
        }
        comparison++;
        // Change count[i] so that count[i] now contains actual position of this digit in output[]
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }
        comparison += 11;
        // Build the output array
        for (int i = n - 1; i >= 0; i--, comparison++) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }
        comparison++;

        // Copy the output array to arr[], so that arr[] now contains sorted numbers according to current digit
        for (int i = 0; i < n; i++, comparison++) {
            arr[i] = output[i];
        }
        comparison++;
        // Delete the temporary array
        delete[] output;
    }

public:
    // Selection sort
    void selectionSort(int* arr, int n, long long& comparison) {
        for (int i = 0; i < n - 1; i++, comparison++) {
            int minIndex = i;

            for (int j = i + 1; j < n; j++, comparison++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
                comparison++;
            }

            comparison++;
            swap(arr[i], arr[minIndex]);
        }
        comparison++;
    }

    // Insertion sort
    void insertionSort(int* arr, int n, long long& comparison) {
        for (int i = 1; i < n; i++, comparison++) {
            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key) {
                comparison += 2;
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            if (j < 0) {
                comparison++;
            }
            else if (j >= 0 && arr[j] <= key) comparison += 2;
            arr[j + 1] = key;
        }
        comparison++;
    }

    // Bubble sort
    void bubbleSort(int* arr, int n, long long& comparison) {
        for (int i = 0; i < n - 1; i++, comparison++) {
            for (int j = 0; j < n - i - 1; j++, comparison++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
                comparison++;
            }
            comparison++;
        }
        comparison++;
    }

    // Shaker sort
    void shakerSort(int* arr, int n, long long& comparison) {
        int left = 0;
        int right = n - 1;
        int k = 0;

        while (left < right) {
            comparison++;
            // Move the largest element to the right
            for (int i = left; i < right; i++, comparison++) {
                if (arr[i] > arr[i + 1]) {
                    swap(arr[i], arr[i + 1]);
                    k = i;
                }
                comparison++;
            }
            comparison++;
            // Set the upper bound
            right = k;

            // Move the smallest element to the left
            for (int i = right; i > left; i--, comparison++) {
                if (arr[i] < arr[i - 1]) {
                    swap(arr[i], arr[i - 1]);
                    k = i;
                }
                comparison++;
            }
            comparison++;
            // Set the lower bound
            left = k;
        }
        comparison++;
    }

    // Shell sort
    void shellSort(int* arr, int n, long long& comparison) {

        // Start with a big gap, then reduce the gap by half
        for (int gap = n / 2; gap > 0; gap /= 2, comparison++) {

            // Perform a gapped insertion sort for this gap size
            for (int i = gap; i < n; i++, comparison++) {

                // Add arr[i] to the elements that have been gap sorted
                // Save arr[i] in temp and make a hole at position i
                int temp = arr[i];
                int j;

                // Shift earlier gap-sorted elements up until the correct location for arr[i] is found
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap, comparison += 2) {
                    arr[j] = arr[j - gap];
                }
                if (j < gap) {
                    comparison++;
                }
                else if (j >= gap && arr[j - gap] <= temp) {
                    comparison += 2;
                }
                // Put temp (the original arr[i]) in its correct location
                arr[j] = temp;
            }
            comparison++;
        }
        comparison++;
    }

    // Heap sort
    void heapSort(int* arr, int n, long long& comparison) {
        // Build a max heap
        for (int i = n / 2 - 1; i >= 0; i--, comparison++) {
            heapify(arr, n, i, comparison);
        }
        comparison++;
        // Extract elements from the heap one by one
        for (int i = n - 1; i > 0; i--, comparison++) {
            // Move the current root to the end
            swap(arr[0], arr[i]);

            // Call max heapify on the reduced heap
            heapify(arr, i, 0, comparison);
        }
        comparison++;
    }

    // Merge sort
    void mergeSort(int* arr, int l, int r, long long& comparison) {
        if (l < r) {
            // Find the middle point
            int m = l + (r - l) / 2;

            // Sort first and second halves
            mergeSort(arr, l, m, comparison);
            mergeSort(arr, m + 1, r, comparison);

            // Merge the sorted halves
            merge(arr, l, m, r, comparison);
        }
        comparison++;
    }

    // Quick sort
    void quickSort(int* arr, int low, int high, long long& comparison) {
        if (low < high) {
            // Partition the array
            int pi = partition(arr, low, high, comparison);

            // Sort the elements on the left of the pivot
            quickSort(arr, low, pi - 1, comparison);

            // Sort the elements on the right of the pivot
            quickSort(arr, pi + 1, high, comparison);
        }
        comparison++;
    }

    // Counting sort
    void countingSort(int* arr, int n, long long& comparison) {
        // No sorting needed for arrays with 1 or fewer elements
        if (n <= 1) {
            comparison++;
            return;
        }

        // Find the range of the array (max and min values)
        int maxVal = arr[0];
        int minVal = arr[0];
        for (int i = 1; i < n; ++i, comparison++) {
            if (arr[i] > maxVal) {
                maxVal = arr[i];
            }
            else if (arr[i] < minVal) {
                minVal = arr[i];
            }
            comparison++;
        }

        // Calculate the range of the data
        int range = maxVal - minVal + 1;

        // Create and initialize the count array
        int* count = new int[range](); // Initialized to 0

        // Count the occurrences of each element
        for (int i = 0; i < n; ++i, comparison++) {
            ++count[arr[i] - minVal]; // Use offset for negative numbers
        }

        // Reconstruct the sorted array from the count array
        int index = 0;
        for (int i = 0; i < range; ++i, comparison++) {
            while (count[i] > 0) {
                arr[index++] = i + minVal; // Reapply the offset
                --count[i];
                comparison++;
            }
        }

        // Clean up dynamically allocated memory
        delete[] count;
    }


    // Radix sort
    void radixSort(int* arr, int n, long long& comparison) {

        // Find the maximum number to know the number of digits
        int max = arr[0];
        for (int i = 1; i < n; i++, comparison++) {
            if (arr[i] > max) {
                max = arr[i];
            }
            comparison++;
        }
        comparison++;

        // Do counting sort for every digit
        for (int exp = 1; max / exp > 0; exp *= 10, comparison++) {
            countingSortByDigit(arr, n, exp, comparison);
        }
    }

    // Flash sort
    void flashSort(int* arr, int n, long long& comparison) {
        if (n <= 1) {
            comparison++;
            return; // No sorting needed for arrays with 1 or fewer elements
        }
        // Step 1: Identify the range of the array (min and max elements)
        int minVal = arr[0];
        int maxIndex = 0;

        // Find the min and max values
        for (int i = 1; i < n; ++i, comparison++) {
            if (arr[i] < minVal) {
                minVal = arr[i];
            }
            if (arr[i] > arr[maxIndex]) {
                maxIndex = i;
            }
            comparison += 2;
        }
        comparison++;

        // If all elements are the same, the array is already sorted
        if (arr[maxIndex] == minVal) {
            comparison++;
            return;
        }
        // Step 2: Create the L classification array
        int m = static_cast<int>(0.45 * n); // Number of buckets (empirically chosen constant)
        int* L = new int[m](); // Initialize L array to 0

        // Calculate the scaling factor for classification
        double c = (double)(m - 1) / (arr[maxIndex] - minVal);

        // Classify the elements into L buckets
        for (int i = 0; i < n; ++i, comparison++) {
            int k = static_cast<int>(c * (arr[i] - minVal)); // Calculate bucket index
            ++L[k];
        }
        comparison++;

        // Step 3: Calculate the starting index of each bucket
        for (int i = 1; i < m; ++i, comparison++) {
            L[i] += L[i - 1];
        }
        comparison++;

        // Step 4: Permute elements into their correct buckets
        int count = 0;
        int i = 0;

        while (count < n) {
            comparison++;

            int k = static_cast<int>(c * (arr[i] - minVal)); // Determine the bucket of the current element

            // While the current element is not in its correct bucket
            while (i >= L[k]) {
                comparison++;
                ++i; // Move to the next element
                k = static_cast<int>(c * (arr[i] - minVal)); // Recalculate bucket
            }
            comparison++;

            // Swap the element to its correct position in the bucket
            if (i < L[k]) {
                swap(arr[i], arr[--L[k]]);
                ++count; // Increment the count of sorted elements
            }
            comparison++;
        }
        comparison++;

        // Step 5: Perform insertion sort within each bucket
        for (int i = 1; i < n; ++i, comparison++) {
            int key = arr[i];
            int j = i - 1;

            // Insert the current element into the sorted portion of the array
            while (j >= 0 && arr[j] > key) {
                comparison += 2;
                arr[j + 1] = arr[j];
                --j;
            }
            if (j < 0) {
                comparison++;
            }
            else if (j >= 0 && arr[j] <= key) {
                comparison += 2;
            }
            arr[j + 1] = key;
        }

        // Cleanup dynamically allocated memory
        delete[] L;
    }

};
