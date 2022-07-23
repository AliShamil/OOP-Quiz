#pragma once

namespace Header_files {

	namespace File_Handling {
		using namespace Quiz_files;
		using namespace User_files;
void write(fstream& stream, Answer* a)
{

	if (!stream)
		throw exception("File can't created!");

	if (!stream.is_open())
		throw exception("File can't opened!");

	stream << a->answer() << endl << a->isCorrect() << endl;
	return;

}

void write(fstream& stream, Question* q)
{
	if (!stream)
		throw exception("File can't created!");

	if (!stream.is_open())
		throw exception("File can't opened!");


	stream << q->get_question() << endl << q->get_answers().size() << endl;;

	for (auto& answer : q->get_answers())
		write(stream, answer);


}

void write(fstream& stream, Quiz* quiz)
{
	if (!stream)
		throw exception("File can't created!");

	if (!stream.is_open())
		throw exception("File can't opened!");

	stream << quiz->Name() << endl ;

	stream << quiz->get_questions().size() << endl;

	for (auto& question : quiz->get_questions())
		write(stream, question);
}

void write(fstream& stream, Player* p)
{
	if (!stream)
		throw exception("File can't created!");

	if (!stream.is_open())
		throw exception("File can't opened!");

	stream << p->Username() << endl
		<< p->Password() << endl
		<< p->Max_score() << endl;
	

}

void write(fstream& stream, Admin* a)
{
	if (!stream)
		throw exception("File can't created!");

	if (!stream.is_open())
		throw exception("File can't opened!");

	stream << a->Username() << endl
		<< a->Password() << endl
		<< a->Max_score() << endl;

}



Answer* read_answer(fstream& stream)
{
	string answer;
	bool isCorrect;

	if (!stream)
		throw exception("File can't created!");

	if (!stream.is_open())
		throw exception("File can't opened!");


	getline(stream, answer);
	stream >> isCorrect;
	stream.ignore();

	return new Answer(answer, isCorrect);
}

Question* read_question(fstream& stream)
{
	if (!stream)
		throw exception("File can't created!");

	if (!stream.is_open())
		throw exception("File can't opened!");


	string question;
	getline(stream, question);

	size_t answersCount;
	stream >> answersCount;
	stream.ignore();

	Question* q = new Question(question);


	for (size_t i = 0; i < answersCount; i++)
		q->add_answer(read_answer(stream));

	return q;
}

Quiz* read_quiz(fstream& stream)
{
	if (!stream)
		throw exception("File can't created!");

	if (!stream.is_open())
		throw exception("File can't opened!");

	string name;
	size_t questionCount;

	getline(stream, name);

	Quiz* quiz = new Quiz(name);

	stream >> questionCount;
	stream.ignore();

	for (size_t i = 0; i < questionCount; i++)
		quiz->add_question(read_question(stream));

	return quiz;
}

Player* read_player(fstream& stream)
{
	if (!stream)
		throw exception("File can't created!");

	if (!stream.is_open())
		throw exception("File can't opened!");

	string name;
	string pass;
	float score;

	getline(stream, name);
	getline(stream, pass);

	stream >> score;
	stream.ignore();
	Player* p = new Player(name, pass);

	p->set_score(score);

	return p;
}

Admin* read_admin(fstream& stream)
{
	if (!stream)
		throw exception("File can't created!");

	if (!stream.is_open())
		throw exception("File can't opened!");

	string name;
	string pass;
	float score;

	getline(stream, name);
	getline(stream, pass);

	stream >> score;
	stream.ignore();
	Admin* a = new Admin(name, pass);

	a->set_score(score);

	return a;
}



vector<Quiz*> load_quizzes(string fileName)
{
	fstream stream(fileName, ios::in);

	vector<Quiz*> quizes;


	if (!stream || !stream.is_open())
		return quizes;

	stream.seekg(0);

	size_t quizCount;

	stream >> quizCount;
	stream.ignore();

	for (size_t i = 0; i < quizCount; i++)
		quizes.push_back(read_quiz(stream));

	stream.close();

	return quizes;
}

vector<Player*> load_players(string fileName)
{
	fstream stream(fileName, ios::in);

	vector<Player*> players;

	if (!stream || !stream.is_open())
		return players;

	stream.seekg(0);

	size_t playersCount;

	stream >> playersCount;
	stream.ignore();

	for (size_t i = 0; i < playersCount; i++)
		players.push_back(read_player(stream));

	stream.close();


	return players;
}

vector<Admin*> load_admins(string fileName)
{
	fstream stream(fileName, ios::in);

	vector<Admin*> admins;

	if (!stream || !stream.is_open())
		return admins;

	stream.seekg(0);


	size_t playersCount;

	stream >> playersCount;
	stream.ignore();

	for (size_t i = 0; i < playersCount; i++)
		admins.push_back(read_admin(stream));


	stream.close();
	return admins;
}



void save_players(string fileName, vector<Player*> players)
{
	fstream stream(fileName, ios::out);


	if (!stream)
		throw exception("File can't created!");

	if (!stream.is_open())
		throw exception("File can't opened!");

	stream << players.size() << endl;

	for (auto& player : players)
		write(stream, player);

	stream.close();

}

void save_admins(string fileName, vector<Admin*> admins)
{
	fstream stream(fileName, ios::out);


	if (!stream)
		throw exception("File can't created!");

	if (!stream.is_open())
		throw exception("File can't opened!");

	stream << admins.size() << endl;

	for (auto& admin : admins)
		write(stream, admin);

	stream.close();

}

void save_quizzes(string fileName, vector<Quiz*>& quizes)
{

	fstream stream(fileName, ios::out);


	if (!stream)
		throw exception("File can't created!");

	if (!stream.is_open())
		throw exception("File can't opened!");

	stream.seekg(0);

	stream << quizes.size() << endl;

	for (auto& quiz : quizes)
		write(stream, quiz);

	stream.close();

}
	}
}


