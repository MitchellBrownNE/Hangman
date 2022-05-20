#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>

void PrintCorrectVector(std::string word, char Guess , std::vector<char> & State)
{
	for (int i = 0; i < State.size(); i++)
	{
		if (word[i] == Guess)
		{
			State[i] = word[i];
		}
		std::cout << State[i];
	}
}

void PrintVector(std::vector<char> &State)
{
	for (int i = 0; i < State.size(); i++)
	{
		std::cout << State[i];
	}
}

void PopulateVector(std::string word , std::vector<char>& State)
{
	for (int i = 0; i < word.length(); i++)
	{
		State[i] = '_';
	}
}

int main()
{
	//Variables
	std::string Word = ("Telephone");
	std::string WordFinal = Word;
	char LetterGuess;
	int MaxGuess = 6;

	//Vector population
	std::vector<char> CurrentState(Word.length());
	PopulateVector(Word, CurrentState);

	//Greeting prompt
	std::cout << "Hello welcome to the hangman game!" << std::endl;

	PrintVector(CurrentState);

	//Game end when MaxGuess = 0
	while (MaxGuess > 0)
	{
		std::cout << "\nPlease guess a letter for the word: ";
		std::cin >> LetterGuess;

		//Char in word
		if (Word.find(LetterGuess) != std::string::npos)
		{
			system("cls");
			std::cout << "You have " << MaxGuess << " lives left!\n";
			PrintCorrectVector(Word, LetterGuess, CurrentState);
		}

		//Char not in word
		else
		{
			MaxGuess = MaxGuess - 1;
			system("cls");
			std::cout << "You have " << MaxGuess << " lives left!\n";
			PrintVector(CurrentState);
		}
		
		//When word is guessed properly
		if (std::find(CurrentState.begin(), CurrentState.end(), '_') == CurrentState.end())
		{
			std::cout << "\n" << std::setfill('-') << std::setw(50) << "\n";
			std::cout << "Congratulations the word is: " << (WordFinal) << std::endl;
			std::exit(0);
		}
	}

	//Prompt for losing
	if (MaxGuess == 0)
	{
		std::cout << "\nSorry you lost, the word was " << WordFinal;
	}

	return 0;
}