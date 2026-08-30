/*
 * Platform: LeetCode
 * Submission: 2049268620
 * Problem: Keyboard Row
 * Verdict: Compile Error
 * Date: 2026-06-29
 * URL: https://leetcode.com/problems/keyboard-row/
 *  */

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        auto first_row = 'q,w,e,r,t,y,u,i,o,p,Q,W,E,R,T,Y,U,I,O,P';
        auto second_row = 'a,s,d,f,g,h,j,k,l,A,S,D,F,G,H,J,K,L';
        auto third_row = 'z,x,c,v,b,n,m,Z,X,C,V,B,N,M';
        auto ans = '';
        for(int i = 0; i < words.size(), i++){
            for(int j = 0; j < i; j++){
                if(words[i[j]] == first_row){
                    ans += words[i];
                }
                
                else if(words[i[j]] == second_row){
                    ans += words[i];
                }
                
                else if(words[i[j]] == third_row){
                    ans += words[i];
                }
                return ans;
            }
        }
    }
};