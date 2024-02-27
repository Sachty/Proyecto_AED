

#include <SFML/Graphics.hpp>


int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Treap");
    sf::String userInput;
    sf::Text text;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode < 128) {
                    userInput += event.text.unicode;
                    text.setString(userInput);
                }
            }
        }
        window.clear();
        window.draw(text);
        window.display();
    }




    return 0;
}
