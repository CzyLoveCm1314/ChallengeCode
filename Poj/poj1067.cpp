#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main() 
{
	int a, b, d, t;
while ( cin>>a>>b)
{
        if (a > b) 
		{
             t = a;
             a = b;
             b = t;

		}
		 d = b - a;
		 t = floor(d * (sqrt(5.0) + 1) / 2);
		 puts((t == a) ? "0" : "1");
		
	}
		 return 0;
	
}
