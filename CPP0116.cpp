#include <iostream>

using namespace std;

const int Max = 10000;
int u_prime[Max+1];

void sang(){
    for(int i=1;i<=Max;i++){
        u_prime[i] = i; // khởi tạo 
    }
    for(int i=2;i*i <= Max ;i++){
        if(u_prime[i] == i){ // dùng số nguyên tố ở hiện tại để làm ước cho các số có liên quan
            for(int j=i*i;j<=Max;j+=i){
                if(u_prime[j] == j){ // gặp lần đầu nên gán giá trị i bé nhất để tránh bị ghi đè
                    u_prime[j] = i;
                }
            }
        }
    }
}

void test_case(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cout << u_prime[i] << " ";
    }
    cout << endl;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sang();
    int t;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}