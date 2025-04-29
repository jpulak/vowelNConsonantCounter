// menu driven program to find various things (vowel, consonant, both)
// create functions to find vowel/consonants
// store results in vector list and output all at the endl

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

// func prototype

int countVowel(const char *str);
int countConsonant(const char *str);

// func for finding vowels

int countVowel(const char *str)
{
	int count = 0; // track
	while (*str) // iterate thro each char
	{
		char ch = tolower(*str); // easier to filter thro w/o uppers
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
		{
			count++;
		}
		str++;
	}
	return count;
}

// func to find consonants

int countConsonant(const char *str)
{
	int count = 0; //track
	while (*str) // iterate thro each char
	{
		char ch = tolower(*str); // easier to filter thro wihout upper
		if (isalpha(ch) && !(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')) // not vowel = consonant
		{
			count++;
		}
		str++;
	}
	return count;
}

// driver func

int main()
{

	// initialize vars

	const int SIZE = 100;
	char str[SIZE];
	char choice;

	// Store the output lines in vector to print later

	vector<string> laterPrint;

	// gather user input

	cout << "Enter a string: ";
	cin.getline(str, SIZE);

	// present menu options

	do {
		cout << "\nMenu ~_~ Choose one of the following options below:\n";
		cout << "A) Count the number of vowels in the string\n";
		cout << "B) Count the number of consonants in the string\n";
		cout << "C) Count both the vowels and consonants in the string\n";
		cout << "D) Enter another string\n";
		cout << "E) Exit the program\n";
		cout << "~Enter your choice~ ";
		cin >> choice;
		choice = toupper(choice); // less cases to ask for
		cin.ignore(); // Ignore leftover newline

		// run respective input case option thro switch case
		// pushback results into vector list to output later
		// change output to str to concatinate

		switch (choice)
		{
		case 'A':
			laterPrint.push_back("The string has " + to_string(countVowel(str)) + " vowels."); // vowel
			break;
		case 'B':
			laterPrint.push_back("The string has " + to_string(countConsonant(str)) + " consonants."); // consonats
			break;
		case 'C':
		{
			int vowel = countVowel(str);
			int consonant = countConsonant(str);
			laterPrint.push_back("The string has " + to_string(vowel) + " vowels and " + to_string(consonant) + " consonants."); //both
			break;
		}
		case 'D':
			cout << "Enter a new string: "; // new
			cin.getline(str, SIZE);
			break;
		case 'E':
			laterPrint.push_back("Program terminated"); // exit
			break;
		default:
			cout << "Invalid  x_x Enter A, B, C, D, or E.\n"; // fallback
		}
	} while (choice != 'E'); // if program not terminated

	// Output all the collected results after user exits program

	for (const string &line : laterPrint) //go thro all elements in list n print
	{
		cout << line << endl;
	}
	return 0;
}

//end of program
