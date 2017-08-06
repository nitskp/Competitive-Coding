#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int > dp;

int ncode(string s){
	int n = s.length();
	
	if(dp[n] != -1) return dp[n];

	if(n == 1){
		// cout<<"Inside 1\n";
		if(s[0] != '0') dp[1] = 1;
		else dp[1] = 0;
		return dp[1];
	}

	if(n == 2){
		int k = 10*(int)(s[0] - '0') + (int)(s[1] - '0');
		// cout<<"Inside 2\n";
		if(s[1] == '0' || s[0] =='0' || k > 26) dp[2] = 1;
		else dp[2] = 2;
		return dp[2];
	}

	int k = 10*(int)(s[0] - '0') + (int)(s[1] - '0');
	if(s[0] == '0' || k % 10 == 0 || k > 26 || k <= 9 || s[2] == '0'){
		// cout<<"Inside < 26\n";
		s.erase(s.begin());
		dp[n] = ncode(s);
		return dp[n];
	}

	if(k <= 26)
	{
		// cout<<"Inside >= 26\n";
		string s1 = s;
		s1.erase(s1.begin());
		// cout<<s1<<endl;
		string s2 = s1;
		s2.erase(s2.begin());
		// cout<<s2<<endl;
		dp[n] = ncode(s1) + ncode(s2);
		// cout<<dp[n];
		return dp[n];
	}
}

int main(int argc, char const *argv[])
{

	while(1) {
	    string s;
	    cin>>s;
		int n = s.length();
		if(s == "0") break;
		dp.resize(n + 1, -1);
		int output = ncode(s);
		cout<<output<<endl;
		dp.clear();
	}
	
	return 0;
}