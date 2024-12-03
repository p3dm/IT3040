/*
 * Dữ liệu vào:

Dòng đầu tiên chứ số n là kích thước của ma trận.

n dòng tiếp theo, mỗi dòng n số nguyên mô tả các phần tử của ma trận thứ nhất.

n dòng tiếp theo, mỗi dòng n số nguyên mô tả các phần tử của ma trận thứ hai.

Kết quả:

In ra tổng và tích của hai ma trận đầu vào.

n dòng đầu tiên, mỗi dòng chứa n số nguyên biểu diễn ma trận tổng.

n dòng đầu tiên, mỗi dòng chứa n số nguyên biểu diễn ma trận tích.
 */
#include<iostream>

int main(){
    int n;
    std::cin >> n;
    int** mat1 = new int*[n];
    int** mat2 = new int*[n];
    for(int i = 0; i < n; i++){
        mat1[i] = new int[n];
        mat2[i] = new int[n];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cin >> mat1[i][j];
        }
        std::cout << std::endl;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cin >> mat2[i][j];
        }
        std::cout << std:: endl;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            std::cout << mat1[i][j] + mat2[i][j] << " ";
        }
        std::cout << std::endl;
    }
    

    int** c = new int*[n];
    for(int i = 0; i < n; i++){
        c[i] = new int[n];
        for(int j = 0; j < n; j++){
            c[i][j] = 0;
            for(int k = 0; k < n; k++){
                c[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++){
            std::cout << c[i][j] << " ";
        }
        std::cout << std::endl;
    }
    
    for(int i = 0; i < n; i++){
        delete[] mat1[i];
        delete[] mat2[i];
        delete[] c[i];
    }
    delete[] mat1;
    delete[] mat2;
    delete[] c;
}