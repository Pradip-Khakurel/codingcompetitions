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

void addRemaining(string &s, string &t, int i) {
    while(i < t.size()) {
        s += t[i];
        i++;
    }
}

string computeBinaryString(string &a, string &b, string &c) {
    int i=0, j=0, k=0;
    int n2 = a.size();
    string s;

    while(i < n2 && j < n2 && k < n2) {
        if(a[i] == b[j]) {
            s += a[i];
            i++;
            j++;
        }
        else if(a[i] == c[k]) {
            s += a[i];
            i++;
            k++;

        }
        else {
            s += b[j];
            j++;
            k++;
        }
    }

    if(i == n2) {
        if(j > k) addRemaining(s, b, j);
        else addRemaining(s, c, k);
    }
    else if(j == n2) {
        if(i > k) addRemaining(s, a, i);
        else addRemaining(s, c, k);
    }
    else {
        if(i > j) addRemaining(s, a, i);
        else addRemaining(s, b, j);
    }

    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, n;
    cin >> T;

    for(int t=1;t<=T;t++) {
        string a, b, c;
        cin >> n >> a >> b >> c;

        cout << computeBinaryString(a, b, c) << "\n";
    }
}