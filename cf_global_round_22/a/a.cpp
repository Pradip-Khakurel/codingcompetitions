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

ll sum(vector<int> &arr) {
    ll ans = 0;
    for(int i=0;i<arr.size();i++) {
        ans+=arr[i];
    }
    return ans;
}

ll interleaveSum(vector<int> const &arr1, vector<int> const &arr2) {
    ll ans = 0;
   
    int n = min(arr1.size(), arr2.size());

    for(int i=0;i<n;i++) {
        ans += 2*arr1[i];
        ans += 2*arr2[i];
    }

    if(arr1.size() == arr2.size()) {
        ans -= min(arr1[n-1], arr2[n-1]);
    }
    else if(arr1.size() > arr2.size()) {
        for(int i=n;i<arr1.size();i++) {
            ans+= arr1[i];
        }
    }
    else  { // if(arr2.size() > arr1.size())
        for(int i=n;i<arr2.size();i++) {
            ans+= arr2[i];
        }
    }

    return ans;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, n, x;
    cin >> T;

    for(int t=0;t<T;t++) {
        cin >> n;

        vector<int> types(n);

        for(int i=0;i<n;i++) {
            cin >> types[i];
        }

        vector<int> fires;
        vector<int> frosts;

        for(int i=0;i<n;i++) {
            cin >> x;
            if(types[i] == 0) {
                fires.push_back(x);
            }
            else {
                frosts.push_back(x);
            }
        }

        ll ans = 0;

        if(fires.size() == 0) {
            ans = sum(frosts);
        }
        else if(frosts.size() == 0) {
            ans = sum(fires);
        }
        else {
            sort(fires.begin(), fires.end(), greater<>());
            sort(frosts.begin(), frosts.end(), greater<>());

            ans = interleaveSum(frosts, fires);
        }

        cout << ans << "\n";
    }

    return 0;
} 