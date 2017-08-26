#include <iostream>
#include <vector>

using namespace std;

int godsend(vector<int > v){
	int n = v.size();
	int tsum = 0;
	int pos = -1;
	vector<int > sum;
	sum.resize(n);
	int m = n;

	
	for (int i = 0; i < n; ++i)
	{
		tsum += v[i];
		sum[i] = tsum;
	}

	bool chance = true;

	while(tsum > 0){
		if(chance){
			if(tsum % 2 != 0)
				return 1;
			else{
				for (int i = 0; i < m; ++i)
				{
					if(sum[i] % 2 != 0){
						int temp = sum[i];
						pos = i;
						while(i < m){
							sum[i + 1] -= temp;
							tsum -= temp;
						}
					}
				}
				if(pos == -1)
					return 2;
				chance = false;
				m--;
				sum.erase(sum.begin() + pos);
			}
		}

		else{
			if(tsum % 2 == 0)
				return 2;
			else{
				for (int i = 0; i < m - 1; ++i)
				{
					if(sum[i] % 2 == 0 || sum[i + 1] % 2 != 0){
						if(sum[i] % 2 == 0){
						int temp = sum[i];
						pos = i;
						while(i < m){
							sum[i + 1] -= temp;
							tsum -= temp;
						}
					}

					else{
						int temp = sum[i + 1];
						pos = i + 1;
						i++;
						while(i < m){
							sum[i + 1] -= temp;
							tsum -= temp;
						}

					}
				}
				if(pos == -1)
					return 1;

				chance = true;
				m--;
				sum.erase(sum.begin() + pos);
			}
		}
	}
}

}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	vector<int> v;
	v.resize(n);

	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
	}

	int ans = godsend(v);
	if(ans == 1)
		cout<<"First\n";
	else if(ans == 2)
		cout<<"Second\n";
	return 0;
}
