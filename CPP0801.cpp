#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream in("PTIT.in");
    ofstream out("PTIT.out");

    string s;
    while(getline(in , s)){
        out << s << endl;
    }
    in.close();
    out.close();
}