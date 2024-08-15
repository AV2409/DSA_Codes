#include <bits/stdc++.h>

using namespace std;

void findArraySum(vector<int>&a, int n, vector<int>&b, int m) {
	// Write your code here.
	vector<int> ans;
	int num1=0;
	int num2=0;
	for(int i=0;i<n;i++){
		num1=num1*10+a[i];
	}

	for(int i=0;i<m;i++){
		num2=num2*10+b[i];
	}

	int sum=num1+num2;
    cout<<sum;

	// while(sum!=0){
	// 	int rem=sum%10;
	// 	ans.push_back(rem);
	// 	sum=sum/10;

	// }



	// int i=0;
	// int j=ans.size()-1;

	// while(i<j){
	// 	swap(ans[i],ans[j]);

	// 	i++;
	// 	j--;
	// }

}

int main(){
    vector<int> a={1,2,3,4};
    vector<int> b={6};

    findArraySum(a,4,b,1);


}