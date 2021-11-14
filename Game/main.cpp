#include <ZLua/ZLua.h>
bool DebugMode = true;

int main()
{
	World game(800, 600, "GameEngine Testing");
	std::vector<float> verts = {
		0.5f,  0.5f, 0.0f,   1.0f, 1.0f,   
		 0.5f, -0.5f, 0.0f,  1.0f, 0.0f,   
		-0.5f, -0.5f, 0.0f,  0.0f, 0.0f,  
		-0.5f,  0.5f, 0.0f,  0.0f, 1.0f    
	};

	std::vector<float> texCoords = {
		0.0f, 0.0f,
		1.0f, 0.0f,
		0.5f, 1.0f
	};

	Textured2D one("./Game/Tex/container.jpg");
	Diffuse2D two(0.5f, 0.5f, 1.0f);
	
	Mesh Triangle(verts, one);

	std::vector<vec2> Tri2 = 
	{
		vec2(-1.0f,-1.0f),
		vec2(1.0f,1.0f),
		vec2(1.0f,-1.0f)
	};

	Mesh Triangle2(fromList(Tri2),two);

	std::vector<float> d = fromList(Tri2);


	Scene mainScene("MainScene", DebugMode);
	mainScene.add(Triangle);
	mainScene.add(Triangle2);
	game.setScene(mainScene);
	game.init();
	game.draw();
	game.end();
	return 0;
}