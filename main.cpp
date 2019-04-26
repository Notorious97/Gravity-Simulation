#include<SFML/Graphics.hpp>
#include<cmath>
#include<iostream>
using namespace sf;

int main(){
    RenderWindow window(VideoMode(1500, 800), "Window");
    CircleShape c1(50);
    c1.setOrigin(50, 50);
    c1.setFillColor(Color::Yellow);
    c1.setPosition(Vector2f(750, 400));


    CircleShape c2(20);
    c2.setOrigin(20, 20);
    c2.setFillColor(Color::Blue);
    c2.setPosition(Vector2f(50, 50));

    float mass = 20;
    float vx=0.2,vy=0; // Initial velocity of Blue sprite
    sf::VertexArray vertices;
    vertices.setPrimitiveType(sf::PrimitiveType::LinesStrip);




    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            if(event.type == Event::Closed){
                window.close();
            }
        }

        if(Mouse::isButtonPressed(Mouse::Left)){
            c1.setPosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
        }
        float a = c1.getPosition().x - c2.getPosition().x;
        float b = c1.getPosition().y - c2.getPosition().y;
        float acc = (mass)/(a*a + b*b);
        float accx = (acc*a)/(sqrt(a*a + b*b));
        float accy = (acc*b)/(sqrt(a*a + b*b));
        vertices.append(Vertex(Vector2f(c2.getPosition().x, c2.getPosition().y)));
        vx += accx;
        vy += accy;
        c2.move(vx, vy);

        window.clear();
        window.draw(vertices);
        window.draw(c1);
        window.draw(c2);

        window.display();

    }
        return 0;

}
