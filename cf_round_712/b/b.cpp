#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <assert.h>
#include <math.h>
#include <tuple>
#include <unordered_set>

using namespace std;


struct result {
    bool flipped;
    bool canMatch;

    result(bool _flipped, bool _canTransform) {
        flipped = _flipped;
        canMatch = _canTransform;
    }
};
/**
 * 0111010000
   0100101100
            ^
 * **/
result transform(string &a, string &b, int i, int countOnes) {
    int n = a.size();
    
    if(i == n) {
        return result(false, true);
    }

    if(a[i] == '1') {
        countOnes++;
    }

    result next = transform(a, b, i+1, countOnes);

    if(!next.canMatch) {
        return next;
    }

    bool matchWithoutflippingHere = (next.flipped && a[i] != b[i]) || !next.flipped && a[i] == b[i];

    if(matchWithoutflippingHere) {
        return next;
    }

    bool matchByFlippingHere = ((i+1) % 2 == 0) && (countOnes == (i+1)/2);

    if(matchByFlippingHere) {
        return result(!next.flipped, true);
    }

    return result(false, false);
}

int main() {
    int T, n;
    string a, b;
    cin >> T;

    for(int t=0;t<T;t++) {
        cin >> n >> a >> b;;

        result ans = transform(a, b, 0, 0);

        if(ans.canMatch) {
            cout << "YES \n";
        }
        else {
            cout << "NO \n";
        }
    }

    return 0;
} 