#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include <algorithm>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

void shellsort(vector<int>& arr) {
    size_t n = arr.size();
    for (size_t gap = n / 2; gap > 0; gap /= 2) {
        for (size_t i = gap; i < n; ++i) {
            int temp = arr[i];
            size_t j = i;

            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

void radixsort(vector<int>& arr) {
    if (arr.empty()) return;

    int maxval = *max_element(arr.begin(), arr.end());

    for (int exp = 1; maxval / exp > 0; exp *= 10) {
        int n = arr.size();
        vector<int> output(n);
        int count[10] = { 0 };

        for (int i = 0; i < n; i++)
            count[(arr[i] / exp) % 10]++;

        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (int i = n - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        for (int i = 0; i < n; i++)
            arr[i] = output[i];
    }
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quicksort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}


namespace SortingTests
{
    TEST_CLASS(SortingTests)
    {
    public:

        TEST_METHOD(TestShellSort)
        {
            vector<int> arr = { 5, 3, 1, 4, 2 };
            shellsort(arr);
            vector<int> expected = { 1, 2, 3, 4, 5 };

            for (int i = 0; i < arr.size(); i++)
                Assert::AreEqual(expected[i], arr[i]);
        }

        TEST_METHOD(TestRadixSort)
        {
            vector<int> arr = { 170, 45, 75, 90 };
            radixsort(arr);
            vector<int> expected = { 45, 75, 90, 170 };

            for (int i = 0; i < arr.size(); i++)
                Assert::AreEqual(expected[i], arr[i]);
        }

        TEST_METHOD(TestQuickSort)
        {
            vector<int> arr = { 10, 7, 8, 9 };
            quicksort(arr, 0, arr.size() - 1);
            vector<int> expected = { 7, 8, 9, 10 };

            for (int i = 0; i < arr.size(); i++)
                Assert::AreEqual(expected[i], arr[i]);
        }
    };
}