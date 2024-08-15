#include <iostream>
#include<deque> 

#include <algorithm>
using namespace std;

deque<int> binary(int n)
{
    deque<int> ans;

    // while(n!=0){
    //     int bit=n%2;
    //     ans.push_back(bit);
    //     n=n/2;
    // }

    while (n != 0)
    {
        int bit = n & 1;
        ans.push_front(bit);
        n = n >> 1;
    }
    return ans;
}

void toBinary(int n){
    if(n==0) return;

    toBinary(n>>1);

    int x=n&1;
    cout<<x;
}

void print(deque<int> ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
    }
}

int main()
{

    deque<int> x = binary(116655);
    print(x);

    cout<<endl;

    toBinary(116655);
}