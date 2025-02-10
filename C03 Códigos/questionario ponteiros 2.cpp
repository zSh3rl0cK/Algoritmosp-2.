#include <iostream>
using namespace std;

int main()
{
	int x[4] = {1,2,3,4};
	int y = 3;
	int *p, *q;
	
	p = x;
	q = &y;
	
	p++;
	
	cout << *p + *q; // deve ser igual a 5
	
	return 0;
}