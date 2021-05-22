/*CPP code for find the minimum number of coins,
Question is, Given a value V, if we want to make a change for V Rs, and we have an infinite supply 
of each of the denominations in Indian currency, i.e., we have an infinite supply of { 1, 2, 5, 10, 
20, 50, 100, 500, 1000} valued coins/notes, what is the minimum number of coins and/or notes needed to 
make the change?,
The Solution is pretty simple traverse from the bigger notes or denominations and check which denomination
is less than the value V, if there is then count that denomination in number of changes and else don't count.
You can sort the array also in descending but there is no need for that, we can simple traverse the array 
from back

Input:
Enter the value: 70

Output:
Number of changes: 2
Changes are: 50 20 

Input:
Enter the value: 93

Output:
Number of changes: 4
Changes are: 50 20 20 2 1 

Time: O(V)
Space: O(1)
*/

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int v;
    cout<<"Enter the value: ";
    cin>>v;

    int denominations[] = {1, 2, 5, 10, 20, 50, 100, 500, 2000};
    vector<int> changes;
    int numberOfChanges = 0;
    int i = 8;

    while(v > 0){
        if(denominations[i] <= v){
            int numberOfNotes = v/denominations[i];        //finding the number of notes or denominations
            v = v - (numberOfNotes * denominations[i]);     //remaining v value
            numberOfChanges++;                              //count the number of changes

            //store type of denomination we have found
            while(numberOfNotes){
                changes.push_back(denominations[i]);
                numberOfNotes--;
            }
        }
        i--;
    }
    cout<<"Number of changes: "<<numberOfChanges<<endl;
    cout<<"Changes are: ";
    for(int i=0; i<changes.size(); i++){
        cout<<changes[i]<<" ";
    }
    cout<<endl;
    return 0;
}
