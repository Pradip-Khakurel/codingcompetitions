#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <assert.h>
#include <math.h>
#include <tuple>
#include <unordered_set>

using namespace std;

vector<int> getArray(int n, int k) {
    int max_k = n < 3 ? 0 : 1+(n-3)/2;
    
    if(k > max_k) {
        return vector<int>(1, -1);    
    }

    vector<int> ans(n, 1);

    int i = 1;

    while (k > 0) {
        ans[i] = i+2;
        ans[i+1] = i+1;
        k--;
        i+=2;
    }

    for(;i<n;i++) {
        ans[i] = i+1;
    }

    return ans;
}

int main() {
    int T, n, k;
    cin >> T;

    for(int t=0;t<T;t++) {
        cin >> n >> k;

        vector<int> arr = getArray(n, k); 
        
        for(int i=0;i<arr.size();i++) {
            cout << arr[i] << " ";
        }

        cout << "\n";
    }

    return 0;
} 