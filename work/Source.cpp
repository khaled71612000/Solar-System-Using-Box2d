#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

using namespace sf;
using namespace std;

#define PI 22/7.0f

float getMagnitude(Vector2f p0, Vector2f p1) {
    return sqrt(((p0.x - p1.x) * (p0.x - p1.x)) + ((p0.y - p1.y) * (p0.y - p1.y)));
}


ConvexShape getCircle(Vector2f center, float radius, float MouseAngle, float RotateAngle)
{

    int pointsCount = 30;
    float deltaAngle = (2.0f * PI - (2 * PI / MouseAngle)) / (pointsCount - 2);
    float angle = RotateAngle;
    ConvexShape circle(30);
    circle.setPoint(0, Vector2f(center.x, center.y));

    for (size_t i = 1; i < pointsCount; i++)
    {

        float x = radius * cos(angle + (PI / MouseAngle)) + center.x;
        float y = radius * sin(angle + (PI / MouseAngle)) + center.y;
        circle.setPoint(i, Vector2f(x, y));
        angle += deltaAngle;

    }
    return circle;
}



int main()

{

    RenderWindow window(VideoMode(800, 800), "FOV");

    CircleShape circle1(20);
    circle1.setOrigin(20, 20);
    circle1.setPosition(400,400);
    circle1.setFillColor(Color(11, 70, 25));

    ConvexShape shape = getCircle((Vector2f)circle1.getPosition(), 150, 1.3, 0);

    CircleShape circle2(20);
    circle2.setPosition(100,100);
    circle2.setFillColor(Color(232, 232, 204));

    while (window.isOpen())
    {
        float moused = getMagnitude(circle1.getPosition(), (Vector2f)Mouse::getPosition(window));
        float mousex = circle1.getPosition().x - Mouse::getPosition(window).x;

        float angle = acos(mousex / moused);

        if (Mouse::getPosition(window).y > circle1.getPosition().y) {
            angle = -angle;
        }
        shape = getCircle((Vector2f)circle1.getPosition(), 150, 1.3, angle);
        shape.setFillColor(Color::Green);


        Event event;
        float x1 = circle2.getPosition().x + circle2.getRadius();
        float y1 = circle2.getPosition().y + circle2.getRadius();

        if (shape.getGlobalBounds().contains(Vector2f(x1, y1))) {
            shape.setFillColor(Color::Red);
        }
        else
        {
            shape.setFillColor(Color(117, 49, 136));
        }


        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed)
            {

                switch (event.key.code)
                {
                case Keyboard::D:
                    circle1.setPosition(circle1.getPosition() + Vector2f(20.0f, 0));
                    break;
                case  Keyboard::A:
                    circle1.setPosition(circle1.getPosition() + Vector2f(-20.0f, 0));
                    break;
                case  Keyboard::S:
                    circle1.setPosition(circle1.getPosition() + Vector2f(0, 20.0f));
                    break;
                case  Keyboard::W:
                    circle1.setPosition(circle1.getPosition() + Vector2f(0, -20.0f));
                    break;
                default:
                    break;
                }

            }
        }

        window.clear(Color(255, 204, 29));
        window.draw(shape);
        window.draw(circle2);
        window.draw(circle1);
        window.display();

    }


}