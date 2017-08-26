#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	int m,n;
	cin>>m>>n;
	vector<int > v;
		

	if(n < m -1 || n > 2*(m + 1)){
		cout<<"-1";
	}

	else if(n == m -1){
		for (int i = 0; i < n + m ; ++i)
		{
			if(i % 2 == 0)
				v.push_back(0);
			else
				v.push_back(1);
		}
		for (int i = 0; i < v.size(); ++i)
		{
			cout<<v[i];
		}
	}
	else{
		
		while(n > m + 1 && m > 0) {
		    v.push_back(1);
		    v.push_back(1);
		    v.push_back(0);
		    n -= 2;
		    m--;
		}

		// cout<<m<<" "<<n<<endl;

		while(n > 0 && m > 0){
			// cout<<"n > 0\n";
			v.push_back(1);
		    v.push_back(0);	
		    n--;
		    m--;	    
		}

		// cout<<m<<" "<<n<<endl;

		while(n > 0){
			v.push_back(1);
			n--;
		}

		// cout<<m<<" "<<n<<endl;
		
		while(m > 0){
			v.push_back(0);
			m--;
		}

		// cout<<m<<" "<<n<<endl;

		for (int i = 0; i < v.size(); ++i)
		{
			cout<<v[i];
		}
	}
	return 0;
}