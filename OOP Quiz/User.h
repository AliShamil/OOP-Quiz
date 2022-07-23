#pragma once
namespace Header_files {
	namespace User_files {

class User
{
protected:
	string _username = "";
	string _password = "";

public:

	User() = default;
	User(string username, string password)
	{
		set_username(username);
		set_password(password);
	}

	string Username() const { return _username; }
	string Password() const { return _password; }

	void set_username(string username);
	void set_password(string password);

	virtual ~User() = 0 {};
};

#pragma region Setter
void User::set_username(string username)
{
	if (username.size() < 3)
		throw exception("Username must be bigger than 3 character!");

	_username = username;
}

void User::set_password(string password)
{
	if (password.size() < 4)
		throw exception("Password must be bigger than 4 character!");

	bool found = password.find(_username) != std::string::npos;

	if (found)
		throw exception("Password is too weak!(Pls creeate stronger password!)");

	_password = password;
}

#pragma endregion

	}

}





