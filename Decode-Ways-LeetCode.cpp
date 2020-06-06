// Decode Ways - LeetCode
// https://www.youtube.com/watch?v=9Ky-lgdaJUE

class Solution {
public:
    
    unordered_map <int, int> Map;
    
    int go(string s, int index){
        
        if(s[index] == '0') return 0;
        if(index == s.length() or index == s.length() - 1) return 1;
    
        if(Map.count(index)) return Map[index];
        
        int way1 = go(s, index + 1);
        int way2 = 0;
        
        if(s[index] == '1' or (s[index] == '2' and s[index + 1] <= '6')) way2 = go(s, index + 2);
        
        return Map[index] = way1 + way2;
    }
    
    int numDecodings(string s) {
        
        return go(s, 0);   
    }
};