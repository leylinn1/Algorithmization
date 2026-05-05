#include <vector>
#include <algorithm>
#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

void shellSort(std::vector<int>& arr) {
    size_t n = arr.size();  

    for (size_t gap = n / 2; gap > 0; gap /= 2) {
        for (size_t i = gap; i < n; ++i) {
            int temp = arr[i];
            size_t j = i;

            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j = j - gap;
            }
            arr[j] = temp;
        }
    }
}

vector<int> generateArray(int size) {
    vector<int> arr(size);
    for (int i = 0; i < size; i++)
        arr[i] = rand() % 100000;
    return arr;
}

int main(){
    vector<int> data = { 4, 2, 6, 7, 5, 2, 6, 9 };
    shellSort(data);
    for (int x : data) 
		cout << x << " ";

    vector<int> sizes = { 1000, 5000, 10000, 20000 };

    for (int size : sizes) {
        vector<int> arr = generateArray(size);
        auto start = high_resolution_clock::now();
        shellSort(arr);
        auto end = high_resolution_clock::now();

        auto time = duration_cast<microseconds>(end - start).count();

        cout << "\n" << size << " " << time;
    }
    return 0;
}
