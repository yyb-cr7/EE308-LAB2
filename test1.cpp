#include<stdio.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stack>

using namespace std;

class preparation {
	public:
	
	string Delete_useless(string s) {
    	string new_str = "";
		int pre; 
    	for(int i=0; i<s.size(); i++){ // the size of the string must change randomly
        	if(s[i] == '"'){
            	for(int k=i+1; i<s.size(); k++){
                	if(s[k] == '"'){
                		pre = k-i+1;
                    	s.erase(i,pre);
                    	break;
                	}
            	}
        	}
    	}    
    	for(int i=0; i<s.size(); i++){
    		pre = i+1;
        	if(s[i]=='/' && s[pre]=='/'){
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
	
	void count_sw_ca(string file, int level) {
		int j = -1;
		int begin = -1;
		int next = 0;
		int count = 0;
		int pre = 0;
		int case_num[99] = {0, };
		while((begin=file.find("switch", begin+1)) != string::npos) {		    
				j ++;
				count ++;
				begin = begin + 5;
				pre = begin;
				if((begin=file.find("switch", begin+1)) != string::npos) {
					next = begin;
					begin = pre;
				while((begin=file.find("case", begin+1)) < next) {
					case_num[j] ++;
					begin = begin + 4;
					}
				}else {
					begin = pre;
				while((begin=file.find("case", begin+1)) != string::npos) {
					case_num[j] ++;
					begin = begin + 4;
				}
			}
			begin = pre;		
		}
		
		if(level <= 2) {
			cout << "switch num: " << count << endl;
		}else {
			cout << "switch num: " << count << endl;
			cout << "case num: ";
			for(int l=0; l<=j; l++) {
				cout << case_num[l] << " ";
		}
		cout << endl;
		}
	} 
	
	void count_ifelse_ifelse(string file, int level) {
		int count1 = 0;
		int count2 = 0;
		int begin = -1;
		stack<int> s;
		for (int i = 0; i<file.size()-5; i++) {
        	if (file[i] == 'i' && file[i+1] == 'f' && (before_no_zero(file, i) != 'e')) {    
            s.push(1);
        	}else if (file[i] == 'e' && file[i+1] == 'l' && file[i+2] == 's' && file[i+3] == 'e' && (next_no_zero(file, i+4) != 'i')) {
            if (s.top() == 1) {
                count1++;     
            } else {
                count2++;     
            }
            s.pop();     
        }else  if (file[i] == 'e' && file[i+1] == 'l' && file[i+2] == 's' && file[i+3] == 'e' && (next_no_zero(file, i+4) == 'i')) {
            s.push(2);
        }
    }	
		if(level <= 4) {
			cout << "if-else num: " << count1 << endl;
		}else {
			cout << "if-else num: " << count1 << endl;
			cout << "if-elseif-else num: " << count2 << endl;
		}
	}
		// "E://test1_sf.c"	
		
	char next_no_zero(string file, int loc) {
		char ans = 'a';
		for (int i = loc; i<file.length(); i++) {
			if(file[i] != ' ') {
				return file[i];
			}
		}
		return ans;
	}
	
	char before_no_zero(string file, int loc) {
		char ans = 'a';
		for (int i = loc-1; i>0; i--) {
			if(file[i] != ' ') {
				return file[i];
			}
		}
		return ans;
	}
};

int main() {
	int level;	
	statistics test;
	preparation pre;
	string str;
	string path = "";
	string all;
	cout << "Please input your path of the file" << endl;
	cin >> path;
	ifstream fp(path.c_str());
	while(getline(fp, str)){
		str = pre.Delete_useless(str);
		all += str;
	}	
	cout << all << endl;
    // "E://test1_sf.c"
	string key_words[] = {"auto", "break", "case", "char", "const", "continue", "default", "do ", 
	"double", "else", "enum", "extern", "extern", "float", "for", "goto", "if", "int", "long",
	"register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", 
	"union", "unsigned", "void", "volatile", "while"};

	cout << "Please input your searching level" << endl;
	cout << "1--Total keywords searching" << endl;
	cout << "2--Switch searching" << endl;
	cout << "3--Case searching" << endl;
	cout << "4--If_else searching" << endl;
	cout << "5--IF_elseif_Else searching" << endl; 	
	cin >> level;
	switch (level)  {
		case 1: test.count_kw(all, key_words);
			break;
		case 2: test.count_kw(all, key_words);
			test.count_sw_ca(all, level);
			break;
		case 3: test.count_kw(all, key_words);
			test.count_sw_ca(all, level);	
			break;
		case 4:	test.count_kw(all, key_words);
			test.count_sw_ca(all, level);
			test.count_ifelse_ifelse(all, level);
			break;
		case 5:	test.count_kw(all, key_words);
			test.count_sw_ca(all, level);
			test.count_ifelse_ifelse(all, level);
			break;
		default: 
			cout << "Your input is invalid, please restart the program" << endl;
	}	
	return 0;
}

//string s = "int main(){  int i=1;  // yybzjbsdouble j=0;   //long ";
//	s = pre.Delete_useless(s);
//	cout << s << endl;;
//	test.count_kw(s, key_words);

