#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <assert.h>
#include <math.h>

using namespace std;

bool ithBitIsOne(int x, int i) {
    int mask = 1 << i;
    return (x & mask) != 0;
}


int main() {
    int n, T;
    cin >> T;

    for(int t=0;t<T;t++) {
        int a, b;

        cin >> a >> b;

        int x=0;

        for(int i=0;i<31;i++) {
            if(ithBitIsOne(a, i) && ithBitIsOne(b, i)){
                x = x | (1 << i); // set the ith bit to 1
            }
        }

        cout << (a^x)+(b^x) << "\n";
    }

    return 0;
}