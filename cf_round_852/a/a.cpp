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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll T, a, b, n, m;
    cin >> T;

    for(int t=0;t<T;t++) {
        cin >> a >> b;
        cin >> n >> m;

        ll cost = 0;
        int numberOfTimesPromoIsUsed = n/(m+1);
        int numerOfItemsLeftToBuyAfterPromo = n%(m+1);

        if(a <= b) {
            cost = numberOfTimesPromoIsUsed * m * a + numerOfItemsLeftToBuyAfterPromo*a;
        }
        else { // a > b
            if(m < n && (m*a < (m+1)*b)) { 
                cost = numberOfTimesPromoIsUsed * m * a + numerOfItemsLeftToBuyAfterPromo*b;
            }   
            else {
               cost = n*b;
            }
        }

        cout << cost << "\n";
    }
}