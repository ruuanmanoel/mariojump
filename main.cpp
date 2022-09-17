#include "SFML/Graphics.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Jump Mario");
	window.setFramerateLimit(60);

	sf::Texture t1, t2, t3, t4, t5, t6;
	t1.loadFromFile("img/ceu.png");
	t2.loadFromFile("img/nuvem1.png");
	t3.loadFromFile("img/chao.png");
	t4.loadFromFile("img/montanha.png");
	t5.loadFromFile("img/cano.png");
	t6.loadFromFile("img/mario.png");
	t3.setRepeated(true);
	t4.setRepeated(true);
	float currentFrame = 0.0;
	sf::Sprite sCeu(t1), sNuvem(t2), sChao(t3), sMontanha(t4), sMontanha1(t4), sCano(t5), sPersonagem(t6, sf::IntRect(175 * currentFrame, 0, 175, 351));
	sChao.setTextureRect({ 0,0,1601,600 });
	sMontanha.setTextureRect({ 0, 0, 800,351 });
	sMontanha.setScale(2, 1);
	sNuvem.setScale(1.3, 1.3);
	sMontanha.setPosition(0, 200);
	sPersonagem.setPosition(0, 375);
	sPersonagem.setScale(0.5, 0.5);

	sNuvem.setPosition(801, 10);
	sChao.setPosition(0, 550);
	sCano.setPosition(801, 410);
	sCano.setScale(0.5, 0.5);




	sf::Clock clock;

	sf::Event event;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::Closed)
			{
				window.close();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && sPersonagem.getPosition().y == 375)
			{

				sPersonagem.move(0, -50);
			}


		}
		if (sPersonagem.getPosition().y < 375)
		{
			sPersonagem.move(0, 3);
			sPersonagem.setTextureRect(sf::IntRect(0, 352, 175, 352));
		}
		if (clock.getElapsedTime().asSeconds() > 0.05f && sPersonagem.getPosition().y == 375)
		{
			if (currentFrame > 3)
			{
				currentFrame = 0;
			}
			else
			{
				currentFrame += 0.5f;
				sPersonagem.setTextureRect(sf::IntRect(175 * (int)currentFrame, 0, 175, 351));
			}
			clock.restart();
		}
		if (sNuvem.getPosition().x < -800)
		{
			sNuvem.setPosition(801, 10);

		}
		else
		{
			sNuvem.move(-2, 0);

		}if (sChao.getPosition().x < -800)
		{
			sChao.setPosition(0, 550);
		}
		else
		{
			sChao.move(-8, 0);
		}
		if (sMontanha.getPosition().x < -1600)
		{
			sMontanha.setPosition(0, 200);
		}
		else
		{
			sMontanha.move(-4, 0);
		}
		if (sCano.getPosition().x < -1160)
		{
			sCano.setPosition(801, 410);
		}
		else
		{
			sCano.move(-8, 0);
		}

		window.draw(sCeu);
		window.draw(sNuvem);
		window.draw(sChao);
		window.draw(sCano);
		window.draw(sPersonagem);
		window.display();

	}
}