#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

/**\func void doxygen(string& cpy, ifstream& pF)*/

void doxygen(string& str, ifstream& file){
		
		bool flag = 0;
		
		while(getline(file, str)){
		if (str.find("/**") != string::npos) flag = 1;
		str+='\n';
		
		if (str.find("\\func") != string::npos && flag) {
		
			int i  = str.find("func") + strlen("func");
			
			if (str[i] == ' ') while (str[i] == ' ') i++;
			
			while (str.find("*/") != i && str[i] != '\n'){
				cout << str[i];
				i++;
			}
			cout << endl;
			flag = 0;	
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
