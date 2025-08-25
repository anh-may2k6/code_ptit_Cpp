#include <iostream>
#include <iomanip>

using namespace std;

double sum_pt(int n){
    double sum = 0;
    for(int i = 1;i<=n;i++){
        sum+=(1.0/i); // ép kiểu double cho i vì i ban đầu là int
    }
    return sum;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cout << fixed << setprecision(4) << sum_pt(n) << endl; // nếu dùng cout thì in như v là ra số thập phân thứ 4 , nếu không thích thì dùng printf
    return 0;
}