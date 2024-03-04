#include "definition.hpp"
int main(int argc, char* argv[]) {
	if(!Init()) return -1;
	if (!LoadMedia()) return -1;
	bool quit = false;
	Uint8 r = 255;
	Uint8 g = 255;
	Uint8 b = 255;
	while (!quit) {
		while (SDL_PollEvent(&g_event)) {
			if (g_event.type == SDL_QUIT) {
				quit = true;
			}
			else if (g_event.type == SDL_KEYDOWN) {
				switch (g_event.key.keysym.sym) {
						//Increase red
					case SDLK_q:
						r += 32;
						break;

						//Increase green
					case SDLK_w:
						g += 32;
						break;

						//Increase blue
					case SDLK_e:
						b += 32;
						break;

						//Decrease red
					case SDLK_a:
						r -= 32;
						break;

						//Decrease green
					case SDLK_s:
						g -= 32;
						break;

						//Decrease blue
					case SDLK_d:
						b -= 32;
						break;
				}
			}
		}
		SDL_SetRenderDrawColor(g_screen, 255, 255, 255, 255);
		SDL_RenderClear(g_screen);
		g_image.SetColor(r, g, b);
		g_image.render(0, 0);
		SDL_RenderPresent(g_screen);
	}
	CLOSE();
	return 0;
}