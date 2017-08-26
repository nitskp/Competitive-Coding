#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > dp;

int editdist(string s1, string s2){
	int m = s1.length();
	int n = s2.length();

	if(dp[m][n] != -1)
		return dp[m][n];
	

	if(m == 0) {
		dp[m][n] = n;
		return dp[m][n];
	}

	if(n == 0){
		dp[m][n] = m;	
		return dp[m][n];
	}
	
	if(s1[0] == s2[0]){

		s1.erase(s1.begin());
		s2.erase(s2.begin());
		dp[m][n] = editdist(s1,s2);
		return dp[m][n];
	}

	else{
		string s3 = s1;
		s3.erase(s3.begin());
		string s4 = s2;
		s4.erase(s4.begin());
		dp[m][n] = 1 + min(editdist(s3,s4),min(editdist(s1,s4),editdist(s3,s2)));
		return dp[m][n];
	}
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	for (int i = 0; i < t; ++i)
	{
		int m, n;
		string s1, s2;
		cin>>s1>>s2;
		m = s1.length();
		n = s2.length();
		dp.clear();
		dp.resize(m + 1);
		for (int i = 0; i <= m; ++i)
		{
			dp[i].resize(n + 1, -1);
		}
		int ans = editdist(s1,s2);
		cout<<ans<<endl;
	}
	return 0;
}