//Program with a recursive function for detecting if string input is a palindrome
#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s)
{
	//if size is 0 assume a palindrome
	if (s.size() == 0)
		return true;
	
	//similarly, if size is 1 assume a palindrome	
	else if (s.size() == 1)
		return true;
	
	//if size > 1	
	else{
		int start = 0; //starting index
		int end = s.size()-1; //ending index
		int len = s.size(); //length of substring
		
		//ignore all spaces
		while (s[start] == ' '){
			start++; //go to the next character
			len--; //decrement substring length
		}
		while (s[end] == ' '){
			end--; 
			len--;
		}
		//cout << s[start] << s[end] << endl;
		
		if (s[start] != s[end]) //if first and last character don't match
			return false;
			
		else if (start < end){
			//send the middle of the current substring to the function again
			return isPalindrome(s.substr(start+1, len-2)); 
		}
	}
	
	return true;		
}//end isPalindrome


int main()
{
	string str;
	
	cout << "Enter a word/phrase: ";
	getline(cin, str);
	
	if(isPalindrome(str))
		cout << endl << "String is a palindrome" << endl << endl;
	else
		cout << endl << "String is NOT a palindrome" << endl << endl;		
	
	return 0;
}
