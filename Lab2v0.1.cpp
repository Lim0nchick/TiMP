#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

int main (int argc, char* argv[]) {
	
	ifstream file(argv[1]);
	string str;
	
	if (!file.is_open()){
		cout << "Error";
		return 1;
	}
		

	while(getline(file, str)){
		
		if (str.find("func") != string::npos && str.find("/**") != string::npos) {
			int i  = str.find("func") + strlen("func");

			while (str[str.find("*/")] != str[i]){
				cout << str[i];
				i++;
			}
			cout << endl;	
		}
	}
	
	file.close();
	return 0;
}
