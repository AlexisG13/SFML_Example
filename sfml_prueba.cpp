#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
// -lsfml-graphics -lsfml-window -lsfml-system
int main() 
{   
    sf::Texture arbolito;
    arbolito.loadFromFile("textures/arbol.png");
    sf::Sprite arbol;
    arbol.setTexture(arbolito);
    arbol.setTextureRect(sf::IntRect(0,32,64,64));
    arbol.setPosition(320,320);
    sf::Texture link;
    link.loadFromFile("textures/linksheet.png");
    sf::Sprite linkNormal;
    linkNormal.setTexture(link);
    linkNormal.setTextureRect(sf::IntRect(0,0,32,32));
    sf::Sprite grass_tile;
    sf::Sprite pantalla[20][20];
    for(int i = 0;i<20;i++){
        for(int j = 0;j<20;j++){
            pantalla[i][j] = sf::Sprite(arbolito);
            pantalla[i][j].setTextureRect(sf::IntRect(0,0,32,32));
            pantalla[i][j].setPosition(i*32,j*32);
        }
    }
    sf::RenderWindow window(sf::VideoMode(640, 640), "FP_LABO_09",sf::Style::Close);
    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            linkNormal.setTextureRect(sf::IntRect(0,0,32,32));
            linkNormal.move(0,0.1f);
            if(linkNormal.getGlobalBounds().intersects(arbol.getGlobalBounds())){
                linkNormal.move(0,-1);
                cout << "Estoy colisionando :o" << endl;
            }
            }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            linkNormal.setTextureRect(sf::IntRect(64,0,32,32));
            linkNormal.move(0,-0.1f);
            if(linkNormal.getGlobalBounds().intersects(arbol.getGlobalBounds())){
                linkNormal.move(0,0.1f);
                cout << "Estoy colisionando :o" << endl;
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            linkNormal.setTextureRect(sf::IntRect(96,0,32,32));
            linkNormal.move(-0.1f,0);
            if(linkNormal.getGlobalBounds().intersects(arbol.getGlobalBounds())){
                linkNormal.move(0.1f,0);
                cout << "Estoy colisionando :o" << endl;
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            linkNormal.setTextureRect(sf::IntRect(32,0,32,32)); 
            linkNormal.move(0.1f,0);
            if(linkNormal.getGlobalBounds().intersects(arbol.getGlobalBounds())){
                linkNormal.move(-0.1f,0);
                cout << "Estoy colisionando :o" << endl;
            }
        }
        
        window.clear(sf::Color::Black);
        for(int i = 0;i<20;i++){
        for(int j = 0;j<20;j++){
            window.draw(pantalla[i][j]);
        }
        }
        window.draw(arbol);
        window.draw(linkNormal);
        window.display();
    }

    return 0;
}