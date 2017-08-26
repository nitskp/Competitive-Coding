#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<vector<int> > dp;

bool isposs(set<int> s,int sum){
	
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

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;

	for (int i = 0; i < t; ++i)
	{
		int n, sum = 0;
		bool ans = false;
		cin>>n;
		set<int> s;
		for (int j = 0; j < n; ++j)
		{
			int temp;
			cin>>temp;
			sum += temp;
			s.insert(temp);
			cout<<j<<" ";
			cout<<temp<<endl;
		}
		// cout<<"tesr\n";
		// cout<<s.size()<<endl;

		if(sum % 2 == 0) {
			sum /= 2;

			dp.resize(sum + 1);
			for (int i = 0; i < sum + 1; ++i)
			{
				dp[i].resize(n + 1, -1);
			}
			
		 ans = isposs(s,sum);
		 
		}
		if(ans)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
}