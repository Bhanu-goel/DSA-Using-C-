#include<iostream>
using namespace std;

int* binary(long long n)
{
	int binarynum[32];
	int i=0;
	while(n>0)
	{
		binarynum[i]=n%2;
		n/=2;
		i++;
	}
    int bin[i-1];
	for(int j=i-1;j>=0;j--)
	{
		bin[j]=binarynum[j];
	}
    return bin;
}

int main(){
    int *ptr = binary(7);
    cout<<ptr[0]<<ptr[1];
    return 0;
}