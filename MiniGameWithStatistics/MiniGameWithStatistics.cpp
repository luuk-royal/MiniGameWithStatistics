// MiniGameWithStatistics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

struct score {
	string name;
	int highScore;
};

int main()
{
	vector<int>::const_iterator iter;

	bool gameOn = true;
	int guess;
	int highScore = 0;
	
	while (gameOn) {
		int randomNumber = (rand() % 2) + 1;
		cout << "Guess 1 or 2 untill you fail!" << endl;
		cin >> guess;
		while (!cin.good())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please only enter numbers!" << endl;
			cin >> guess;
		}

		if (guess < 1 || guess > 2)
		{
			cout << "Please only enter 1 or 2!" << endl;
		}
		else
		{
			if (guess == randomNumber)
			{
				cout << "You guessed correct!" << endl;
				highScore + 1;
			}
			else {
				cout << "You guessed wrong!" << endl;
				gameOn = false;
			}
		}
	}

	string name;
	cout << "Please enter your name" << endl;
	cin >> name;

	score finalScore = {name, highScore};

	// Read a list of highscores and add new highscore to it.
	cout << "Creating a list of scores.";
	vector<int> scores;
	scores.push_back(10);
	scores.push_back(30);
	scores.push_back(45);

	cout << "\nHigh Scores: \n";

	for (iter = scores.begin(); iter != scores.end(); ++iter)
	{
		cout << *iter << endl;
	}

	cout << "\nFinding a score.";
	int score;
	cout << "\nEnter a score to find.";
	cin >> score;
	iter = find(scores.begin(), scores.end(), score);
	if (iter != scores.end())
	{
		cout << "Score found. \n";
	}
	else
	{
		cout << "Score not found. \n";
	}

	cout << "\nRandomizing scores.";
	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(scores.begin(), scores.end());
	cout << "\nHigh Scores: \n";
	for (iter = scores.begin(); iter != scores.end(); ++iter)
	{
		cout << *iter << endl;
	}

	cout << "\nSorting scores.";
	sort(scores.begin(), scores.end());
	cout << "\nHigh Scores:\n";
	for (iter = scores.begin(); iter != scores.end(); ++iter)
	{
		cout << *iter << endl;
	}

	return 0;
}
