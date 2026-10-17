class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int l =0;
         int e = n-1;
        while(l<e){
            swap(s[l++] , s[e--]);
        }
        
    }
};