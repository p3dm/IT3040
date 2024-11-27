/***
 * Viết chương trình in ra tất cả các dãy con của một dãy cho trước.
Dữ liệu vào:

Dòng đầu tiên chứ số n là số lượng phần tử của dãy.

Dòng tiếp theo chứa n số nguyên cách nhau bởi dấu cách là các phần tử của dãy.

Kết quả:

In ra các dãy con của dãy trên, mỗi dãy con in trên một dòng.
case = 1 

input = 2 

3 2 

output = 3 

3 2 

2 

case = 2 

input = 3 

5 1 4 

output = 5 

5 1 

5 1 4 

1 

1 4 

4 

case = 3 

input =  

10 

1 4 -2 4 65 8 -9 12 5 67 

output = 1 

1 4 

1 4 -2 

1 4 -2 4 

1 4 -2 4 65 

1 4 -2 4 65 8 

1 4 -2 4 65 8 -9 

1 4 -2 4 65 8 -9 12 

1 4 -2 4 65 8 -9 12 5 

1 4 -2 4 65 8 -9 12 5 67 

4 

4 -2 

4 -2 4 

4 -2 4 65 

4 -2 4 65 8 

4 -2 4 65 8 -9 

4 -2 4 65 8 -9 12 

4 -2 4 65 8 -9 12 5 

4 -2 4 65 8 -9 12 5 67 

-2 

-2 4 

-2 4 65 

-2 4 65 8 

-2 4 65 8 -9 

-2 4 65 8 -9 12 

-2 4 65 8 -9 12 5 

-2 4 65 8 -9 12 5 67 

4 

4 65 

4 65 8 

4 65 8 -9 

4 65 8 -9 12 

4 65 8 -9 12 5 

4 65 8 -9 12 5 67 

65 

65 8 

65 8 -9 

65 8 -9 12 

65 8 -9 12 5 

65 8 -9 12 5 67 

8 

8 -9 

8 -9 12 

8 -9 12 5 

8 -9 12 5 67 

-9 

-9 12 

-9 12 5 

-9 12 5 67 

12 

12 5 

12 5 67 

5 

5 67 

67 

 */
#include<iostream>


int main(){
    int n;
    std::cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        std::cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        int j = i;
        while(j < n){
            for(int k = i; k <= j; k++){
                std::cout << arr[k] << " ";
            }
            std::cout << std::endl;
            j++;
        }
    }
    return 0;
}