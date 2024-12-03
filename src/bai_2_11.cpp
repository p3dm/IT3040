/***Cho 2 đa thức A(x) và B(x) tương ứng có bậc N và M. Hãy tính đa thức tích C(x) = A(x) * B(x) có bậc N+M.
Dữ liệu vào:

Gồm 2 dòng biểu diễn các đa thức A(x) và B(x), mỗi dòng bao gồm

Số đầu tiên N là một số nguyên dương tương ứng với bậc của đa thức;
N+1 số nguyên tiếp theo là các hệ số của đa thức, số thứ i là hệ số của xi-1.
Kết quả: Ghi ra một số nguyên duy nhất là XOR của các hệ số của đa thức C(x).

Giải thích:
Trong ví dụ trên, các hệ số của đa thức tích lần lượt là 7719, 10903, 17309, 19122, 19126, 12588, 5153, 735. 
Do đó kết quả in ra là: 
7719 xor 10903 xor 17309 xor 19122 xor 19126 xor 12588 xor 5153 xor 735 = 20731

Lưu ý: Để tính xor hai số nguyên a và b trong C/C++, các bạn có thể dùng câu lệnh a ^ b.

Giới hạn:

Các hệ số của các đa thức đầu vào có trị tuyệt đối nhỏ hơn 100. 
Có 5 tests, test thứ i có bậc của các đa thức đầu vào không quá 10i. 
*/

#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n;
    std::vector<int> a(n+1);
    for (int i = 0; i <= n; i++) {
        std::cin >> a[i];
    }

    std::cin >> m;
    std::vector<int> b(m+1);
    for (int i = 0; i <= m; i++) {
        std::cin >> b[i];
    }

    std::vector<int> c(n + m + 1, 0);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            *(c.data() + i + j) += *(a.data() + i) * *(b.data() + j);
        }
    }
    int result = 0;
    for(int num : c){
        result ^= num;
    }

    std::cout << result;
    return 0;
}
