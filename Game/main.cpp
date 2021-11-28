#include <ZLua/ZLua.h>
bool DebugMode = true;

class Game : public ZWorldBehaviour
{
public:
	void init()
	{

	}

	void draw(Renderer currFrame)
	{
		
	}
	void end()
	{

	}
};


int main()
{
	World game(800, 800, "GameEngine Testing");
	std::vector<float> verts = {
		 0.5f,  0.5f, 0.0f,   1.0f, 1.0f,   
		 0.5f, -0.5f, 0.0f,   1.0f, 0.0f,   
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f,  
		-0.5f,  0.5f, 0.0f,   0.0f, 1.0f    
	};

	std::vector<int> indices = {
		0,1,3,
		1,2,3
	};


	Textured2D one("./Game/Tex/container.jpg");
	Diffuse2D two(0.5f, 0.5f, 1.0f);

	Mesh Rectangle = *CreateRectangle(1.f, 1.f, &one);
	GameObject Player = GameObject(Rectangle);

	std::vector<vec2> Tri2 =

	{
		vec2(-1.0f,-1.0f),
		vec2(1.0f,1.0f),
		vec2(1.0f,-1.0f)
	};

	std::vector<int> Tri2Indices =
	{
		0,1,2
	};

	//Mesh Triangle2(fromList(Tri2), Tri2Indices ,two);

	std::vector<float> d = fromList(Tri2);


	Scene mainScene("MainScene", DebugMode, new Game());
	mainScene.add(&Player);
	//mainScene.add(Triangle2);
	game.setScene(mainScene);
	game.init();
	game.draw();
	game.end();
	return 0;
}