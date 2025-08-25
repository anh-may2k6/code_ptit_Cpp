#include <iostream>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false); // loại bỏ liên kết giữa cin và scanf
    cin.tie(nullptr); // cout mà ko cần chờ cin 

    int t;
    cin >> t;
    cin.ignore(); // loại bỏ xuống dòng khi dùng cin ở đâu để tránh nhớ nhầm 

    string x = "084"; // loại bỏ theo kí tự yêu cầu
    while(t--){
        string s;
        cin >> s;

        size_t pos = s.find(x); // tìm vị trí của chuỗi x
        if(pos != string::npos){ // đối chiếu xem có x ở trong s hay không
            s.erase(pos, x.length()); // có thì triệt tiêu 
        }
        cout << s << endl; // in ra sau khi triệt tiêu
    }    
    return 0;
}