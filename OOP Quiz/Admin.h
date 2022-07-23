#pragma once
namespace Header_files {
	namespace User_files {

class Admin : public User
{
	double max_score = 0;

public:

	Admin() = default;
	Admin(string username, string password)
	: User(username, password) {}
	double Max_score() const { return max_score; }

	void set_score(double score)
	{
		if (max_score < score)
			max_score = score;
	}
};

ostream& operator<<(ostream& out, const Admin& a)
{
	out << "Username: " << a.Username() << endl
		<< "Max Score: " << a.Max_score() << endl;

	return out;
}
	}
}