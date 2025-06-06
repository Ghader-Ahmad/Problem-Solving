#include<iostream>
#include<cstdlib>

using namespace std;

enum enGameChoice { Stone = 1, Paper = 2, Sicsseor = 3 };
enum enWinner { Player1 = 1, Computer = 2, Draw = 3 };

struct stRoundInfo
{
	short Round = 0;
	enGameChoice Player1Choice;
	enGameChoice ComputerChoice;
	enWinner Winner;
	string WinnerName = "";
};

struct stGameResults
{
	short Rounds = 0;
	short Player1WonTimes = 0;
	short ComputerWonTimes = 0;
	short DrawTimes = 0;
	enWinner WinnerGame;
	string WinnerName = "";
};

int RandomNumber(int From, int To)
{
	int RandNumber = rand() % (To - From + 1) + From;
	return RandNumber;
}

enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
	if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
	{
		return enWinner::Draw;
	}

	switch (RoundInfo.Player1Choice)
	{
	case enGameChoice::Paper:
		if (RoundInfo.ComputerChoice == enGameChoice::Sicsseor)
		{
			return enWinner::Computer;
		}
		break;

	case enGameChoice::Sicsseor:
		if (RoundInfo.ComputerChoice == enGameChoice::Stone)
		{
			return enWinner::Computer;
		}
		break;

	case enGameChoice::Stone:
		if (RoundInfo.ComputerChoice == enGameChoice::Paper)
		{
			return enWinner::Computer;
		}
		break;

	}

	return enWinner::Player1;
}

enWinner WhoWonTheGame(stGameResults GameResults)
{
	if (GameResults.Player1WonTimes > GameResults.ComputerWonTimes)
		return enWinner::Player1;

	else if (GameResults.ComputerWonTimes > GameResults.Player1WonTimes)
		return enWinner::Computer;

	else
		return enWinner::Draw;
}

string Tabs(short NumberOfTabs)
{
	string t = "";
	for (int i = 1; i <= NumberOfTabs; i++)
	{
		t = t + "\t";
	}
	return t;
}

string ChoiceName(enGameChoice GameChoice)
{
	string arrGameChoice[3] = { "Stone" , "Paper", "Seicsseor" };
	return arrGameChoice[GameChoice - 1];
}

string WinnerName(enWinner Winner)
{
	string arrWinnerName[3] = { "Player1", "Computer", "Draw" };
	return arrWinnerName[Winner - 1];
}

short ReadHowManyRounds()
{
	short Rounds = 0;
	do
	{
		cout << "How many Rounds 1 to 10 ?\n";
		cin >> Rounds;
	} while (Rounds < 1 || Rounds > 10);

	return Rounds;
}

enGameChoice ReadPlayer1Choice()
{
	short Player1Choice = 0;
	do
	{
		cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors ?\n";
		cin >> Player1Choice;
	} while (Player1Choice < 1 || Player1Choice > 3);
	return (enGameChoice)Player1Choice;
}

enGameChoice GetComputerChoice()
{
	return (enGameChoice)RandomNumber(1, 3);
}

stGameResults FillGameResults(short Rounds, short Player1Times, short ComputerTimes, short DrawTimes)
{
	stGameResults GameResults;
	GameResults.Rounds = Rounds;
	GameResults.Player1WonTimes = Player1Times;
	GameResults.ComputerWonTimes = ComputerTimes;
	GameResults.DrawTimes = DrawTimes;
	GameResults.WinnerGame = WhoWonTheGame(GameResults);
	GameResults.WinnerName = WinnerName(GameResults.WinnerGame);

	return GameResults;
}

void SetWinnerScreenColor(enWinner Winner)
{
	if (Winner == enWinner::Computer)
	{
		cout << "\a";
		system("color 4F");
	}

	else if (Winner == enWinner::Player1)
		system("color 2F");

	else
		system("color 6F");
}

void ShowGameOverInScreen()
{
	cout << Tabs(4) << "___________________________________________________________\n\n";
	cout << Tabs(6) << "+++ C a m e  O v e r +++\n";
	cout << Tabs(4) << "___________________________________________________________\n\n";
}

void ShowFinalResults(stGameResults GameResults)
{
	cout << Tabs(4) << "_________________________[ Game Results ]____________________\n\n";
	cout << Tabs(4) << "Game Rounds        : " << GameResults.Rounds << endl;
	cout << Tabs(4) << "Player1 won times  : " << GameResults.Player1WonTimes << endl;
	cout << Tabs(4) << "Computer won times : " << GameResults.ComputerWonTimes << endl;
	cout << Tabs(4) << "Draw times         : " << GameResults.DrawTimes << endl;
	cout << Tabs(4) << "Final Winner       : " << GameResults.WinnerName << endl;
	cout << Tabs(4) << "_____________________________________________________________\n\n";
	SetWinnerScreenColor(GameResults.WinnerGame);
}

void PrintRounds(stRoundInfo RoundInfo)
{
	cout << "\n_____________Round [" << RoundInfo.Round << "] _____________________\n";
	cout << "Player1 Choice  : " << ChoiceName(RoundInfo.Player1Choice) << endl;
	cout << "Computer Choice : " << ChoiceName(RoundInfo.ComputerChoice) << endl;
	cout << "Round Winner    : " << RoundInfo.WinnerName << endl;
	cout << "___________________________________________\n\n";
	SetWinnerScreenColor(RoundInfo.Winner);
}

stGameResults PlayGame(short HowManyRounds)
{
	stRoundInfo RoundInfo;
	short Plarer1Wontimes = 0, ComputerWontimes = 0, DrawTimes = 0;

	for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++)
	{
		cout << "Round [ " << GameRound << " ] begins :\n";
		RoundInfo.Round = GameRound;
		RoundInfo.Player1Choice = ReadPlayer1Choice();
		RoundInfo.ComputerChoice = GetComputerChoice();
		RoundInfo.Winner = WhoWonTheRound(RoundInfo);
		RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

		PrintRounds(RoundInfo);

		if (RoundInfo.Winner == enWinner::Computer)
			ComputerWontimes++;
		else if (RoundInfo.Winner == enWinner::Player1)
			Plarer1Wontimes++;
		else
			DrawTimes++;
	}
	return FillGameResults(HowManyRounds, Plarer1Wontimes, ComputerWontimes, DrawTimes);
}

void ResetScreen()
{
	system("cls");
	system("color 0F");
}

void GameStart()
{
	char PlayAgain = 'y';
	do
	{
		ResetScreen();
		stGameResults GameResults = PlayGame(ReadHowManyRounds());
		ShowGameOverInScreen();
		ShowFinalResults(GameResults);
		cout << Tabs(4) << "Do you want to play again ? Y/N ?";
		cin >> PlayAgain;
	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main()
{
	srand((unsigned)time(NULL));

	GameStart();

	return 0;
}