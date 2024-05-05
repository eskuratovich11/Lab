#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(360, 360), "SFML");
    window.setFramerateLimit(60);
    sf::CircleShape shape(180);
    shape.setFillColor(sf::Color::Blue);
    sf::Font font;
    if (!font.loadFromFile("res/tnr_font.ttf"))
    {
        throw std::exception();
    }
    sf::Text text("Text",font,25);
    text.setPosition(150,0);
    sf::Music music;
    if(!music.openFromFile("res/music.ogg")){
        throw std::exception();
    }
    sf::Event event{};
    music.play();
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
                music.stop();
            }
        }
        window.clear();
        window.draw(shape);
        window.draw(text);
        window.display();
    }

    return 0;
}