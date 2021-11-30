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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, n, l, r, k, x;
    cin >> T;

    for(int t=0;t<T;t++) {
        cin >> n >> l >> r >> k;
        vector<int> list;
        for(int i=0;i<n;i++) {
            cin >> x;
            if(x < l || x > r) continue;
            list.push_back(x);
        }
        sort(list.begin(), list.end());

        int e = 0, ans = 0, i = 0;

        while(i < list.size() && list[i]+e <= k) {
            e += list[i++];
            ans +=1;
        }

        cout << ans << "\n";
    }
    
    return 0;
} 