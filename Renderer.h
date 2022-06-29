#pragma once
#include <SFML/Graphics.hpp>
#include <list>

class Renderer {
private:
	std::list<sf::Drawable*> drawables;
public:
	void AddDrawable(sf::Drawable* drawable);
	void Render(sf::RenderWindow* window);
};

void Renderer::AddDrawable(sf::Drawable* drawable) {
	drawables.push_back(drawable);
}

void Renderer::Render(sf::RenderWindow* window) {
	std::list<sf::Drawable*>::iterator it;
	window->clear();
	for (it = drawables.begin(); it != drawables.end(); it++) {
		window->draw(**it);
	}
	window->display();
}
