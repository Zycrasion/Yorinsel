#include <ZLua/ZLua.h>
bool DebugMode = true;

int main()
{
	World game(800, 600, "GameEngine Testing");
	std::vector<float> verts = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f,  0.5f, 0.0f
	};
	Shader diffuse("./Game/Shaders/fragment.glsl", "./Game/Shaders/vertex.glsl");
	Mesh Triangle(verts, diffuse.getID());
	Scene mainScene("MainScene", DebugMode);
	mainScene.add(Triangle);
	game.setScene(mainScene);
	game.init();
	game.draw();
	game.end();
	return 0;
}