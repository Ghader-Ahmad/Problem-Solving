#include <cstdlib>
#include <iostream>

using namespace std;
 
enum enQuestionsLevel { Easy = 1, Med = 2, Hard = 3, Mix = 5 };
enum enOperationType { Add = 1, Sub = 2, Mul = 3, Div = 4, MixOp = 5 };

string GetOpTypeSympol(enOperationType OpType)
{
	switch (OpType)
	{
	case enOperationType::Add:
		return "+";
		break;

	case enOperationType::Sub:
		return "-";
		break;

	case enOperationType::Mul:
		return "*";
		break;

	case enOperationType::Div:
		return "/";
		break;

	default:
		return "Mix";
		break;
	}
}

string GetQuestionsLevelText(enQuestionsLevel QuestionsLevel)
{
	string arrQuestionsLevelText[4] = { "Easy", "Med","Hard","Mix" };
	return arrQuestionsLevelText[QuestionsLevel - 1];
}

int RandomNumber(int From, int To)
{
	int RandNumber = rand() % (To - From + 1) + From;
	return RandNumber;
}

void SetScreenColor(bool Right)
{
	if (Right)
	{
		system("color 2F");
	}
	else
	{
		system("color 4F");
		cout << "\a";
	}
}

short ReadHowManyQuestion()
{
	short NumberOfQuestions = 0;
	do
	{
		cout << "\nHow many Questions do you want to answer?\n";
		cin >> NumberOfQuestions;
	} while (NumberOfQuestions < 1 || NumberOfQuestions > 10);
	return NumberOfQuestions;
}

enQuestionsLevel ReadQuestionsLevel()
{
	short QuestionsLevel = 0;
	do
	{
		cout << "Enter Question Level [1] Easy, [2] Med, [3] Hard, [4] Mix ?\n";
		cin >> QuestionsLevel;
	} while (QuestionsLevel < 1 || QuestionsLevel > 4);
	return (enQuestionsLevel)QuestionsLevel;
}

enOperationType ReadOperationType()
{
	short OperationType = 0;
	do
	{
		cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ?\n";
		cin >> OperationType;
	} while (OperationType < 1 || OperationType > 5);
	return (enOperationType)OperationType;
}

struct stQuestion
{
	int Number1 = 0;
	int Number2 = 0;
	enQuestionsLevel QuestionsLevel;
	enOperationType OperationType;
	int CorrectAnswer = 0;
	int PlayerAnswer = 0;
	bool AnswerResult = false;
};

struct stQuizz
{
	stQuestion QuestionList[100];
	short NumberOfQuestions = 0;
	enQuestionsLevel QuestionsLevel;
	enOperationType OperationType;
	short NumberOfWorngAnswer = 0;
	short NumberOfRightAnswer = 0;
	bool IsPass = false;
};

int SimpleCalculator(int Number1, int Number2, enOperationType OperationType)
{
	switch (OperationType)
	{
	case enOperationType::Add:
		return Number1 + Number2;
		break;

	case enOperationType::Sub:
		return  Number1 - Number2;
		break;

	case enOperationType::Mul:
		return  Number1 * Number2;
		break;

	case enOperationType::Div:
		return  Number1 / Number2;
		break;

	default:
		return  Number1 + Number2;
		break;
	}
}

enOperationType GetRandomOperationType()
{
	return (enOperationType)RandomNumber(1, 4);
}

stQuestion GenerateQuestion(enQuestionsLevel QuestionsLevel, enOperationType OpType)
{
	stQuestion Question;
	if (QuestionsLevel == enQuestionsLevel::Mix)
	{
		QuestionsLevel = (enQuestionsLevel)RandomNumber(1, 3);
	}
	if (OpType == enOperationType::MixOp)
	{
		OpType = GetRandomOperationType();
	}

	Question.OperationType = OpType;

	switch (QuestionsLevel)
	{
	case enQuestionsLevel::Easy:
		Question.Number1 = RandomNumber(1, 10);
		Question.Number2 = RandomNumber(1, 10);

		Question.CorrectAnswer = 
			SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);

		Question.QuestionsLevel = QuestionsLevel;
		return Question;

	case enQuestionsLevel::Med:
		Question.Number1 = RandomNumber(10, 50);
		Question.Number2 = RandomNumber(10, 50);

		Question.CorrectAnswer =
			SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);
		
		Question.QuestionsLevel = QuestionsLevel;
		return Question;

	case enQuestionsLevel::Hard:
		Question.Number1 = RandomNumber(50, 100);
		Question.Number2 = RandomNumber(50, 100);

		Question.CorrectAnswer =
			SimpleCalculator(Question.Number1, Question.Number2, Question.OperationType);

		Question.QuestionsLevel = QuestionsLevel;
		return Question;
	}
	return Question;
}

