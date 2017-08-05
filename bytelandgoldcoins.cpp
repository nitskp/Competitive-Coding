#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> dp;

long long dollars(int n){
	if(n == 0) return 0;
	else if(dp[n] != -1) return dp[n];
	else{
		dp[n] = max((long long )n, dollars(n/2) + dollars(n/3) + dollars(n/4));
		return dp[n];
	}
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	for (int i = 0; i < t; ++i)
	{
		int n;
		cin>>n;
		dp.clear();
		dp.resize(n + 1,-1);
		long long output = dollars(n);
		cout<<output<<endl;
	}
	return 0;
}