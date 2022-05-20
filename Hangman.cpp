#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
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

void AlphaVector(std::vector<char> &Alpha)
{
	std::cout << std::endl << "\nLetters available:\n";
	for (int i = 0; i < Alpha.size(); i++)
	{
		std::cout << Alpha[i] << " ";
	}
	std::cout << std::endl;
}

void AlphaRemoveChar(char Guess, std::vector<char> &Alpha)
{
	for (int i = 0; i < Alpha.size(); i++)
	{
		if (Alpha[i] == toupper(Guess))
		{
			Alpha[i] = NULL - 1;
		}
	}
}

int main()
{
	//Variables
	int MaxGuess = 6;
	std::string Word = ("Telephone");
	std::string WordFinal = Word;
	char LetterGuess;
	char Alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::vector<char> Alphabet(Alpha, Alpha+ sizeof(Alpha)-1);

	//Vector population
	std::vector<char> CurrentState(Word.length());
	PopulateVector(Word, CurrentState);
	
	//Greeting prompt
	std::cout << "Hello welcome to the hangman game!" << std::endl;

	PrintVector(CurrentState);
	AlphaVector(Alphabet);

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
			AlphaRemoveChar(LetterGuess, Alphabet);
			AlphaVector(Alphabet);
		}

		//Char not in word
		else
		{
			MaxGuess = MaxGuess - 1;
			system("cls");
			std::cout << "You have " << MaxGuess << " lives left!\n";
			PrintVector(CurrentState);
			AlphaVector(Alphabet);
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