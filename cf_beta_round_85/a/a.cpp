#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
 
using namespace std;
 
int compare(string &s1, string &s2) {
    for(int i=0; i< s1.size();i++) {
        if(tolower(s1[i]) == tolower(s2[i])) {
            continue;
        }
        else if(tolower(s1[i]) < tolower(s2[i])) {
            return -1;
        }
        else {
            return 1;
        }
    }

    return 0;
}

int main() {
    string s1, s2;
    
    cin >> s1 >> s2;
    
    cout << compare(s1, s2);
 
    return 0;
}