/*
Minimum Platforms
https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#
*/

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    //Time: O(nlogn), Space: O(1)
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr, arr+n);
    	sort(dep, dep+n);
    	
    	int i=1, j=0, platformsNeeded = 1, result = 1;
    	while(i < n && j < n){
    	    if(arr[i] <= dep[j]){
    	        platformsNeeded++;
    	        i++;
    	    }
    	    else if(arr[i] > dep[j]){
    	         platformsNeeded--;
    	         j++;
    	    }
    	    
    	    result = max(result, platformsNeeded);
    	}
    	return result;
    }
};
