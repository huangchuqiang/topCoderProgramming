#ifndef _STRINGDUP_H_
#define _STRINGDUP_H_

#include "common.h"

class StringDup
{
public:
	char getMax(string input)
	{
		struct Item
		{
			char m_char;
			int m_count;

			Item(char c,int count)
				: m_char(c)
				, m_count(count)
			{}
		};

		vector<Item> vecItems;
		for (auto it = input.begin(); it != input.end(); ++it)
		{
			auto itemIt = vecItems.begin();
			while (itemIt != vecItems.end())
			{
				if ((*itemIt).m_char == *it)
				{
					++(*itemIt).m_count;
					break;
				}

				++itemIt;
			}

			if (itemIt == vecItems.end())
				vecItems.push_back(Item(*it, 1));
		}

		Item max = vecItems[0];
		for (std::size_t i = 1; i < vecItems.size(); ++i)
		{
			if (vecItems[i].m_count > max.m_count)
				max = vecItems[i];
		}

		return max.m_char;
	}
};

void StringDupTest()
{
	StringDup dup;
	TestCaseInfo(dup.getMax("aaiicccnn"), 'c');
	TestCaseInfo(dup.getMax("aabbccdd"), 'a');
	TestCaseInfo(dup.getMax("ab2sbf2dj2skl"), '2');
}

#endif