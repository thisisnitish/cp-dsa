/*
Move all negative numbers to beginning and positive to end with constant extra space
Input: -12, 11, -13, -5, 6, -7, 5, -3, -6
Output: -12 -13 -5 -7 -3 -6 11 6 5
https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/
*/

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    //two pointer approach
    int left = 0, right = n-1;

    while(left <= right){
        if(arr[left] < 0 && arr[right] < 0)
            left++;

        else if(arr[left] > 0 && arr[right] < 0){
            swap(arr[left], arr[right]);
            left++; right--;
        }
        else if(arr[left] > 0 && arr[right] > 0){
            right--;
        }
        else if(arr[left] < 0 && arr[right] > 0){
            left++;
            right--;
        }
    }

    //display the array
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}