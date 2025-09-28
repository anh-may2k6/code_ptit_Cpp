//Bài này ta có 3 cách làm: Sinh kế tiếp , quay lui or dùng next_permutation
//Tôi sẽ làm sinh kế tiếp 
#include <iostream>
#include <vector>

using namespace std;

int n,k;
vector<int> a;

bool sinh(){
    int i = k;
    while(i>0 && a[i] == n-k+i) i--; //tìm thấy phần tử có thể tăng
    if(i==0) return false; // tổ hợp cuối cùng thì dừng lại
    a[i]++;
    for(int j=i+1;j<=k;j++){
        a[j] = a[j-1]+1;
    }
    return true;
}

void test_case(){
    cin >> n >> k;
    a.resize(k+1);
    for(int i=1;i<=k;i++){
        a[i] = i; // tổ hợp đầu tiên
    }
    do{
        for(int i=1;i<=k;i++){
            cout << a[i];
        }
        cout << " ";
    }while(sinh());
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        test_case();
    }
    return 0;
}

//đây là cách làm quay lui

// #include <iostream>
// #include <vector>

// using namespace std;

// int n,k;
// vector<int> a;

// void quay_lui(int i , int start){
//     a.resize(k+1);
//     for(int j = start ; j <= n-k+i ; j++){
//         a[i] = j;
//         if(i==k){
//             for(int q=1;q<=k;q++){
//                 cout << a[q];
//             }
//             cout << " ";
//         }
//         else{
//             quay_lui(i+1,j+1);
//         }
//     }
// }

// void test_case(){
//     cin >> n >> k;
//     quay_lui(1,1);
//     cout << endl;
// }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t;
//     cin >> t;
//     while(t--){
//         test_case();
//     }
//     return 0;
// }

//cách còn lại thì giống với sinh kế tiếp nên thôi 
