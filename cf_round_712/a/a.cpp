#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <assert.h>
#include <math.h>
#include <tuple>
#include <unordered_set>

using namespace std;


// cbaba
//    ^

int find(string &s) {
    int n = s.size();
    int midLeft, midRight;

    if(n % 2 == 0) {
        midLeft = n/2-1;
        midRight = n/2;
    }
    else {
        midRight = n/2;
        midLeft = n/2;
    }

    for(int i=0;i<n;i++) {
        if(i < midLeft && s[n-i-2] != 'a') {
            return i;
        }
        if(i > midRight && s[n-i-1] != 'a') {
            return i;
        }
    }

    if(midRight == midLeft && s[midLeft] != 'a') {
        return midLeft;
    }

    if(midLeft != midRight && s[midLeft] != 'a') {
        return midLeft+1;
    }

    if(midLeft != midRight && s[midRight] != 'a') {
        midLeft-1;
    }

    return -1;
}

string breakPalindrome(string &s) {
    int n = s.size();

    if(s[n-1] != 'a'){
        return "a" + s;
    }
    
    int idx = find(s);

    if(idx != -1) {
        return s.substr(0, idx+1) + "a" + s.substr(idx+1, n-idx-1);
    }

    return "";
    
}

int main() {
    int T;
    cin >> T;

    for(int t=0;t<T;t++) {
        string s;
        cin >> s;

        string ans = breakPalindrome(s);

        if(ans != "" ) {
            cout << "YES \n" << ans << "\n";
        }
        else {
            cout << "NO \n";
        }
    }

    return 0;
} 