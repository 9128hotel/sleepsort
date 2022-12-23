#include <algorithm>
#include <iostream>
#include <vector>

// Function to partition the input list around a pivot element
int partition(std::vector<int>& list, int low, int high) {
    // Choose the pivot element as the last element in the list
    int pivot = list[high];

    // Index of the smaller element
    int i = low - 1;

    // Iterate through the list and partition it around the pivot element
    for (int j = low; j <= high - 1; j++) {
        if (list[j] < pivot) {
            i++;
            std::swap(list[i], list[j]);
        }
    }
    std::swap(list[i + 1], list[high]);

    return i + 1;
}

// Recursive function to sort the input list using quicksort
void quicksort(std::vector<int>& list, int low, int high) {
    if (low < high) {
        // Partition the list around a pivot element
        int pivot_index = partition(list, low, high);

        // Recursively sort the two halves of the list
        quicksort(list, low, pivot_index - 1);
        quicksort(list, pivot_index + 1, high);
    }
}

int main() {
    int length = std::rand() % 100 + 1;  // Random number between 1 and 100

    // Create the vector and fill it with random numbers
    std::vector<int> list(length);
    std::generate(list.begin(), list.end(), [] { return std::rand(); });

    // Sort the list using quicksort
    quicksort(list, 0, (int)list.size() - 1);

    // Print the sorted list
    for (int num : list) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}