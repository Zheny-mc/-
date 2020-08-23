#include <iostream>
#include <vector>
#include <string>


#define ERROR -1
using std::vector;
using std::string;

//для открытия файлов
int FileLen(FILE* f);
void selecting_FileName(vector<string>& path);
//для записи
vector<int> FileLens(const vector<string>& FileNames);
//длс шифрования
void Xor(string& StrLeft, const string& StrRight);  
int Cash(const string& key);  //создание хеш пароля
bool check_key(int cash, const string& key);  //проверка пароля

class Zipper
{
private:
	//имена
	string name;  //имя архива
	vector<string> FileNames;  //имена файлов
	//запись
	FILE* fIn;  //для файлов
	FILE* fOut;  //для архива
	int count;  //Количество файлов
	char ch;  //символ для считывания
	//шифрование
	string key;  //ключ для шифрования
	int cash;  //кеш ключа
	bool  HaveKey;  //нужен ли ключ?  

public:
	Zipper(const string& name, const vector<string>& FileNames);
	~Zipper();

	//требование ключа
	void set_HaveKey(){ HaveKey = true; }

	//архивация
	void Pack(); //архивация
	//void compression(); //сжатие
	//void encrypion(string& _FileName);  //шифрование
	//распаковка
	
	void UnPack();  //распаковка 
	//void streching();  //растяжение
	//void decryption(string& _CodeFileName);  //расшифровка
	//информация о архиве
	
	void info();
	//помощь
	void help();
};

