#include <iostream>
#include <cstring>

using namespace std;

const int Max = 100000;
char prime[Max+1];

void sang(){
    memset(prime,1,sizeof(prime));
    prime[0] = 0;prime[1] = 0;
    for(int i=2;i*i<=Max;i++){
        if(prime[i]){
            for(int j=i*i;j<=Max;j+=i){
                prime[j] = 0;
            }
        }
    }
}

void test_case(){
    int l,r,dem = 0;
    cin >> l >> r;
    for(int i=l;i<=r;i++){
        if(prime[i]){
            dem++;
        }
    }
    cout << dem << endl;
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