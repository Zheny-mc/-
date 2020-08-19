#include <iostream>
#include <cstdlib>
#include <string>

#define alphabet 255
using std::string;

void GenerateKey(string& key, const int text_len)
{
	srand(time(0));
	int ch;

	for (int i = 0; i < text_len; i++)
	{
		ch = rand() % alphabet;
		key.push_back(ch);
	}
}

string Code(string& text)
{
	string key;
	GenerateKey(key, text.size());

	for (int i = 0; i < text.size(); i++)
		text[i] ^= key[i];

	return key;
}

void DeCode(string& code_text, const string& key)
{
	for (int i = 0; i < code_text.size(); i++)
		code_text[i] ^= key[i];
}