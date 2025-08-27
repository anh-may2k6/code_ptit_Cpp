#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

#define Max 1000000

char prime[Max+1]; // cho biến theo kiểu char để dùng memset

void sang(){
    memset(prime,1,sizeof(prime)); // gán từ 0-10^6 là 1
    prime[0] = 0,prime[1] = 0; // ko phải số nguyên tố thì là 0
    for(int i=2;i<=sqrt(Max);i++){ // duyệt bằng cách này thì độ phức tạp chỉ là căn n
        if(prime[i]){ // nếu là số nguyên tố thì bỏ qua giảm kha khá time
            for(int j=i*i;j<=Max;j+=i){ // các biến có liên quan đến số ko phải số nguyên tố trong tương lai thì cho = 0
                prime[j] = 0;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sang();
    int t;
    cin >> t;
    while(t--){
        int m,n;
        cin >> m >> n;
        for(int i=m;i<=n;i++){
            if(prime[i]){
                cout << i << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
