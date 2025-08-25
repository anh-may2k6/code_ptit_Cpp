#include <iostream>
#include <cmath>
#include <cstring>

#define Max 10000

using namespace std;

char prime[Max+1];

void sang(){
    memset(prime,1,sizeof(prime));
    prime[0] = 0,prime[1] = 0;
    for(int i=2;i<=sqrt(Max);i++){
        if(prime[i]){
            for(int j=i*i;j<=Max;j+=i){
                prime[j] = 0;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sang();
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=2;i<=n;i++){
            if(prime[i]){
                cout << i << " ";
            }
        }
        cout << endl;
    }

    return 0;
}