// Program to Find Length of Longest Bitonic Subsequence
// https://www.geeksforgeeks.org/longest-bitonic-subsequence-dp-15/
// LBS = max(LIS + LDS - 1)


class Solution{
	public:
	int LongestBitonicSequence(vector<int> a){
	    
	    int n = a.size();
	    
	    int lis[n], lds[n];
	    for(int i = 0; i < n; i++) lis[i] = 1, lds[i] = 1;
	    
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < i; j++){
	            if(a[i] > a[j])
	                lis[i] = max(lis[i], 1 + lis[j]);
	        }
	    }
	    
	    for(int i = n-1; i >= 0; i--){
	        for(int j = n-1; j > i; j--){
	            if(a[i] > a[j])
	                lds[i] = max(lds[i], 1 + lds[j]);
	        }
	    }
	    
	    int mx = 0;
	    
	    for(int i = 0; i < n; i++){
	        mx = max(mx, lis[i] + lds[i] - 1);
	    }
	    return mx;
	}
};
