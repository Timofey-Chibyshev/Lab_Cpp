#include"GameController.h"

GameController::GameController() 
{
	font.loadFromFile("Lato-Bold.ttf");

	tScore.setFont(font);
	tScore.setString(printScore + to_string(score));
	tScore.setPosition(Vector2f(0, 0));
	tScore.setCharacterSize(16);
	tScore.setFillColor(Color::White);

	tHealth.setFont(font);
	tHealth.setString(printHealth + to_string(3 - health));
	tHealth.setPosition(Vector2f(100, 0));
	tHealth.setCharacterSize(16);
	tHealth.setFillColor(Color::White);

	esc.setFont(font);
	esc.setCharacterSize(15);
	esc.setPosition(7, static_cast<float>(windowHeight - 20));
	esc.setString("Press Esc for exit");
	esc.setFillColor({ 255,255,255,150 });

	window.setFramerateLimit(frameLimit);
	LoadImages();
	balls.emplace_back(300, 300);
}

bool GameController::IsIntersecting(GameObject& obj1, GameObject& obj2) 
{
	float rightPaddle = obj1.right();
	float leftPaddle = obj1.left();
	float topPaddle = obj1.top();
	float bottomPaddle = obj1.bottom();
	float leftBonus = obj2.left();
	float rightBonus = obj2.right();
	float topBonus = obj2.top();
	float bottomBonus = obj2.bottom();

	return(obj1.right() >= obj2.left() && obj1.left() <= obj2.right() && obj1.bottom() >= obj2.top() && obj1.top() <= obj2.bottom());
}

void GameController::testCollision(Ball& white, Ball& red) 
{
	if (!IsIntersecting(white, red)) 
	{
		return;
	}

	float overlapLeft = white.right() - red.left();
	float overlapRight = red.right() - white.left();
	float overlapTop = white.bottom() - red.top();
	float overlapBottom = red.bottom() - white.top();

	bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));
	bool ballFromTop(abs(overlapTop) < abs(overlapBottom));

	float minOverlapX = ballFromLeft ? overlapLeft : overlapRight;
	float minOverlapY = ballFromTop ? overlapTop : overlapBottom;

	if (abs(minOverlapX) < abs(minOverlapY)) 
	{
		white.velocity.x = (ballFromLeft ? -abs(white.velocity.x) : abs(white.velocity.y));
		red.velocity.x = (ballFromLeft ? abs(red.velocity.x) : -abs(red.velocity.y));
	}
	else 
	{
		white.velocity.y = (ballFromTop ? -abs(white.velocity.x) : abs(white.velocity.y));
		red.velocity.y = (ballFromTop ? abs(red.velocity.x) : -abs(red.velocity.y));
	}
}

bool GameController::testCollision(Paddle& racket, Bonus& bonus) 
{
	if (!(racket.right() >= bonus.left() && racket.left() <= bonus.right() && racket.bottom() <= bonus.top() && racket.top() <= bonus.bottom())) 
	{
		return false;
	}
	else 
	{
		return true;
	}
}

void GameController::StartBonus(int it) 
{
	switch (bonus.type)
	{
	case CHANGE_WIDTH_PADDLE:
		if (testCollision(paddle, bonus))
		{
			paddle.IncraseWidth();
			bonus.isActive = false;
			bonus.SetType(++bonus.type);
			break;
		}
		else
		{
			bonus.isActive = false;
			bonus.SetType(++bonus.type);
			break;
		}
	case DECREASE_SPEEDBALL:
		if (testCollision(paddle, bonus))
		{
			bonus.isActive = false;
			bonus.SetType(++bonus.type);
			balls[it].SpeedDown();
			break;
		}
		else
		{
			bonus.isActive = false;
			bonus.SetType(++bonus.type);
			break;
		}
	case BALL_STICKING:
		break;
	case SET_FLOOR:
		bonus.SetType(++bonus.type);
		break;
	case CHANGE_TRAJECTORY:
		bonus.isActive = false;
		balls[it].ReflectX();
		bonus.SetType(++bonus.type);
		break;
	case SECOND_BALL:
		bonus.isActive = false;
		bonus.SetType(CHANGE_WIDTH_PADDLE);
		break;
	}
}

void GameController::DrawGameOver() 
{
	window.draw(gameOverBackground);
	window.display();
}

void GameController::DrawGameWinner() 
{
	window.draw(gameWinnerBackground);
	window.display();
}

