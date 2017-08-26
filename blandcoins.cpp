#include <iostream>
#include <map>

using namespace std;

map<int,long long> dp;

long long blandcoins(long long n){
	// if(dp[n] != -1) 
	// 	return dp[n];
	if(n == 0){
		dp[n] = 0;
		return dp[n];
	}
	if(dp[n] != 0) 
		return dp[n];
	else{
		dp[n] = max(n,blandcoins(n/2) + blandcoins(n/3) + blandcoins(n/4));
		return dp[n];
	}
}

int main(int argc, char const *argv[])
{
	int t;
	long long n;
	cin>>t;
	for (int i = 0; i < t; ++i)
	{
		/* code */
	
	cin>>n;
	
	long long ans = blandcoins(n);
	cout<<ans<<endl;
	}
	return 0;
}