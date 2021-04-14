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

bool IsOk(vector<int> &arr, int v) {
    for(int i=0;i<arr.size();i++) {
        if((v & arr[i]) != v) return false;
    }
    return true;
}

ll fact(ll n){
     return (n==0) || (n==1) ? 1 : n* fact(n-1)%NUMBER;
}

int getAndSequences(vector<int> &arr) {
    unordered_map<int, ll> map;
    
    for(int i=0;i<arr.size();i++) {
        map[arr[i]]++;
    }

    ll count = 0;

    for(auto const &pair : map) {
        if(pair.second < 2 || !IsOk(arr, pair.first)) continue;

        count += (pair.second*(pair.second-1)%NUMBER)*(fact(arr.size()-2)%NUMBER)%NUMBER;
    }

    return count;
}

int main() {
    int T, n;
    cin >> T;

    for(int t=0;t<T;t++) {
        cin >> n;

        vector<int> arr(n);
        
        for(int i=0;i<n;i++) {
            cin >> arr[i];
        }


        cout << getAndSequences(arr) << "\n";
    }

    return 0;
} 