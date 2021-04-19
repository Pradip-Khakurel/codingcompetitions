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

void lexicographicalSmaller(vector<int> &arr, int k) {
    int i = 0;
    
    while(k > 0) {
        if(i >= arr.size()-1) return;

        if(arr[i] == 0) {
            i++;
            continue;
        }

        arr[i]-=1;
        arr[arr.size()-1] +=1;
        k--;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, n, k;
    cin >> T;

    for(int t=0;t<T;t++) {
        cin >> n >> k;
        vector<int> arr(n);

        for(int i=0;i<n;i++) {
            cin >> arr[i];
        }

        lexicographicalSmaller(arr, k);

        for(int i=0;i<n;i++) {
            cout << arr[i] << " ";
        }

        cout << "\n";
    }
}