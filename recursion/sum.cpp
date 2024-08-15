#include <iostream>
using namespace std;

int getSum(int arr[], int st, int size)
{
    
    if (size == 0)
    {
        return 0;
    }
    
    return  arr[st]+getSum(arr, ++st, --size);
    

   
}

int main()
{
    int arr[6] = {1, 3, 15, 2, 34, 0};
    cout << getSum(arr, 0, 6) << endl;

}