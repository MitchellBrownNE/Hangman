/*
TO DO

-Format everything
-Graphics through cmd (Actual hangman and updates when wrong guess) (USE SWITCH STATEMENT)

*/

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
	std::cout << "\nLetters available:\n";
	for (int i = 0; i < Alpha.size(); i++)
	{
		std::cout << Alpha[i] << " ";
	}
	std::cout << "\n\n";
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

void AlphaCheckLetter(char &Guess, std::vector<char>& Alpha)
{
	while (std::find(Alpha.begin(), Alpha.end(), toupper(Guess)) == Alpha.end())
	{
		std::cout << "\nLetter has already been used, enter another:";
		std::cin >> Guess;
	}
}

void CorrectWord(std::string Word, std::vector<char>& State)
{
	if (std::find(State.begin(), State.end(), '_') == State.end())
	{
		std::cout << "\n" << std::setfill('-') << std::setw(50) << "\n";
		std::cout << "Congratulations the word is: " << (Word) << std::endl;
		std::exit(0);
	}
}

void DrawHangman(int Lives)
{
	switch (Lives+1)
	{
	case 1:
		std::cout << "\n\n----------------";
		std::cout << "\n|        |";
		std::cout << "\n|        O";
		std::cout << "\n|       /|\\";
		std::cout << "\n|        |";
		std::cout << "\n|       / \\";
		std::cout << "\n|";
		std::cout << "\n|";
		break;
	case 2:
		std::cout << "\n\n----------------";
		std::cout << "\n|        |";
		std::cout << "\n|        O";
		std::cout << "\n|       /|\\";
		std::cout << "\n|        |";
		std::cout << "\n|         \\";
		std::cout << "\n|";
		std::cout << "\n|";
		break;

	case 3:
		std::cout << "\n\n----------------";
		std::cout << "\n|        |";
		std::cout << "\n|        O";
		std::cout << "\n|       /|\\";
		std::cout << "\n|        |";
		std::cout << "\n|         ";
		std::cout << "\n|";
		std::cout << "\n|";
		break;

	case 4:
		std::cout << "\n\n----------------";
		std::cout << "\n|        |";
		std::cout << "\n|        O";
		std::cout << "\n|        |\\";
		std::cout << "\n|        |";
		std::cout << "\n|         ";
		std::cout << "\n|";
		std::cout << "\n|";
		break;

	case 5:
		std::cout << "\n\n----------------";
		std::cout << "\n|        |";
		std::cout << "\n|        O";
		std::cout << "\n|        |";
		std::cout << "\n|        |";
		std::cout << "\n|         ";
		std::cout << "\n|";
		std::cout << "\n|";
		break;
	case 6:
		std::cout << "\n\n----------------";
		std::cout << "\n|        |";
		std::cout << "\n|        O";
		std::cout << "\n|         ";
		std::cout << "\n|         ";
		std::cout << "\n|         ";
		std::cout << "\n|";
		std::cout << "\n|";
		break;
	case 7:
		std::cout << "\n\n----------------";
		std::cout << "\n|        |";
		std::cout << "\n|         ";
		std::cout << "\n|         ";
		std::cout << "\n|         ";
		std::cout << "\n|         ";
		std::cout << "\n|";
		std::cout << "\n|";
		break;
	}
	

}


int main()
{
	int LivesLeft = 6;
	std::string  Word = ("Telephone");
	char LetterGuess;
	const char Alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::vector<char> Alphabet(Alpha, Alpha+ sizeof(Alpha)-1);


	//Vector population
	std::vector<char> CurrentState(Word.length());
	PopulateVector(Word, CurrentState);

	//Greeting prompt
	std::cout << "Hello welcome to the hangman game!" << std::endl;



	//Display for unguessed word and remaining letter
	AlphaVector(Alphabet);
	PrintVector(CurrentState);
	DrawHangman(LivesLeft);



	//Game end when MaxGuess = 0
	while (LivesLeft > 0)
	{
		//Input with letter validation
		std::cout << "\n\nPlease guess a letter for the word: ";
		std::cin >> LetterGuess;
		while (!isalpha(LetterGuess))
		{
		std::cin.clear();
		std::cout << "\nEnter a alphabetical character: ";
		std::cin >> LetterGuess;
		}

		std::transform(Word.begin(), Word.end(), Word.begin(), ::toupper);
		LetterGuess = toupper(LetterGuess);

		//Check if LetterGuess used already
		AlphaCheckLetter(LetterGuess, Alphabet);

		//Char in word or not
		if (Word.find(LetterGuess) != std::string::npos)
		{
			system("cls");
			std::cout << "You have " << LivesLeft << " lives left!\n";
			AlphaRemoveChar(LetterGuess, Alphabet);
			AlphaVector(Alphabet);
			PrintCorrectVector(Word, LetterGuess, CurrentState);
			DrawHangman(LivesLeft);
		}
		else
		{
			system("cls");
			LivesLeft = LivesLeft - 1;
			std::cout << "You have " << LivesLeft << " lives left!\n";
			AlphaVector(Alphabet);
			PrintVector(CurrentState);
			DrawHangman(LivesLeft);
			
		}
		


		//When word is guessed properly
		CorrectWord(Word, CurrentState);
	}



	//Prompt for losing
	if (LivesLeft == 0)
	{
		std::cout << "\nSorry you lost, the word was " << Word;
	}

	return 0;
}