void GameController::DrawField() 
{
	window.draw(gamePlayBackground);
	for (auto& block : blocks)
	{
		window.draw(block); window.draw(block);
	}
	if (bonus.isActive) 
	{
		window.draw(bonus);
	}
	if (bonus.floor.active == true)
	{
		window.draw(bonus.floor.rect);
	}
	for (auto& ball : balls) 
	{
		window.draw(ball);
	}
	window.draw(paddle);

	tScore.setString(printScore + to_string(score));
	esc.setString("Press Esc for exit");
	tHealth.setString(printHealth + to_string(3 - health));
	
	window.draw(tScore);
	window.draw(esc);
	window.draw(tHealth);

	window.display();
}

bool GameController::IsCollisionPaddle(GameObject& paddle, Ball& ball) 
{
	if (!IsIntersecting(ball, paddle))
	{
		return false;
	}
	ball.moveUp();
	if (bonus.floor.active) 
	{
		return true;
	}
	float coef = 0.025f;
	if (ball.getPosition().x < paddle.getPosition().x) 
	{
		if (ball.velocity.x > 0) 
		{
			ball.velocity.x = ball.ballVelocity + coef * fabs(paddle.getPosition().x - ball.getPosition().x);
		}
		else 
		{
			ball.velocity.x = -ball.ballVelocity + coef * fabs(ball.getPosition().x - paddle.getPosition().x);
		}
	}
	else if (ball.getPosition().x > paddle.getPosition().x) 
	{
		if (ball.velocity.x > 0) 
		{
			ball.velocity.x = ball.ballVelocity + coef * fabs(ball.getPosition().x - paddle.getPosition().x);
		}
		else 
		{
			ball.velocity.x = -ball.ballVelocity + coef * fabs(paddle.getPosition().x - ball.getPosition().x);
		}
	}
	return true;
}

void GameController::HandleCollisionBlock(Block& block, Ball& ball) 
{
	switch (block.type)
	{
	case ORDINARY:
		block.destroy();
		break;
	case NOT_DESTROYED:
		break;
	case WITH_BONUS:
		block.destroy();
		bonus.isActive = true;
		bonus.SetPosition(block.getPosition());

		if (bonus.type == SET_FLOOR)
		{
			bonus.floor.active = true;
		}
		break;
	case INCREASE_SPEED:
		ball.SpeedUp();
		block.destroy();
		break;
	case WITH_HEALTH:
		if (block.withHealth.lvl != 0) 
		{
			block.withHealth.lvl--;
			block.SetColor(block.type);
		}
		else 
		{
			block.destroy();
		}
		break;
	default:
		break;
	}

}

bool GameController::IsCollisionBlock(Block& block, Ball& ball) 
{
	if (!IsIntersecting(block, ball))
	{ 
		return false;
	}

	HandleCollisionBlock(block, ball);

	float overlapLeft = ball.right() - block.left();
	float overlapRight = block.right() - ball.left();
	float overlapTop = ball.bottom() - block.top();
	float overlapBottom = block.bottom() - ball.top();
	float minOverlapX, minOverlapY;

	bool ballFromLeft = fabs(overlapLeft) < fabs(overlapRight);
	bool ballFromTop = fabs(overlapTop) < fabs(overlapBottom);
	if (ballFromLeft)
	{
		minOverlapX = overlapLeft;
	}
	else
	{
		minOverlapX = overlapRight;
	}

	if (ballFromTop)
	{
		minOverlapY = overlapTop;
	}
	else
	{
		minOverlapY = overlapBottom;
	}

	if (fabs(minOverlapX) < fabs(minOverlapY)) 
	{
		ballFromLeft ? ball.moveLeft() : ball.moveRight();
	}
	else 
	{
		ballFromTop ? ball.moveUp() : ball.moveDown();
	}

	return true;
}

void GameController::SetBlocksToDefualt() 
{
	blocks.clear();
	for (int i = 1; i < (int)blocksY; i++) 
	{
		for (int j = 0; j < (int)blocksX; j++)
		{
			blocks.emplace_back(20 + (j + 1) * (blockWidth + 4), (i + 1) * (blockHeight + 4), blockWidth, blockHeight);
		}
	}
	int i = 0, j = 0, type = 0;
	// only for placing blocks on the field
	for (auto& block : blocks) 
	{
		if (i < 20) 
		{
			type = ORDINARY;
		}
		else if (i <= 30 && i >= 20 || i == 58 ) 
		{
			type = WITH_HEALTH;
		}
		else if (i == 31 || i == 32 || i == 35 || i == 36 || i == 41 || i == 48) 
		{
			type = NOT_DESTROYED;
		}
		else if (i == 33 || i == 34 || i == 37 || i == 38 || i == 40 || i == 49 || i == 50 || i == 59) 
		{
			type = INCREASE_SPEED;
		}
		else if (i == 41 || i == 42 || i == 43 || i == 44 || i == 45 || i == 46 || i == 47 || i == 48) 
		{
			type = WITH_BONUS;
		}
		else if (i % 2 == 0 || i == 57 || i == 55 || i == 53)
		{
			type = WITH_BONUS;
		}
		else 
		{
			type = WITH_HEALTH;
		}

		block.SetColor(type);
		i++;
	}

	paddle.SetDefualtWidth();
	bonus.isActive = false;
	bonus.floor.active = false;
	bonus.type = CHANGE_WIDTH_PADDLE; // start bonus, mb change to random bonus
	for (auto& ball : balls) 
	{
		ball.SetSpeedDefualt();
		ball.updatePosition(300, 300);
	}
}

