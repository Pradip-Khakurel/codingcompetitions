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
// TMTMTT
string isSubsequence(string &s) {
    int n = s.size();
    
    vector<int> leftTs(n);
    vector<int> rightTs(n);

    int count;
    count = 0;
    for(int i=0;i<n;i++) {
        if(s[i] == 'T') count++;
        leftTs[i] = count;
    }

    if((count % 2) != 0 || count/2 != n-count) {
        return "NO";
    }

    count = 0;
    for(int i=0;i<n;i++) {
        if(s[i] == 'T') count++;
        else count--;
        if (count < 0) return "NO";
    }
    
    count = 0;
    for(int i=n-1;i>=0;i--) {
        if(s[i] == 'T') count++;
        else count--;
        if (count < 0) return "NO";
    }

    return "YES";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T, n;
    string s;
    cin >> T;

    for(int t=0;t<T;t++) {
        cin >> n >> s;

        cout << isSubsequence(s) << "\n";
    }

    return 0;
} 