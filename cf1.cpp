#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int n, k;
	cin>>n>>k;
	string s1;
	bool check = true;
	int a[26] = {0};
	cin>>s1;
	for (int i = 0; i < n; ++i)
	{
		int temp = (int)(s1[i] - 'a');
		a[temp]++;
		if(a[temp] > k){
			check = false;
			break;
		}
	}

	if(check)
		cout<<"Yes\n";
	else
		cout<<"No\n";
	return 0;
}