// High-Access Employees

/*
You are given a 2D 0-indexed array of strings, access_times, with size n. For each i where 0 <= i <= n - 1, access_times[i][0] represents the name of an employee, and access_times[i][1] represents the access time of that employee. All entries in access_times are within the same day.

The access time is represented as four digits using a 24-hour time format, for example, "0800" or "2250".

An employee is said to be high-access if he has accessed the system three or more times within a one-hour period.

Times with exactly one hour of difference are not considered part of the same one-hour period. For example, "0815" and "0915" are not part of the same one-hour period.

Access times at the start and end of the day are not counted within the same one-hour period. For example, "0005" and "2350" are not part of the same one-hour period.

Return a list that contains the names of high-access employees with any order you want.

 
*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string,vector<int>> mpp;
        for(auto i:access_times){
            mpp[i[0]].push_back(stoi(i[1]));
        }
        vector<string> ans;
        for(auto i:mpp){
            auto v=i.second;
            sort(v.begin(),v.end());
            int l=0,r=0,cnt=0;
            for(;r<v.size();r++){
                cnt++;
                if(cnt>=3 && v[r]-v[l]<100){
                    ans.push_back(i.first);
                    break;
                }
                if(v[r]-v[l]>=100)l++,cnt--;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<string>> v={{"akuhmu","0454"},{"aywtqh","0523"},{"akuhmu","0518"},{"ihhkc","0439"},{"ihhkc","0508"},{"akuhmu","0529"},{"aywtqh","0530"},{"aywtqh","0419"}};
    vector<string> a=s.findHighAccessEmployees(v);
    for(auto i:a)cout<<i<<" ";
    
    return 0;
}