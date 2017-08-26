#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> dp;

int coinchange(int n, set<int > s){
	if(dp[n] != -1) return dp[n];
	if(n == 0) {
		dp[n] = 0;
		return dp[n];
	}

	int m = s.size();
	dp[n] = 0;
	set<int > s1(s.begin(),s.end());
	for (int i = 0; i < m; ++i){
			dp[n] += coinchange(n - *s1.end(),s);
			s1.erase(s1.end());
	}
	return dp[n];
}

int main(int argc, char const *argv[])
{
	int m, n, t;
	set<int > s;
	cin>>t;
	for (int i = 0; i < t; ++i)
	{
		cin>>m;
		for (int j = 0; j < m; ++j)
			{
				int temp;
				cin>>temp;
				s.insert(temp);
			}
			cin>>n;
			dp.resize(n + 1, -1);
			int ans = 9;
			ans = coinchange(n,s);
			cout<<ans<<endl;

	}

	return 0;
}