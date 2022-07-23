#pragma once
namespace Header_files {
	namespace Quiz_functions {
		using namespace Quiz_files;
		using namespace User_files;
bool cursorControl(Quiz& q, int& key, bool& submit)
{
	vector<Question*>& questions = q.get_questions();
	short& answerIndex = questions[q.questionIndex]->answerIndex;

	if (key == 224)
	{
		key = _getch();

		switch (key)
		{
		case 72:
			system("cls");
			--answerIndex;
			break;
		case 77:
			system("cls");
			++q.questionIndex;
			break;

		case 75:
			system("cls");
			--q.questionIndex;
			break;

		case 80:
			system("cls");
			++answerIndex;
			break;
		}

		if (q.questionIndex < 0) q.questionIndex = questions.size() - 1;
		if (q.questionIndex >= questions.size()) q.questionIndex = 0;
		if (answerIndex < 0) answerIndex = questions[q.questionIndex]->get_answers().size() - 1;
		if (answerIndex >= questions[q.questionIndex]->get_answers().size()) answerIndex = 0;

		return false;
	}

	else if (key == 13)
	{
		system("cls");
		q.get_questions()[q.questionIndex]->get_current_answer() = questions[q.questionIndex]->get_answers()[answerIndex];
		return true;
	}

	else if (key == 83 || key == 115)
	{
		submit = !submit;
		return false;
	}


	system("cls");
	return false;

}

bool cursorControl(Command& c)
{
	int key = _getch();

	if (key == 224)
	{
		key = _getch();
		switch (key)
		{
		case 72:
			system("cls");
			--c.commandIndex;
			break;
		case 80:
			system("cls");
			++c.commandIndex;
			break;
		default:
			system("cls");
			break;
		}

		if (c.commandIndex < 0) c.commandIndex = c.commands.size() - 1;
		if (c.commandIndex >= c.commands.size()) c.commandIndex = 0;

		return false;
	}

	else if (key == 13)
	{
		system("cls");

		return true;
	}

	system("cls");
	return false;
}


Quiz* createQuiz()
{
	string quiz_name = "";
	mySetColor(11, 0);


	cout << "Enter Quiz Name: ";
	getline(cin, quiz_name);
	system("cls");

	if (quiz_name.empty())
		throw exception("Quiz is empty!");

	Quiz* temp_quiz = new Quiz(quiz_name);

	Command q_command;
	q_command.commands.push_back("Add Question");
	q_command.commands.push_back("Accept");
	q_command.commands.push_back("Go Back");


	Command a_command;
	a_command.commands.push_back("Add Answer");
	a_command.commands.push_back("Accept");
	a_command.commands.push_back("Go Back");

	Command Answer_is_True;
	Answer_is_True.commands.push_back("True");
	Answer_is_True.commands.push_back("False");


	bool choice = false;
	bool isCorrect = false;
	bool back = false;

	Question* temp_question = nullptr;
	string question;
	string answer;


	while (!back)
	{
		cout << q_command;
		choice = cursorControl(q_command);

		if (choice)
		{
			switch (q_command.commandIndex)
			{
			case 0:

				cout << "Enter Question Text: ";
				getline(cin, question);

				temp_question = new Question(question);

				while (!back)
				{
					system("cls");
					cout << a_command;
					choice = cursorControl(a_command);

					if (choice)

					{

						switch (a_command.commandIndex)
						{
						case 0:
							cout << "Enter Answer Text: ";
							getline(cin, answer);

							while (true)
							{
								system("cls");
								cout << "Answer is Correct?" << endl;
								cout << Answer_is_True;
								choice = cursorControl(Answer_is_True);
								if (choice) 
								{
									switch (Answer_is_True.commandIndex)
									{
									case 0:

										temp_question->add_answer(new Answer(answer, 1));
										break;


									case 1:

										temp_question->add_answer(new Answer(answer, 0));
										break;

									}
									break;
								}

							}


							break;

						case 1:
							back = true;
							break;
						case 2:
							delete temp_question;
							temp_question = nullptr;
							back = true;

						}
					}

				}
				temp_quiz->add_question(temp_question);

				back = false;
				break;

			case 1:

				back = true;
				break;

			case 2:
				return nullptr;

				break;

			}
		}
	}

	return temp_quiz;
}

void random_quiz(Quiz* quiz)
{
	for (auto& q : quiz->get_questions())
		random_shuffle(q->get_answers().begin(), q->get_answers().end());

	random_shuffle(quiz->get_questions().begin(), quiz->get_questions().end());
}

bool check_username(vector<Player*> players, vector<Admin*> admins, const string& username)
{

	for (auto& player : players)
	{
		if (player->Username() == username)
			return true;
	}

	for (auto& admin : admins)
	{
		if (admin->Username() == username)
			return true;
	}

	return false;
}


Player* findPlayer(vector<Player*> players, const string& username, const string& password)
{
	for (auto& player : players)
	{
		if (player->Username() == username && player->Password() == password)
			return player;
	}

	return nullptr;
}


Admin* findAdmin(vector<Admin*> admins, const string& username, const string& password)
{
	for (auto& admin : admins)
	{
		if (admin->Username() == username && admin->Password() == password)
			return admin;
	}

	return nullptr;
}


void show_quiz_c(Command& quiz_name, vector<Quiz*> quizzes)
{
	for (auto& quiz : quizzes)
		quiz_name.commands.push_back(quiz->Name());
}


Quiz* find_quiz(vector<Quiz*> quizes, string name)
{
	for (auto& quiz : quizes)
	{
		if (quiz->Name() == name)
			return new Quiz(*quiz);
	}

	return nullptr;
}


Quiz* play_q(Quiz*& quiz)
{
	bool submit = false;
	bool choice = false;

	int button;

	while (!submit)
	{
		cout << *quiz->get_questions()[quiz->questionIndex];

		cout << "\nPress 'S' or 's' to submit";
		button = _getch();

		choice = cursorControl(*quiz, button, submit);

		if (choice)
		{
			quiz->to_place_questions(quiz->get_questions()[quiz->questionIndex]);
			continue;
		}

	}
	for (auto& question : quiz->get_questions())
	{
		if (question->get_current_answer() == nullptr)
			quiz->get_neutral_q().push_back(question);
	}


	return quiz;

}



double findScore(Quiz* quiz)
{
	size_t correct_size = quiz->get_correct_q().size();
	size_t false_size = quiz->get_false_q().size();

	double finalPoint = (int(correct_size) * 5) - int(false_size);
	return finalPoint;
}

void seeAllPlayersResults(vector<Player*>& players)
{
	sort(players.begin(), players.end(), [](Player* p1, Player* p2)->bool {
		return p1->Max_score() > p2->Max_score();
		});

	
	for (size_t i = 0; i < players.size() && i != 10; i++)
	{
		if (players[i]->Max_score() > 0)
		{
			cout << "Player Number: " << i + 1 << endl;
			cout << *players[i] << endl;
			cout << "-----------\n\n";
		}


	}
}
	}

}