#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main(int argc, char const *argv[])
{
	
	int n;
	cin>>n;
	vector<int > a, dp;



	for (int i = 0; i < n; ++i){
		int temp;
		cin>>temp;
		a.push_back(temp);
	}
	dp.clear();
	dp.resize(n + 1);
	sort(a.begin(),a.end());

	int count = 1;

	vector<pair<int,int > > v;

	for (int i = 0; i < n - 1; ++i){
		if(a[i] != a[i + 1]){
			pair<int, int > temp;
			temp.first = a[i];
			temp.second = count;
			v.push_back(temp);
			count = 1;
		}
		else{
			count++;
		}
	}

	pair<int, int > temp;
			temp.first = a[n - 1];
			temp.second = count;
			v.push_back(temp);
			dp[0] = 0;
	dp[1] = v[n - 1].first * v[n - 1].second;
	n = a.size();
	for(int i = 2; i <= n; i++){
		dp[i] = max(dp[i  - 1], dp[i - 2] + v[n - i].first * v[n - i].second);

	}
	int ans = dp[n];

	cout<<ans;

	return 0;
}