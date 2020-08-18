#include <iostream>
#include <vector>
#include <string>

#define ERROR -1
using std::vector;
using std::string;

int FileLen(FILE* f);
vector<int> FileLens(const vector<string>& FileNames);

class Zipper
{
private:
	string name; //имя архива
	vector<string> FileNames; //имена файлов

public:
	Zipper(const vector<string>& FileNames, const string& name);
	~Zipper();

	//архивация
	void Pack(); //архивация
	void compression(); //сжатие
	void encrypion();  //шифрование
	//распаковка
	void UnPack();  //распаковка 
	void streching();  //растяжение
	void decryption();  //расшифровка
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


