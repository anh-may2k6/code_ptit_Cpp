#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

void nhap(ifstream &in ,set<string> &v){
    string s;
    while(in >> s){
        for(char &c : s){
            c = tolower(c);
        }
        v.insert(s);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream in1("DATA1.in");
    ifstream in2("DATA2.in");

    set<string> a,b;
    vector<string> giao , hop;

    nhap(in1 , a);
    nhap(in2 , b);

    set_union(a.begin() , a.end() , b.begin(), b.end() , back_inserter(hop));
    set_intersection(a.begin(),a.end() , b.begin() , b.end() , back_inserter(giao));
    
    for(auto &x : hop){
        cout << x << " ";
    }
    cout << endl;
    for(auto &x : giao){
        cout << x << " ";
    }
    return 0;
}