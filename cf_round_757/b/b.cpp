#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <assert.h>
#include <math.h>
#include <tuple>
#include <unordered_map>
#include <deque>

using namespace std;

typedef long long ll;
ll NUMBER = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, n, a;
    cin >> T;

    for(int t=0;t<T;t++) {
        cin >> n;
        vector<pair<int, int>> arr;

        for (int i = 0; i < n; ++i) {
            cin >> a;
            arr.push_back(make_pair(a, i));
        }

        sort(arr.begin(), arr.end(), greater<pair<int, int>>());

        vector<pair<int, int>> coords;
        ll left=0, right=0;
        ll sum = 0;

        for(int i=0;i<arr.size(); i++) {
            if(i % 2 == 0) {
                right++;
                coords.push_back(make_pair(arr[i].second, right));
                sum += 2 * arr[i].first * right;
            }
            else {
                left--;
                coords.push_back(make_pair(arr[i].second, left));
                sum += 2 * arr[i].first * -left;
            }
        }

        sort(coords.begin(), coords.end());

        cout << sum << "\n";

        cout << 0 << " ";

        for(int i=0; i<coords.size(); i++) {
            cout << coords[i].second << " ";
        }

        cout << "\n";

    }
    
    return 0;
} 