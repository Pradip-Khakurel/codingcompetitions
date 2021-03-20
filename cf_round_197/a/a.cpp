#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <assert.h>
#include <math.h>
#include <tuple>
#include <unordered_map>

using namespace std;

tuple<int, int> getCoordinates() {
    int r, c, x;

    for(int i=1;i<=5;i++) {
        for(int j=1;j<=5;j++) {
            cin >> x;

            if(x == 1) {
                 return make_tuple(i, j);
            }
        }
    }

    return make_tuple(-3, -3);
}

int main() {

    int counts[4] = { 0, 0, 0, 0 };
    string input;
    cin >> input;

    for(int i=0;i<input.size();i+=2) {
        int c = (int)input[i]-48;
        counts[c]++;
    }

    string output="";

    for(int i=1;i<=3;i++) {
        for(int j=0;j<counts[i];j++) {
            output+= to_string(i) + "+";
        }
    }
    
    output.pop_back();

    cout << output;

    return 0;
}