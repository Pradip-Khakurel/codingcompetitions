#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
/***
 
8 5
10 9 8 7 7 7 5 5
 ***/

int calculate(vector<int> v) {
    int size = v.size();

    if (size <= 2) return size;

    int i=0, j=1, val=v[1]-v[0];
    int ans = 2;
    while(i < size-1) {
        while(j < size  && v[j]-v[j-1] == val) {
            ans = max(ans, j-i+1);
            j++;
        }
        val = v[j]-v[j-1];
        i = j-1;
    }
    return ans;
}

int main() {
    int T;
    cin >> T;

    for(int i=0;i<T;i++) {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int j=0;j<n;j++) {
            cin >> v[j];
        }

        cout << "Case #" << (i+1) <<": " << calculate(v) << "\n";
    }

    return 0;
}