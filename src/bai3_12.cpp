/***
 * Cho đồ thị vô hướng  G , hãy đếm số đường đi đi qua  k  cạnh và không đi qua đỉnh nào quá một lần.

Dữ liệu vào:

Dòng 1: Chứa hai số nguyên  n  và  k  ( 1≤n≤30 ,  1≤k≤10 ) với  n  là số đỉnh của  G . Các đỉnh sẽ được đánh số từ 1 đến  n 

Dòng 2: Chứa số nguyên  m ( 1≤m≤60 ) là số cạnh của  G
;
 

m  dòng tiếp theo: Mỗi dòng chưa hai số nguyên là một cạnh của  G 

Kết quả:

Số lượng đường đi đơn độ dài  k
 

Ví dụ:

Dữ liệu mẫu:

4 3
5
1 2
1 3
1 4
2 3
3 4

Kết quả mẫu:

6
 */

#include<iostream>
#include<vector>

using namespace std;

int n, k, m;
vector<vector<int>> graph;
vector<bool> visited;

void countPaths(int u, int depth, int &count){
    if(depth == k){
        count++;
        return;
    }
    visited[u] = true;
    for(int i : graph[u]){
        if(!visited[i]){
            countPaths(i, depth + 1, count);
        }
    }
    visited[u] = false;
}

int main(){
    cin >> n >> k;
    cin >> m;
    graph.resize(n + 1);
    visited.resize(n + 1, false);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int count = 0;
    for(int i = 1; i <= n; i++){
        countPaths(i, 0, count);
    }
    cout << count/2;
    return 0;
}