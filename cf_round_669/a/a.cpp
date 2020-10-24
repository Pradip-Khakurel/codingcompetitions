#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <assert.h>
#include <math.h>

using namespace std;

void print(vector<int> arr) {
    int countOnes = 0;

    for(int i=0;i<arr.size();i++) {
        if(arr[i] == 1) countOnes++;
    }

    if (countOnes <= arr.size()/2) {
        cout << (arr.size() - countOnes) << "\n";

        for(int i=0;i<arr.size()-countOnes;i++) {
            cout << "0 ";
        }
    }
    else {
        if(countOnes % 2 != 0) {
            countOnes--;
        }

        cout << countOnes << "\n";

        for(int i=0;i<countOnes;i++) {
            cout << "1 ";
        }
    }
}


int main() {
    int n, T;
    cin >> T;

    for(int t=0;t<T;t++) {
        cin >> n;

        vector<int> arr(n), res;

        for(int i=0;i<n;i++) {
            cin >> arr[i];
        }

        print(arr);

        cout << "\n";
    }

    return 0;
}