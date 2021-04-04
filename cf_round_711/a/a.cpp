#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <assert.h>
#include <math.h>
#include <tuple>
#include <unordered_set>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

ll getb(int a) {
    string a_str = to_string(a);
    ll sum = 0;
    for(int i = 0;i < a_str.size(); i++) {
        sum += a_str[i] - '0';
    }
    return sum;
}

int main() {
    ll a, T;
    cin >> T;

    for(int t=0;t<T;t++) {
        cin >> a;
        ll ans = gcd(a, getb(a));

        while(ans == 1) {
            a++;
            ans = gcd(a, getb(a));
        }

        cout << a << "\n";
    }

    return 0;
}