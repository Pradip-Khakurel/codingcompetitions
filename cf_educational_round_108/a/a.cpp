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

string canMakeRedAndBluePackets(ll r, ll b, ll d) {
    return b <= (r*(d+1)) ? "YES": "NO";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, r, b, d;
    cin >> T;

    for(int t=0;t<T;t++) {
        cin >> r >> b >> d;

        if(r < b) {
            cout << canMakeRedAndBluePackets(r, b, d) << "\n";
        }
        else {
            cout << canMakeRedAndBluePackets(b, r, d) << "\n";
        }

    }

    return 0;
} 