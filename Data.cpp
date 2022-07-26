#include "Data.h"


void Data::inputData() {
	cout << "PraxNES loading" << endl;
	ifstream file("StateArticles.csv");
	if (!file.is_open()) {
		cout << "No File Detected";
	}
	getline(file, text);
	while (!file.eof()) {
		getline(file, text);
		int rhs = text.find(",");
		string stateCodeFind = text.substr(0, rhs);

		int lhs = rhs + 1;
		rhs = text.find(",", lhs);
		string stateFind = text.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = text.find(",", lhs);
		string codeFind = text.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = text.find(",", lhs);
		string progName = text.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = text.find(",", lhs);
		string licType = text.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = text.find(",", lhs);
		string artNum = text.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = text.find(",", lhs);
		string artSite = text.substr(lhs, rhs - lhs);

		lhs = rhs + 1;
		rhs = text.find(",", lhs);
		string pathway = text.substr(lhs, rhs - lhs);

		enterprise.push_back(new Article(stateCodeFind, stateFind, codeFind, progName, licType, artNum, artSite, pathway));


	}
	system("cls");
}



void Data::printCheatSheet() {
	char choice;
	string letterChoice;
	string iniSite = "https://cm.wgu.edu/t5/Teacher-Licensure-Information/Teacher-Licensure-Home-Page/ta-p/1386";
	string secSite = "https://cm.wgu.edu/t5/Teacher-Licensure-Information/WGU-Praxis-Program-Graduation-Requirements/ta-p/1529";
	string initialLic[] = { "BAECE: Early Childhood Education","ENDEDL: Educational Leadership","ENDEDLST: Educational Leadership","ENDEDLSTE: Educational Leadership","ENDEDLSTS: Educational Leadership","MSEDL: Educational Leadership","MSEDLST: Educational Leadership","MSEDLSTE: Educational Leadership","MSEDLSTS: Educational Leadership","BAELED: Elementary Education","BAISK8: Elementary Education","MATELED: Elementary Education","MATELK8: Elementary Education","PBELED: Elementary Education","PBELK8: Elementary Education","BAMA9: Foundational/Middle Grades Mathematics","BSMEMG: Foundational/Middle Grades Mathematics","MATMA9: Foundational/Middle Grades Mathematics","MATMEMG: Foundational/Middle Grades Mathematics","PBMA9: Foundational/Middle Grades Mathematics","BASC9: Foundational/Middle Grades Science","BSSEMG: Foundational/Middle Grades Science","MATSC9: Foundational/Middle Grades Science","PBSC9: Foundational/Middle Grades Science","MATEES: Secondary English","MATENG12: Secondary English","BAMA12: Secondary Mathematics","BSMES: Secondary Mathematics","MATMA12: Secondary Mathematics","MATMES: Secondary Mathematics","PBMA12: Secondary Mathematics","MATSC12: Secondary Science","MATSES: Secondary Science","PBSC12: Secondary Science","BASCB12: Secondary Science- Biology/Life Sciences","BSSESB: Secondary Science- Biology/Life Sciences","BASCH12: Secondary Science- Chemistry","BSSESC: Secondary Science- Chemistry","BASCG12: Secondary Science- Geology/Earth & Space Science","BSSESE: Secondary Science- Geology/Earth & Space Science","BASCPH12: Secondary Science- Physics","BSSESP: Secondary Science- Physics","MATSS12: Secondary Social Science","PBSS12: Secondary Social Science","BASS12: Social Science Education","BASPMM: Special Education - Mild to Moderate","BASP: Special Education/Elementary Education","BASPEE: Special Education/Elementary Education" };
	string secondaryLic[] = { "ENDELL: English as a Second Language","MAELLP12: English as a Second Language","MAME12: Secondary Mathematics","MAME9: Foundational/Middle Grades Mathematics","MAMEMG: Foundational/Middle Grades Mathematics","MAMES: Secondary Mathematics","MASE9: Foundational/Middle Grades Science","MASEB12: Secondary Science- Biology/Life Sciences","MASECH12: Secondary Science- Chemistry","MASEG12: Secondary Science- Geology/Earth & Space Science","MASEMG: Foundational/Middle Grades Science","MASEPH12: Secondary Science- Physics","MASESB: Secondary Science- Biology/Life Sciences","MASESC: Secondary Science- Chemistry","MASESE: Secondary Science- Geology/Earth & Space Science","MASESP: Secondary Science- Physics","MSSP: Special Education" };
	string nonLic[] = { "BAES: Educational Studies","MAES: Educational Studies","MAMEK6: Mathematics Education","MEDID: Instructional Design","MEDLT: Learning and Technology","MSCIN: Curriculum and Instruction" };
	int intLicSize = 48;
	int secLicSize = 17;
	int nonLicSize = 6;

	do {
		int i = 0;
		cout << left;
		cout << setw(60) << "         Initial";
		cout << termcolor::green;
		cout << setw(50) << "                Secondary";
		cout << termcolor::cyan;
		cout << setw(50) << "            Non-Licensure" << endl;
		cout << termcolor::reset;

		while (i < nonLicSize) {
			cout << termcolor::reset << setw(60) << initialLic[i] << termcolor::green << setw(60) << secondaryLic[i] << termcolor::cyan << setw(30) << nonLic[i] << endl;
			i++;
		}
		while (i < secLicSize) {
			cout << left;
			cout << termcolor::reset << setw(60) << initialLic[i] << termcolor::green << termcolor::green << setw(60) << secondaryLic[i] << endl;
			i++;
		}

		while (i < intLicSize) {
			cout << termcolor::reset << setw(60) << initialLic[i] << endl;
			i++;
		}
		cout << endl << endl << endl << endl;
		cout << "Enter:\n1. Go to Article for Initial Licensure(All States)\n2. Go To Article 1626 for Secondary Licensure\n3. Go Back" << endl;
		cin >> choice;
		system("cls");
		switch (choice) {
		case '1':
		{
			ShellExecuteA(NULL, "open", iniSite.c_str(), NULL, NULL, SW_SHOWNORMAL);
			break;
		}
		case '2':
		{
			ShellExecuteA(NULL, "open", secSite.c_str(), NULL, NULL, SW_SHOWNORMAL);
			break;
		}
		case '3':
		{
			system("cls");
			break;
		}
		default:
		{
			choice = '0';
		}
		}
	} while (choice != '3');
}

