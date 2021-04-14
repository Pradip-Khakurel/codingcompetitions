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
int max_n =200005;
vector<ll> dp(max_n);
 
ll addOne(string &s, int m) {
    ll count = 0;
 
    for(int i=0;i<s.size();i++) {
        int c = s[i] - '0';
 
        if(m+c < 10) {
            count += 1;
        }
        else {
            count = (count + dp[m-10+c]) % NUMBER;
        }
    }
 
    return count;
}
 
void initdp(){
    for(int i=0;i<9;i++) {
        dp[i] = 2;
    }
 
    dp[9] = 3;
 
    for(int i=10;i<max_n;i++) {
        dp[i] = (dp[i-10] + dp[i-9])%NUMBER;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    initdp();
 
    int T, m;
    string s;
    cin >> T;
 
    for(int t=0;t<T;t++) {
        cin >> s >> m;
 
        cout << addOne(s, m) << "\n";
    }
 
    return 0;
}