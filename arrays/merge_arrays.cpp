#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v1 = {1, 3, 5};
    vector<int> v2 = {2, 4, 6,8,9};
    int k = 0;
    int n1 = v1.size();
    int n2 = v2.size();
    vector<int> ans(n1+n2);

    int i = 0, j = 0;
    while ((i < v1.size()) && (j < v2.size()))
    {
        if (v1[i] <= v2[j])
        {
            ans[k] = v1[i];
            i++;
            k++;
        }
        else
        {
            ans[k] = v2[j];
            j++;
            k++;
        }
    }

    while (i < v1.size())
    {
        ans[k] = v1[i];
        i++;
        k++;
    }

    while (j < v2.size())
    {
        ans[k] = v2[j];
        j++;
        k++;
    }

    for(int i=0;i<(v1.size()+v2.size());i++){
        cout<<ans[i]<<" ";
    }
}