#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct bigNum {
    int sign;       
    string num;     

  
    bigNum(string s) {
        sign = (s[0] == '1') ? 1 : -1;  
        num = s.substr(1);              
        
        while (num.size() > 1 && num[0] == '0') {
            num.erase(num.begin());
        }
    }

    
    string toString() const {
        return (sign == -1 ? "0" : "1") + num;
    }

    
    static string add(const string &a, const string &b) {
        string res = "";
        int carry = 0, i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 || j >= 0 || carry > 0) {
            int digitA = (i >= 0) ? a[i--] - '0' : 0;
            int digitB = (j >= 0) ? b[j--] - '0' : 0;
            int sum = digitA + digitB + carry;
            carry = sum / 10;
            res += (sum % 10) + '0';
        }
        reverse(res.begin(), res.end());
        return res;
    }

    
    static string subtract(const string &a, const string &b) {
        string res = "";
        int borrow = 0, i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 || j >= 0) {
            int digitA = (i >= 0) ? a[i--] - '0' : 0;
            int digitB = (j >= 0) ? b[j--] - '0' : 0;
            int diff = digitA - digitB - borrow;
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            res += diff + '0';
        }
        while (res.size() > 1 && res.back() == '0') {
            res.pop_back(); 
        }
        reverse(res.begin(), res.end());
        return res;
    }

    
    static string multiply(const string &a, const string &b) {
        int m = a.size(), n = b.size();
        string res(m + n, '0');

        for (int i = m - 1; i >= 0; --i) {
            int carry = 0;
            for (int j = n - 1; j >= 0; --j) {
                int sum = (res[i + j + 1] - '0') + (a[i] - '0') * (b[j] - '0') + carry;
                carry = sum / 10;
                res[i + j + 1] = (sum % 10) + '0';
            }
            res[i] += carry;
        }

        
        size_t startpos = res.find_first_not_of("0");
        if (string::npos != startpos) {
            return res.substr(startpos);
        }
        return "0";
    }

    
    static string multiplySmall(const string &a, int b) {
        string res = "";
        int carry = 0;
        for (int i = a.size() - 1; i >= 0; --i) {
            int prod = (a[i] - '0') * b + carry;
            carry = prod / 10;
            res += (prod % 10) + '0';
        }
        while (carry > 0) {
            res += (carry % 10) + '0';
            carry /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }


    static int compareAbs(const string &a, const string &b) {
        if (a.size() != b.size()) {
            return a.size() < b.size() ? -1 : 1;
        }
        return a.compare(b);
    }

    bigNum operator+(const bigNum &other) const {
        if (sign == other.sign) {
            return bigNum((sign == -1 ? "0" : "1") + add(num, other.num));
        } else {
            if (compareAbs(num, other.num) >= 0) {
                return bigNum((sign == -1 ? "0" : "1") + subtract(num, other.num));
            } else {
                return bigNum((other.sign == -1 ? "0" : "1") + subtract(other.num, num));
            }
        }
    }

    bigNum operator-(const bigNum &other) const {
        return *this + bigNum((other.sign == -1 ? "1" : "0") + other.num);
    }

    bigNum operator*(const bigNum &other) const {
        bigNum result("1" + multiply(num, other.num));
        result.sign = sign * other.sign;
        return result;
    }

    bigNum operator*(int small) const {
        bigNum result("1" + multiplySmall(num, small));
        result.sign = sign;
        return result;
    }
};

int main() {
    string a_str, b_str;
    cin >> a_str >> b_str;

    bigNum a(a_str);
    bigNum b(b_str);

    
    bigNum ab = a * b;
    bigNum three_a = a * 3;
    bigNum four_b = b * 4;
    
    bigNum result = ab - three_a + four_b;
    cout << result.toString() << endl;
    return 0;
}
