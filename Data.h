#pragma once
#include "Article.h"
#include "Windows.h"
#include "termcolor.hpp"

class Data
{
public:
	vector<Article*> enterprise;

private:
	string text;
	string initials;
	int articleLocation;

public:
	void inputData();
	void printCheatSheet();
	void praxisArticleCheck(string userInitials);
	string checkListState(string userState);
	string checkListProgram(string userProgram);
	void listState();
	void listProgram();
	string upperCase(string input);
	void findArticle();
	string pathwayType(string userState, string userProgram);
	void print(int i);

	//getters
	int getArticleLocation();
	
	~Data();
};

