#include <ZLua/ZLua.h>
bool DebugMode = true;

int main()
{
	Scene main("MainScene", DebugMode);
	World game(800,600, "GameEngine Testing");
	game.init();
	game.draw();
	game.end();
	return 0;
}