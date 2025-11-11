#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string build_from_freq(string s){
	vector<int> freq(11,0);
	for(char c : s){
		freq[c-'0']++;
	}
	bool chan = false;
	bool check = false;
	int MAX = 10;
	for(int i=0;i<10;i++){
		if(freq[i] >= freq[MAX] && freq[i] % 2 == 1){
			MAX = i;
		}
		if(freq[i] > 0 && freq[i] % 2 == 0 && i > 0){
			chan = true;
		}
		if(i > 0 && freq[i] != 0){
			check = true;
		}
	}
	string result;
	if(check){
		if(!chan){
			int m = 1;
			for(int i=1;i<10;i++){
				if(freq[i] > 0 && freq[i] >= freq[m]){
					m = i;
				}
			}
			for(int i=0;i<freq[m];i++){
				result.push_back(m + '0');
			}
		}
		else{
			for(int i=0;i<10;i++){
				if((freq[i] % 2 == 1 && freq[i] < freq[MAX]) || (freq[i] == freq[MAX] && i < MAX)){
					freq[i] = 0;
				}
			}
			for(int i=9;i>=0;i--){
				if(i != MAX){
					for(int j=0;j<freq[i]/2;j++){
						result.push_back(i+'0');
					}
				}
			}
			for(int i=0;i<freq[MAX];i++){
				result.push_back(MAX + '0');
			}
			for(int i=0;i<10;i++){
				if(i != MAX){
					for(int j=0;j<freq[i]/2;j++){
						result.push_back(i+'0');
					}
				}
			}
			while(!result.empty() && result.front() == '0') result.erase(result.begin());
			while(!result.empty() && result.back() == '0') result.pop_back();
		}
	}
	return result;
}

void test_case(){
	string s;
	cin >> s;
	cout << build_from_freq(s) << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while(t--){
		test_case();
	}
	return 0;
}