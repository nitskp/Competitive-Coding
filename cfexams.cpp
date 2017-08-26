#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	vector<pair<int,int > > v;
	for (int i = 0; i < n; ++i)
	{
		pair<int,int > temp;
		cin>>temp.first>>temp.second;
		v.push_back(temp);
	}

	sort(v.begin(),v.end());

	int currdate = v[0].second;

	for (int i = 1; i < n; ++i)
	{
		if(currdate > v[i].second){
			currdate = v[i].first;
		}

		else if(currdate < v[i].second)
			currdate = v[i].second;
	}

	cout<<currdate;

	return 0;
}