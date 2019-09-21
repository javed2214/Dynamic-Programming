// Container With Most Water - LeetCode
// https://leetcode.com/problems/container-with-most-water/

class Solution{
public:

	int maxArea(vector <int> &height){

		int l = 0;
		int r = height.size() - 1;
		int mx = INT_MIN;

		while(l < r){
			int mi = min(height[l], height[r]);
			mx = max(mx, mi * (r - l));
			if(height[l] < height[r]) l++;
			else r--;
		}
		return mx;
	}
};