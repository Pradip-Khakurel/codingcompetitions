#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <assert.h>
#include <math.h>
#include <tuple>
#include <unordered_set>

using namespace std;

int findLargestFit(vector<int> &powers, int curr_w, int w) {
    for(int i=powers.size()-1;i>=0;i--) {
        if(powers[i] > 0 && curr_w+pow(2,i) <= w) {
            return i;
        }
    }
    return -1;
}
/***
 * 2
5 16
1 2 8 4 8
6 10
2 8 8 2 2 8
 * 
*/
int getMinimumHeight(vector<int> &arr, int w) {
    vector<int> powers(21);

    for(int i=0;i<arr.size();i++) {
        int val = arr[i];
        powers[log2(val)] +=1;
    }

    int height = 0;
    int n = arr.size();
    int curr_w = 0;

    while (n > 0) {
        int largestIdx = findLargestFit(powers, curr_w, w);
        if(largestIdx == -1) {
            height++;
            curr_w = 0;
        }
        else {
            curr_w += pow(2,largestIdx);
            powers[largestIdx]--;
            n--;
        }
    }

    return height+1;
}


int main() {
    int n, w, T;
    cin >> T;

    for(int t=0;t<T;t++) {
        cin >> n >> w;

        vector<int> arr(n);

        for(int i=0;i<n;i++) {
            cin >> arr[i];
        }

        cout << getMinimumHeight(arr, w) << "\n";
    }

    return 0;
}