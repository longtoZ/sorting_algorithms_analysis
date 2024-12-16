#include <iostream>

using namespace std;

class Algorithms {
private:
    // Helper function for heap sort
    void heapify(int* arr, int n, int i) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // If the left child is larger than the root
        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        // If the right child is larger than the largest so far
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        // If the largest is not the root
        if (largest != i) {
            swap(arr[i], arr[largest]);

            // Recursively heapify the affected sub-tree
            heapify(arr, n, largest);
        }
    }

    // Helper function for merge sort
    void merge(int* arr, int l, int m, int r) {
        int n1 = m - l + 1;
        int n2 = r - m;

        // Create temporary arrays
        int* L = new int[n1];
        int* R = new int[n2];

        // Copy data to temporary arrays L[] and R[]
        for (int i = 0; i < n1; i++) {
            L[i] = arr[l + i];
        }

        for (int j = 0; j < n2; j++) {
            R[j] = arr[m + 1 + j];
        }

        // Merge the temporary arrays back into arr[l..r]
        int i = 0;
        int j = 0;
        int k = l;

        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }

            k++;
        }

        // Copy the remaining elements of L[], if there are any
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        // Copy the remaining elements of R[], if there are any
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }

        // Delete temporary arrays
        delete[] L;
        delete[] R;
    }

    // Helper function for quick sort
    int partition(int* arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[i + 1], arr[high]);
        return i + 1;
    }

    // Helper function for radix sort
    void countingSortByDigit(int* arr, int n, int exp) {
        int* output = new int[n];
        int count[10] = { 0 };

        // Store count of occurrences in count[]
        for (int i = 0; i < n; i++) {
            count[(arr[i] / exp) % 10]++;
        }

        // Change count[i] so that count[i] now contains actual position of this digit in output[]
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        // Build the output array
        for (int i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        // Copy the output array to arr[], so that arr[] now contains sorted numbers according to current digit
        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
        }

        // Delete the temporary array
        delete[] output;
    }

