//Bài 1:
#include<iostream>

int lucas(int n)
{
    if (n <= 1)
        return 2 - n;
    return lucas(n - 1) + lucas(n - 2);
}
//----------------------------------------------------------------------------------

//Bài 2:
#include <iostream>
using namespace std;

int n;
int X[100], Y[100]; 
int mark[100][100]; 


const int hx[] = {1, 1, 2, 2, -1, -1, -2, -2};
const int hy[] = {2, -2, 1, -1, 2, -2, 1, -1};

void print_sol() {
    for (int j = 1; j <= n * n; ++j)
        printf("(%d %d)\n", X[j], Y[j]);
    exit(0);
}


void TRY(int k) {
    for (int i = 0; i < 8; i++) { 
        int xx = X[k - 1] + hx[i];
        int yy = Y[k - 1] + hy[i];

        
        if (xx >= 1 && yy >= 1 && xx <= n && yy <= n && mark[xx][yy] == 0) {
        
            mark[xx][yy] = 1;
            X[k] = xx;
            Y[k] = yy;

            if (k == n * n) {
                print_sol();
            } else {
                TRY(k + 1);
            }
            mark[xx][yy] = 0;
        }
    }
}

int main() {
    cin >> n; 
    mark[1][1] = 1; 
    X[1] = Y[1] = 1;
    TRY(2);
    return 0;
}

//----------------------------------------------------------------------------------

//Bài 3:
#include <bits/stdc++.h>
using namespace std;
#define MAX 100  

int n, c[MAX][MAX];
int cmin = INT_MAX; 
int best = INT_MAX;
int curr = 0;       
int mark[MAX];    
int x[MAX];         


void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> c[i][j];
            if (c[i][j] > 0) cmin = min(cmin, c[i][j]);
        }
    }
}


void TRY(int k) {
    for (int i = 2; i <= n; i++) { 
        if (!mark[i] && c[x[k - 1]][i] > 0) { 
            mark[i] = 1;                     
            x[k] = i;                         
            curr += c[x[k - 1]][i];           

            
            if (k == n) {
                if (c[x[k]][1] > 0) { 
                    best = min(best, curr + c[x[k]][1]); 
                }
            } else if (curr + cmin * (n - k + 1) < best) {
                
                TRY(k + 1);
            }

    
            mark[i] = 0;
            curr -= c[x[k - 1]][i];
        }
    }
}

int main() {
    input();
    x[1] = 1;      
    mark[1] = 1;   
    TRY(2);        
    cout << best;  
    return 0;
}
//----------------------------------------------------------------------------------

//Bài 4:
#include <bits/stdc++.h>
using namespace std;

int a[1000], n;
int mem[1000]; 

void init() {
    memset(mem, -1, sizeof(mem)); 
}

int lis(int i) {
    if (mem[i] != -1) return mem[i]; 

    mem[i] = 1; 
    for (int j = 0; j < i; j++) {
        if (a[j] < a[i]) { 
            mem[i] = max(mem[i], 1 + lis(j));
        }
    }
    return mem[i];
}

void trace(int i) {
    for (int j = 0; j < i; j++) {
        if (a[j] < a[i] && mem[i] == 1 + mem[j]) { 
            trace(j); 
            break;
        }
    }
    cout << a[i] << " ";
}

int main() {
    init(); 
    cin >> n; 
    for (int i = 0; i < n; i++) cin >> a[i]; 

    int res = 1, pos = 0; 
    for (int i = 0; i < n; i++) {
        if (res < lis(i)) { 
            res = lis(i);
            pos = i;
        }
    }

    cout << res << endl; 
    trace(pos);          
    
}
//----------------------------------------------------------------------------------

//Bài 5:
#include <iostream>
using namespace std;

int binom(int n, int k) {
    if (k > n) return 0;
    if (k == 0) return 1;
    return binom(n-1, k) + binom(n-1, k-1);
}

int binom2(int n, int k){
    if (k > n) return 0;
    if (k == 0) return 1;
    return binom2(n-1, k) + binom2(n-1, k-1);
}

int main() {
    int m;
    cin >> m;
    for (int n = 1; n <= m; ++n){
        for (int k = 0; k <= n; ++k)
            printf("%d ", binom(n, k));
        printf("\n");
    }
    for (int n = 1; n <= m; ++n){
        for (int k = 0; k <= n; ++k)
            printf("%d ", binom2(n, k));
        printf("\n");
    }
    return 0;
}
//----------------------------------------------------------------------------------
//Bài 6:
#include<iostream>

using namespace std;

int ucln(int a, int b){
    if (a % b == 0) return b;
    return ucln(b, a%b);
}

int main(){
    int a, b;
    cin >> a >> b;
    cout << ucln(a, b) << endl;
    cout << ucln(a, b);
    return 0;
}
//----------------------------------------------------------------------------------
//Bài 7:

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct state {
    int i, j, old_L;
    state(int _i = 0, int _j = 0, int _L = 0)
        : i(_i)
        , j(_j)
        , old_L(_L)
    {
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> x(n + 1);
    stack<state> s;
    int L = 0;
    s.push(state(1, 0));
    while (!s.empty()) {
        state& top = s.top();
        if (top.i > n) {
            for (int i = 1; i <= n; ++i)
                cout << x[i] << " \n"[i == n];
            s.pop();
            continue;
        }
        if (top.j > 0)
            L = top.old_L;
        if (top.j > 1) {
            s.pop();
            continue;
        }
        if (L + 1 < k || top.j == 0) {
            x[top.i] = top.j;
            top.old_L = L;
            L = top.j ? L + 1 : 0;
            s.push(state(top.i + 1, 0));
        }
        ++top.j;
    }
    return 0;
}
//----------------------------------------------------------------------------------
