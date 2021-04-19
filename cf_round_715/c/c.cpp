#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <assert.h>
#include <math.h>
#include <tuple>
#include <unordered_map>

using namespace std;

typedef long long ll;
ll NUMBER = 1000000007;

// 1 3 3 3 6 6
//         ^
//           ^
// d = 5+3+3
ll getMinimumValue(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    vector<ll> dp(n);

    for(int l=2;l<=n;l++) {
        for(int i=0;i<=n-l;i++) {
            if(i < n-1) {
                dp[i] = arr[i+l-1] - arr[i] + min(dp[i], dp[i+1]);
            }
            else {
                 dp[i] = arr[i+l-1] - arr[i] + dp[i];
            }
        }
    }

    return dp[0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }

    cout << getMinimumValue(arr) << "\n";

    return 0;
}