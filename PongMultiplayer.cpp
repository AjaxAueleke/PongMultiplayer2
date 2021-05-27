// Pong.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "bat.h"
#include "ball.h"
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
    int speed = 0;

    Clock clock;
    Time td = clock.restart();
    RenderWindow window(VideoMode(800, 600), "Pong", Style::Default);
    Ball ball(Vector2f(300, 50));
    Font font;
    if (font.loadFromFile("font/ds_digital/DS-DIGI.TTF"))
    {
        std::cout << "FONT loaded correctly" << std::endl;
    }
    Text text, text2,text3,text4;
    Text paused_text;

    paused_text.setFont(font);
    paused_text.setString("Press Enter to play");
    paused_text.setCharacterSize(30);
    paused_text.setFillColor(Color::White);
    paused_text.setPosition(200, 200);
    // select the font
    text.setFont(font); // font is a sf::Font
    text2.setFont(font);
    text3.setFont(font);
    text4.setFont(font);
    // set the string to display
    text2.setString("");
    // set the character size
    text.setCharacterSize(32); // in pixels, not points!
    text2.setCharacterSize(32);
    // set the color
    text.setFillColor(sf::Color::White);
    text2.setFillColor(sf::Color::White);
    text2.setPosition(Vector2f(670, 0));
    Bat bat(3, 300);
    Bat bat2(795, 300);
    bool paused = true;
    int score1 = 0;
    int score2 = 0;
    std::string score_s;
    std::string lives_s;
    std::stringstream ss, ss2;
    std::string hud1, hud2,hud3,hud4;
    while (window.isOpen())
    {
        hud1 = "SCORE : ";
        hud1.append(std::to_string(score1));
        hud2 = "SCORE : ";
        hud2.append(std::to_string(score2));
        text.setString(hud1);
        text2.setString(hud2);

        // std::cout << hud << std::endl;
        Event event;
        while (window.pollEvent(event))
        {

            if (event.type == Event::Closed)
            {
                window.close();
            }

            if (event.type == Event::KeyPressed)
            {
                if (event.key.code == Keyboard::P)
                {
                    paused = true;
                }
                if (event.key.code == Keyboard::Enter)
                {
                    paused = false;
                    ball.setSpeed(20, 20);
                }
                if (!paused)
                {
                    if (event.key.code == Keyboard::Up)
                    {
                        bat.Move(-20);
                    }
                    else if (event.key.code == Keyboard::Down)
                    {
                        bat.Move(20);
                    }
                    if (event.key.code == Keyboard::W) {
                        bat2.Move(-20);

                    }
                    else if (event.key.code == Keyboard::S) {
                        bat2.Move(20);
                    }



                }
                if (event.key.code == Keyboard::Escape)
                {
                    window.close();
                }
            }
        }
        // std::cout << "ball pos " << ball.m_getShape().getPosition().y  << std::endl;
        if (!paused)
        {
            if (ball.m_getShape().getPosition().x > 900)
            {
                ball.setPosition(Vector2f(400, 30));
                score1++;
                if (score1  > 3)
                {
                    score1 = 0;
                    paused_text.setString("PLAYER 1 WINS! PRESS ENTER TO START A NEW GAME!");
                    paused = true;
                    score2 = 0;
                }
                if (score2 > 3){
                    
                    score2 = 0;
                    paused_text.setString("PLAYER 2 WINS! PRESS ENTER TO START A NEW GAME!");
                    paused = true;
                    score1 = 0;
                }
            }
            if (ball.m_getShape().getPosition().x < -100) {
                ball.setPosition(Vector2f(400, 30));
                score2++;
                if (score1 > 3)
                {
                    score1 = 0;
                    paused_text.setString("PLAYER 1 WINS! PRESS ENTER TO START A NEW GAME!");
                    paused = true;
                    score2 = 0;
                    
                }
                if (score2 > 3) {

                    score2 = 0;
                    paused_text.setString("PLAYER 2 WINS! PRESS ENTER TO START A NEW GAME!");
                    paused = true;
                    score1 = 0;
                }

            }
        }

        window.clear();

        if (!paused)
        {
            ball.move(td);

        }
        else
        {
            window.draw(paused_text);
        }
        
        speed += 0.01;
        ball.collision_bat(bat, td, speed);
        ball.collision_bat(bat2, td, speed);

        ball.collision_sides();
        window.draw(bat2.m_getShape());
        window.draw(ball.m_getShape());
        window.draw(text);
        window.draw(bat.m_getShape());
        window.draw(text2);
        window.display();

    }

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
