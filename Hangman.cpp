#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

int main()
{
	std::string Word = ("Fiber");
	std::string WordFinal = Word;
	char LetterGuess;
	int MaxGuess = 6;

	std::cout << "Hello welcome to the hangman game!" << std::endl;

	while (MaxGuess > 0)
	{
		std::cout << "\nPlease guess a letter for the word: ";

		std::cin >> LetterGuess;

		if (Word.find(LetterGuess) != std::string::npos)
		{
			std::cout << "Letter " << LetterGuess << " is in the word!\n";
			Word.erase(remove(Word.begin(), Word.end(), LetterGuess), Word.end());
		}
		else
		{
			std::cout << "Letter " << LetterGuess << " is not in the word.\n";
			MaxGuess = MaxGuess - 1;

		}
		
		if (Word == "")
		{
			std::cout << "\n" <<std::setfill('-') << std::setw(50) << "\n";
			std::cout << "Congratulations the word is: " << (WordFinal) << std::endl;
			std::exit(0);
		}
	}

	if (MaxGuess == 0)
	{
		std::cout << "\nSorry you lost, the word was " << WordFinal;
	}

	return 0;
}