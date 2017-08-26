#include <iostream>

using namespace std;

long long decorations(long long r, long long g, long long b){
	
	if(g < 0 && b < 0){
		return 0;
	}

	if(r == g && g == b){
		return r;
	}

	if(b + g >= r){
		return (r + b + g)/3;
	}

	if(r >= 2*(b + g)){
		return b + g;
	}

	else{

		return (b + g + r)/3;
	}

}

int main(int argc, char const *argv[])
{
	long long r,g,b,ans;
	cin>>r>>g>>b;
	if(r >= max(g,b))
	{
		if(g >= b)
			ans = decorations(r,g,b);
		else
			ans = decorations(r,b,g);
	}

	else if(g >= max(r,b))
	{
		if(r >= b)
			ans = decorations(g,r,b);
		else
			ans = decorations(g,b,r);
	}

	else if(b >= max(g,r))
	{
		if(g >= r)
			ans = decorations(b,g,r);
		else
			ans = decorations(b,r,g);
	}

	cout<<ans;


	return 0;
}