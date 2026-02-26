#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
using namespace std;

void removeElement(vector<int>& vec, size_t pos) {
    for (size_t i = pos; i < vec.size() - 1; ++i) {
        vec[i] = vec[i + 1];
    }
    vec.pop_back();
}

long long measureRemovalTime(size_t n) {
    vector<int> vec(n);
    for (size_t i = 0; i < n; ++i) vec[i] = i;

    auto start = chrono::high_resolution_clock::now();
    removeElement(vec, 0);
    auto end = chrono::high_resolution_clock::now();

    return chrono::duration_cast<chrono::nanoseconds>(end - start).count();
}

int main() {
    vector<size_t> sizes = {
        10, 100, 1000, 10000, 100000, 1000000, 5000000, 10000000, 50000000, 100000000
    };
    const int repetitions = 10;

    for (size_t n : sizes) {
        long long totalTime = 0;
        for (int rep = 0; rep < repetitions; ++rep) {
            totalTime += measureRemovalTime(n);
        }
        double avgTime = static_cast<double>(totalTime) / repetitions;
        cout << setw(15) << n << setw(20) << fixed << setprecision(2) << avgTime << endl;
    }
    return 0;
}