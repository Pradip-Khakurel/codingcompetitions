#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map> 
#include <assert.h>
#include <math.h>

using namespace std;

struct cell {
    int r;
    int c;
    char val;

    cell(int _r, int _c, vector<vector<char>> &matrix) {
        r = _r;
        c = _c;
        val = matrix[r][c];
    }
};

int main() {
    int n, T;
    string s;
    cin >> T;

    for(int t=0;t<T;t++) {
        cin >> n;
        
        vector<vector<char>> matrix(n, vector<char>(n));

        for(int i=0;i<n;i++) {
            cin >> s;
            for(int j=0;j<n;j++) {
                matrix[i][j] = s[j];
            }
        }

        cell downStart(1, 0, matrix), rightStart(0, 1, matrix), upFinish(n-2, n-1, matrix), leftFinish(n-1, n-2, matrix);

        vector<cell> result;

        if(downStart.val == rightStart.val) {
            if(downStart.val == upFinish.val) {
                result.push_back(upFinish);
            }
            if(downStart.val == leftFinish.val) {
              result.push_back(leftFinish);
            }
        }
        else if (upFinish.val == leftFinish.val) {
            if(upFinish.val == downStart.val) {
                result.push_back(downStart);
            }
            if(upFinish.val == rightStart.val) {
              result.push_back(rightStart);
            }
        }
        else {
            result.push_back(rightStart);

            if(downStart.val == upFinish.val) {
                result.push_back(upFinish);
            }
            else {
                result.push_back(leftFinish);            
            }
        }

        cout << result.size() << "\n";

        for(int i=0;i<result.size();i++) {
            cout << result[i].r+1 << " " << result[i].c+1 << "\n";
        }
    }

    return 0;
}