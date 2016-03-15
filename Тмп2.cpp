#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

/**\func void doxygen(string& cpy, ifstream& pF)*/

void doxygen(string& str, ifstream& file){
		
		while(getline(file, str)){
		str+='\n';
		if (str.find("\\func") != string::npos && str.find("/**") != string::npos) {
			int i  = str.find("func") + strlen("func");
			if (str[i] == ' ') while (str[i] == ' ') i++;
			
			while (str.find("*/") != i && str[i] != '\n'){
				if (str[i] == '\n') break;
				cout << str[i];
				i++;
			}
			cout << endl;	
		}
		
	}
	
}

/**\func int main ()*/
 
int main (int argc, char* argv[]) {
	
	ifstream file(argv[1]);
	string str;
	
	if (!file.is_open()){
		cout << "Error";
		return 1;
	}
	
	doxygen (str, file);

	file.close();
	return 0;
}
