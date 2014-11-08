#ifndef _COMMON_H_
#define _COMMON_H_

#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::cout;

#define TestCase(CONTENT)	cout << "TestCase " << #CONTENT << ": " << ((CONTENT)? "Succeed" : "Failed!!!!") << std::endl;


#endif