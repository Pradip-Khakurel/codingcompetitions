#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <assert.h>
#include <math.h>
#include <tuple>

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

    tuple<int, int> coords = getCoordinates();
    int ans = abs(3-get<0>(coords))+abs(3-get<1>(coords));

    cout << ans;
    
    return 0;
}