#pragma once
#include <iostream>
#include<iomanip>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Article
{
private:
	string stateCode;
	string stateName;
	string programCode;
	string programName;
	string licenseType;
	string articleNumber;
	string articleSite;
	string pathway;

public:
	Article();
	Article(string stateCode, string stateName, string programCode, string programName, string licenseType, string articleNumber, string articleSite, string pathway);
	~Article();

	//getters
	string getStateCode();
	string getStateName();
	string getProgramCode();
	string getProgramName();
	string getLicenseType();
	string getArticleNumber();
	string getArticleSite();
	string getPathway();


	//setters

	void setStateCode(string sCode);
	void setStateName(string sName);
	void setProgramCode(string progCode);
	void setProgramName(string progName);
	void setLicenseType(string licType);
	void setArticleNumber(string artNum);
	void setArticleSite(string artSite);
	void setPathway(string pathway);




};

