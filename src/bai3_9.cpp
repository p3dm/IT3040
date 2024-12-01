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
vector<int> s;

