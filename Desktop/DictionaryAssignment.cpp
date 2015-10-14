/*Made By Trevor Bird*/

#include <cstdio>
#include <cctype>
#include <iostream>
#include <cstring>
#define ROW 10
#define COL 30
#define MAXWORD 256

using namespace std;

int searchDictionary(char word [], char dictionary [][COL], int length){	//searches the dictionary for the found word, if found returns the location in the dictionary, if not returns -1.
	int loc= 0;
	for (int r= 0; r< sizeof(dictionary); r++){
		if(strcmp(word,dictionary[r])==0){
			return r;
		}
	}
	return -1;
}

void insertWord(char word[], char dictionary[][COL], int dictLoc) {			//Inserts a word into the dictionary
	for (int c = 0; c < sizeof(dictionary[dictLoc]); c++) dictionary[dictLoc][c] = word[c];
}

void dumpDictionary(char dictionary [][COL], int frequency [], int wordCount){//Prints out all words in the dictionary and how many times they were found.
	cout << "Word                |Frequency \n";
	for(int r=0; r<wordCount; r++){
		printf("%-20s|%9i \n", dictionary[r], frequency[r]);
	}
}

int main() {

char ch;
int newLine= 0;
int wordCount= 0;
int wordLength= 0;
int row= 0;
int check= 0;
int frequency [ROW] = {0};
char dictionary [ROW][COL];
char buffer [MAXWORD];

while( cin.good() )
{
 ch = cin.get();
 if ( isalpha(ch) )
    {
	buffer[wordLength] = ch;
	wordLength++;
	
    }
 else newLine = 1;
       if (newLine)
          {
		buffer[wordLength] = '\0';
		wordLength = 0;
		check = searchDictionary(buffer, dictionary, wordLength);
		if (check == -1 && buffer[0] != '\0') {
			insertWord(buffer, dictionary, wordCount);
			frequency[wordCount]++;
			wordCount++;
		}	
		else frequency[check]++;
              	newLine = 0;
          }
}

dumpDictionary(dictionary, frequency, wordCount);
return 0;
}
