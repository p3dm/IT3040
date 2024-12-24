/***
Bài 4.11. Bức tường bao quanh một lâu đài nọ được cấu thành
từ  n  đoạn tường được đánh số từ 1 đến  n .
Quân giặc lên kế hoạch tấn công lâu đài bằng cách gửi  ai
tên giặc đánh vào đoạn tường thứ  i.
Để bảo vệ lâu đài có tất cả  s  lính.

Yêu cầu hãy viết chương trình phân bố lính đứng ở các đoạn
tường sao cho tổng số lính là  s  và tổng số lượng tên giặc
lọt vào lâu đài là nhỏ nhất.
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Data {
    int ai;
    int ki;

    Data(int ai, int ki){
        this->ai = ai;
        this->ki = ki;
    }
};

struct compare{
    bool operator() (Data a, Data b){
        int ra, rb;

        if(a.ai <= a.ki) ra = a.ai;
        else ra = a.ki;

        if(b.ai <= b.ki) rb = b.ai;
        else rb = b.ki;

        return ra < rb;
    }
};

int n, s, kill_enemy, total_enemy;
priority_queue<Data, vector<Data>, compare> p_q;

void input(){
    cin >> n >> s;
    kill_enemy = 0;
    total_enemy = 0;
    for(int i=0; i<n; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        total_enemy += tmp1;
        p_q.push(Data(tmp1, tmp2));
    }
}

void solve(){
    while(!p_q.empty() && s>0){
        Data inf = p_q.top(); p_q.pop();

        if(inf.ai <= inf.ki){
            kill_enemy += inf.ai;
        } else {
            int nenemy = inf.ai - inf.ki;
            p_q.push(Data(nenemy, inf.ki));
            kill_enemy += inf.ki;
        }

        s -= 1;
    }
}

int calc_enemy(){
    return total_enemy - kill_enemy;
}

int main(){
    input();
    solve();
    cout << calc_enemy();
    return 0;
}