void Data::praxisArticleCheck(string userInitials) {
	char bchoice = '0';
	char cChoice = '0';

	userInitials = upperCase(userInitials);
	this->initials = userInitials;

	do {
		int artNum = 0;
		findArticle();
		artNum = this->articleLocation;
		print(artNum);
		cout << endl;
		cout << "Press 1 to go to next praxis check\nPress 2 to return to main menu" << endl;
		cin >> bchoice;
		system("cls");
		switch (bchoice) {
		case '1':
			system("cls");
			continue;
		case '2':
			system("cls");
			break;
		}
	} while (bchoice != '2');
	
	return;
}

string Data::checkListState(string userState) {
	if (userState == "list" || userState == "LIST") {
		do {
			system("cls");
			userState = "";
			listState();
			cout << "Enter State Code: " << endl;
			cout << "Type list to show available options." << endl;
			cin >> userState;
		} while (userState == "list" || userState == "LIST");
	}
	userState = upperCase(userState);
	return userState;
}

string Data::checkListProgram(string userProgram) {
	if (userProgram == "list" || userProgram == "LIST") {
		do {
			system("cls");
			userProgram == "";
			listProgram();
			cout << "Enter Program Code: " << endl;
			cout << "Type list to show available options." << endl;
			cin >> userProgram;
			system("cls");
		} while (userProgram == "list" || userProgram == "LIST");
	}
	userProgram = upperCase(userProgram);
	return userProgram;
}