void GenerateQuestions(stQuizz& Quizz)
{
	for (short Questions = 0; Questions < Quizz.NumberOfQuestions; Questions++)
	{
		Quizz.QuestionList[Questions] = GenerateQuestion(Quizz.QuestionsLevel, Quizz.OperationType);
	}
}

int ReadQuestionAnswer()
{
	int Answer = 0;
	cin >> Answer;
	return Answer;
}

void PrintQuestion(stQuizz& Quizz, short QuestionNumber)
{
	cout << "\n";
	cout << "Question [ " << QuestionNumber + 1 << "/" << Quizz.NumberOfQuestions << "] :\n\n";
	cout << Quizz.QuestionList[QuestionNumber].Number1 << endl;
	cout << Quizz.QuestionList[QuestionNumber].Number2 << " ";
	cout << GetOpTypeSympol(Quizz.QuestionList[QuestionNumber].OperationType);
	cout << "\n---------\n";
}

void CorrectTheQuestionAnswer(stQuizz& Quizz, short QuistionNumber)
{
	
	if (Quizz.QuestionList[QuistionNumber].PlayerAnswer !=
		Quizz.QuestionList[QuistionNumber].CorrectAnswer)
	{
		Quizz.QuestionList[QuistionNumber].AnswerResult = false;
		Quizz.NumberOfWorngAnswer++;

		cout << "Wrong Answer : -(\n";
		cout << "The right answer is : ";
		cout << Quizz.QuestionList[QuistionNumber].CorrectAnswer;
		cout << "\n";
	}
	else
	{
		Quizz.QuestionList[QuistionNumber].AnswerResult = true;
		Quizz.NumberOfRightAnswer++;

		cout << "Right Answer : -) \n";
	}
	cout << endl;
	SetScreenColor(Quizz.QuestionList[QuistionNumber].AnswerResult);
}

void AskAndCorrectQuestionsListAnswer(stQuizz& Quizz)
{
	stQuestion Question;
	for (short QuestionNumber = 0; QuestionNumber < Quizz.NumberOfQuestions; QuestionNumber++)
	{
		PrintQuestion(Quizz, QuestionNumber);

		Quizz.QuestionList[QuestionNumber].PlayerAnswer = ReadQuestionAnswer();

		CorrectTheQuestionAnswer(Quizz, QuestionNumber);
	}

	Quizz.IsPass = (Quizz.NumberOfRightAnswer >= Quizz.NumberOfWorngAnswer);
}

string GetFinalResultText(bool Pass)
{
	if (Pass)
		return "Pass : -)";
	else
		return "Fail : -(";
}

void PrintQuizzResults(stQuizz Quizz)
{
	cout << "\n";
	cout << "--------------------------------------------\n\n";

	cout << "Final Results is " <<
		GetFinalResultText(Quizz.IsPass);
	cout << "\n-------------------------------------------\n\n";

	cout << "Number of Question: " << Quizz.NumberOfQuestions << endl;
	cout << "Questions Level : " << GetQuestionsLevelText(Quizz.QuestionsLevel) << endl;
	cout << "OpType : " << GetOpTypeSympol(Quizz.OperationType) << endl;
	cout << "Number of Right Answer : " << Quizz.NumberOfRightAnswer << endl;
	cout << "Number of Wrong Answer : " << Quizz.NumberOfWorngAnswer << endl;
	cout << "---------------------------------\n";
}

void PlayMathGame()
{
	stQuizz Quizz;

	Quizz.NumberOfQuestions = ReadHowManyQuestion();
	Quizz.QuestionsLevel = ReadQuestionsLevel();
	Quizz.OperationType = ReadOperationType();


	GenerateQuestions(Quizz);
	AskAndCorrectQuestionsListAnswer(Quizz);
	PrintQuizzResults(Quizz);
}

void ResetScreen()
{
	system("cls");
	system("color 0F");
}

void StartGame()
{
	char PlayAgin = 'Y';
	do
	{
		ResetScreen();
		PlayMathGame();
		cout << "\nDo You want to play a agin ? Y/N ?\n ";
		cin >> PlayAgin;
	} while (PlayAgin == 'Y' || PlayAgin =='y');
}

int main()
{
	srand((unsigned)time(NULL));

	StartGame();

	return 0;

}

