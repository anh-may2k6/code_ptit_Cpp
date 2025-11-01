//bài này tốt nhất là đưa về giai thừa các số nguyên tố là hợp lý
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void test_case() {
    int n;
    string s;
    cin >> n >> s;
    
    vector<int> digits;
    
    // Phân tích từng chữ số
    for(auto c : s){
        int num = c - '0';
        switch (num){
            case 4: // 4! = 3! * 2! * 2!
            digits.push_back(3);
            digits.push_back(2);
            digits.push_back(2);
            break;
            case 6: // 6! = 5! * 3!
            digits.push_back(5);
            digits.push_back(3);
            break;
            case 8: // 8! = 7! * 2! * 2! * 2!
            digits.push_back(7);
            digits.push_back(2);
            digits.push_back(2);
            digits.push_back(2);
            break;
            case 9: // 9! = 7! * 3! * 3! * 2!
            digits.push_back(7);
            digits.push_back(3);
            digits.push_back(3);
            digits.push_back(2);
            break;
            default:
            // với số nguyên tố thì giữ lại
            if(num > 1){
                digits.push_back(num);
            }
            break;
        }
    }
    
    // Sắp xếp giảm dần để được số lớn nhất
    sort(digits.rbegin(), digits.rend());
    
    // In kết quả
    for (int d : digits) {
        cout << d;
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        test_case();
    }
    return 0;
} 