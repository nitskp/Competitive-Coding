#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int m,n,prev,curr;
	long long time = 0;
	cin>>n>>m;
	for (int i = 0; i < m; ++i)
	{
		cin>>curr;
		if(i == 0){
			prev = curr;
			time += curr - 1;
		}
		else{
			if(prev > curr){
				time += n - prev + curr;
			}

			else{
				time += curr - prev;
			}
			prev = curr;
		}

	}
	cout<<time;
	return 0;
}