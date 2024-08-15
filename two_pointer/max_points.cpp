#include<iostream>
using namespace std;

int maxSum(int nums[],int k){
    int r=8;
    int lsum=0;
    int rsum=0;
    for(int i=0;i<k;i++){
        lsum=lsum+nums[i];
    }
    int maxsum=lsum;
    
    for(int i=k-1;i>=0;i--){
        lsum=lsum-nums[i];
        rsum=rsum+nums[r];
        r=r-1;
        int sum=lsum+rsum;
        maxsum=max(maxsum,lsum+rsum);
    }

    return maxsum;
}
int main(){
    int arr[9]={6,2,3,4,7,2,1,7,1};

    int ans=maxSum(arr,4);

    cout<<ans;

}
