class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() == 0)
            return 0;
        unordered_set<char> mp;
        int i = 0, j = 0, res = 0;
        while (i < s.size())
        {
            j = max(i, j);
            while (j < s.size())
            {
                if (mp.find(s[j]) != mp.end())
                {
                    break;
                }
                mp.insert(s[j]);
                j++;
            }
            res = max(res, j - i);
            //cout<< i<<" and "<<j<<endl;
            mp.erase(s[i]);
            i++;
        }
        return res;
    }
};