#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int x;
    cin >> x;
    int k;
    cin >> k;

    vector<int> coins(k);
    for (int i = 0; i < k; i++) {
        cin >> coins[i];
    }
    const int inf = 1e9;
    vector<int> dp(x + 1, inf);
    dp[0] = 0;

    for (int i = 1; i <= x; i++) {
        for (int coin : coins) {
            if (i >= coin) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    if (dp[x] == inf)
        cout << -1 << endl;
    else
        cout << dp[x] << endl;
    return 0;
}