#ifndef _SYNTAX_H_
#define _SYNTAX_H_

#include "common.h"

class Syntax
{
public:
	bool match(std::string matchStr)
	{
		std::vector<char> stackBrackets;
		for (auto it = matchStr.begin(); it != matchStr.end(); ++it)
		{
			if (*it == '(' || *it == '[' || *it ==  '{')
			{
				stackBrackets.push_back(*it);
			}
			else if (*it == ')' || *it == ']' || *it ==  '}')
			{
				char c = *stackBrackets.rbegin(); 
				if ((c == '(' && *it == ')')
					|| (c == '[' && *it == ']')
					|| (c == '{' && *it == '}'))
				{
					stackBrackets.pop_back();
				}
				else
				{
					return false;
				}
			}
		}

		return stackBrackets.empty();
	}
};

void SyntaxTest()
{
	Syntax sy;
	TestCase(sy.match("x(y(z{test})abc)") == true);
	TestCase(sy.match("()") == true);
	TestCase(sy.match("([)]") == false);
	TestCase(sy.match("[[]](()){{{}}}") == true);
	TestCase(sy.match("abc(def(ghi)") == false);
}
#endif