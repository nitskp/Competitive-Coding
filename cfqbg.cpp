#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	int n,t;
	cin>>n>>t;
	vector<char> v;
	for (int i = 0; i < n; ++i)
	{
		char temp ;
		cin>>temp;
		v.push_back(temp);
	}

	for (int i = 0; i < t; ++i)
	{
		for (int j = 0; j < n - 1; ++j)
		{
			if(v[j] < v[j + 1]){
				v[j] = 'G';
				v[j + 1]= 'B';
				++j;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		cout<<v[i];
	}

	return 0;
}