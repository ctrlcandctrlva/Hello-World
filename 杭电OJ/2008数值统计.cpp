//https://acm.hdu.edu.cn/showproblem.php?pid=2008
#include <iostream>
using namespace std;

double a[10000];
int main()
{
	int n;
	while (cin >> n && n) 
	{
		for (int i = 0; i < n; ++i)
		{
			double x;
			cin >> x;
			a[i] = x;
		}
		int pcnt = 0, zcnt = 0, ncnt = 0;
		for (int i = 0; i < n; ++i)
		{
                        //浮点数大于零的判断：大于一个很小的正数
			if (a[i] > 1e-8)
				++pcnt;
                        //小于一个很大的负数
			else if (a[i] < -1e-8 )
				++ncnt;
			else
				++zcnt;
		}
		cout << ncnt << ' ' << zcnt << ' ' << pcnt  << endl;
	}
	return 0;
}
