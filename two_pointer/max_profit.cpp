#include<iostream>
#include<vector>
using namespace std;

//brute-force

/*
int maxSum(vector<int>& nums,int k){
    int n=nums.size();
    int maxlen=0;
    for(int i=0;i<n;i++){
        int zeros=0;
        int len;
        for(int j=i;j<n;j++){
            if(nums[j]==0) zeros++;

            if(zeros>k) break;

            len=j-i+1;
            maxlen=max(maxlen,len);


        }
    }
    
    
    return maxlen;
}

*/

int maxProfit(vector<int>& prices){
    int n=prices.size();
    int maxlen=0;
    int l=0;
    int r=1;
    int maxprofit=0;
    
    while(r<n){
        if(prices[l]>prices[r]) {
            l++;
            if(l==r) r++;
        }
        int profit=prices[r]-prices[l];
        maxprofit=max(profit,maxprofit);
        r++;
    }

    return maxprofit;
    
    
}
int main(){
    vector<int> arr={7,6,4,3,1};

    int ans=maxProfit(arr);

    cout<<ans;

}