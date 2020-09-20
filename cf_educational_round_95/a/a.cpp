#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <assert.h>
#include <math.h>

using namespace std;
int main() {
    long long T, x, y, k, result;
    cin >> T;

    for(int i=0;i<T;i++) {
        cin >> x >> y >> k;

        long long result = (k-1 + y*k+ x-2)/(x-1) + k;
        cout << result << "\n";
    }

    return 0;
}