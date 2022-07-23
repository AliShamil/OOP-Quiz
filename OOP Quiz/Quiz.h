#pragma once
namespace Header_files {
	namespace Quiz_files {
	class Quiz
	{
		string _name = "";
		vector<Question*>questions;
		vector<Question*>correct_q;
		vector<Question*>false_q;
		vector<Question*>neutral_q;


	public:
		short questionIndex = 0;

		Quiz(string name)
		{
			set_name(name);
		}

		string Name() const { return _name; }
		const vector<Question*> get_questions() const { return questions; }
		const vector<Question*> get_correct_q() const { return correct_q; }
		const vector<Question*> get_false_q() const { return false_q; }
		const vector<Question*> get_neutral_q() const { return neutral_q; }

		vector<Question*>& get_questions() { return questions; }
		vector<Question*>& get_correct_q() { return correct_q; }
		vector<Question*>& get_false_q() { return false_q; }
		vector<Question*>& get_neutral_q() { return neutral_q; }

		void set_name(string name);

		void add_question(Question* question);

		bool verifyQuestion(const vector<Question*>& questions, Question* q);

		void to_place_questions(Question* q);

		void show_corrects();
		void show_falses();
		void show_neutral();

	};
#pragma region Method


	void Quiz::set_name(string name)
	{
		if (name.empty())
			throw exception("Name is empty!");

		_name = name;
	}

	void Quiz::add_question(Question* question)
	{
		if (!question)
			throw exception("Question is NULL!");

		questions.push_back(new Question(*question));
	}

	bool Quiz::verifyQuestion(const vector<Question*>& questions, Question* q) {

		for (auto& question : questions)
		{
			if (question == q)
				return true;
		}

		return false;
	}

	void Quiz::to_place_questions(Question* q)
	{

		if (!q)
			throw exception("Question is NULL!");

		bool isFind = false;

		isFind = verifyQuestion(questions, q);


		if (!isFind)
			throw exception("Question not found!");


		if (!q->get_current_answer())
			return;

		if (verifyQuestion(correct_q, q))
		{
			if (q->get_current_answer()->isCorrect())return;

			remove_q(correct_q, q);
			false_q.push_back(q);
			return;
		}

		else if (verifyQuestion(false_q, q))
		{
			if (!q->get_current_answer()->isCorrect())return;
			remove_q(false_q, q);
			correct_q.push_back(q);
			return;
		}

		else {

			if (!q->get_current_answer()->isCorrect())
				false_q.push_back(q);
			else
				correct_q.push_back(q);
		}

	}

	void Quiz::show_corrects()
	{
		for (auto& c : correct_q)
		{
			cout << *c;
		}
	}
	void Quiz::show_falses()
	{
		for (auto& f : false_q)
		{
			cout << *f;
		}
	}
	void Quiz::show_neutral()
	{
		for (auto& n : neutral_q)
		{
			cout << *n;
		}
	}
#pragma endregion

	}
}


