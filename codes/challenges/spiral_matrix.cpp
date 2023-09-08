#include <iostream>
#include <vector>
using namespace std;

void printSpiralMatrix(vector<vector<long long int>> &mat, long long int m, long long int n){
	// m rows
	// n cols
	long long int left = 0; //left column pointer
	long long int right = n; //right column pointer
	long long int top = 0; //top pointer
	long long int bottom = m; //bottom pointer
	
	//iterating 
	while(left<right && top<bottom){
		//printing first row
		for(long long int i = left; i<right; i++){
			cout<<mat[top][i]<<" ";
		}
		top++; //eliminating first row
		
		//printing right column
		for(long long int i = top; i < bottom; i++){
			cout<<mat[i][right-1]<<" ";
		}
		right--; 
		if(!(left<right && top<bottom)){
			break;
		}
		
		//printing bottom row
		for(long long int i = right-1; i>=left; i--){
			cout<<mat[bottom-1][i]<<" ";
		}
		bottom--; //eliminating first row
		
		//printing left column
		for(long long int i = bottom-1; i >= top; i--){
			cout<<mat[i][left]<<" ";
		}
		left++;
	}
}

int main() {
	long long int m,n;
	cin>>m>>n;
	vector<vector<long long int>> mat;
	for(long long int i = 0; i<m; i++){
		vector<long long int> temp;
		for(long long int j = 0; j<n; j++){
			long long int inp;
			cin>>inp;
			temp.push_back(inp);
		}
		mat.push_back(temp);
	}
	printSpiralMatrix(mat, m, n);
    // your code goes here
    return 0;
}