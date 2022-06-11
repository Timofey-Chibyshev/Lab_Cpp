#pragma warning(disable:4996)

#include "GameController.h"

void StartGame()
{
	GameController game;

	game.SetBlocksToDefualt();

	while (game.window.isOpen())
	{
		sf::Event event;
		game.window.pollEvent(event);
		if (event.type == sf::Event::Closed)
		{
			game.window.close();
		}

		game.window.clear();

		if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
		{
			break;// changed
		}

		switch (game.GAMESTATE)
		{
		case GAMEPLAY:
			game.RunGame();
			game.DrawField();
			break;

		case GAME_OVER:
			game.SetBlocksToDefualt();

			if (Keyboard::isKeyPressed(Keyboard::Key::Enter))
			{
				game.GAMESTATE = STATES::GAMEPLAY;
				sleep(milliseconds(150));
			}
			game.DrawGameOver();
			sleep(seconds(1.8f));
			game.GAMESTATE = STATES::GAMEPLAY;
			game.score = 0;
			game.DrawField();
			break;

		case WINNER:
			game.SetBlocksToDefualt();

			if (Keyboard::isKeyPressed(Keyboard::Key::Enter))
			{
				game.GAMESTATE = STATES::GAMEPLAY;
				sleep(milliseconds(150));
			}
			game.DrawGameWinner();
			sleep(seconds(1.8f));
			game.GAMESTATE = STATES::GAMEPLAY;
			game.score = 0;
			game.DrawField();
			break;
		}
	}
}

int main() 
{
	StartGame();
	return 0;
}