#include <iostream>
#include <vector>

using namespace std;


vector<vector<int> > dp;

bool isposs(vector<int> s,int sum){
	
	int n = s.size();
	n++;
	if(dp[sum][n] != -1)
		return dp[sum][n];

	if(sum == 0){
		dp[sum][n] = 1;
		return dp[sum][n];
	}

	if(n == 0){
		dp[sum][n] = 0;
		return dp[sum][n];
	}

	else{
		int temp = *s.begin();
		s.erase(s.begin());
		if(isposs(s,sum - temp) || isposs(s,sum))
			dp[sum][n] = 1;
		else
			dp[sum][n] = 0;
		return dp[sum][n];
	}
}

int diff(vector<int > v){

	int n = v.size();

	int sum = 0;

	for (int i = 0; i < n; ++i)
	{
		sum += v[i];
	}

	sum = sum/2;

	dp.resize(sum + 1);

	for (int i = 0; i <= sum; ++i)
	{
		dp[i].resize(n + 1, -1);
	}

	for (int i = sum; i >= 0; --i)
	{
		bool ans = isposs(v,i);
		if(ans)
			return 2*(sum - i);
	}

}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	for (int i = 0; i < t; ++i)
	{
		int n;
		vector<int > v;
		cin>>n;
		v.clear();
		v.resize(n);
		for (int j = 0; j < n; ++j)
		{
			cin>>v[j];
		}

		int ans = diff(v);
		cout<<ans<<endl;

	}
	return 0;
}