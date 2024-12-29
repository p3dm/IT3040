#include <bits/stdc++.h>
using namespace std;

int random(int L, int H) {
    return (rand() << 16 | rand()) % (H - L + 1) + L;
}

int main(int argc, char** argv) {
    if (argc > 1) srand(atoi(argv[1]));
    else srand(time(NULL));

    // Sinh số lượng thành phố và cạnh
    int n = random(2, 20);
    int m = random(n - 1, min(400, n * (n - 1) / 2));

    cout << n << " " << m << endl;

    // Ma trận kề
    vector<vector<int>> adj_matrix(n, vector<int>(n, -1));

    // Tạo cây khung đảm bảo đồ thị liên thông và có chu trình Hamilton
    vector<bool> visited(n, false);
    visited[0] = true;
    for (int i = 1; i < n; ++i) {
        int u = random(0, i - 1);
        adj_matrix[u][i] = adj_matrix[i][u] = random(1, 1000000);
        visited[i] = true;
    }

    // Thêm các cạnh ngẫu nhiên để tăng độ đặc
    while (m > n - 1) {
        int u = random(0, n - 1);
        int v = random(0, n - 1);
        if (u != v && adj_matrix[u][v] == -1) {
            adj_matrix[u][v] = adj_matrix[v][u] = random(1, 1000000);
            m--;
        }
    }

    // In ra ma trận kề
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (adj_matrix[i][j] != -1) {
                cout << i + 1 << " " << j + 1 << " " << adj_matrix[i][j] << endl;
            }
        }
    }

    return 0;
}