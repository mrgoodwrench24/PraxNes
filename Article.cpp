#include "Article.h"
#include <fstream>


Article::Article() {
	this->stateCode = "";
	this->stateName = "";
	this->programCode = "";
	this->programName = "";
	this->licenseType = "";
	this->articleNumber = "";
	this->articleSite = "";
	this->pathway = "";
}

Article::Article(string stateCode, string stateName, string programCode, string programName, string licenseType, string articleNumber, string articleSite, string pathway) {
	this->stateCode = stateCode;
	this->stateName = stateName;
	this->programCode = programCode;
	this->programName = programName;
	this->licenseType = licenseType;
	this->articleNumber = articleNumber;
	this->articleSite = articleSite;
	this->pathway = pathway;
}

Article::~Article() {};

//getters
string Article::getStateCode() {
	return stateCode;
}
string Article::getStateName() {
	return stateName;
}
string Article::getProgramCode() {
	return programCode;
}
string Article::getProgramName() {
	return programName;
}
string Article::getLicenseType() {
	return licenseType;
}
string Article::getArticleNumber() {
	return articleNumber;
}
string Article::getArticleSite() {
	return articleSite;
}
string Article::getPathway() {
	return pathway;
}

//setters

void Article::setStateCode(string sCode) {
	this->stateCode = sCode;
}
void Article::setStateName(string sName) {
	this->stateName = sName;
}
void Article::setProgramCode(string progCode) {
	this->programCode = progCode;
}
void Article::setProgramName(string progName) {
	this->programName = progName;
}
void Article::setLicenseType(string licType) {
	this->licenseType = licType;
}
void Article::setArticleNumber(string artNum) {
	this->articleNumber = artNum;
}
void Article::setArticleSite(string artSite) {
	this->articleSite = artSite;
}
void Article::setPathway(string pathway) {
	this->pathway = pathway;
}