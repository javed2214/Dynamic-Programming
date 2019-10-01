// Arithmetic Slices - LeetCode
// https://leetcode.com/problems/arithmetic-slices/

// *************************** METHOD_1 ***************************
// Time  :  O(n)
// Space :  O(n)

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        
        int n = A.size();
        int co = 0;

        int dp[n] = {0};

        for(int i=2;i<n;i++){
        	if(A[i] - A[i-1] == A[i-1] - A[i-2]){
        		dp[i] = 1 + dp[i-1];
        		co += dp[i];
        	}
        }
        return co;
    }
};


// *************************** METHOD_1 ***************************
// Time  :  O(n^2)
// Space :  O(n)

class Solution {
public:

	int Count(auto &A, int index){

		int diff = A[index] - A[index - 1];
		int co = 0;

		for(int i=index-1;i>=1;i--){
			if(A[i] - A[i-1] == diff) co++;
			else break;
		}
		return co;
	}

    int numberOfArithmeticSlices(vector<int>& A) {
        
        int n = A.size();
        if(n <= 2) return 0;

        int dp[n] = {0};

        for(int i=2;i<n;i++)
        	dp[i] = dp[i-1] + Count(A,i);

        return dp[n-1];
    }
};