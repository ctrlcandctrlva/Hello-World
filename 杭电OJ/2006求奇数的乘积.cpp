//https://acm.hdu.edu.cn/showproblem.php?pid=2006
#include <iostream>
using namespace std;

int a[10000];
int main()
{
	int n;
	while (cin >> n) 
	{
		for (int i = 0; i < n; ++i)
		{
			int x;
			cin >> x;
			a[i] = x;
		}
		int prod = 1;
		for (int i = 0; i < n; ++i)
		{
			if (a[i] & 1)		//a[i] % 2 == 0
				prod *= a[i];
		}
		cout << prod << endl;
	}
	return 0;
}
