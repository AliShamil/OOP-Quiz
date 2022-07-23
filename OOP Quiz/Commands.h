#pragma once
namespace Header_files {

class Command
{
public:
	vector<string> commands;
	short commandIndex = 0;


};

ostream& operator<<(ostream& out, const Command& c)
{

	for (size_t i = 0; i < c.commands.size(); i++)
	{
		if (i == c.commandIndex)
		{
			mySetColor(0, 11);
			out << "\n\n\n\n\t\t\t\t\t\t" << c.commands[i];
			mySetColor(11, 0);
			continue;
		}
		out << "\n\n\n\t\t\t\t\t\t" << c.commands[i];
	}

	return out;
}

}