public:
    // Selection sort
    void selectionSort(int* arr, int n) {
        for (int i = 0; i < n - 1; i++) {

            int minIndex = i;

            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                }
            }

            swap(arr[i], arr[minIndex]);
        }
    }

    // Insertion sort
    void insertionSort(int* arr, int n) {
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }

            arr[j + 1] = key;
        }
    }

    // Bubble sort
    void bubbleSort(int* arr, int n) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    // Shaker sort
    void shakerSort(int* arr, int n) {
        int left = 0;
        int right = n - 1;
        int k = 0;

        while (left < right) {
            // Move the largest element to the right
            for (int i = left; i < right; i++) {
                if (arr[i] > arr[i + 1]) {
                    swap(arr[i], arr[i + 1]);
                    k = i;
                }
            }

            // Set the upper bound
            right = k;

            // Move the smallest element to the left
            for (int i = right; i > left; i--) {
                if (arr[i] < arr[i - 1]) {
                    swap(arr[i], arr[i - 1]);
                    k = i;
                }
            }

            // Set the lower bound
            left = k;
        }
    }

    // Shell sort
    void shellSort(int* arr, int n) {

        // Start with a big gap, then reduce the gap by half
        for (int gap = n / 2; gap > 0; gap /= 2) {
            
            // Perform a gapped insertion sort for this gap size
            for (int i = gap; i < n; i++) {

                // Add arr[i] to the elements that have been gap sorted
                // Save arr[i] in temp and make a hole at position i
                int temp = arr[i];
                int j;

                // Shift earlier gap-sorted elements up until the correct location for arr[i] is found
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                    arr[j] = arr[j - gap];
                }

                // Put temp (the original arr[i]) in its correct location
                arr[j] = temp;
            }
        }
    }

    // Heap sort
    void heapSort(int* arr, int n) {
        // Build a max heap
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        // Extract elements from the heap one by one
        for (int i = n - 1; i > 0; i--) {
            // Move the current root to the end
            swap(arr[0], arr[i]);

            // Call max heapify on the reduced heap
            heapify(arr, i, 0);
        }
    }

    // Merge sort
    void mergeSort(int* arr, int l, int r) {
        if (l < r) {
            // Find the middle point
            int m = l + (r - l) / 2;

            // Sort first and second halves
            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);

            // Merge the sorted halves
            merge(arr, l, m, r);
        }
    }

    // Quick sort
    void quickSort(int* arr, int low, int high) {
        if (low < high) {
            // Partition the array
            int pi = partition(arr, low, high);

            // Sort the elements on the left of the pivot
            quickSort(arr, low, pi - 1);

            // Sort the elements on the right of the pivot
            quickSort(arr, pi + 1, high);
        }
    }

    // Counting sort
    void countingSort(int* arr, int n) {
        // No sorting needed for arrays with 1 or fewer elements
        if (n <= 1) return;

        // Find the range of the array (max and min values)
        int maxVal = arr[0];
        int minVal = arr[0];
        for (int i = 1; i < n; ++i) {
            if (arr[i] > maxVal) maxVal = arr[i];
            if (arr[i] < minVal) minVal = arr[i];
        }

        // Calculate the range of the data
        int range = maxVal - minVal + 1;

        // Create and initialize the count array
        int* count = new int[range](); // Initialized to 0

        // Count the occurrences of each element
        for (int i = 0; i < n; ++i) {
            ++count[arr[i] - minVal]; // Use offset for negative numbers
        }

        // Reconstruct the sorted array from the count array
        int index = 0;
        for (int i = 0; i < range; ++i) {
            while (count[i] > 0) {
                arr[index++] = i + minVal; // Reapply the offset
                --count[i];
            }
        }

        // Clean up dynamically allocated memory
        delete[] count;
    }

    // Radix sort
    void radixSort(int* arr, int n) {

        // Find the maximum number to know the number of digits
        int max = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }

        // Do counting sort for every digit
        for (int exp = 1; max / exp > 0; exp *= 10) {
            countingSortByDigit(arr, n, exp);
        }
    }

    // Flash sort
    void flashSort(int* arr, int n) {
        if (n <= 1) return; // No sorting needed for arrays with 1 or fewer elements

        // Step 1: Identify the range of the array (min and max elements)
        int minVal = arr[0];
        int maxIndex = 0;

        // Find the min and max values
        for (int i = 1; i < n; ++i) {
            if (arr[i] < minVal) {
                minVal = arr[i];
            }
            if (arr[i] > arr[maxIndex]) {
                maxIndex = i;
            }
        }

        // If all elements are the same, the array is already sorted
        if (arr[maxIndex] == minVal) return;

        // Step 2: Create the L classification array
        int m = static_cast<int>(0.45 * n); // Number of buckets (empirically chosen constant)
        int* L = new int[m](); // Initialize L array to 0

        // Calculate the scaling factor for classification
        double c = (double)(m - 1) / (arr[maxIndex] - minVal);

        // Classify the elements into L buckets
        for (int i = 0; i < n; ++i) {
            int k = static_cast<int>(c * (arr[i] - minVal)); // Calculate bucket index
            ++L[k];
        }

        // Step 3: Calculate the starting index of each bucket
        for (int i = 1; i < m; ++i) {
            L[i] += L[i - 1];
        }

        // Step 4: Permute elements into their correct buckets
        int count = 0;
        int i = 0;

        while (count < n) {
            int k = static_cast<int>(c * (arr[i] - minVal)); // Determine the bucket of the current element

            // While the current element is not in its correct bucket
            while (i >= L[k]) {
                ++i; // Move to the next element
                k = static_cast<int>(c * (arr[i] - minVal)); // Recalculate bucket
            }

            // Swap the element to its correct position in the bucket
            if (i < L[k]) {
                swap(arr[i], arr[--L[k]]);
                ++count; // Increment the count of sorted elements
            }
        }

        // Step 5: Perform insertion sort within each bucket
        for (int i = 1; i < n; ++i) {
            int key = arr[i];
            int j = i - 1;

            // Insert the current element into the sorted portion of the array
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                --j;
            }
            arr[j + 1] = key;
        }

        // Cleanup dynamically allocated memory
        delete[] L;
    }

};

int main() {
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int n = sizeof(arr) / sizeof(arr[0]);

    Algorithms algo;

    // Selection sort
    algo.selectionSort(arr, n);
    cout << "Selection sort: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}