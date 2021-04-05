#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <assert.h>
#include <math.h>
#include <tuple>
#include <unordered_set>

using namespace std;

int countOnes(string &s) {
    int count = 0;

    for(int i=0;i<s.size();i++) {
        if(s[i] == '1') {
            count++;
        }
    }

    return count;
}

void fillOnes(string &s, vector<string> &result, int ones) {
    int current_ones = 0;
    for(int i=0;i<s.size();i++) {
        if(s[i] == '0') continue;

        current_ones++;

        if(current_ones <= ones / 2) {
            result[0][i] = '(';
            result[1][i] = '(';
        }
        else {
            result[0][i] = ')';
            result[1][i] = ')';
        }    
    }
}
// 101101
//  (  )


void fillZeros(string &s, vector<string> &result) {
    bool alternate = true;
    for(int i=0;i<s.size();i++) {
        if(s[i] == '1') continue;

        if(alternate) {
            result[0][i] = '(';
            result[1][i] = ')';
        }
        else {
            result[0][i] = ')';
            result[1][i] = '(';
        } 

        alternate = !alternate;  
    }
}

// 101101

vector<string> balance(string &s) {
    int n = s.size();
    //cout << s[0];

    if(s[0] != '1' || s[n-1] != '1') {
        return vector<string>();
    }

    int ones = countOnes(s);

    if(ones % 2 != 0) {
        return vector<string>();
    }

    vector<string> result;
    result.push_back(string(n, ' '));
    result.push_back(string(n, ' '));

    fillOnes(s, result, ones);
    fillZeros(s, result);

    return result;
}

int main() {
    int T, n;
    string s;
    cin >> T;

    for(int t=0;t<T;t++) {
        cin >> n >> s;

        vector<string> res = balance(s);

        if(res.size() == 0) {
            cout << "NO \n";
        }
        else {
            cout << "YES \n" << res[0] << "\n" << res[1] << "\n";
        }
    }

    return 0;
} 