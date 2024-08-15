#include <bits/stdc++.h>

using namespace std;

int first_occurance(vector<int> &arr, int st,int key)
{
    int start=st+1;
    int end=arr.size()-1;
    int mid=start + (end-start)/2;
    int ans=-1;
    
    while(start<=end){

        if(key==arr[mid]) {
            ans=mid;
            end=mid-1;

        }

        else if(key>arr[mid]) start=mid+1;

        else if(key<arr[mid]) end=mid-1;

        mid=start + (end-start)/2;

    }
    return ans;
}

int last_occurence(vector<int> &arr,int key,int first){
    int start=first;
    int end=arr.size()-1;
    int mid=start + (end-start)/2;
    int ans=start;

    while(start<=end){
        if(key==arr[mid]){
            ans=mid;
            start=mid+1;
        }

        else if(key>arr[mid]){
            start=mid+1;
        }

        else if(key<arr[mid]){
            end=mid-1;
        }
        mid=start + (end-start)/2;
    }
    return ans;
}


vector<vector<int>> pairSum(vector<int> &arr, int s)
{
   // Write your code here.

   sort(arr.begin(),arr.end());
   vector<vector<int>> sol;
   for(int i=0;i<arr.size();i++){
      int req=s-arr[i];


      int first=first_occurance(arr, i,req);
      int last=last_occurence(arr,req,first);

      if(first!=-1){
         for(int j=first;j<=last;j++){
            vector <int> temp;
            temp.push_back(arr[i]);
            temp.push_back(arr[j]);

            sol.push_back(temp);

         }
      }

   }

   return sol;
}