void Data::listState() {
	vector <string> stateCode{ "AK","AL","AR","AZ","CA","CNMI","CO","CT","DC","DE","DoD","FL","GA","GU","HI","IA","ID","IL","IN","KS","KY","LA","MA","MD","ME","MI","MN","MO","MS","MT","NC","ND","NE","NH","NJ","NM","NV","NY","OH","OK","OR","PA","PR","RI","SC","SD","TN","TX","UT","VA","VI","VT","WA","WI","WV","WY" };
	vector <string> stateName{ "Alaska","Alabama","Arkansas","Arizona","California","Northern Mariana Islands","Colorado","Connecticut ","Distric of Columbia","Deleware","Department of Defense","Florida","Georgia","Guam","Hawaii","Iowa","Idaho","Illinois","Indiana","Kansas","Kentucky","Louisiana","Massachusetts","Maryland","Maine","Michigan","Minnesota","Missouri","Mississippi","Montana","North Carolina","North Dakota","Nebraska","New Hampshire","New Jersey","New Mexico","Nevada","New York","Ohio","Oklahoma","Oregon","Pennsylvania ","Puerto Rico","Rhode Island","South Carolina","South Dakota","Tennessee","Texas","Utah","Virginia","Virgin Islands","Vermont","Washington","Wisconsin","West Virginia","Wyoming" };

	for (int i = 0; i < stateCode.size(); i++) {
		cout << stateCode.at(i) << ": " << stateName.at(i) << endl;
	}
}



void Data::listProgram() {
	vector <string> programCode{ "MSCIN","BAECE","ENDEDL","ENDEDLST","ENDEDLSTE","ENDEDLSTS","MSEDL","MSEDLST","MSEDLSTE","MSEDLSTS","BAES","MAES","BAELED","BAISK8","MATELED","MATELK8","PBELED","PBELK8","ENDELL","MAELLP12","BAMA9","BSMEMG","MAME9","MAMEMG","MATMA9","MATMEMG","PBMA9","BASC9","BSSEMG","MASE9","MASEMG","MATSC9","PBSC9","MEDID","MEDLT","MAMEK6","MATEES","MATENG12","BAMA12","BSMES","MAME12","MAMES","MATMA12","MATMES","PBMA12","MATSC12","MATSES","PBSC12","BASCB12","BSSESB","MASEB12","MASESB","BASCH12","BSSESC","MASECH12","MASESC","BASCG12","BSSESE","MASEG12","MASESE","BASCPH12","BSSESP","MASEPH12","MASESP","MATSS12","PBSS12","BASS12","MSSP","BASPMM","BASP","BASPEE" };
	vector <string> programName{ "Curriculum and Instruction","Early Childhood Education","Educational Leadership","Educational Leadership","Educational Leadership","Educational Leadership","Educational Leadership","Educational Leadership","Educational Leadership","Educational Leadership","Educational Studies","Educational Studies","Elementary Education","Elementary Education","Elementary Education","Elementary Education","Elementary Education","Elementary Education","English as a Second Language","English as a Second Language","Foundational/Middle Grades Mathematics","Foundational/Middle Grades Mathematics","Foundational/Middle Grades Mathematics","Foundational/Middle Grades Mathematics","Foundational/Middle Grades Mathematics","Foundational/Middle Grades Mathematics","Foundational/Middle Grades Mathematics","Foundational/Middle Grades Science","Foundational/Middle Grades Science","Foundational/Middle Grades Science","Foundational/Middle Grades Science","Foundational/Middle Grades Science","Foundational/Middle Grades Science","Instructional Design","Learning and Technology","Mathematics Education","Secondary English","Secondary English","Secondary Mathematics","Secondary Mathematics","Secondary Mathematics","Secondary Mathematics","Secondary Mathematics","Secondary Mathematics","Secondary Mathematics","Secondary Science","Secondary Science","Secondary Science","Secondary Science- Biology/Life Sciences","Secondary Science- Biology/Life Sciences","Secondary Science- Biology/Life Sciences","Secondary Science- Biology/Life Sciences","Secondary Science- Chemistry","Secondary Science- Chemistry","Secondary Science- Chemistry","Secondary Science- Chemistry","Secondary Science- Geology/Earth & Space Science","Secondary Science- Geology/Earth & Space Science","Secondary Science- Geology/Earth & Space Science","Secondary Science- Geology/Earth & Space Science","Secondary Science- Physics","Secondary Science- Physics","Secondary Science- Physics","Secondary Science- Physics","Secondary Social Science","Secondary Social Science","Social Science Education","Special Education","Special Education - Mild to Moderate","Special Education/Elementary Education","Special Education/Elementary Education" };

	for (int i = 0; i < programCode.size(); i++) {
		cout << programCode.at(i) << ": " << programName.at(i) << endl;
	}
}



