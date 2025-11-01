// bài này chỉ cần tìm được ước số của n là xong
// với test case khổng lồ như thế thì ta ko nên duyệt
// căn n vì nó sẽ lặp đi lặp lại rất nhiều và dẫn đến TLE 
// ta nên tạo 1 mảng vector lưu các số và ước số của nó
// khi cần thì ta sẽ gọi ra.
#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1000000;

vector<int> divisors_count(MAX_N + 1, 0);

<<<<<<< HEAD
void precompute_divisors() { 
=======
void precompute_divisors() {
    //với mỗi ước i thì ta sẽ tăng thêm 1 ứng với số chia được cho i
>>>>>>> 95d922351d4da02601b6f8774e0843bb7d3c7b0e
    for (int i = 1; i <= MAX_N; i++) {
        for (int j = i; j <= MAX_N; j += i) {
            divisors_count[j]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    precompute_divisors();
    
    int T;
    cin >> T;
    
    while (T--) {
        int n;
        cin >> n;
        cout << divisors_count[n] << "\n";
    }
    
    return 0;
}
