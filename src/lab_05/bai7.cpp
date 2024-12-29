#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    int n;
    cin >> n;

    int ans = 0, sum = 0;

    while (n--) {
        int k, t;
        cin >> k >> t;

        int local_sum = 0; 
        for (int i = 0; i < k; ++i) {
            int a;
            cin >> a;
            local_sum += a;
        }

        if (t == 1) sum += local_sum;    
        if (t == -1) sum -= local_sum;  

        ans = max(ans, -sum); 
    }

    cout << ans << '\n';
    return 0;
}