string Data::upperCase(string input) {
	for (int i = 0; i < input.length(); ++i) {
		input[i] = toupper(input[i]);
	}
	return input;
}




void Data::findArticle() {
	string inputState = "";
	string inputProgram = "";
	string userPathway = "";
	bool artFound = false;
	do{
		cout << "Enter State, then Program Code\nType list to show available options." << endl;
		cin >> inputState;
		inputState = checkListState(inputState);
		cin >> inputProgram;
		inputProgram = checkListProgram(inputProgram);
		userPathway = pathwayType(inputState, inputProgram);
		if (userPathway == "") {
			for (int i = 0; i < enterprise.size(); i++) {
				if (enterprise.at(i)->Article::getStateCode() == inputState && enterprise.at(i)->Article::getProgramCode() == inputProgram) {
					this->articleLocation = i;
					artFound = true;
					return;
				}
				else {
					artFound = false;
				}
			}
			if (artFound == false) {
				cout << "State or Program not found!\nRe-enter State and Program\n\n" << endl;
			}
		}

		else {
			for (int i = 0; i < enterprise.size(); i++) {
				if (enterprise.at(i)->Article::getStateCode() == inputState && enterprise.at(i)->Article::getProgramCode() == inputProgram && enterprise.at(i)->Article::getPathway() == userPathway) {
					this->articleLocation = i;
					artFound = true;
					return;
				}
				else {
					artFound = false;
				}
			}
			if (artFound == false) {
				cout << "\nState or Program not found!\nRe-enter State and Program\n\n" << endl;
			}
		}
	} while (artFound == false);
}


