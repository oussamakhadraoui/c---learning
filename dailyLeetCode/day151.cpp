 #include <bits/stdc++.h>
 using namespace std;
 class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i =0,j=0,n=word.size();
        while(j<n&&word[j]!=ch)j++;
        if(j==n)return word;
        while(i<=j){
            swap(word[i],word[j]);
            i++;
            j--;
        }
        return word;
    }
};