#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
 
using namespace std;
 
int main() {
    int r, c, ans;
 
    cin >> r >> c;
    
    if(r % 2 == 0 || c % 2 == 0) {
        ans = (r*c)/2;
    }
    else {
        ans = (r*c-1)/2+r/2;
    }
 
    cout << ans;
 
    return 0;
}