#include "Taller.h"
#include <iostream>
#include <vector>
#include <string>
void MenuJoinWords()
{
	bool MoreWords = true;
	std::vector<char*>* Words = new std::vector<char*>();
	std::string Word, Word2;
	std::cout << "Ingrese una palabra: " << std::endl;
	std::cin >> Word;
	std::cout << "Ingrese otra palabra: " << std::endl;
	std::cin >> Word2;
	Words->push_back((char*)Word.c_str());
	Words->push_back((char*)Word2.c_str());
	/*
	do
	{
		char MoreWrds;
		std::string Word;
		std::cout << "Ingrese una palabra: " << std::endl;
		std::cin>> Word;
		Words->push_back((char*)Word.c_str());

		std::cout << "Desea agregar otra palabra? s/n " << std::endl;
		std::cin >> MoreWrds;
		if (MoreWrds == 'n')
		{
			MoreWords = false;
		}
	}while (MoreWords);
	*/
	char* sentence = Taller::JoinWords(*Words);
}
void RotateMatrixMenu(int n)
{
	char** matrix = new char* [n];
	for (int i = 0; i < n; i++)
	{
		*(matrix + i) = new char[n + 1];
		for (int j = 0; j <= n; j++)
		{
			*(*(matrix + i) + j) = 'a' + j;
			if (j == n)
			{
				*(*(matrix + i) + j) = NULL;
			}
		}
	}
	std::cout << std::endl;
	std::cout << "Matriz inicial: " << std::endl;
	for (int i = 0; i < n; i++)
	{
		Taller::PrintWord(*(matrix + i), n);
	}
	Taller::RotateMatrix(matrix, n, n);
	std::cout << std::endl;
	std::cout << "Rotacion de Matriz: " << std::endl;
	for (int i = 0; i < n; i++)
	{
		Taller::PrintWord(*(matrix + i), n);
	}
}
void ZeroMatrixMenu(int n, int m)
{
	int** mat = new int* [n];
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		*(mat + i) = new int[m];
		for (int j = 0; j < m; j++)
		{
			*(*(mat + i) + j) = (rand() % 8)+1;
			int v1 = rand() % 100;
			if (v1 < 8)
			{
				*(*(mat + i) + j) = 0;
			}
		}
	}
	// print matrix 
	std::cout << "Matriz inicial: " << std::endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::cout << *(*(mat + i) + j);
		}
		std::cout << std::endl;
	}
	// zero call
	std::cout << std::endl;
	Taller::ZeroMatrix(mat, n, m);

	// print matrix 
	std::cout << "Zero Matrix : " << std::endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::cout << *(*(mat + i) + j);
		}
		std::cout << std::endl;
	}
}
int main()
{
	int option;
	do
	{
		system("CLS");
		std::cout << "Bienvenido al taller lindo de arturo!" << std::endl;
		std::cout << "saleccione una opcion para probar: " << std::endl;
		std::cout << std::endl;
		std::cout << "1. Calcular el tamaño de un string." << std::endl;
		std::cout << "2. Unir dos palabras." << std::endl;
		std::cout << "3. Funcion Is Unique." << std::endl;
		std::cout << "4. Funcion Check Permutation." << std::endl;
		std::cout << "5. Funcion URLify." << std::endl;
		std::cout << "6. Funcion Palindrome Permutation." << std::endl;
		std::cout << "7. Funcion One Way." << std::endl;
		std::cout << "8. Funcion String Compression." << std::endl;
		std::cout << "9. Funcion Invert in Place." << std::endl;
		std::cout << "10. Funcion Rotate Matrix." << std::endl;
		std::cout << "11. Funcion Zero Matrix." << std::endl;
		std::cout << "12. Funcion String Rotation." << std::endl;
		std::cout << "13. Salir." << std::endl;

		std::cin >> option;
		std::string Word;
		std::string Word2;

		switch (option)
		{
		case 1:
			{
				std::cout << "Ingrese una palabra: " << std::endl;
				std::cin >> Word;
				int tam = Taller::GetStringLenght(Word.c_str());
				std::cout << Word << " tiene " << tam << " caracteres" << std::endl;
				break;
			}

		case 2:
			MenuJoinWords();
			break;
		case 3:
			{

				std::cout << "Ingrese una palabra: " << std::endl;
				std::cin >> Word;
				bool isUnique = Taller::isUnique(Word.c_str());
				if (isUnique)
				{
					std::cout << Word << " no tiene caracteres repetidos" << std::endl;
				}
				else
				{
					std::cout << Word << " tiene caracteres repetidos" << std::endl;
				}
			}
			break;
		case 4:
			{
				std::cout << "Ingrese una palabra: " << std::endl;
				std::cin >> Word;
				std::cout << "Ingrese otra palabra: " << std::endl;
				std::cin >> Word2;
				bool arePermut = Taller::CheckPermutation(Word.c_str(), Word2.c_str());
				if (arePermut)
				{
					std::cout << Word << " y " << Word<< " son permutacion" << std::endl;
				}
				else
				{
					std::cout << Word << " y " << Word<< " no son permutacion" << std::endl;
				}
			}
			break;
		case 5:
			{
				std::cout << "Ingrese una frase: " << std::endl;
				std::getline(std::cin, Word);
				std::getline(std::cin, Word);
				char* Phrase = new char[1024];
				Phrase = (char*)Word.c_str();
				Taller::URLify(Phrase);
				std::cout << "el url de su frase es: ";
				Taller::PrintWord(Phrase, Taller::GetStringLenght(Phrase));
			}
			break;
		case 6:
			{
				std::cout << "Ingrese una palabra: " << std::endl;
				std::getline(std::cin, Word);
				std::getline(std::cin, Word);
				bool isPalindromePermut = Taller::PalindromePermut(Word.c_str());
				if (isPalindromePermut)
				{
					std::cout <<Word <<" es permutacion de palindrome" << std::endl;
				}
				else
				{
					std::cout <<Word <<" no es permutacion de palindrome" << std::endl;
				}
			}
			break;
		case 7:
			{
				std::cout << "Ingrese una palabra: " << std::endl;
				std::cin >> Word;
				std::cout << "Ingrese otra palabra: " << std::endl;
				std::cin >> Word2;
				bool areOneWay = Taller::OneWay((char* )Word.c_str(), (char*)Word2.c_str());
				if (areOneWay)
				{
					std::cout << Word << " y " << Word << " estan a 1 paso de edicion" << std::endl;
				}
				else
				{
					std::cout << Word << " y " << Word << " estan a mas de 1 paso de edicion" << std::endl;
				}
			}
			break;
		case 8:
			{
				std::cout << "Ingrese un palabra: " << std::endl;
				std::cin >> Word;
				char* Compress = Taller::StringCompression((char*)Word.c_str());
				std::cout << "Su palabra comprimida es: ";
				Taller::PrintWord(Compress, Taller::GetStringLenght(Compress));
			}
			break;
		case 9:
			{
				std::cout << "Ingrese un palabra: " << std::endl;
				std::cin >> Word;
				char* Inverted = new char;
				Inverted = (char*)Word.c_str();
				Taller::InvertInPlace(Inverted);
				std::cout << "Su palabra invertida es: ";
				Taller::PrintWord(Inverted, Taller::GetStringLenght(Inverted));

			}
			break;
		case 10:
			{
				int MatSize;
				std::cout << "Ingrese el tamaño de la matriz: " << std::endl;
				std::cin >> MatSize;
				RotateMatrixMenu(MatSize);
			}
			break;
		case 11:
			{
				int N, M;
				std::cout << "Ingrese el # de filas de la matriz: " << std::endl;
				std::cin >> N;
				std::cout << "Ingrese el # de columnas de la matriz: " << std::endl;
				std::cin >> M;
				ZeroMatrixMenu(N, M);

			}
			break;
		case 12:
			{
				std::cout << "Ingrese una palabra: " << std::endl;
				std::cin >> Word;
				std::cout << "Ingrese otra palabra: " << std::endl;
				std::cin >> Word2;
				bool isRotation = Taller::StringRotation(Word, Word2);
				if (isRotation)
				{
					std::cout << Word << " y " << Word2 << " son rotacion" << std::endl;
				}
				else
				{
					std::cout << Word << " y " << Word2 << " no son rotacion" << std::endl;
				}
			}
			break;
		case 13:
			std::cout << "Adios" << std::endl;
			break;

		default:
			std::cout << "Opcion invalida!." << std::endl;
			
			break;
		}
		system("pause");
	} while (option != 13);
}

