

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

bool isGood(vector<int> &arr) {
    int n = arr.size();
    int sum = 0;

    for(int i=0;i<n;i++) sum += arr[i];

    if(sum%2 != 0) return true;

    vector<vector<bool>> dp(n+1, vector<bool>(sum/2+1));

    for(int i=0;i<=n;i++) {
        dp[i][0] = true;
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=sum/2;j++) {
            int val = arr[i-1];
            if(val > j) dp[i][j] = dp[i-1][j];
            else dp[i][j] = dp[i-1][j-val] || dp[i-1][j];
        }
    }

    return !dp[n][sum/2];
}

int findMinSignificantBitIdx(vector<int> &arr) {
    int minIdx = -1, minPos = 32;
    int n = arr.size();

    for(int i=0;i<n;i++) {
        int val = arr[i];
        int pos = 0;
        while(val % 2 == 0) {
            val = val >> 1;
            pos++;
        }

        if(pos < minPos) {
            minIdx = i;
            minPos = pos;
        }
    }

    return minIdx;
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

    if(isGood(arr)) {
        cout << "0" << "\n";;
    }
    else {
        cout << "1 \n" << findMinSignificantBitIdx(arr)+1 << "\n";;
    }
    
}