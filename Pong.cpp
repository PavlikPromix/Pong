#include "Pong.h"
#define WIDTH 600
#define HEIGHT 800

using namespace std;

bool paused = false;

void Pause() { paused = true; }
void Unpause() { paused = false; }
void Restart(Player &p, Enemy &e, Ball &b)
{
	p.Restart();
	e.Restart();
	b.Restart();
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Pong");
	window.setFramerateLimit(120);
	window.setVerticalSyncEnabled(true);

	Ball mBall(sf::Vector2i(WIDTH, HEIGHT));
	Player mPlayer(sf::Vector2i(WIDTH, HEIGHT));
	Enemy mEnemy(sf::Vector2i(WIDTH, HEIGHT));
	sf::Text t;
	sf::Font f;
	f.loadFromFile("C:\\Windows\\Fonts\\arialbd.ttf");
	t.setFont(f);
	t.setCharacterSize(WIDTH/5);
	t.setString("0");
	t.setFillColor(sf::Color(255, 255, 255, 50));
	t.setPosition(sf::Vector2f(WIDTH/2-WIDTH/25, HEIGHT/2-WIDTH/10));

	int score = 0;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Left || event.key.code == sf::Keyboard::A) && !paused)
				mPlayer.MoveLeft();
			if (event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::D) && !paused)
				mPlayer.MoveRight();
			if (event.type == sf::Event::MouseMoved && !paused)
				mPlayer.SetPos(event.mouseMove.x - (int)(WIDTH * 0.2));
		}
		window.clear(sf::Color::Black);
		if (!paused)
		{
			mBall.Move(sf::Vector2f(mPlayer.GetPos().x, mEnemy.GetPos().x));
			mEnemy.MoveTo(mBall.GetPos());
		}

		mBall.Draw(window);
		mPlayer.Draw(window);
		mEnemy.Draw(window);
		window.draw(t);

		window.display();

		if (mBall.GetPos().y > HEIGHT)
		{
			std::cout << "YOU LOSE!" << '\n';
			Restart(mPlayer, mEnemy, mBall);
			window.clear(sf::Color::Black);

			mBall.Draw(window);
			mPlayer.Draw(window);
			mEnemy.Draw(window);

			window.display();

			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		}
		if (mBall.GetPos().y < 0)
		{
			std::cout << "YOU WIN!" << '\n';
			score++;
			t.setString(std::to_string(score));
			Restart(mPlayer, mEnemy, mBall);
			window.clear(sf::Color::Black);

			mBall.Draw(window);
			mPlayer.Draw(window);
			mEnemy.Draw(window);

			window.display();

			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		}
	}
	return 0;
}
