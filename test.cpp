#include <bits/stdc++.h>
using namespace std;

struct state {
    int i, j, old_L;
    // Constructor
    state(int _i = 0, int _j = 0, int _L = 0) : i(_i), j(_j), old_L(_L) {}
};

int main() {
    int n, k;
    cin >> n >> k;
    int x[n + 1];          // Binary sequence
    stack<state> s;        // Stack for simulating recursion
               // Number of consecutive suffix 1s
    s.push(state(1, 0, 0)); // Start with the first position

    while (!s.empty()) {
        state &top = s.top();

        // If a new binary sequence is found
        if (top.i > n) {
            for (int i = 1; i <= n; ++i)
                cout << x[i] << " \n"[i == n];
            s.pop();
            continue;
        }

        // Non-recursive backtracking logic
        if (top.j <= 1) { // Try assigning 0 or 1
            x[top.i] = top.j; // Assign value (0 or 1)
            int new_L = (top.j == 1 ? top.old_L + 1 : 0); // Update L
            if (new_L < k) { // Check if the sequence is valid
                s.push(state(top.i + 1, 0, new_L)); // Move to the next position
            }
            top.j++; // Increment the choice for the current position
        } else {
            s.pop(); // Backtrack
        }
    }

    return 0;
}
