#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

#define MAX 100000

struct mk{
    string s;
    int l;
};

bool cmp(mk a ,mk b){
    return a.l > b.l;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<mk> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i].s;
        a[i].l = a[i].s.size();
    }
    sort(a.begin(),a.end(),cmp);
    int count = 0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i].s == a[j].s) count += 2;
            else if(a[i].s.find(a[j].s) != string::npos) count++;
        }
    }
    cout << count << endl;
    return 0;
}