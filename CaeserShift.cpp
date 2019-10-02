//Joshua Wolsborn
//Caeser Cipher
//Sources: cplusplus.com stackoverflow.com
//This program will decode a file that is written with a Caeser Cipher

#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <stdio.h>

using namespace std;

void LowerCase(string File);
void WordCount(string Line);
void CaeserShift(string File);
int Key =0;
int Count[26];


int main(){
	string InFile;

	cout << "Please enter the file path of the file to be decoded: ";
	cin >> InFile;
	LowerCase(InFile);
	CaeserShift(InFile);
	getchar();
	getchar();
	return 0;
}

void CaeserShift(string File){
	ifstream TheFile;
	string Line;
	
	TheFile.open(File.c_str());
	
	while(!TheFile.eof()){
		getline(TheFile, Line);
		for(int i =0; i < Line.size(); i++){
			if(isalpha(Line[i])){
				for(int j = 0; j < Key; j++){
					if (Line[i] == 'z'){
						Line[i] = 'a';
					} else if (Line[i] == 'Z'){
						Line[i] = 'A';
					} else{
						Line[i]++;
					}
				}
				
			}
		}
		cout << Line << endl;
	}
	
}

void LetterCount(string Line){
	int MostLetter = 0;
	
	for(int i =0; i < Line.size(); i++){
		if(isalpha(Line[i])){
			for(int j = 0; j < 26; j++){
				if(static_cast<int>(Line[i]) == (97 + j)){
					Count[j] += 1;
				}
			}
		}
	}
	
	for(int j = 0; j < 26; j++){
		if (Count[MostLetter] < Count[j]){
			MostLetter = j;
		}
	}
	Key = 26 - MostLetter + 4;
	
	
return;
}


void LowerCase(string File){
	ifstream theFile;
	string theLine;
	
	theFile.open(File.c_str());
	
	while (!theFile.eof()){
		
		getline(theFile, theLine);
		for(int j = 0; j < theLine.size(); j++){
			theLine[j] = tolower(theLine[j]);
		}
		LetterCount(theLine);
	
	}

	theFile.close();	

return;
}
	
	

