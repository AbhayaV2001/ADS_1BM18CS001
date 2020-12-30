#include<bits/stdc++.h> 
using namespace std; 
  
void findElements(int arr[], int n) 
{ 
	int first = INT_MIN,  
        	second = INT_MIN; 
    	for (int i = 0; i < n; i++) 
    	{ 
        		if (arr[i] > first) 
        		{ 
            			second = first; 
            			first = arr[i]; 
        		} 
  
        		else if (arr[i] > second) 
            		second = arr[i]; 
    	} 
  
     	sort(arr,arr+n);
    	for (int i = 0; i < n; i++) 
        		if (arr[i] < second) 
            			cout << arr[i] << " "; 
} 
  
int main() 
{ 
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int arr[n];
		for(int i=0; i<n;i++)
			cin>>arr[i];
		findElements(arr, n); 
	}
    	
    	return 0; 
} 