string Data::pathwayType(const string userState, const string userProgram) {
	system("cls");
	string findPathway;
	if (userState == "MO") {
		int choice = 0;
		if (userProgram == "ENDELL" || userProgram == "MAELLP12" || userProgram == "MAME9" || userProgram == "MAMEMG" || userProgram == "MASE9" || userProgram == "MASEMG" || userProgram == "MAME12" || userProgram == "MAMES" || userProgram == "MASEB12" || userProgram == "MASESB" || userProgram == "MASECH12" || userProgram == "MASESC" || userProgram == "MASEG12" || userProgram == "MASESE" || userProgram == "MASEPH12" || userProgram == "MASESP" || userProgram == "MSSP") {
			findPathway = "";
		}

		else if (userProgram == "BSSEMG" || userProgram == "BSMEMG" || userProgram == "BASPEE" || userProgram == "BAELED" || userProgram == "ENDEDL" || userProgram == "ENDEDLST" || userProgram == "ENDEDLSTE" || userProgram == "ENDEDLSTS" || userProgram == "MSEDL" || userProgram == "MSEDLST" || userProgram == "MSEDLSTE" || userProgram == "MSEDLSTS") {
			findPathway = "Approved";
			system("cls");
			return findPathway;
		}
		else {
			do {
				cout << left;
				cout << setw(40) << "     Approved" << setw(40) << "      Reciprocity" << setw(40) << "Direct" << endl;
				cout << setw(40) << "BAISK8 - 201709" << setw(40) << "BAISK8 - All Prior to 201708" << setw(40) << "MAME" << endl;
				cout << setw(40) << "BASP - 201709" << setw(40) << "BASP - All Prior to 201708" << setw(40) << "MASE" << endl;
				cout << setw(40) << "BAELED" << setw(40) << "BAMA9 - All Prior to 201708" << setw(40) << "MSSP" << endl;
				cout << setw(40) << "BAMA9 - 201708" << setw(40) << "All Other Programs Except Direct" << setw(40) << endl;
				cout << setw(40) << "BASPEE" << setw(40) << endl;
				cout << setw(40) << "BSMEMG" << setw(40) << endl;
				cout << setw(40) << "BASC9 - 201709 & 201805" << setw(40) << endl;
				cout << setw(40) << "BSSEMG" << setw(40) << endl;
				cout << setw(40) << "MSEDLSTE" << setw(40) << endl;
				cout << setw(40) << "MSEDLSTS" << setw(40) << endl << endl << endl << endl;
				cout << "1. Approved Pathway\n2. Reciprocity Pathway\n3. Direct Pathway" << endl;
				cin >> choice;

				switch (choice) {
				case 1:
					findPathway = "Approved";
					system("cls");
					return findPathway;
				case 2:
					findPathway = "Reciprocity";
					system("cls");
					return findPathway;
				case 3:
					findPathway = "Direct";
					system("cls");
					return findPathway;
				default:
					choice = 0;
				}
			} while (choice != 1 && choice != 2 && choice != 3);
		}
	}
	else if (userState == "OH") {
		int ohChoice = 0;
		if (userProgram == "ENDELL" || userProgram == "MAELLP12" || userProgram == "MAME9" || userProgram == "MAMEMG" || userProgram == "MASE9" || userProgram == "MASEMG" || userProgram == "MAME12" || userProgram == "MAMES" || userProgram == "MASEB12" || userProgram == "MASESB" || userProgram == "MASECH12" || userProgram == "MASESC" || userProgram == "MASEG12" || userProgram == "MASESE" || userProgram == "MASEPH12" || userProgram == "MASESP" || userProgram == "MSSP") {
			findPathway = "";
		}
		else if (userProgram == "ENDEDL" || userProgram == "ENDEDLST" || userProgram == "ENDEDLSTE" || userProgram == "ENDEDLSTS" || userProgram == "MSEDL" || userProgram == "MSEDLST" || userProgram == "MSEDLSTE" || userProgram == "MSEDLSTS") {
			findPathway = "Direct";
			system("cls");
			return findPathway;
		}

		else {
			do {
				cout << left;
				cout << setw(40) << "     Approved" << setw(40) << "      Direct" << endl;
				cout << setw(40) << "BAISK8 - 201709 and Newer" << setw(40) << "BAISK8 - All versions prior to 201709" << endl;
				cout << setw(40) << "PBELK8 - 201709 and Newer" << setw(40) << "PBELK8 - All versions prior to 201709" << endl;
				cout << setw(40) << "MATELK8 - 201709 and Newer" << setw(40) << "MATELK8 - All versions prior to 201709" << endl;
				cout << setw(40) << "BAELED" << setw(40) << "BASP" << endl;
				cout << setw(40) << "MATELED" << setw(40) << "BASPEE " << endl;
				cout << setw(40) << "PBELED" << setw(40) << "BASPMM " << endl;
				cout << setw(40) << "BAMA12  - 201708 and Newer" << setw(40) << "BAMA12 - All versions prior to 201708" << endl;
				cout << setw(40) << "MATMA12 - 201708 and Newer" << setw(40) << "MATMA12  - All versions prior to 201708" << endl;
				cout << setw(40) << "BSMES" << setw(40) << "BASCCH12 - All versions prior to 201709" << endl;
				cout << setw(40) << "MATMES" << setw(40) << "BASCPH12 - All versions prior to 201709" << endl;
				cout << setw(40) << "BASCCH12 - 201709 and Newer" << setw(40) << "BASCB12 - All versions prior to 201709" << endl;
				cout << setw(40) << "BASCPH12 - 201709 and Newer" << setw(40) << "BASCG12 - All versions prior to 201709" << endl;
				cout << setw(40) << "BASCB12 - 201709 and Newer" << setw(40) << "PBSC12 - All versions prior to 201709" << endl;
				cout << setw(40) << "BASCG12 - 201709 and Newer" << setw(40) << "MATSC12 - All versions prior to 201709" << endl;
				cout << setw(40) << "PBSC12 - 201709 and Newer" << setw(40) << "MATENG12 - All versions prior to 201709" << endl;
				cout << setw(40) << "MATSC12 - 201709 and Newer " << setw(40) << "All Other Programs" << endl;
				cout << setw(40) << "BSSESC" << setw(40) << "" << endl;
				cout << setw(40) << "BSSESP" << setw(40) << "" << endl;
				cout << setw(40) << "BSSESB" << setw(40) << "" << endl;
				cout << setw(40) << "BSSESE" << setw(40) << "" << endl;
				cout << setw(40) << "MATSES" << setw(40) << "" << endl;
				cout << setw(40) << "MATENG12 - 201709 and Newer" << setw(40) << "" << endl;
				cout << setw(40) << "MATEES" << setw(40) << "" << endl;
				cout << setw(40) << "MAELLP12 " << setw(40) << "" << endl;
				cout << setw(40) << "ENDELL" << setw(40) << "" << endl << endl << endl << endl;

				cout << "1. Approved Pathway\n2. Direct Pathway" << endl;
				cin >> ohChoice;

				switch (ohChoice) {
				case 1:
					findPathway = "Approved";
					system("cls");
					return findPathway;
				case 2:
					findPathway = "Direct";
					system("cls");
					return findPathway;
				default:
					ohChoice = 0;
				}
			} while (ohChoice != 1 && ohChoice != 2);
		}

	}
	else if (userState == "KY") {
		int kyChoice = 0;

		if (userProgram == "BAELED" || userProgram == "PBELED" || userProgram == "MATELED" || userProgram == "BSMEMG" || userProgram == "MATMEMG" || userProgram == "BSMES" || userProgram == "MATMES" || userProgram == "BSSEMG" || userProgram == "BSSESB" || userProgram == "BSSESC" || userProgram == "BSSESE" || userProgram == "BSSESP" || userProgram == "MATSES" || userProgram == "MATEES" || userProgram == "MSEDL") {
			findPathway = "Approved";
		}

		else if (userProgram == "BASPEE" || userProgram == "BASPMM") {
			do {
				cout << left;
				cout << setw(100) << "BASPEE & BASPMM \n\nApproved = If student was admitted on 1/1/2020 or later\nReciprocity = If student was admitted earlier than 1/1/2020 " << endl << endl;


				cout << "1. Approved Pathway\n2. Reciprocity Pathway" << endl;
				cin >> kyChoice;

				switch (kyChoice) {
				case 1:
					findPathway = "Approved";
					system("cls");
					return findPathway;
				case 2:
					findPathway = "Reciprocity";
					system("cls");
					return findPathway;
				default:
					kyChoice = 0;
				}
			} while (kyChoice != 1 && kyChoice != 2);
		}
		else {
			findPathway = "Reciprocity";
		}
	}

	else if (userState == "NV") {
		int nvChoice = 0;
		if (userProgram == "MATEES" || userProgram == "MATENG12") {
			cout << "Enter 1 for Approved\nEnter 2 for Reciprocity\n\nCheck Field Experience Tab" << endl;
			cin >> nvChoice;

			switch (nvChoice) {
			case 1:
				findPathway = "Approved";
				system("cls");
				return findPathway;
			case 2:
				findPathway = "Reciprocity";
				system("cls");
				return findPathway;
			default:
				nvChoice = 0;
			}
		}
		else {
			findPathway = "";
		}
	}
	else {
		return findPathway = "";
	}
}


