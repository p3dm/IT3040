#include <iostream>
#include <map>

using namespace std;

inline int calc(int v) {
    return v * (v-1) / 2;
}

int main() {
    string str;
    cin >> str;
    
    map<int, int> m; 
    map<int, int>::iterator it;
    int difference = 0; 
    
    for (char c : str) {
        if (c == '0') difference--; 
        else difference++; 
        
        it = m.find(difference);
        if (it != m.end()) { 
            it->second += 1; 
        } else {
            m.insert({difference, 1});
        }
    }
    
    int res = 0; // result
    for (it = m.begin(); it != m.end() ; ++it) {
        res += calc(it->second);
        if (it->first == 0) res += it->second; 
    }
    
    cout << res;
    return 0;
}

