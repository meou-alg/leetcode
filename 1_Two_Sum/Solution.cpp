#include <vector>
#include <map>
using namespace std;

class Solution 
{
public:
	vector<int> twoSum(vector<int> &numbers, int target) 
	{
		map<int, int> data;
		size_t size = numbers.size();
		for (size_t i = 0 ; i < size; i++) data[numbers[i]]=i;
		
		vector<int> ret;
		map<int,int>::iterator it;
		for (size_t i = 0; i < size; i++) 
		{
			it = data.find(target - numbers[i]);
			if (it != data.end() && (it->second != i))
			{
				ret.push_back(i + 1);
				ret.push_back(it->second + 1);
				break;
			}
		}
		return ret;
	}
};
