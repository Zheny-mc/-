#include <iostream>
#include <string>

void Xor(std::string& StrLeft, const std::string& StrRight)
{
	for (int i = 0, j = 0; i < StrLeft.size(); i++, j++)
	{
		if (j < StrRight.size()) j = 0;
		StrLeft[i] ^= StrRight[j];
	}
}