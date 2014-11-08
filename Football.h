#ifndef _FOOTBALL_H_
#define _FOOTBALL_H_

#include "common.h"

class Football
{
public:
	Football()
	{
		this->m_score.push_back(7);
		this->m_score.push_back(3);
		this->m_score.push_back(2);
	}

	int fetchCombinations(int input)
	{
		return fetchCombinations(input, m_score.begin()); 
	}

private:
	int fetchCombinations(int input, vector<int>::iterator it)
	{
		if (input < 0 || it == m_score.end())
			return 0;
		else if (input == 0)
			return 1;
		else
			return fetchCombinations(input, it + 1) + fetchCombinations(input - *it, it);
	}

	vector<int> m_score;
};


void FootballTest()
{
	Football fb;	
	TestCaseInfo(fb.fetchCombinations(1), 0);
	TestCaseInfo(fb.fetchCombinations(4), 1);
	TestCaseInfo(fb.fetchCombinations(9), 3);
	TestCaseInfo(fb.fetchCombinations(11), 3);
}
#endif