int Taller::GetStringLenght(const char* String)
{
	int size = 0;
	char currentCharacter = *(String + size);
	while (currentCharacter != NULL);
	{
		size++;
		currentCharacter = *(String + size);
	}
	return size;
}
char* Taller::JoinWords(const std::vector<char*>& Words)
{
	char* Sentence = new char[1024]; 
	int size = 0;
	for (char* word : Words)
	{
		int wordSize = 0;
		while (word[wordSize] != NULL)
		{
			Sentence [size] = word[wordSize];
			wordSize++;
			size++;
		}
		
	}
	Taller::PrintWord(Sentence, size);
	return Sentence;
}
bool Taller::isUnique(const char* Word)
{
	int size = Taller::GetStringLenght(Word);
	return Taller::isUniqueDivide((char*)Word,size);

}
bool Taller::isUniqueDivide( char* Word, int size)
{
	int half = size / 2;
	int middlepos;
	if (size == 1)
	{
		return true;
	}
	if (size != 2)
	{
		if ((size % 2) != 0)
		{
			middlepos = size / 2;
		}
		else
		{
			middlepos = 0;
		}
		char* Word1 = Word;
		char* Word2;
		char* MidCharacter = nullptr;
		if (middlepos == 0)
		{
			Word2 = Word+half;
		}
		else
		{
			MidCharacter = Word + half;
			Word2 = Word+half+1;
		}
		bool FirstHalf = Taller::isUniqueDivide(Word1,half);
		bool SecondHalf = Taller::isUniqueDivide(Word2, half);
		if ((!FirstHalf || !SecondHalf))
		{
			return false;
		}
		if (MidCharacter!=nullptr)
		{
			bool MiddleCase1 = Taller::isUniqueCompareWords(MidCharacter, 1, Word1, half);
			bool MiddleCase2 = Taller::isUniqueCompareWords(MidCharacter, 1, Word2, half);
			if ((!MiddleCase1 || !MiddleCase2))
			{
				return false;
			}
		}
		bool finalCompare = Taller::isUniqueCompareWords(Word1, half, Word2, half);
		if (!finalCompare)
		{
			return false;
		}
		return true;

	}
	else
	{
		
		if ((*Word) == *(Word + 1))
		{
			return false;
		}
		else
		{		
			return true;
		}

	}

}
bool Taller::isUniqueCompareWords(const char* Word, int size, const char* Word2, int size2)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			char letter1 = *(Word + i);
			char letter2 = *(Word2 + j);
			if (*(Word + i) == *(Word2 + j))
			{
				return false;
			}
		}
	}
	return true;
}
void Taller::PrintWord(char* word, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << *(word + i);
	}
	std::cout << std::endl;
}

