#include <iostream>
using namespace std;

int main()
{
	int x[3];
	int y;
	int *p;
	
	y = 6;
	p = &y;
	
	for(int i=0;i<3;i++){
		x[i] = (*p*i)%10;
		cout << x[i] << " ";
	}

	return 0;
}
