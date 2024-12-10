/**
 * Superior là một hòn đảo tuyệt đẹp với  n  địa điểm chụp ảnh và các đường một chiều nối các điểm chụp ảnh với nhau. Đoàn khách tham quan có  r  người với sở thích chụp ảnh khác nhau. Theo đó, mỗi người sẽ đưa ra danh sách các địa điểm mà họ muốn chụp. Bạn cần giúp mỗi người trong đoàn lập lịch di chuyển sao cho đi qua các điểm họ yêu cầu đúng một lần, không đi qua điểm nào khác, bắt đầu tại điểm đầu tiên và kết thúc tại điểm cuối cùng trong danh sách mà họ đưa ra, và có tổng khoảng cách đi lại là nhỏ nhất.
Dữ liệu vào:
Dòng đầu chứa  n  và  r
 
Tiếp theo là ma trận  n×n mô tả chi phí đi lại giữa các địa điểm. Chi phí bằng 0 có nghĩa là không thể đi lại giữa hai địa điểm đó.
r  dòng tiếp theo chứa danh sách các địa điểm mà người  r  đưa ra. Lưu ý là hành mỗi hành trình cần phải bắt đầu và kết thúc bởi hai đỉnh đầu và cuối của danh sách, còn các địa điểm còn lại có thể thăm theo bất kỳ thứ tự nào.
Kết quả:
Gồm  r  dòng ghi chi phí đi lại ít nhất của  r  người theo thứ tự đầu vào.
Ví dụ:
Dữ liệu mẫu:
6 3
0 1 2 0 1 1
1 0 1 1 1 0
0 2 0 1 3 0
4 3 1 0 0 0
0 0 1 1 0 0
1 0 0 0 0 0
1 3 5
6 3 2 5
6 1 2 3 4 5
Kết quả mẫu:
5
0
7
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

const int INF = INT_MAX;

int tsp(int pos, int visited, const vector<vector<int>> &cost, vector<vector<int>> &dp, int start, int end) {
    if (visited == (1 << cost.size()) - 1) {
        if (pos == end){
            return 0;
        } else{// Nếu đã thăm hết và đang ở điểm kết thúc
            return (cost[pos][end] > 0) ? cost[pos][end] : INF;
        } // Trở về điểm kết thúc
    }

    if (dp[pos][visited] != -1) return dp[pos][visited];

    int res = INF;
    for (int i = 0; i < cost.size(); ++i) {
        if (!(visited & (1 << i)) && cost[pos][i] > 0) { // Nếu chưa thăm và có đường đi
            int nextRes = tsp(i, visited | (1 << i), cost, dp, start, end);
            res = min(res, cost[pos][i] + nextRes);
        }
    }

    return dp[pos][visited] = res;
}

int solveTSP(const vector<int> &places, const vector<vector<int>> &matrix) {
    int m = places.size();
    vector<vector<int>> cost(m, vector<int>(m, INF));

    // Tạo ma trận chi phí cho các địa điểm trong danh sách yêu cầu
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            cost[i][j] = matrix[places[i] - 1][places[j] - 1];
        }
    }

    // Khởi tạo DP và chạy thuật toán TSP
    vector<vector<int>> dp(m, vector<int>(1 << m, -1));
    int start = 0, end = m - 1;
    return tsp(start, 1 << start, cost, dp, start, end);
}

int main() {
    int n, r;
    cin >> n >> r;

    // Nhập ma trận chi phí
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    // Nhập danh sách các địa điểm mỗi người muốn tham quan
    vector<vector<int>> itineraries(r);
    for (int i = 0; i < r; ++i) {
        int x;
        while (cin >> x) {
            itineraries[i].push_back(x);
            if (cin.peek() == '\n') break; // Dừng khi hết dòng
        }
    }

    // Tính toán và in kết quả cho từng người
    for (int i = 0; i < r; ++i) {
        int result = solveTSP(itineraries[i], matrix);
        cout << (result >= INF ? 0 : result) << endl; // Nếu không có đường đi thì in 0
    }

    return 0;
}
