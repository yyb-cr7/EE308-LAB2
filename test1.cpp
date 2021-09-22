#include<stdio.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

class preparation {
	public:
	
	string Delete(string s)
	{
    	string new_str = "";
    	for(int i=0; i<s.size(); i++){
        	if(s[i] == '"'){
            	for(int j=i+1; i<s.size(); j++){
                	if(s[j] == '"'){
                    	s.erase(i,j-i+1);
                    	break;
                	}
            	}
        	}
    	}    
    	for(int i=0; i<s.size(); i++){
        	if(s[i]=='/' && s[i+1]=='/'){
            	return new_str;
        	}	
        	new_str += s[i];
    	}
    	return new_str;
	} 	
};

class statistics {
	public:
		
	void count_kw(string file, string key_words[]) {
		int count = 0;  // all kinds of numbers will be initially sttled as 0
		int begin = -1;
		for (int i = 0; i < 32; i++) {
			while((begin=file.find(key_words[i], begin+1)) != string::npos) {
				count ++;
				begin = begin + key_words[i].length();
			}	
		}
		cout << "total num: " << count << endl;
	}
	
	void count_sw_ca(string file) {
		int j, begin = -1;
		int next, count = 0;
		int case_num[99] = {0, };
		while((begin=file.find("switch", begin+1)) != string::npos) {			    
				j, count ++;
				begin = begin + 5;
				next = file.find("switch", begin+1);
				cout << 1<< endl;
				while((begin=file.find("case", begin+1)) < next) {
					case_num[j] ++;
					begin = begin + 4;
				}
		}
		
		cout << "switch num: " << count << endl;
		cout << "case num: ";
			for(int i = 0; i<count; i++)
				cout << case_num[i] << " ";
		cout << endl;
	} 
	
	void count_ifelse(string str) {
		int count = 0;
		
		cout << "if-else num: " << count << endl;
	}
	
	void count_ifelse_ifelse(string str) {
		int count = 0;
		cout << "if-elseif-else num: " << count<< endl;
	}
};

int main() {
	int level;	
	statistics test;
	preparation pre;
	char* c;
	string str;
	string path;
	cout << "Please input your path of the file" << endl;
	cin >> path;
	ifstream fp(path.c_str());
	if (fp == NULL)
	{
		cout << "File not found" << endl;
		return 0;
	}
	while(getline(fp, str)){
		str = pre.Delete(str);
		cout << str << endl;
	}	
	str = str.c_str();
    // "E://test1_sf.c"
	string key_words[] = {"auto", "break", "case", "char", "const", "continue", "default", "do ", 
	"double", "else", "enum", "extern", "extern", "float", "for", "goto", "if", "int", "long",
	"register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", 
	"union", "unsigned", "void", "volatile", "while"};

	cout << "Please input your searching level" << endl;
	cout << "1--Total keywords searching" << endl;
	cout << "2--Switch-case searching" << endl;
	cout << "3--If_else searching" << endl;
	cout << "4--IF_elseif_Else searching" << endl;
	cin >> level;
	switch (level)  {
		case 1: test.count_kw(str, key_words);
			break;
		case 2: test.count_kw(str, key_words);
			test.count_sw_ca(str);
			break;
		case 3: test.count_kw(str, key_words);
			test.count_sw_ca(str);
			test.count_ifelse(str);
			break;
		case 4:	test.count_kw(str, key_words);
			test.count_sw_ca(str);
			test.count_ifelse(str);	
			test.count_ifelse_ifelse(str);
			break;
		default: 
			cout << "Your input is invalid, please restart the program" << endl;
	}	
	return 0;
}


