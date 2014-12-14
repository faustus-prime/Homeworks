Homework#6
=========
#include <iostream>
using namespace std;

//Exercise 1
const int m_dim = 3;
typedef double Matrix33[m_dim][m_dim];

void Mat_Add (Matrix33 output, Matrix33 A, Matrix33 B){
int i,j;
for (i=0; i<m_dim; i++){
for (j=0; j<m_dim; j++){
output[i][j] = A[i][j]+ B[i][j];}}}

void Mat_Print(Matrix33 input){
int i,j;
for (i=0; i<m_dim; i++){
cout<<endl;
for (j=0; j<m_dim; j++){
cout<<" ["<<input[i][j]<<"] ";}}}

void Mat_Mult (Matrix33 output, Matrix33 A, Matrix33 B){
int i,j,k;
for(i=0; i<m_dim; i++){
for(j=0; j<m_dim; j++){
for(k=0; k<m_dim; k++){
//output[i][j]=0;                           //initialize elements with zero?
output[i][j]=A[i][k]B[k][j];
}}}}

//Exercise 2
const int s_dim = 9;
typedef int Sudoku[s_dim][s_dim];

bool Sudoku_Spalte(Sudoku s, int col){
int number=1;
while(number <= s_dim){
for(int j = 0; j<s_dim; j++){
if(number == s[col][j]) ++number;
if (number==s_dim+1) return true; break;    //when number= 9 is element of sudoku, then number++ is true and this funktion should terminate here
}}                                          //break needed?
return false;}

bool Sudoku_Zeile(Sudoku s, int row){
int number=1;
while(number<=s_dim){
for(int i = 0; i<s_dim;i++){
if(number == s[i][row]) ++number;
if (number==s_dim+1) return true; break;
}}
return false;}

bool test_sudoku(Sudoku s){
int i;
while (i <= s_dim){
while (Sudoku_Spalte(s,i) && Sudoku_Zeile(s,i))
++i;
if (i==s_dim) return true; break;           // when 0+8 elements were found, terminate
return false;}}

//Excercise 3

bool StringBeginsWithSubstring(const char* str, const char* subStr){
int i=0;
while(str[i]){
if(str[i]==subStr[i]) return true; i++;
}return false;}

bool FindSubstringInString(const char* str, const char* subStr){
while (str!=subStr){
++subStr;
if (str==subStr) while(str){str++; return true;}
}return false;}

/*
char* FindSubstringInString2(const char* str, const char* subStr){
while (str!=subStr){
++subStr;
if (str==subStr) while(str){str++; return *subStr;}
} return false;}
*/
int main(){
//Excercise 1
Matrix33 A = {{2.1,8.3,-1.3},
{-1.1, 2.3,4},
{1,-7.3,8}};
Matrix33 B = {{0.9,-3,4},
{-1.1,-1.3,19},
{6,-3.3,4}};
Matrix33 C;
Matrix33 D;

Mat_Add(C, A, B); cout<<"Aufgabe 1:"<<endl<<"A + B:" << endl;
Mat_Print(C); cout<< endl;

Mat_Mult(D,A,B); cout << "A * B:" << endl;
Mat_Print(D); cout<< endl;

Mat_Mult(D,B,A); cout << "B * A:" << endl;
Mat_Print(D); cout<< endl<<endl;

//Excercise 2
Sudoku sud = {{1, 2, 3, 4, 5, 6, 7, 8, 9},
{4, 5, 6, 7, 8, 9, 1, 2, 3},
{7, 8, 9, 1, 2, 3, 4, 5, 6},
{2, 3, 4, 5, 6, 7, 8, 9, 1},
{5, 6, 7, 8, 9, 1, 2, 3, 4},
{3, 4, 5, 6, 7, 8, 9, 1, 2},
{8, 9, 1, 2, 3, 4, 5, 6, 7},
{6, 7, 8, 9, 1, 2, 3, 4, 5},
{9, 1, 2, 3, 4, 5, 6, 7, 8}};

Sudoku sud2 = {{1, 2, 3, 4, 5, 6, 7, 8, 9},
{4, 5, 6, 7, 8, 9, 1, 2, 3},
{7, 8, 9, 1, 2, 3, 4, 5, 6},
{2, 3, 4, 5, 6, 7, 7/8/, 9, 1},
{5, 6, 7, 8, 9, 1, 2, 3, 4},
{3, 4, 5, 6, 7, 8, 9, 1, 2},
{8, 9, 1, 2, 3, 4, 5, 6, 7},
{6, 7, 8, 9, 1, 2, 3, 4, 5},
{9, 1, 2, 3, 4, 5, 6, 7, 8}};

cout<<"Excercise 2 (Sudoku):"<<" Testcase true"<<endl<<test_sudoku(sud)<<endl;
cout<<"Excercise 2 (Sudoku):"<<" Testcase false"<<endl<<test_sudoku(sud2)<<endl<<endl;

//Excercise 3
const char* text = "Dieser Text besteht aus mehreren Worten";
const char* word = "meh";
const char* text2 = "mehDieser Text besteht aus mehreren Worten";

//cout<<"Excercise 3a: "<<"Testfall false"<<endl<<StringBeginsWithSubstring(word, text)<<endl;
//cout<<"Excercise 3b: "<<FindSubstringInString(word,text);
/*
*
const char* subText = FindSubstringInString(text, word);
if(subText != 0){
cout << "Der Teil des Textes ’" << text << "’, der mit ’"
<< word << "’ beginnt, lautet: ’"
<< subText << "’ " << endl;
}else{
cout << "Das Wort ’" << word << "’ ist nicht in dem Text ’"
<< text << "’ enthalten." << endl;
}
/
cout<<"***********DONE************"<<"\a\a\a\a\a\a\a\a";        //why \a doesnt give a sound?
return 0;}
