#include <iostream>
#include <vector>
#include <string>


#define ERROR -1
using std::vector;
using std::string;

int FileLen(FILE* f);
vector<int> FileLens(const vector<string>& FileNames);
void Xor(string& StrLeft, const string& StrRight);

class Zipper
{
private:
	string name;  //имя архива
	vector<string> FileNames;  //имена файлов
	string key;  //ключ для шифрования

public:
	Zipper(const string& name, const vector<string>& FileNames);
	Zipper(const string& name, const vector<string>& FileNames, const string& key);
	~Zipper();

	//архивация
	void Pack(); //архивация
	void compression(); //сжатие
	void encrypion(string& _FileName);  //шифрование
	//распаковка
	void UnPack();  //распаковка 
	void streching();  //растяжение
	void decryption(string& _CodeFileName);  //расшифровка
	//помощь
	void help();
};

class Power 
{
public:
	int mode; //режим запуска
	Zipper archive;

	void check_args(const vector<string>& argv);
	void poll(const string& Mode);
	void run();
};


