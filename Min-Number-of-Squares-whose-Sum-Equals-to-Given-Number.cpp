// Minimum Number of Squares whose Sum Equals to Given Number 'n'
// https://www.youtube.com/watch?v=96-qEnEuj5U

// Example : n = 18  Output : 2 (9 + 9)
// n = 100  Output : 1 (100)
// n = 28  Output : 4 (9 + 9 + 9 + 1)

#include<bits/stdc++.h>
using namespace std;


// ******** Resursion ********

int go1(int n, int x){

    if(n <= 0) return 0;

    int res = INT_MAX;
   
    for(int i = 1; i <= x; i++){
        if(i * i <= n)
            res = min(res, 1 + go1(n - i * i, x));
    }
    return res;
}


// ******** Recursion + Memoization (DP) ********

unordered_map <int, int> Map;
int go2(int n, int x){

    if(n <= 0) return 0;

    if(Map.find(n) != Map.end()) return Map[n];
   
    int res = INT_MAX;
   
    for(int i = 1; i <= x; i++){
        if(i * i <= n)
            res = min(res, 1 + go2(n - i * i, x));
    }
    return Map[n] = res;
}

int main(){

    int n;
    cin >> n;

    int x = ceil(sqrt(n));
    cout << go2(n, x);

    return 0;
}
