#include <iostream>
using namespace std;

const long long MOD = 1000000007;
long long power(long long a, long long n) {
    if (n == 0)
        return 1;
    long long half = power(a, n / 2);
    long long result = (half * half) % MOD;
    if (n % 2 == 1)
        result = (result * a) % MOD;

    return result;
}
int main() {
    long long a, n;
    cin >> a >> n;
    cout << power(a % MOD, n);
    return 0;
}