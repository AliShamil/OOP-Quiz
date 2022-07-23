#pragma once
namespace Header_files {
	namespace Quiz_files {
		class Answer
		{
			string _answer = "";
			bool is_correct = false;

		public:
			Answer() = default;
			Answer(string answer, bool is_correct);


			string answer() const { return _answer; }
			bool isCorrect() const { return is_correct; }

			void set_answer(string answer);
		};

#pragma region Constructor

		Answer::Answer(string answer, bool is_correct)
		{
			set_answer(answer);
			this->is_correct = is_correct;
		}

#pragma endregion

#pragma region Setter_AND_Operator

		void Answer::set_answer(string answer)
		{
			if (answer.empty())
				throw exception("Answer is empty!");

			_answer = answer;
		}

		ostream& operator<<(ostream& out, const Answer& a)
		{
			out << a.answer() /*<< ' ' << a.isCorrect()*/;
			return out;
		}

#pragma endregion

	}
}

