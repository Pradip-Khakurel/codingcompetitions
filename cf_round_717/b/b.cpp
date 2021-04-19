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

string canAgagaaXor(vector<ll> &arr) {
    ll n = arr.size();
    ll a = 0;
    
    for(int i=0;i<n;i++) {
        a ^= arr[i];
    }

    if(a == 0) return "YES";  
    ll x = 0, y = 0, z = 0;

    for(int i=0;i<n-2;i++) {
        x ^= arr[i];
        for(int j=i+1;j<n-1;j++) {
            y ^= arr[j];

            z = a ^ x ^ y;
        
            if(x == y && y == z) return "YES";
        }
        y = 0;
    }

    return "NO";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, n;
    cin >> T;

    for(int t=1;t<=T;t++) {
        cin >> n;
        vector<ll> arr(n);

        for(int i=0;i<n;i++) {
            cin >> arr[i];
        }

        cout << canAgagaaXor(arr) << "\n";
    }
}