#include <iostream>
using namespace std;

double a[10000];
int main()
{
	int n;
	while (cin >> n) 
	{
		for (int i = 0; i < n; ++i)
		{
			double x;
			cin >> x;
			a[i] = x;
		}
                //最大值初始化为一个很小的数
		double max = -100000000000000;
                //最小值初始化为一个很大的数
		double min = 100000000000000;
		double sum = 0;
		for (int i = 0; i < n; ++i)
		{
			if (a[i] > max)
				max = a[i];
			if (a[i] < min)
				min = a[i];
			sum += a[i];
		}
		sum -= max;
		sum -= min;
		sum /= (n - 2);
		printf("%.2lf\n", sum);
	}
	return 0;
}
