#include <iostream>
#include <vector>

using namespace std;

#define Max 100000

vector<bool> prime(Max+1 , true);

void sang(){
    prime[0] = prime[1] = false;
    for(int i=2;i*i<=Max;i++){
        if(prime[i]){
            for(int j=i*i;j<=Max;j+=i){
                prime[j] = false;
            }
        }
    }
}

int num_sum(int n){
    int sum = 0;
    while(n>0){
        sum += (n%10);
        n/=10;
    }
    return sum;
}

int sum_nt(int n){
    int sum = 0;
    for(int i=2;i*i<=n;i++){
        while(n%i==0){
            sum+=num_sum(i);
            n/=i;
        }
    }
    if(n>1){
        sum+=num_sum(n);
    }
    return sum;
}

void test_case(){
    int n;
    cin >> n;
    if(!prime[n] && sum_nt(n) == num_sum(n)){
        cout << "YES";
    }
    else{
        cout << "NO";
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