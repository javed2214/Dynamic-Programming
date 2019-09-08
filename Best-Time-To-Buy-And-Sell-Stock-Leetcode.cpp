// Best Time to Buy and Sell Stock - LeetCode
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// https://www.youtube.com/watch?v=mj7N8pLCJ6w

int maxProfit(vector <int> &prices){

	int mx = 0;
	int mi = INT_MAX;

	for(int i=0;i<prices.size();i++){
		if(prices[i] < mi) mi = prices[i];
		else mx = max(mx, prices[i] - mi);
	}
	return mx;
}