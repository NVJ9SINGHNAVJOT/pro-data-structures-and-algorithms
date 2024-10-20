#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
using namespace std;

// algorithm:
// example:
// answer:
// explanation:
// tags:

std::array<int, 256> hashTheString(string s)
{
    std::array<int, 256> hashVector = {0};
    for (int i = 0; i < s.length(); i++)
    {
        hashVector[s[i]]++;
    }
    return hashVector;
}

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    // Method - 1 -> With sorting
    // map<string,vector<string>>mp;
    // for(auto str : strs){
    //     string s = str;
    //     sort(s.begin(),s.end());
    //     mp[s].push_back(str);
    // }
    // vector<vector<string>>ans;
    // for(auto it = mp.begin(); it!=mp.end();it++){
    //     ans.push_back(it->second);
    // }
    // return ans;

    // Method - 2 -> Without sorting

    map<std::array<int, 256>, vector<string>> mp;
    for (auto str : strs)
    {
        mp[hashTheString(str)].push_back(str);
    }

    vector<vector<string>> ans;

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        ans.push_back(it->second);
    }
    return ans;
}

int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans = groupAnagrams(strs);
    for (auto str : ans)
    {
        for (auto s : str)
        {
            cout << s << " ";
        }
        cout << endl;
    }
}