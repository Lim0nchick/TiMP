#include <сstring>
#include <iostream>

using namespace std;

int main (int argc, char *argv[]){
	
	int num;
	FILE *f1 = fopen (argv[1], "r");
	FILE *f2 = fopen (argv[2], "r");
	
	if (f1 == 0 || f2 == 0) {
		cout << "Error";
		if (!f2) fclose (f1);
		if (!f1) fclose (f2);
		return 1;
	}
	
	num = 1;
	while (!feof (f1))	{
		char str1[256];
		bool flag = 1;
		
		fgets (str1, 255, f1);
		if (str1[strlen(str1) - 1] == '\n') str1[strlen(str1) - 1] = '\0';
		//cout << str1 << endl; 
		
		fseek(f2, 0, SEEK_SET);
		while (!feof (f2)){
			
			char str2[256];
		
			fgets (str2, 255, f2);
			if (str2[strlen(str2) - 1] == '\n') str2[strlen(str2) - 1] = '\0';		
			//cout << "From f2-> " << str2 << endl;
			
			if (!strcmp(str1, str2)) {
				flag = 0;
				break;
			} 
			
		}
		
		if(flag) cout << argv[1] << ' ' << num << ' ' << str1 << endl;
		num++;	
	}
	
	
	num = 1;
	fseek(f2, 0, SEEK_SET);
	while (!feof (f2))	{
		char str2[256];
		bool flag = 1;
		
		fgets (str2, 255, f2);
		if (str2[strlen(str2) - 1] == '\n') str2[strlen(str2) - 1] = '\0';
		
		fseek (f1, 0, SEEK_SET);
		while (!feof (f1)){
			
			char str1[256];
			
			fgets (str1, 255, f1);
			if (str1[strlen(str1) - 1] == '\n') str1[strlen(str1) - 1] = '\0';
			
			if (!strcmp(str1, str2)) {
				flag = 0;
				break;
			} 
			
		}
		
		if(flag) cout << argv[2] << ' ' << num << ' ' << str2 << endl;
		num++;	
	}

	fclose (f1);
	fclose (f2);
	
	return 0;
}
