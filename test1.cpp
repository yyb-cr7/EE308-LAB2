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
		cout << "Please input your searching level" << endl;
		cout << "1--Total keywords searching" << endl;
		cout << "2--Switch-case searching" << endl;
		cout << "3--If_else searching" << endl;
		cout << "4--IF_elseif_Else searching" << endl;
	// transform the c file into string form
	return str;
	}
		
};

class statistics {
	public:
		int count, begin ; 
	void count_kw(string file, string key_words[]) {
		count = 0;  // all kinds of numbers will be initially sttled as 0
		begin = -1;
		for (int i = 0; i < 32; i++) {
			while((begin=file.find(key_words[i], begin+1)) != string::npos) {
				count ++;
				begin = begin + key_words[i].length();
			}	
		}
		cout << "total num: " << count << endl;
	}
	
	void count_sw_ca(string file) {
		count = 0;
		begin = -1;
		int case_num[99] = {0, };
		while((begin=file.find("switch", begin+1)) != string::npos) {
				count ++;
				begin = begin + 5;
		}
		
		cout << "switch num: " << count << endl;
		cout << "case num: ";
			for(int i = 0; i<count; i++)
		cout << case_num[i] << " ";
		cout << endl;
	} 
	
	void count_ifelse(string str) {
		cout << "if-else num: " << count << endl;
	}
	
	void count_ifelse_ifelse(string str) {
		cout << "if-elseif-else num: " << count<< endl;
	}
};

int main() {	
	statistics test;
	preparation pre;
    string str = pre.acquire_file();
    // "E://test1_sf.c"
	string key_words[] = {"auto", "break", "case", "char", "const", "continue", "default", "do ", 
	"double", "else", "enum", "extern", "extern", "float", "for", "goto", "if", "int", "long",
	 "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", 
	 "union", "unsigned", "void", "volatile", "while"};
	
	test.count_kw(str, key_words);
	test.count_sw_ca(str);
	test.count_ifelse(str);
	test.count_ifelse_ifelse(str);
	return 0;
}

// "E://test1_sf.c"

