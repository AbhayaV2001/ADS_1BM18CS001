#include<bits/stdc++.h> 
using namespace std; 
  
void solution(int l, int r) 
{ 
    	for (int i=l ; i<=r ; i++) 
    	{ 
        		int num = i; 
        		bool visited[10] = {false}; 
  
        		while (num) 
        		{ 
            			if (visited[num % 10]) 
                			break; 
  
            			visited[num%10] = true; 
  
            			num = num/10; 
        		} 
  
        		if (num == 0) 
            			cout << i << " "; 
    	} 
} 
  

int main() 
{ 
    	int l , r ; 
	cout<<"L=";
	cin>>l;
	cout<<"\nR=";
	cin>>r;
	cout<<"\n";
    	solution(l, r); 
    	return 0; 
} 
