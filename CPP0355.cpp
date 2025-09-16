#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// check xem có kí tự nào đặc biệt dể tách thành 1 câu không
bool isEND(char c){
    return c == '.' || c == '?' || c == '!';
}

//chuyển đổi sang in hoa
void lower(string &a){
    for(auto &x : a){
        x = tolower(x);
    }
}

int main(){
    string s;
    //nhập cho đến khi nào ctrl + z thì dừng 
    while(getline(cin , s)){
        string tmp = "";
        for(char c : s){
            if(isEND(c)){
                //nếu tmp rỗng thì bỏ qua
                if(!tmp.empty()){
                    lower(tmp);
                    stringstream ss(tmp);
                    string word;
                    bool first = true;
                    string output = "";
                    while(ss >> word){
                        if(first){
                            word[0] = toupper(word[0]);
                            first = false;
                        }
                        output += word + " ";
                    }
                    // output ko rỗng thì ta loại bỏ 1 ô cách ở cuối dòng
                    if(!output.empty() && output.back() == ' ') output.pop_back();
                    cout << output << endl;
                    tmp.clear();
                }
            }
            // nếu chưa tạo thành 1 câu thì ta gộp lại tmp
            else{
                tmp += c;
            }
        }
    }
    return 0;
}