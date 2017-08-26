#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}

int main(int argc, char const *argv[])
{
	int n, t2s3 = 0, n2s3 = 0;
	long long ans = 0,sum = 0;
	cin>>n;
	vector<int> v;
	for (int i = 0; i < n; ++i)
	{	
		int temp;
		cin>>temp;
		sum += temp;
		v.push_back(sum);
	}

	if(sum == 0){
		for (int i = 0; i < n; ++i)
		{
			if(v[i] == 0){
				ans++;
			}
		}

		ans--;
		ans = ans*(ans - 1)/2;
		cout<<ans;
	}


	else if(sum % 3 == 0 && n > 2){

	int s3 = sum/3;



	vector<pair<int,int> > a;

	for (int i = 0; i < n; ++i)
	{
		if(v[i] == s3 || v[i] == 2*s3){
			if(v[i] == 2*s3)
				t2s3++;
			pair<int,int> temp;
			temp.first = v[i];
			temp.second = i;
			a.push_back(temp);
		}
	}

	sort(a.begin(),a.end(),sortbysec);

	for (int i = 0; i < a.size(); ++i)
	{
		if(a[i].first == 2*s3)
			n2s3++;
		else{
			ans += t2s3 - n2s3;
		}
	}

	cout<<ans;
}

	else{
		cout<<"0";
	}
	return 0;
}