bool  Taller::CheckPermutation(const char* Word, const char* Word2)
{
	int Size = Taller::GetStringLenght(Word);
	int Word2Size = Taller::GetStringLenght(Word2);
	if (Size != Word2Size)
	{
		return false;
	}
	//Duplicate word 2
	char* Word2Copy = new char[Size];
	for (int i = 0; i < Size; i++)
	{
		Word2Copy[i] = *(Word2 + i);
	}
	int succes = 0;
	for (int i = 0; i < Size; i++)
	{
		for (int j = 0; j < Size; j++)
		{
			if (*(Word + i) == Word2Copy[j])
			{
				Word2Copy[j] = NULL;
				succes++;
				break;
			}
		}

	}
	if (succes == Size)
	{
		return true;
	}
	return false;
}


void Taller::URLify(char* URL)
{
	char aux[1024] = {NULL};
	char bufferLetter = *URL;
	int auxSize = 0;
	int auxCounter = 0;
	int counter = 0;

	while (bufferLetter != NULL)
	{
		bufferLetter = *(URL + counter);
		if (bufferLetter != ' ')
		{
			*(aux + auxSize) = bufferLetter;
			if (auxSize != 0)
			{
				auxSize++;
			}
		}
		else
		{
			*(aux + auxSize) = '%';
			auxSize++;
			*(aux + auxSize) = '2';
			auxSize++;
			*(aux + auxSize) = '0';
			auxSize++;
			
		}

		*(URL + counter) = *(aux + auxCounter);
		if (auxSize != 0)
		{
			auxCounter++;
		}
		counter++;
	}

	while (auxSize > auxCounter)
	{
		*(URL + counter) = *(aux + auxCounter);
		auxCounter++;
		counter++;
	}

}

