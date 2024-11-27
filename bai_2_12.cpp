/***
 * Hôm nay, cô giáo giao cho An một câu hỏi hóc búa. Cô cho một danh sách với mỗi phần tử có dạng <key, value> và yêu cầu An sắp xếp danh sách đó giảm dần theo giá trị value. Nếu 2 phần tử có value giống nhau thì sắp xếp giảm dần theo key.

Hãy viết một chương trình sử dụng hàm nặc danh để giúp An làm bài tập.

Input: Danh sách đầu vào. Mỗi dòng ghi một cặp giá trị key, value cách nhau bởi dấu cách (|key|  ≤109 , |value|  ≤109 ).

Output: In danh sách đã được sắp xếp theo yêu cầu. Mỗi dòng ghi một cặp giá trị key, value cách nhau bởi dấu cách.
 */

#include <iostream>
#include <vector>   
#include <algorithm>
#include <string>
#include <sstream>

int main(){
    std::vector<std::pair<int,int>> list;
    int key, value;
    std::string line;
    while(true){
        if(!std::getline(std::cin, line) || line.empty()) break;
        std::stringstream iss(line);
        iss >> key >> value;
        list.push_back(std::make_pair(key, value));
    }
    
    std::sort(list.begin(), list.end(), [](std::pair<int,int> a, std::pair<int,int> b){
        if(a.second == b.second){
            return a.first > b.first;
        }
        return a.second > b.second;
    });

    for(auto p : list){
        std::cout << p.first << " " << p.second << std::endl;
    }
    return 0;
}