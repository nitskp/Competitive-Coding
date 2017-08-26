#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int > > dp;

int lcs(string s1, string s2){
	int m = s1.length();
	int n = s2.length();
	
	if(dp[m][n] != -1){
		return dp[m][n];
	}

	if(m == 0){
		dp[m][n] = 0;
		return dp[m][n];
	}

	if(n == 0){
		dp[m][n] = 0;
		return dp[m][n];
	}

	if(s1[0] == s2[0]){
		s1.erase(s1.begin());
		s2.erase(s2.begin());
		dp[m][n] = lcs(s1,s2) + 1;
		return dp[m][n];
	}

	else{
		string s3 = s1;
		string s4 = s2;
		s3.erase(s3.begin());
		s4.erase(s4.begin());
		dp[m][n] = max(lcs(s1, s4),lcs(s3, s2));
		return dp[m][n];
	}
}


int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	for (int i = 0; i < t; ++i){
	int m, n;
	cin>>m>>n;
	dp.clear();
	dp.resize(m + 1);
	for (int j = 0; j < m + 1; ++j)
	dp[j].resize(n + 1, -1);
	string s1,s2;
	cin>>s1>>s2;
	int ans = lcs(s1,s2);
	cout<<ans<<endl;
	}
	return 0;
}