bool Taller::PalindromePermut(const char* Word)
{
	int size = Taller::GetStringLenght(Word);
	char* aux = new char[size];
	int min = 0;
	int max = 0;

	char letterBuffer = *Word;
	int WordIterator = 0;
	while ((letterBuffer != NULL))
	{
		bool bhasFoundPair= false;
		if (letterBuffer != ' ')
		{
			for (int i = min; i < max; i++)
			{
				if (letterBuffer == *(aux+i))
				{
					*(aux + i) = *(aux + min);
					min++;
					bhasFoundPair = true;
					break;
				}
			}
			if (!bhasFoundPair)
			{
				*(aux + max) = letterBuffer;
				max++;
			}
		}
		WordIterator++;
		letterBuffer = *(Word + WordIterator);
	}
	std::cout << "min: " << min << " max: " << max << std::endl;
	if ((max - min > 1))
	{
		return false;
	}
	return true;

}

bool Taller::OneWay(char* Word1, char* Word2)
{
	int size1 = Taller::GetStringLenght(Word1);
	int size2 = Taller::GetStringLenght(Word2);

	int success = 0;

	//Duplicate word 2
	char* Word2Copy = new char[size1];
	for (int i = 0; i < size2; i++)
	{
		Word2Copy[i] = *(Word2 + i);
	}
	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			if (*(Word2 + j) != NULL)
			{
				if (*(Word2Copy + j) == *(Word1 + i))
				{
					*(Word2Copy + j) = NULL;
					success++;
					break;
				}
			}
		}
	}
	if (size2-success > 1)
	{
		return false;
	}
	return true;
}

char* Taller::StringCompression(char* Word)
{
	int size = Taller::GetStringLenght(Word);
	char* CompressedWord = new char[size*2];
	int CompressedPos = 0;
	int CurrentLetterRepetition = 1;
	char CurrentLetter;
	for (int i = 0; i < size; i++)
	{
		CurrentLetter = *(Word+i);
		if(CurrentLetter == *(Word+i+1))
		{
			CurrentLetterRepetition++;
		}
		else
		{
			*(CompressedWord+CompressedPos) = CurrentLetter;
			 CompressedPos++;
			*(CompressedWord+CompressedPos) = CurrentLetterRepetition+48;
			CurrentLetterRepetition = 1;
			CompressedPos++;

		}
	}
	*(CompressedWord + CompressedPos) = NULL;
	if (CompressedPos > size)
	{
		return Word;
	}
	return CompressedWord;
}

void Taller::InvertInPlace(char* Word)
{
	int size = Taller::GetStringLenght(Word);
	size--;
	int counter=0;
	char aux;
	while (counter < size)
	{
		aux = Word[counter];
		Word[counter] = Word[size];
		Word[size] = aux;
		counter++;
		size--;
	}
}

void Taller::RotateMatrix(char** matrix, int n, int m)
{
	n--;
	m--;
	
	

	for (int i = 0; i <= m/2; i++)
	{
		
		for (int j = 0; j <= n/2 ; j++)
		{
			char aux = matrix[i][j];
			matrix[i][j] = matrix[j][n-i];
			matrix[j][n-i] = matrix[n - i][m - j];
			matrix[n - i][m - j] = matrix[m - j][i];
			matrix[m - j][i] = aux;

		}	
	}
	if (m % 2 == 0)
	{
		m++;
		int axis = m / 2;
		for (int j = 0; j < 3; j++)
		{

			for (int i = 0; i <= axis; i++)
			{
				char aux = matrix[i][axis];
				matrix[i][axis] = matrix[axis][n - i];
				matrix[axis][n - i] = matrix[n - i][axis];
				matrix[n - i][axis] = matrix[axis][i];
				matrix[axis][i] = aux;
			}
		}

	}
}

void Taller::ZeroMatrix(int** matrix, int n, int m)
{
	std::vector<int> positions = std::vector<int>();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (matrix[i][j] == 0)
			{
				positions.push_back(i);
				positions.push_back(j);
			}
		}
	}
	bool alternate = true;
	for (int p : positions)
	{
		if (alternate)
		{
			for (int j = 0; j < m; j++)
			{
				matrix[p][j] = 0;
			}
			
			alternate = false;
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				matrix[i][p] = 0;
			}
			alternate = true;
		}
	}
}

bool Taller::StringRotation(std::string str1, std::string str2)
{
	std::string rotation = str2 + str2;
	std::size_t found = rotation.find(str1);
	if (found != std::string::npos)
	{
		std::cout << found<<std::endl;
		std::string first = rotation.substr(0, found);
		std::string second = rotation.substr(found + str1.size(), rotation.size());
		std::string rotated = second + first;
		std::cout << rotated << std::endl;
		if (str1 == rotated)
		{
			return true;
		}
	}
	return false;
}