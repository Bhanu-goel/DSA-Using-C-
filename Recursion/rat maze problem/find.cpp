#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> arr={"ab","bv","vd"};
    vector<string>::iterator it;

    it = find(arr.begin(),arr.end(),"ab");
    if(it!=arr.end())
    {
        cout<<it-arr.begin()<<endl;
    }
}
