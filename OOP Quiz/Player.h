#pragma once
namespace Header_files {
	namespace User_files {

class Player : public User
{

	double max_score = 0;

public:

	Player() = default;
	Player(string username, string password)
		: User(username, password) {}

	double Max_score() const { return max_score; }
	void set_score(double score)
	{
		if (score < 0)
			score = 0;
		max_score = score;
	}
};

ostream& operator<<(ostream& out, const Player& p)
{
	out << "Username: " << p.Username() << endl
		<< "Max Score: " << p.Max_score() << endl;

	return out;
}
	}
}
