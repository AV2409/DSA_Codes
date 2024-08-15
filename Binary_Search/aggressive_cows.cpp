bool ispossible(vector<int> &stalls, int k,int mid){
    int cows=1;
    int posi=stalls[0];

    for(int i=0;i<stalls.size();i++){
        if(stalls[i]-posi>=mid){
            cows++;
            posi=stalls[i];

            if(cows==k) return true;
        }


    }
    return false;
}


int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    sort(stalls.begin(),stalls.end());

    int mini=stalls[0];
    int maxi=stalls[0];
    

    for(int i=0;i<stalls.size();i++){
        mini=min(mini,stalls[i]);
        maxi=max(maxi,stalls[i]);
    }

    int s=1;
    int ans=-1;

    int e=maxi-mini;

    int mid=s+(e-s)/2;

    while (s<=e){
        if(ispossible(stalls,k,mid)){
            ans=mid;
            s=mid+1;
        }

        else{
            e=mid-1;
        }

        mid=s+(e-s)/2;
    }

    return ans;

}