#include<stdio.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

class statistics {
	public:
		int count, begin ; 
	int count_kw(string file, string key_words[]) {
		//cout << file <<endl;
		count = 0;  // all kinds of numbers will be initially sttled as 0
		begin = -1;
		for (int i = 0; i < 32; i++) {
			while((begin=file.find(key_words[i], begin+1)) != string::npos) {
				count ++;
				// cout << begin << "  " << count << endl;
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
				//cout << begin << "  " << count << endl;
				begin = begin + 5;
			}
		return count;
	} 
	
	int* count_ca(int sw_num, string file) {
		int* count = new int [sw_num];
		count[0] = 0, count[1] = 0; 
		begin = -1;
		for(int i = 0; i < sw_num; i++) {
			while((begin=file.find("case", begin+1)) != string::npos) {
				count ++;
				//cout << begin << "  " << count << endl;
				begin = begin + 4;
				}
			return count;
		}
	} 
	//private:
		
		
};

int main()
{
    //"E://test.txt"  "E:\\test_sf.c"
	int stat [5] = {0,};
	string key_words[] = {"auto", "break", "case", "char", "const", "continue", "default", "do ", "double", "else", "enum", "extern", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};
	ifstream ifile("E://test1_sf.c");
	ostringstream buf;
	char ch;	
	while(buf && ifile.get(ch)) {
		buf.put(ch);
	}
	string str = buf.str(); // transform the c file into string form
	
	statistics test;
	stat[0] = test.count_kw(str, key_words);
	stat[1] = test.count_sw(str);
	int sw_num = stat[1];
	//stat[2] = test.count_ca(sw_num, str);
	//cout << stat[0] << endl;
	
	cout << "total num: " << stat[0] << endl;
	cout << "switch num: " << stat[1] << endl;
	cout << "case num: " << stat[2] << endl;
	cout << "if-else num: " << stat[3] << endl;
	cout << "if-elseif-else num: " << stat[4] << endl;
	return 0;
}