void GameController::RunGame() 
{
	int visibleBlocks = 0;

	if (Keyboard::isKeyPressed(Keyboard::Key::Enter)) 
	{ // restart
		SetBlocksToDefualt();
		GAMESTATE = STATES::GAMEPLAY;
		sleep(milliseconds(150));
		return;
	}

	auto itBall = balls.begin();
	vector<Ball> ::iterator itBallToDelete;
	int i = 0;
	bool thereAreBallToDelete = false;

	for (auto& ball : balls) 
	{
		if (bonus.isActive) 
		{
			if (bonus.update(windowWidth, windowHeight)) 
			{
				Clock.restart();
			}
			else 
			{
				StartBonus(i);
			}
		}

		if (bonus.floor.active && IsCollisionPaddle(bonus.floor.rect, ball)) 
		{
			bonus.floor.active = false;
		}
		if (!ball.update(windowWidth, windowHeight)) 
		{ //the ball touched the bottom
			if (balls.size() == 1) 
			{
				if (health >= 2) 
				{
					GAMESTATE = STATES::GAME_OVER;
					health = 0;
					score = 0;
				}
				else 
				{
					balls.emplace_back(300, 300);
					sleep(seconds(1.0f));
					health++;
					return;
				}
			}
			else 
			{
				thereAreBallToDelete = true;
				itBallToDelete = itBall;
			}
		}

		paddle.update(windowWidth);

		if (IsCollisionPaddle(paddle, ball)) 
		{
			if (bonus.isActive && bonus.type == BALL_STICKING)
			{
				if (Clock.getElapsedTime().asSeconds() >= 2.5) 
				{
					bonus.isActive = false;
					bonus.SetType(++bonus.type);
				}
				else 
				{
					ball.setPosition(paddle.getPosition());
					ball.FollowPaddle(paddle.getVelocity());
				}
			}
		}

		auto it = blocks.begin();
		visibleBlocks = 0;
		for (auto& block : blocks) 
		{
			visibleBlocks++;
			if (IsCollisionBlock(block, ball) && block.isDestroyed()) 
			{
				blocks.erase(it);
				if (block.type == WITH_HEALTH)
				{
					score += 3;
				}
				else if (block.type == NOT_DESTROYED || block.type == ORDINARY || block.type == WITH_BONUS || block.type == INCREASE_SPEED)
				{
					score++;
				}
				break;
			}
			it++;
		}
		itBall++;
		i++;
	}

	if (bonus.isActive && bonus.type == SECOND_BALL) 
	{ // if bonus second ball
		bonus.isActive = false;
		bonus.SetType(0);
		balls.emplace_back(300, 300);
	}
	if (thereAreBallToDelete) 
	{
		balls.erase(itBallToDelete);
	}
	if (visibleBlocks == 5) 
	{ // there are no blocks
		for (auto& block : blocks) 
		{
			if (block.type != NOT_DESTROYED)
			{
				return;
			}
		}
		GAMESTATE = STATES::WINNER;
		health = 0; 
		score = 0;
	}
}

void GameController::LoadImages() 
{
	string img = "back2.jpg";
	if (!gamePlayBackgroundTexture.loadFromFile(img)) 
	{
		cout << "Error loading image " << img << endl;
	}
	gamePlayBackground.setTexture(gamePlayBackgroundTexture);
	gamePlayBackground.setColor(sf::Color(255, 255, 255, 255));

	img = "gameOver3.jpg";
	if (!gameOverBackgroundTexture.loadFromFile(img)) 
	{
		cout << "Error loading image " << img << endl;
	}
	gameOverBackground.setTexture(gameOverBackgroundTexture);
	gameOverBackground.setColor(sf::Color(255, 255, 255, 255));

	img = "gameWinner2.png";
	if (!gameWinnerBackgroundTexture.loadFromFile(img)) 
	{
		cout << "Error loading image " << img << endl;
	}
	gameWinnerBackground.setTexture(gameWinnerBackgroundTexture);
	gameWinnerBackground.setColor(sf::Color(255, 255, 255, 255));
}