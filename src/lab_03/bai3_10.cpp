/***Khoảng cách Hamming giữa hai xâu cùng độ dài là số vị trí mà ký tự tại vị trí đó là khác nhau trên hai xâu. Cho  S  là xâu gồm  n  ký tự 0. 
 * Hãy liệt kê tất cả các xâu nhị phân độ dài  n , có khoảng cách Hamming với  S  bằng  H . Các xâu phải được liệt kê theo thứ tự từ điển

Dữ liệu vào:

Dòng đầu chứa  T  là số testcase

T  dòng tiếp theo, mỗi dòng mô tả một testcase, ghi  N  và  H  ( 1≤H≤N≤16 )

Kết quả:

Với mỗi testcase, in ra danh sách các xâu thỏa mãn. In ra một dòng trống giữa hai testcase

Ví dụ:

Dữ liệu mẫu:

2
4 2
1 0

Kết quả mẫu:

0011
0101
0110
1001
1010
1100

0
 */

#include<iostream>
#include<vector>

using namespace std;

int n, h;
vector<vector<int>> result;
vector<int> a;

void checkIfValid(){
    int count = 0;
    for(int i = 0; i < n; i++){
        if(a[i] != 0){
            count++;
        }
    }
    if(count == h){
        result.push_back(a);
    }
}

void Try(int i){
    if(i == n){
        checkIfValid();
        return;
    }
    a.push_back(0);
    Try(i+1);
    a.pop_back();

    a.push_back(1);
    Try(i+1);
    a.pop_back();

}

int main(){
    int t ;
    cin >> t;
    vector<vector<vector<int> > > allResults;

    for (int testCase = 0; testCase < t; testCase++) {
        cin >> n >> h;
        a.clear();
        result.clear();
        Try(0);
        allResults.push_back(result);
    }

    for (int testCase = 0; testCase < t; testCase++) {
        for (const auto& res : allResults[testCase]) {
            for (int num : res) {
                cout << num;
            }
            cout << endl;
        }
        if (testCase < t - 1) {
            cout << endl;
        }
    }
}
