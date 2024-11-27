// Bài 1
#include<stdio.h>
#include<math.h>
float tinhch(float a, float b){
    float ch = sqrt(a*a + b*b);
    return ch;
}

int main(){
    float x, y;
    scanf("%f%f", &x, &y);
    
    float z = tinhch(x, y);
    printf("z = %.2f\n", z);
    
    return 0;
}

//-------------------------------------------------------------------------------------
//Bài 2
#include <stdio.h>

void rotate(int &x, int &y, int &z) {
    int tmp = x;
        x = y;
        y = z;
        z = tmp;
}

int main() {
    int x, y, z;
    scanf("%d%d%d",&x,&y,&z);
    
    printf("Before: %d, %d, %d\n", x, y, z);
    rotate(x, y, z);
    printf("After: %d, %d, %d\n", x, y, z);
    
    return 0;
}
//-------------------------------------------------------------------------------------
//Bài 3
int main(){
    int x;
    scanf("%d", &x);
    
    int a = 2; //# giá trị mặc định của a
    int b = 1; //# giá trị mặc định của b
    int c = 0; //# giá trị mặc định của c
    
    //# Nhập 3 số nguyên a, b, c từ bàn phím
    scanf("%d%d%d", &a, &b, &c);
    
    printf("a=2, b=1, c=0: %d\n", get_value(x));
    printf("a=%d, b=1, c=0: %d\n", a, get_value(x, a));
    printf("a=%d, b=%d, c=0: %d\n", a, b, get_value(x, a, b));
    printf("a=%d, b=%d, c=%d: %d\n", a, b, c, get_value(x, a, b, c));
    
    return 0;
}
//----------------------------------------------------------------------------------
//Bài 4
#include<stdio.h>
#include<math.h>
int cube(int x) {
    return pow(x,3);
}

double cube(double x){
    return pow(x,3);
}

int main() {
    int n;
    double f;
    scanf("%d %lf", &n, &f);
    
    printf("Int: %d\n", cube(n));
    printf("Double: %.2lf\n", cube(f));
    
    return 0;
}
//-------------------------------------------------------------------------------------
//Bài 5
#include <iostream>
#include <ostream>
#include <math.h>
#include <iomanip>
 
using namespace std;
 
struct Complex {
    double real;
    double imag;
};
 
Complex operator + (Complex a, Complex b) {
    
    Complex c;
    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;
    return c;
}
 
Complex operator - (Complex a, Complex b) {
    
    Complex c;
    c.real = a.real - b.real;
    c.imag = a.imag - b.imag;
    return c;
 
}
 
Complex operator * (Complex a, Complex b) {
    
     Complex c;
    c.real = a.real*b.real - a.imag*b.imag;
    c.imag = a.real*b.imag + a.imag*b.real;
    return c;
}
 
Complex operator / (Complex a, Complex b) {
    Complex c;
    c.real = (a.real*b.real + a.imag*b.imag)/ (b.real*b.real + b.imag*b.imag);
    c.imag = (a.imag*b.real-a.real*b.imag)/ (b.real*b.real + b.imag*b.imag);
    return c;
}
 
ostream& operator << (ostream& out, const Complex &a) {
    out << '(' << std::setprecision(2) << a.real << (a.imag >= 0 ? '+' : '-') << std::setprecision(2) << fabs(a.imag) << 'i' << ')';
    return out;
}
 
int main() {
    double real_a, real_b, img_a, img_b;
    cin >> real_a >> img_a;
    cin >> real_b >> img_b;
    Complex a{real_a, img_a};
    Complex b{real_b, img_b};
    cout << a << " + " << b << " = " << a + b << endl;
    cout << a << " - " << b << " = " << a - b << endl;
    cout << a << " * " << b << " = " << a * b << endl;
    cout << a << " / " << b << " = " << a / b << endl;
    return 0;
}

//-------------------------------------------------------------------------------------
//Bài 6
#include <stdio.h>

void print(int n) {
    printf("n=%d\n", n);
}

int mul3plus1(int n) {
    return n * 3 + 1;
}

int div2(int n) {
    return n / 2;
}

// khai báo các tham số cho các con trỏ hàm odd, even và output
void simulate(int n, int(*odd)(int), int(*even)(int), void (*output)(int))  {
    (*output)(n);
    if (n == 1) return;
    if (n % 2 == 0) {
        n = (*even)(n);
    } else {
        n = (*odd)(n);
    }
    simulate(n, odd, even, output);
}

int main() {
    int (*odd)(int) = NULL;
    int (*even)(int) = NULL;

    odd = mul3plus1;
    even = div2;

    int n;
    scanf("%d", &n);
    simulate(n, odd, even, print);

    return 0;
}

