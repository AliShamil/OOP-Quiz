#pragma once
namespace Header_files {
	namespace Quiz_files {

		class Question
		{
			string q_txt = "";
			vector<Answer*>answers;
			Answer* current_answer = NULL;

		public:
			short answerIndex = 0;

			Question() = default;
			Question(string q_txt);

			Question(const Question& q);

			Question(Question&& q) noexcept;

			Question& operator=(const Question& q);


			Question& operator=(Question&& q) noexcept;


			string get_question() const { return q_txt; }
			vector<Answer*> get_answers() const { return answers; }
			vector<Answer*>& get_answers() { return answers; }
			Answer* get_current_answer() const { return current_answer; }
			Answer*& get_current_answer() { return current_answer; }

			void set_q_txt(string txt);
			void add_answer(Answer* answer);

			~Question()
			{
				for (auto& answer : answers)
				{
					delete answer;
					answer = nullptr;
				}

				delete current_answer;
			}
		};


#pragma region Constructor

		Question::Question(string txt)
		{
			set_q_txt(txt);
		}

		Question::Question(const Question& q)
		{
			q_txt = q.q_txt;

			for (auto& answer : q.answers)
				answers.push_back(new Answer(*answer));

			if (q.current_answer != nullptr)
				current_answer = new Answer(*q.current_answer);

		}


		Question& Question::operator=(const Question& q)
		{
			q_txt = q.q_txt;

			for (auto& answer : q.answers)
				answers.push_back(new Answer(*answer));

			if (q.current_answer != nullptr)
				current_answer = new Answer(*q.current_answer);

			return *this;
		}


		Question& Question::operator=(Question&& q) noexcept
		{
			q_txt = q.q_txt;


			q.answers.swap(answers);


			for (auto& answer : answers)
				answer = nullptr;


			q.current_answer = current_answer;

			current_answer = nullptr;
			return *this;
		}

#pragma endregion

#pragma region Method

		void Question::set_q_txt(string txt)
		{
			if (txt.empty())
				throw exception("Question is empty!");

			q_txt = txt;
		}



		void Question::add_answer(Answer* answer)
		{
			if (!answer)
				throw exception("Answer is NULL!");

			answers.push_back(answer);
		}

#pragma endregion

#pragma region Operator_Overload

		ostream& operator<<(ostream& out, const Question& q)
		{
			mySetColor(15, 0);

			out << q.get_question() << endl;
			mySetColor(11, 0);
			for (size_t i = 0; i < q.get_answers().size(); i++)
			{
				if (i == q.answerIndex)
				{

					mySetColor(0, 11);
					out << *q.get_answers()[i] << endl;
					mySetColor(11, 0);

					continue;
				}

				out << *q.get_answers()[i] << endl;

			}

			mySetColor(11, 0);

			if (q.get_current_answer())
				out << "\n\nYour choice : " << *q.get_current_answer() << endl;

			return out;
		}

#pragma endregion

	}
}




