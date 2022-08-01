#pragma once
#include <iostream>
#include <vector>

class Taller
{

public:
	Taller();
	static void PrintWord(char* word, int size);


	static int GetStringLenght(const char* String);

	static char* JoinWords(const std::vector<char*>& Words);

	//is unique functions 
	static bool isUnique(const char* Word);

	static bool isUniqueDivide(char* Word, int size);

	static bool isUniqueCompareWords(const char* Word, int size, const char* Word2, int size2);

	//are permutation
	static bool CheckPermutation(const char* Word, const char* Word2);

	//URLify
	static void URLify(char* URL);

	//Palindrome permutation
	static bool PalindromePermut(const char* Word);

	//One way
	static bool OneWay(char* Word1, char* Word2);

	//String compression
	static char* StringCompression(char* Word);

	//invert in Place
	static void InvertInPlace(char* Word);

	//Rotate Matrix
	static void RotateMatrix(char** matrix, int n, int m);

	//Zero Matrix
	static void ZeroMatrix(int** matrix, int n, int m);

	//String rotation
	static bool StringRotation(std::string str1, std::string str2);
};

