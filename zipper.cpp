#include "zipper.h"

Zipper::Zipper(const string& name, const vector<string>& FileNames)
{	
	/*Архивация с шифрованием*/
    this->name = name;
	this->FileNames = FileNames;
}

Zipper::~Zipper()
{}

void Zipper::Pack()
{
    /*Создает архив из текстовых файлов*/
	fOut = fopen(name.c_str(), "wb");
	count = FileNames.size();  // Количество файлов
	vector<int> fileLens = FileLens(FileNames);
	int FileNameLen;  //длина имени файла
	
	if (HaveKey)  //если архив с паролем
	{
		printf("Input key: ");
		std::cin >> key;
		cash = Cash(key);
		fwrite(&cash, sizeof(int), 1, fOut);	
	}

	//запись количества файлов
	fwrite(&count, sizeof(int), 1, fOut); 

	for (int i = 0; i < count; i++)
	{
		if (fileLens[i] == -1)
		{
			std::cout << FileNames[i] << ": " << "Error" << std::endl;
			continue;
		}

		//запись имени файла
		FileNameLen = FileNames[i].size();
		fwrite(&FileNameLen, sizeof(int), 1, fOut);
		fwrite(FileNames[i].c_str(), sizeof(char), FileNameLen, fOut);

		//запись даннных
		fwrite(&fileLens[i], sizeof(int), 1, fOut);
		fIn = fopen(FileNames[i].c_str(), "rb");  //открытие i файла
		
		while(fread(&ch, sizeof(char), 1, fIn))
			fwrite(&ch, sizeof(char), 1, fOut);

		std::cout << FileNames[i] << std::endl;

		fclose(fIn);  //закрытие i файла
	}

	fclose(fOut);
}

void Zipper::UnPack()
{
	fOut = fopen(name.c_str(), "rb");
	string FileName;
	int FileNameLen;  //Количество символов в имени файла
	int FileLen;  //Количество символов в файле

	if (HaveKey)
	{
		printf("Input key: ");
		std::cin >> key;
		fread(&cash, sizeof(int), 1, fOut);
		
		if (cash == Cash(key)) 
			printf("UnPack archive...\n");
		else
		{
			printf("Error key!\n");
			goto close;
		}
	}

	fread(&count, sizeof(int), 1, fOut);

	for (int i = 0; i < count; i++)
	{
		fread(&FileNameLen, sizeof(int), 1, fOut);  //считывание длину имени файла
		for (int i = 0; i < FileNameLen; i++)  //чтение имени файла
		{
			fread(&ch, sizeof(char), 1, fOut);
			FileName.push_back(ch);
		}

		fIn = fopen(FileName.c_str(), "wb");
		fread(&FileLen, sizeof(int), 1, fOut);  //считывание длины файла
		for (int i = 0; i < FileLen; i++)  //чтение имени файла
		{
			fread(&ch, sizeof(char), 1, fOut);
			fwrite(&ch, sizeof(char), 1, fIn);
		}
		fclose(fIn);
		std::cout << FileName << std::endl;  //Выводим
		FileName = "";   //Зачищаем строку для нового имени файла
	}
close:
	fclose(fOut);
}

void Zipper::help()
{
    vector<string> strhelp = { 
	"*****************Zipper***************",
	"*./zipper <mode> <name>.zip(.z) <files>",
	"*--<mode>:",
	"*--<name>:",
	"*--<files>:"
	"*Pack:",
	"*UnPack:"
	"***************************************"
	};

	for (int i = 0; i < strhelp.size(); i++)
		std::cout << strhelp[i] << std::endl;
}

int FileLen(FILE* f)
{
	/* Находит количество символов в файле */
	int count = 0;
	char ch;

	while (fread(&ch, sizeof(char), 1, f))
		count++;

	return count;
}

vector<int> FileLens(const vector<string>& FileNames)
{
	/*находит количество символов в каждом файле*/
	vector<int> lens;
	FILE* file = NULL;

	for (int i = 0; i < FileNames.size(); i++)
	{
		file = fopen(FileNames[i].c_str(), "rb");
		
		if (file != NULL)
		{
			lens.push_back(FileLen(file));
			fclose(file);
		}
		else
			lens.push_back(ERROR);
	}
	return lens;
}

/*
void Zipper::encrypion(string& _FileName)  //шифрование
{
	//Функция предназначена для шифровки имени файла
	Xor(_FileName, key);
}

void Zipper::decryption(string& _CodeFileName)  //расшифровка
{
	//Функция предназначена для расшифровывания имени файла
	Xor(_CodeFileName, key);
}
*/

void Zipper::info()
{
	//информация о архиве
	//-имена файлов
	//-размер файлов
	//-общий размер архива
	
}


int Cash(const string& key)
{
	int sum = 0;
	int del = key.size()+1;

	for (int i = 0; i < del; i++) sum += int(key[i]);

	return sum / del;
}

bool check_key(int cash, const string& key)
{
	return cash == Cash(key)? true : false;
}

void selecting_FileName(vector<string>& path)
{
	//Выделяет имя файла из пути
}