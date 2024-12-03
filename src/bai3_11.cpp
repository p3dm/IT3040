/***
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

#include<iostream>
#include<vector>

using namespace std;

