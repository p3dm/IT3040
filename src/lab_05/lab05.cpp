//Bai 1
#include <stdio.h>

int x[100], mark[100], n;

void print(){
    for (int i = 1; i <= n; ++i) printf("%d ", x[i]);
    printf("\n"); // sai từ khóa
}

void process(int i) {
    if (i > n){
        print(); //sai từ khóa
        return;
    }
    for (int j = 1; j <= n; ++j)
        if (!mark[j]){
            mark[j] = 1;
            x[i] = j;
            process(i+1);
            mark[j] = 0;
        }
}

int main() {
    n = 5;
    process(1);
    return 0;
}
//---------------------------------------------------------

//Bai 2
#include <iostream>
using namespace std;

int n, M, m[100], v[100];
int x[100], best, sumV, sumM, All[100];


void init(){
    for (int i = n; i >= 1; --i){
        All[i] = All[i+1] + v[i]; // sai cú pháp hàm
    }
}

void print() {
    cout << best;
}

void process(int i){
    if (sumV + All[i] <= best || sumM > M) return; //ko return ve 0
    if (i > n){
        best = sumV; // thiếu ';'
    }
    process(i+1);
    sumM += m[i];
    sumV += v[i];
    process(i+1);
    sumM -= m[i];
    sumV -= v[i];
}

int main() {
    cin >> n >> M;
    for (int i = 1; i <= n; ++i)
        cin >> m[i] >> v[i];
    init();
    process(1);
    print();
    return 0;
}
//---------------------------------------------------------

//Bai 3
#include <iostream>
#include <string.h>
#include <stack>

using namespace std; 

int par(string str){
    int a = str.length();
    stack<char> S;
    char x, y;
    for (int i=0; i<a; i++){
        x = str[i];
        if (x == '(' || x == '[' || x == '{'){
            S.push(x);
        }
        else {
            if (x == ')') {
                if (!S.empty() && S.top() == '('){// loi dieu kien
                    S.pop();
                }
                else return 0;
            }
            else if (!S.empty() && x == ']') { // loi dieu kien
                if (S.top() == '['){
                    S.pop();
                }
                else return 0;
            }
            else if (!S.empty() && x == '}') {// loi dieu kien
                if (S.top() == '{'){
                    S.pop();
                }
                else return 0;
            }
        }
    }
    if (!S.empty()){ //loi logic
        return 0;
    }
    else return 1;
}
 
int main(){
    int n;
    string str;
    
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> str;
        cout << par(str) << endl;
    }
    
    return 0;
}
//---------------------------------------------------------

//Bai 4
#include <bits/stdc++.h>
using namespace std;
int m, n, Smin = 100000;
long long S = 0;
int cmin = 100000000;
int x[100];
int c[100][100];
vector<int> flag(100, false);
void TRY(int k)
{
    for (int i = 2; i <= n; i++)
    {
        if (flag[i] == false && c[x[k - 1]][i] != -1)
        {
            flag[i] = true;
            x[k] = i;
            S = S + c[x[k - 1]][i];
            if (k == n)
            {
                if (S + c[i][1] < Smin && c[i][1] != -1)
                    Smin = S + c[i][1];
            }
            else if (S + cmin * (n - k + 1) < Smin)
            {
 
                TRY(k + 1);
            }
            flag[i] = false;
            S = S - c[x[k - 1]][i];
        }
    }
}
main()
{
    int a, b;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                c[i][j] = 0;
            else
                c[i][j] = -1;
        }
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        cin >> c[a][b];
        if (c[a][b] < cmin)
            cmin = c[a][b];
    }
    x[1] = 1;
    flag[1] = true;
    TRY(2);
    cout << Smin;
}
//---------------------------------------------------------

//Bai 5
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    bool found = false;
    while(n--){
        int a;
        cin >> a;
        if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0)){
            found = true;
            cout << "Yes";
            return 0;
        }

    }
    cout << "No";
}
//---------------------------------------------------------

//Bai 6
#include <bits/stdc++.h>
using namespace std;

char cal(double a) {
    if (a < 4) return 'F';
    else if (a < 5.5) return 'D';
    else if (a < 7) return 'C';
    else if (a < 8.5) return 'B';
    else return 'A';
}

int main() {
    int n;
    cin >> n;
    int A = 0, B = 0, C = 0, D = 0, F = 0;

    while (n--) {
        double a; 
        cin >> a;

        char grade = cal(a); 
        switch (grade) {
            case 'A': ++A; break;
            case 'B': ++B; break;
            case 'C': ++C; break;
            case 'D': ++D; break;
            case 'F': ++F; break;
        }
    }

    cout << A << " " << B << " " << C << " " << D << " " << F;
    return 0;
}

//---------------------------------------------------------

//Bai 7
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int ans = 0, sum = 0;
    while(n--){
        int k, t;
        cin >> k >> t;

        if(t == 1){
            while(k--){
                int a;
                cin >> a;
                sum += a;
                ans = max(ans, -sum);
            }
        } else {
            while(k--){
                int a;
                cin >> a;
                sum -= a;
                ans = max(ans, -sum);
            }
        }
    }
    cout << ans;
}
//---------------------------------------------------------------------------------

//Bai 8
#include <bits/stdc++.h>
using namespace std;

int w, h;
int table[601][601];

void init() {
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            table[i][j] = i * j; 
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    cin >> w >> h;
    int m;
    cin >> m;
    init();
    for (int i = 0; i < m; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        table[tmp2][tmp1] = 0; 
    }

    //dp
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            int minWaste = table[i][j];
            //horizontal cut
            for (int k = 1; k < i; k++) {
                minWaste = min(minWaste, table[k][j] + table[i - k][j]);
            }
            //vertical cut
            for (int k = 1; k < j; k++) {
                minWaste = min(minWaste, table[i][k] + table[i][j - k]);
            }
            table[i][j] = minWaste;
        }
    }

    cout << table[h][w] << endl;
    return 0;
}
//---------------------------------------------------------------------------------

//Bai 9
