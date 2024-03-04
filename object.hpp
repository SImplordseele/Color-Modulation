#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <iostream>
#include <string>
#include <stdio.h>
using std::cout;
using std::string;
const int screen_width = 640;
const int screen_height = 480;
bool Init();
bool LoadMedia();
void CLOSE();
SDL_Window* g_window = NULL;
SDL_Renderer* g_screen = NULL;
SDL_Event g_event;
class BaseObject {
protected:
	SDL_Texture* text;
	int wid;
	int heig;
public:
	BaseObject();
	~BaseObject();
	void free();
	void render(int,int);
	int GetWid();
	int GetHeig();
	void SetColor(Uint8 red, Uint8 green, Uint8 blue);
	SDL_Texture* GetText();
	bool LoadImg(string);
};
BaseObject g_image;