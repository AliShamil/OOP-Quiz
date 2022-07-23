#include <iostream>
#include <vector>
#include <windows.h>
#include <conio.h>
#include <algorithm>
#include<fstream>
#include <string>

using namespace std;
#include "SetColor.h"
#include "Commands.h"
#include "nlohmann/json.hpp"
#include "Answer.h"
#include "Question.h"
#include"Helper Functions.h"
#include"Quiz.h"
#include "User.h"
#include "Player.h"
#include "Admin.h"
#include "File.h"
#include "Quiz Functions.h"
#include "Game.h"
using json = nlohmann::json;
using namespace Header_files;
using namespace Quiz_files;
using namespace User_files;
using namespace File_Handling;
using namespace Quiz_functions;
using namespace Game_files;

int main()
{
	game();
}