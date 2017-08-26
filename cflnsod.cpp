#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int m, s;
	cin>>m>>s;

	int temp = s;
	if(s <= 0 & m > 1)
		cout<<"-1 -1";
	else if(s > 9*m)
		cout<<"-1 -1";
	else{
	vector<int > v;
	for (int i = m - 1; i >= 0; --i){
		int dig = s - 9*i;
		if(dig < 0){
			if(v.empty())
				dig = 1;
			else
				dig = 0;

		}
		v.push_back(dig);
		s -= dig;
	}

	for (int i = 0; i < m; ++i)
		cout<<v[i];
	cout<<' ';

	v.clear();
	//cout<<temp<<endl;

	for (int i = m - 1; i >= 0; --i){
		int dig = temp - 9;
		if(dig < 0){
			dig = temp;
		}
		else
			dig = 9;
		//cout<<dig<<endl;
		v.push_back(dig);
		temp -= dig;
	}
		for (int i = 0; i < m; ++i)
		cout<<v[i];
}
	return 0;
}