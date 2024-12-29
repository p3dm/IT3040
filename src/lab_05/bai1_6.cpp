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
