#include <iostream>
using namespace std;
int main() {
	int T; //number of test cases
	int N; //number to be examined 

	cin>>T;
    
	for(int i = 0; i<T; i++){
		cin>>N;
		int count=0;
		for(int j=0;j<=N;j++){
			for(int k=0;k<=N;k++){
				if((j*k)==N){
					count++;
				}
			}
		}
		cout<<count;
	}
	
}
