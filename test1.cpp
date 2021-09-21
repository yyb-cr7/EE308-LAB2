#include<stdio.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

class statistics {
	public:
		int num = 0;
	
	int count_kw(string file, char* key_words[]) {
		cout << file <<endl;
		return num;
	}
	//private:
		
		
};

int main()
{
    //"E://test.txt"  "E:\\test_sf.c"
	int stat [5] = {0,};
	char* key_words[] ={"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};
	ifstream ifile("E://test.txt");
	ostringstream buf;
	char ch;	
	while(buf&&ifile.get(ch)) {
		buf.put(ch);
	}
	string str = buf.str();
	
	statistics test;
	stat[0] = test.count_kw(str, key_words);
	
	cout << "total num: " << stat[0] << endl;
	cout << "switch num: " << stat[1] << endl;
	cout << "case num: " << stat[2] << endl;
	cout << "if-else num: " << stat[3] << endl;
	cout << "if-elseif-else num: " << stat[4] << endl;
	return 0;
}


