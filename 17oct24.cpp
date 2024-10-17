// You are given an integer num. You can swap two digits at most once to get the maximum valued number.

// Return the maximum valued number you can get.

 

// Example 1:

// Input: num = 2736
// Output: 7236
// Explanation: Swap the number 2 and the number 7.
// Example 2:

// Input: num = 9973
// Output: 9973
// Explanation: No swap.
 

// Constraints:

// 0 <= num <= 108

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        string ans = to_string(num);
        int n = ans.size();
        vector<pair<int,int>> v;

        for(int i=0;i<n;i++){
            v.push_back({ans[i]-'0',i});
        }

        sort(v.rbegin(),v.rend());
        int i=0,j=0;
        while(j<v.size()){
            auto p=v[j];
            j++;
            if(p.first == ans[i]-'0'){
                i++;
                continue;

            }
            break;
        }
        v={};
        int temp = i;
        while(i<n){
            v.push_back({ans[i]-'0',i});
            i++;
        }
        sort(v.rbegin(),v.rend());
        j=0;
        if(v.size()){
            swap(ans[temp],ans[v[j].second]);
        }
        return stoi(ans);
    }
};