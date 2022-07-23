#pragma once
namespace Header_files {
	namespace Quiz_files {

		void remove_q(vector<Question*>& questions, Question* q)
		{
			for (size_t i = 0; i < questions.size(); i++)
			{
				if (questions[i] == q)
				{
					questions.erase(questions.begin() + i);
					break;
				}
			}
		}


		void hidePassword(string& tempPass)
		{
			char ch;
			ch = _getch();
			while (ch != 13)
			{
				if (ch == 8)
				{
					if (tempPass.size() != 0)
					{
						tempPass.pop_back();
						cout << "\b \b";
					}
				}
				else
				{
					tempPass.push_back(ch);
					cout << '*';
				}

				ch = _getch();
			}

		}
	}
}