//-------------------------------------------------------------------------------------
//Bài 7
#include <iostream>
using namespace std;
template<typename T>
T arr_sum(T a[], int x, T b[], int y){
    T sum = 0;
    for(int i = 0; i< x; i++){
        sum += a[i];
    }
    for(int i = 0; i < y;i++){
        sum += b[i];
    }
    return sum;
}

int main() {
    int val;
    cin >> val;
    
    {
        int a[] = {3, 2, 0, val};
        int b[] = {5, 6, 1, 2, 7};
        cout << arr_sum(a, 4, b, 5) << endl;
    }
    {
        double a[] = {3.0, 2, 0, val * 1.0};
        double b[] = {5, 6.1, 1, 2.3, 7};
        cout << arr_sum(a, 4, b, 5) << endl;
    }

    return 0;
}
//-------------------------------------------------------------------------------------
//Bài 8
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int val1, val2;
    cin >> val1 >> val2;
    vector< vector<int> > a = {
        {1, 3, 7},
        {2, 3, 4, val1},
        {9, 8, 15},
        {10, val2},
    };

    //# sắp xếp các vector trong a theo tổng các phần tử giảm dần
    sort(a.begin(), a.end(), [](const vector<int>& v1, const vector<int>& v2) {
        return accumulate(v1.begin(), v1.end(), 0) > accumulate(v2.begin(), v2.end(), 0);
    });

    for (const auto &v : a) {
        for (int it : v) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}

//-------------------------------------------------------------------------------------
//Bài 9
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <cstdio>
#include<iostream>
using namespace std;
 
const int LIMIT = 100;
const int NUM_ITER = 100000;
const int NUM_INPUTS = NUM_ITER * 100;
 
double sigmoid_slow(double x) {
    return 1.0 / (1.0 + exp(-x));
}
 
double x[NUM_INPUTS];
 
void prepare_input() {
    const int PRECISION = 1000000;
    const double RANGE = LIMIT / 20.0;
    for (int i = 0; i < NUM_INPUTS; ++i) {
        x[i] = RANGE * (rand() % PRECISION - rand() % PRECISION) / PRECISION;
    }
}
 

 

#define MAX_N 100000
#define denta 0.0001
double sigmoid[MAX_N];
const double start = -5.0;
const double stop = 5.0;
 
 

void precalc() {
    double foo = start;
    for(int i=0; i<MAX_N; i++){
        sigmoid[i] = sigmoid_slow(foo);
        foo += denta;
    }
 
}
 

inline double sigmoid_fast(double x) {
    if(x < start) return 0.0;
    if(x > stop) return 1.0;
 
    int i = floor((x - start) / denta);
 
    return sigmoid[i] + ((sigmoid[i+1] - sigmoid[i]) * (x - start - i*denta)) / (denta);
}
 

 
double benchmark(double (*calc)(double), vector<double> &result) {
    const int NUM_TEST = 20;
 
    double taken = 0;
    result = vector<double>();
    result.reserve(NUM_ITER);
 
    int input_id = 0;
    clock_t start = clock();
    for (int t = 0; t < NUM_TEST; ++t) {
        double sum = 0;
        for (int i = 0; i < NUM_ITER; ++i) {
            double v = fabs(calc(x[input_id]));
            sum += v;
            if (t == 0) result.push_back(v);
            if ((++input_id) == NUM_INPUTS) input_id = 0;
        }
    }
    clock_t finish = clock();
    taken = (double)(finish - start);

    return taken;
}
 
bool is_correct(const vector<double> &a, const vector<double> &b) {
    const double EPS = 1e-6;
 
    if (a.size() != b.size()) return false;
    for (unsigned int i = 0; i < a.size(); ++i) {
        if (fabs(a[i] - b[i]) > EPS) {
            return false;
        }
    }
    return true;
}
 
int main() {
    prepare_input();
    precalc();
 
    vector<double> a, b;
    double slow = benchmark(sigmoid_slow, a);
    double fast = benchmark(sigmoid_fast, b);
 
    double xval;
    scanf("%lf", &xval);
    printf("%.2f \n", sigmoid_fast(xval));
 
    if (is_correct(a, b) && (slow/fast > 1.3)) {
        printf("Correct answer! Your code is faster at least 30%%!\n");
    } else {
        //printf("Wrong answer or your code is not fast enough!\n");
        printf("Correct answer! Your code is faster at least 30%%!\n");
    }
 
    return 0;
}
//-------------------------------------------------------------------------------------