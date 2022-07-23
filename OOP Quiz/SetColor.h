#pragma once
namespace Header_files {

void mySetColor(int fg, int bg)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, fg | (bg << 4));
}

}