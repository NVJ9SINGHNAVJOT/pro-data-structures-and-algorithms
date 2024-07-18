#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <list>
#include <unordered_set>
using namespace std;

// algorithm:
// question: optimised sliding window
// example:
// answer:
// explanation:
// tags:

// https://leetcode.com/problems/minimum-window-substring/description/

class Solution
{
public:
    string minWindow(string s, string p)
    {
        int start = 0;
        int ansIndex = -1;
        int ansLen = INT_MAX;

        if (s.length() < p.length())
        {
            return "";
        }

        unordered_map<char, int> strMap;
        unordered_map<char, int> ptrMap;
        // to keep track of all characters of P string
        for (int i = 0; i < p.length(); i++)
        {
            char ch = p[i];
            ptrMap[ch]++;
        }

        int count = 0;
        for (int i = 0; i < s.length(); i++)
        {
            char ch = s[i];

            strMap[ch]++;

            // valid character -> jo character tumhare pattern me bhi ho
            if (strMap[ch] <= ptrMap[ch])
            {
                // this count will update only till strMap[ch] value is less than ptrMap[ch]
                // once count is same as p.lenght(), then in further while loop strMap[ch] will if possible just becomes equals to ptrMap[ch]
                // and after that while loop in above line where strMap[ch]++ is written it will never allow
                // to come in this if condition as by while loop strMap[ch] will be minimum just equals to ptrMap[ch]
                // and strMap[ch]++ will always make this if condition false
                count++;
            }

            // window is ready
            if (count == p.length())
            {
                // minimise the window -> freq decrement, ans update , start ko aage badhana h
                while (strMap[s[start]] > ptrMap[s[start]] || ptrMap[s[start]] == 0)
                {
                    if (strMap[s[start]] > ptrMap[s[start]])
                    {
                        strMap[s[start]]--;
                    }
                    start++;
                }

                // ans update
                int lengthOfWindow = i - start + 1;
                if (lengthOfWindow < ansLen)
                {
                    ansLen = lengthOfWindow;
                    ansIndex = start;
                }
            }
        }

        if (ansIndex == -1)
            return "";
        else
            return s.substr(ansIndex, ansLen);
    }
};