void Data::print(int i) {
	string webSite = enterprise.at(i)->Article::getArticleSite();

	cout << "Cleared:\nPraxis Check 1: Cleared " << enterprise.at(i)->Article::getStateCode() << " " << enterprise.at(i)->Article::getArticleNumber() << " "<< initials << endl;
	cout << "Praxis Check 2: Cleared " << enterprise.at(i)->Article::getStateCode() << " " << enterprise.at(i)->Article::getArticleNumber() << " " << initials << endl << endl;
	cout << "Not Cleared:\nPraxis Check 1: Not Cleared " << enterprise.at(i)->Article::getStateCode() << " " << enterprise.at(i)->Article::getArticleNumber() << " " << initials << endl << endl << endl << endl;
	cout << enterprise.at(i)->Article::getStateName() << "\t" << enterprise.at(i)->Article::getProgramCode() << ": " << enterprise.at(i)->Article::getProgramName() << endl << endl;
	cout << enterprise.at(i)->Article::getLicenseType() << " license type\t" << enterprise.at(i)->Article::getPathway() << " Pathway" << endl << endl;
	cout << "Article: " << enterprise.at(i)->Article::getArticleNumber() << '\t' << enterprise.at(i)->Article::getArticleSite() << endl << endl << endl << endl;
	ShellExecuteA(NULL, "open", webSite.c_str(), NULL, NULL, SW_SHOWNORMAL);
}


int Data::getArticleLocation() {
	return articleLocation;
}



Data::~Data() {
	for (int i = 0; i < enterprise.size(); i++) {
		delete enterprise.at(i);
		enterprise.at(i) = nullptr;
	}

}
