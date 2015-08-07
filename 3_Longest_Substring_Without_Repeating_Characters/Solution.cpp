#include <string>
#include <deque>
#include <map>

using namespace std;

class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
    	int max = 0;
    	map<char, int> dic;
    	deque<char> vec;
    	int len = s.length();
    	for (int i = 0; i < len; i++)
    	{
    		char c = s.at(i);
    		if (dic.count(c))
    		{
    			if (vec.size() > max) max = vec.size();
    			while (vec.front() != c)
    			{
    				dic.erase(vec.front());
    				vec.pop_front();
    			}
    			vec.pop_front();
    		}
    		dic[c] = i;
    		vec.push_back(c);
    	}
    	return (vec.size() > max) ? vec.size() : max;
    }
};
