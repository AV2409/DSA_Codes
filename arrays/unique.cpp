#include <iostream>
using namespace std;


void printarr(int arr[], int size)
{
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

void unique(int arr[],int size){
    
    for(int i=0;i<size;i++){
        int count=1;
        for(int j=0;j<size&&j!=i;j++){
            if(arr[i]==arr[j]){
                count++;
            }
            
        }
        if(count==1) {
            cout<<arr[i];
            
        }

}
}
int main()
{
    
    int arr[9]={23,4,33,1,33,-99,23,-99,1};
    

    printarr(arr, 9);
    cout << endl;
    unique(arr,9);
    
}