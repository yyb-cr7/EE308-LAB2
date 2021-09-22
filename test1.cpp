#include<stdio.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

class preparation {
	public:
		
	string acquire_file() {
		cout << "Please input your path of the file" << endl;
		char* c;
		string path;
		cin >> path;
		// "E://test1_sf.c"
		ifstream ifile(path.c_str(), ios::in);
		ostringstream buf;
		char ch;	
			while(buf && ifile.get(ch)) {
				buf.put(ch);
			}
		string str = buf.str(); 
	// transform the c file into string form
	return str;
	}
};

class statistics {
	public:
		int count, begin ; 
	int count_kw(string file, string key_words[]) {
		count = 0;  // all kinds of numbers will be initially sttled as 0
		begin = -1;
		for (int i = 0; i < 32; i++) {
			while((begin=file.find(key_words[i], begin+1)) != string::npos) {
				count ++;
				begin = begin + key_words[i].length();
			}	
		}
		return count;
	}
	
	int count_sw(string file) {
		count = 0;
		begin = -1;
		while((begin=file.find("switch", begin+1)) != string::npos) {
				count ++;
				begin = begin + 5;
			}
		return count;
	} 
	
	int* count_ca(int sw_num, string file) {
		int *case_count;
		case_count = new int [sw_num];
		case_count[0] = 0;
		case_count[1] = 0;
		begin = -1;
		for(int i = 0; i < sw_num; i++) {
			while((begin=file.find("case", begin+1)) != string::npos) {
				if(file.find("switch"))
					break;
				case_count[i] ++;
				//cout << begin << "  " << count << endl;
				begin = begin + 4;
				}
		}
		return case_count;
	} 
	//private:
		
};

int main()
{
	statistics test;
	preparation pre;
    string str = pre.acquire_file();
    // "E://test1_sf.c"
    
	int stat [5] = {0,};
	string key_words[] = {"auto", "break", "case", "char", "const", "continue", "default", "do ", 
	"double", "else", "enum", "extern", "extern", "float", "for", "goto", "if", "int", "long",
	 "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", 
	 "union", "unsigned", "void", "volatile", "while"};
	
	stat[0] = test.count_kw(str, key_words);
	stat[1] = test.count_sw(str);
	int sw_num = stat[1];
	int *case_num;
	case_num = test.count_ca(sw_num, str);

	cout << "\ntotal num: " << stat[0] << endl;
	cout << "switch num: " << stat[1] << endl;
	cout << "case num: ";
	for(int i = 0; i<sw_num; i++)
	cout << case_num[i] << " ";
	cout << "\nif-else num: " << stat[3] << endl;
	cout << "if-elseif-else num: " << stat[4] << endl;
	return 0;
}


