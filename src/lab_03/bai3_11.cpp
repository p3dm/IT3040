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
#include <sstream>
#include <climits>

using namespace std;
const int MAX = 10000;
int n, r;
int price[MAX][MAX];
int x[MAX];
bool visited[MAX];
vector<int> vt;
int min_price;
int sum_price;
int start, destination, numberOfPoint;

void input(){
    cin >> n >> r;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            cin >> price[i][j];
        }
}

bool check(int a, int i){
    if(visited[vt[i]]) return false;
    if(price[x[a-1]][vt[i]] == 0) return false;
    return true;
}

void solution(){
    if(price[x[numberOfPoint-2]][destination] == 0) return;
    min_price = min(min_price, sum_price + price[x[numberOfPoint-2]][destination]);
}

void TRY(int a){
    for(int i=1; i<numberOfPoint-1; i++){
        if(check(a, i)){
            visited[vt[i]] = true;
            sum_price += price[x[a-1]][vt[i]];

            x[a] = vt[i];
            if(a == numberOfPoint-2) solution();
            else TRY(a+1);

            visited[vt[i]] = false;
            sum_price -= price[x[a-1]][vt[i]];
        }
    }
}

int main(){
    string str;
    input(); getline(cin,str);
    vector<int> result;
    while(r > 0){
        min_price = INT_MAX;
        sum_price = 0;

        getline(cin, str);

        
        while (!str.empty()){
            stringstream convert(str.substr(0, str.find(" ")));
            int tmp = 0;
            convert >> tmp;
            vt.push_back(tmp - 1);

            if (str.find(" ") > str.size()){
                break;
            } else {
                str.erase(0, str.find(" ") + 1); // Update string
            }
        }

        start = vt[0]; // diem bat dau dau
        destination = vt[vt.size()-1]; // diem dich
        numberOfPoint = vt.size(); // so diem phai di qua
        x[0] = start; x[numberOfPoint-1] = destination;
        for(int i=0; i<n; i++)
            visited[i] = false;

        TRY(1);
        result.push_back(min_price);
        vt.erase(vt.begin(), vt.end());
        r--;
    }
    for(int num : result){
        if(num == INT_MAX){
            cout << "0" << endl;
        }
        else{
        cout << num << endl;
        }
    }
    
}