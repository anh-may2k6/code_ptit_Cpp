#include <iostream>
#include <map>

using namespace std;

struct cmp{
    bool operator() (const string &a,const string &b) const { 
        if(a.size() != b.size()) return a.size() > b.size();
        return a > b;
    }
};

bool check_tn(string &s){
    int n = s.size();
    if(n<2) return false;
    for(int i=0;i<n/2;i++){
        if(s[i] != s[n-1-i]) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    map<string,int,cmp> m;
    string s;
    while(cin >> s){
        if(check_tn(s)){
            m[s]++;
        }
    }
    for(auto &x : m){
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}