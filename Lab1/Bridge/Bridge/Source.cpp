#include <iostream>

using namespace std;

//Draw API
class DrawAPI
{
public:
	virtual void Draw() = 0;
};

//Draw Implementation
class DrawImpl : public DrawAPI
{
public:
	void Draw() { cout << "Draw Impl" << endl; };
};

//Character Class
class Character
{
public:
	virtual void Draw() = 0;
};

//Player class
class Player : public Character
{
public:
	Player(DrawAPI* api) { this->api = api; };
	void Draw() { api->Draw(); };
private:
	DrawAPI* api;
};


int main()
{
	DrawAPI * api = new DrawImpl();

	Character* character = new Player(api);

	character->Draw();

	cin.get();

	system("Pause");

	return 0;
}