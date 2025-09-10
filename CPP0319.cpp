#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(const string &a ,int m,int s){
    int sum = 0;
    if(a.size() != m) return false;
    for(auto x : a){
        int num = x - '0';
        sum+=num;
    }
    if(sum != s) return false;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m,s;
    cin >> m >> s;
    bool check_1 = false ,check_2 = false;
    int sum = s;
    string Max_num = ""; // tạo 1 chuỗi các số Max
    for(int i=0;i<m;i++){
        int num = min(9,sum); // so sánh để lấy chữ số lớn nhất từ trái qua phải
        Max_num += char('0'+num); //thêm đằng sau mỗi chỗi là 1 số kiểu char
        sum-=num;
    }
    sum = s;
    string Min_num = "";
    for(int i=0;i<m;i++){
        int num = 0;
        for(int j=(i==0) ? 1:0;j<=9;j++){ // thử j tăng dần để tìm số bé nhất ở ô đầu tiên 
            if(sum-j <= 9*(m-i-1)){
                num = j;
                break; // break để tránh lẵng phí time
            }
        }
        Min_num += char('0' + num);
        sum-=num;
    }
    if(check(Min_num,m,s) && check(Max_num,m,s)){
        cout << Min_num << " " << Max_num << endl;
    }
    else{
        cout << "-1 -1" << endl;
    }
    return 0;
}