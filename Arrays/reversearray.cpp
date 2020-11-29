/*
Input  : arr[] = {1, 2, 3, 4, 5, 6}
Output : arr[] = {6, 5, 4, 3, 2, 1}
*/

#include <iostream>
using namespace std;

void reverseArray(int arr[], int n)
{

    for (int i = 0; i < n / 2; i++){
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }

    //print the array
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    reverseArray(arr, n);
    return 0;
}