#include <ZLua/ZLua.h>
bool DebugMode = true;



class Game : public ZWorldBehaviour
{
public:
	GameObject* object;
	int i = 0;
	void init()
	{

	}

	void init(GameObject* obj)
	{
		object = obj;
	}

	void draw()
	{
		//object->rotate(1.f);
		object->setPosition(0.f, sin(glfwGetTime()));
		i++;
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

	std::vector<vec2> Tri2 =

	{
		vec2(0.0f,0.0f),
		vec2(0.5f,0.5f),
		vec2(-0.5f,0.5f)
	};


	std::vector<int> Tri2Indices =
	{
		0,1,2
	};

	/*for (int i = 0; i < Tri2.size(); i++)
	{
		Tri2[i].rotate(vec2(-0.5f,0.f), 90);
	}*/
	std::vector<float> E = fromList(Tri2,true);

	Textured2D one("./Game/Tex/container.jpg");
	Diffuse2D two(0.5f, 0.5f, 1.0f);

	Mesh Rectangle = *CreateRectangle(1.f, 1.f, &one);
	Mesh* Tri2M = new Mesh(E,indices,&two);
	GameObject Player = GameObject(Rectangle);
	GameObject* object = new GameObject(*Tri2M);
	Game* gameBehav = new Game();
	gameBehav->init(object);
	Scene mainScene("MainScene", DebugMode, gameBehav);
	mainScene.add(&Player);
	mainScene.add(object);
	game.setScene(mainScene);
	game.init();
	game.draw();
	game.end();
	return 0;
}