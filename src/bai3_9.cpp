/***
 * Một y tá cần lập lịch làm việc trong  N ngày, mỗi ngày chỉ có thể là làm việc hay nghỉ ngơi. Một lịch làm việc là tốt nếu không có hai ngày nghỉ nào liên tiếp và mọi chuỗi ngày tối đại làm việc liên tiếp đều có số ngày thuộc đoạn  [K1,K2] . Hãy liệt kê tất cả các cách lập lịch tốt, với mỗi lịch in ra trên một dòng một xâu nhị phân độ dài  n  với bit 0/1 tương ứng là nghỉ/làm việc. Các xâu phải được in ra theo thứ tự từ điển

Dữ liệu vào:

Ghi 3 số nguyên  N,K1,K2  ( N≤200,K1<K2≤70 )

Kết quả:

Ghi danh sách các lịch tìm được theo thứ tự từ điển

Ví dụ:

Dữ liệu mẫu:

6 2 3

Kết quả mẫu:

011011
110110
110111
111011
 */

#include<iostream>
#include<vector>

using namespace std;

int n, k1, k2;
vector<int>schedule;
vector<vector<int> > lich;


bool isValidDate(){
    int streak = 0;
    for(int i = 0; i < schedule.size(); i++){
        if(schedule[i] == 1){
            streak++;
        }
        else{
            if(streak > 0 &&(streak < k1 || streak > k2)){
                return false;
            }
            streak = 0;
            if(i > 0 && schedule[i-1] == 0){
                return false;
            }
        }
    } 
    if(streak > 0 && (streak < k1 || streak > k2)){
        return false;
    }
    return true;
    
}

void Try(int day){
    if(day == n){
        if(isValidDate()){
            lich.push_back(schedule);
        }
        return;
    }

    schedule.push_back(0);
    Try(day + 1 );
    schedule.pop_back();

    schedule.push_back(1);
    Try(day + 1);
    schedule.pop_back();

}

int main(){
    cin >> n >> k1 >> k2;
    Try(0);
    for(vector<int> ngay : lich){
        for(int num : ngay){
            cout << num;
        }
        cout << endl;
    }

}

