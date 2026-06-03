#include <iostream>
#include <vector>

using namespace std;

bool backtrack(vector<int>& a, int index, int currentSum, int target) {
    if (currentSum == target)
        return true;

    if (index == a.size() || currentSum > target)
        return false;

    if (backtrack(a, index + 1,
        currentSum + a[index],
        target))
        return true;

    if (backtrack(a, index + 1,
        currentSum,
        target))
        return true;
    return false;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (backtrack(a, 0, 0, k))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}