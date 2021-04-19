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


vector<int> getPhotogenicArray(vector<int> &arr) {
    int n = arr.size();
    vector<int> result;

    for(int i=0;i<n;i++) {
        if(arr[i] % 2 != 0) result.push_back(arr[i]);
    }

    for(int i=0;i<n;i++) {
        if(arr[i] % 2 == 0) result.push_back(arr[i]);
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, n;
    cin >> T;

    for(int t=0;t<T;t++) {
        cin >> n;

        vector<int> arr(n);
        
        for(int i=0;i<n;i++) {
            cin >> arr[i];
        }

        vector<int> result = getPhotogenicArray(arr);

        for(int i=0;i<n;i++) {
            cout << result[i] << " ";
        }

        cout << "\n";
    }

    return 0;
} 