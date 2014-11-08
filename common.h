#ifndef _COMMON_H_
#define _COMMON_H_

#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::cout;

#define TestCase(CONTENT)	cout << "test case " << #CONTENT << ": " << ((CONTENT)? "Succeed" : "Failed!!!!") << std::endl;

#define TestCaseInfo(CONTENT, VALUE) TestCase(CONTENT == VALUE);cout << "method value: " << #CONTENT << " = " << CONTENT << std::endl << std::endl;


#endif