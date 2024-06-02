#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <SFML/Audio.hpp>
#include <string>
#include "Menu.h"
#include "Menu.cpp"
#include <iostream>
#include <cmath>
#include <fstream>
sf::RenderWindow window(sf::VideoMode(1400, 900), "                                                                                                                  ....PACMAN....");

// char map[][23] =
//     {
//         {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
//         {' ', ' ', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#', '#', '#', '#', ' ', ' '},
//         {' ', ' ', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', ' ', ' '},
//         {' ', ' ', '#', '.', '#', '.', '#', '.', '#', '#', '#', '.', '.', '#', '#', '#', '.', '#', '#', 'o', '#', ' ', ' '},
//         {' ', ' ', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', ' ', ' '},
//         {' ', ' ', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '.', '#', '.', '#', '.', '#', '#', '.', '#', ' ', ' '},
//         {' ', ' ', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '.', '.', '.', '#', '.', '.', '.', '.', '#', ' ', ' '},
//         {' ', ' ', '.', '.', '.', '.', '.', '.', '.', '.', ' ', '.', ' ', '.', '.', '.', '.', '.', '.', '.', '.', ' ', ' '},
//         {' ', ' ', '#', '#', '#', '.', '#', '#', '#', '.', '#', '#', '#', '.', '#', '.', '#', '#', '#', '#', '#', ' ', ' '},
//         {' ', '.', '#', '.', '#', '.', '#', '.', ' ', '.', '#', '=', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', ' '},
//         {' ', '.', '#', '#', '#', '.', '#', ' ', ' ', '.', '#', '#', '#', '.', '#', '.', '#', ' ', '#', '.', '#', ' ', ' '},
//         {' ', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', ' '},
//         {' ', ' ', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#', ' ', ' '},
//         {' ', ' ', '#', '.', '#', '.', '#', '#', '#', '.', '#', '.', '#', '#', '#', '.', '#', '.', '#', '.', '#', ' ', ' '},
//         {' ', ' ', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', ' ', ' '},
//         {' ', ' ', '#', '.', '#', '#', '.', '#', '#', '#', '.', '#', '.', '#', '#', '#', '.', '#', '#', '.', '#', ' ', ' '},
//         {' ', ' ', '#', 'o', '.', '#', '.', '.', '.', '.', '.', 'P', '.', '.', '.', '.', '.', '#', '.', 'o', '#', ' ', ' '},
//         {' ', ' ', '#', '#', '.', '#', '.', '#', '.', '#', '#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '#', ' ', ' '},
//         {' ', ' ', '#', '.', '.', '.', '.', '#', '.', '.', '.', '#', '.', '.', '.', '#', '.', '.', '.', '.', '#', ' ', ' '},
//         {' ', ' ', '#', '.', '#', '#', '#', '#', '#', '#', '.', '#', '.', '#', '#', '#', '#', '#', '#', '.', '#', ' ', ' '},
//         {' ', ' ', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', ' ', ' '},
//         {' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', ' '},
//         {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
// };

char map[][23] =
    {
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', ' '},
        {' ', ' ', '#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '#', ' ', ' '},
        {' ', ' ', '#', 'o', '#', '#', '.', '#', '#', '#', '.', '#', '.', '#', '#', '#', '.', '#', '#', 'o', '#', ' ', ' '},
        {' ', ' ', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', ' ', ' '},
        {' ', ' ', '#', '.', '#', '#', '.', '#', '.', '#', '#', '#', '#', '#', '.', '#', '.', '#', '#', '.', '#', ' ', ' '},
        {' ', ' ', '#', '.', '.', '.', '.', '#', '.', '.', '.', '#', '.', '.', '.', '#', '.', '.', '.', '.', '#', ' ', ' '},
        {' ', ' ', '#', '#', '#', '#', '.', '#', '#', '#', ' ', '#', ' ', '#', '#', '#', '.', '#', '#', '#', '#', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', '#', '.', '#', ' ', ' ', ' ', '0', ' ', ' ', ' ', '#', '.', '#', ' ', ' ', ' ', ' ', ' '},
        {' ', '#', '#', '#', '#', '#', '.', '#', ' ', '#', '#', '=', '#', '#', ' ', '#', '.', '#', '#', '#', '#', '#', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', '.', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', '.', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', '#', '#', '#', '#', '#', '.', '#', ' ', '#', '#', '#', '#', '#', ' ', '#', '.', '#', '#', '#', '#', '#', ' '},
        {' ', ' ', ' ', ' ', ' ', '#', '.', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '.', '#', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', '#', '#', '#', '#', '.', '#', ' ', '#', '#', '#', '#', '#', ' ', '#', '.', '#', '#', '#', '#', ' ', ' '},
        {' ', ' ', '#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '#', ' ', ' '},
        {' ', ' ', '#', '.', '#', '#', '.', '#', '#', '#', '.', '#', '.', '#', '#', '#', '.', '#', '#', '.', '#', ' ', ' '},
        {' ', ' ', '#', 'o', '.', '#', '.', '.', '.', '.', '.', 'P', '.', '.', '.', '.', '.', '#', '.', 'o', '#', ' ', ' '},
        {' ', ' ', '#', '#', '.', '#', '.', '#', '.', '#', '#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '#', ' ', ' '},
        {' ', ' ', '#', '.', '.', '.', '.', '#', '.', '.', '.', '#', '.', '.', '.', '#', '.', '.', '.', '.', '#', ' ', ' '},
        {' ', ' ', '#', '.', '#', '#', '#', '#', '#', '#', '.', '#', '.', '#', '#', '#', '#', '#', '#', '.', '#', ' ', ' '},
        {' ', ' ', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', ' ', ' '},
        {' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
};
class Game_components
{
protected:
    sf::CircleShape character;
    int pos_x;
    int pos_y;
    float looking_vertical;
    float looking_horizontal;
    sf::Texture texture, bgimage, cbgimage;
    sf::Sprite sprite;
    sf::Font fon;
    sf::Text control, control1, control2, control3, control4, control5;
    sf::RectangleShape background, cbackground;

public:
    void startfun()
    {
    game:
        sf::SoundBuffer buffer;
        sf::Sound gamestart, gamesound;
        if (!buffer.loadFromFile("audio/eat_fruit.wav"))
            ;

        gamestart.setBuffer(buffer);
        Menu menu(window.getSize().x, window.getSize().y);
        // set background image
        background.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
        if (!bgimage.loadFromFile("img/bgimage2.jpg"))
            ;
        background.setTexture(&bgimage);
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                switch (event.type)
                {
                case sf::Event::KeyReleased: // control in moving in the start menu
                    gamestart.play();

                    switch (event.key.code)
                    {
                    case sf::Keyboard::Up:
                        menu.MoveUp();
                        break;
                    case sf::Keyboard::Down:
                        menu.MoveDown();
                        break;
                    case sf::Keyboard::Return: // control on the enter button
                        switch (menu.PressedItem())
                        {
                        case 0:
                            return;
                            // game starting function
                            break;
                        case 1:
                            while (window.isOpen())
                            {
                                sf::Event event;
                                while (window.pollEvent(event))
                                {
                                    if (event.type == sf::Event::Closed)
                                    {
                                        window.close();
                                    }
                                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace))
                                    {
                                        goto game;
                                    }
                                }
                                sf::Font font;
                                font.loadFromFile("font/Minecraft.ttf");
                                control.setFont(font);
                                control.setPosition(1000, 800);
                                control.setFillColor(sf::Color::White);
                                control.setCharacterSize(35);
                                control.setString("Press Backspace to return.");
                                int s;
                                std::ifstream infile("highscore.txt");
                                infile >> s;
                                infile.close();
                                std::string str1, str2;
                                str1 = std::to_string(s);
                                str2 = "HIGH SCORE: " + str1;
                                cbackground.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
                                if (!cbgimage.loadFromFile("img/bgimage3.jpg"))
                                    ;
                                cbackground.setTexture(&cbgimage);

                                sf::Text text;
                                text.setFont(font);
                                text.setCharacterSize(75);
                                text.setFillColor(sf::Color::Magenta);
                                text.setString(str2);
                                text.setPosition(300, 300);
                                window.clear();
                                window.draw(cbackground);
                                window.draw(text);

                                window.draw(control);
                                window.display();
                            }

                            break;
                        case 2:
                            // open controls
                            controlfun();
                            while (window.isOpen())
                            {
                                sf::Event event;
                                while (window.pollEvent(event))
                                {
                                    if (event.type == sf::Event::Closed)
                                    {
                                        window.close();
                                    }
                                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace))
                                    {
                                        goto game;
                                    }
                                }
                                window.clear();
                                window.draw(cbackground);
                                window.draw(control);
                                window.draw(control1);
                                window.draw(control2);
                                window.draw(control3);
                                window.draw(control4);
                                window.draw(control5);
                                window.display();
                            }

                            break;
                        case 3:
                            exit(0);
                            break;
                        }
                        break;
                    }
                    break;
                case sf::Event::Closed:
                    window.close();
                    break;
                }
            }
            window.clear();
            window.draw(background);
            menu.draw(window);

            window.display();
        }
    }
    void controlfun()
    {
        cbackground.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
        if (!cbgimage.loadFromFile("img/bgimage3.jpg"))
            ;
        cbackground.setTexture(&cbgimage);
        if (!fon.loadFromFile("font/font.ttf"))
        {
            std::cout << "Error";
        }
        control.setFont(fon);
        control.setPosition(500, 300);
        control.setFillColor(sf::Color::White);
        control.setCharacterSize(35);
        control.setString("Press Esc to quit.");

        control1.setFont(fon);
        control1.setPosition(500, 350);
        control1.setFillColor(sf::Color::White);
        control1.setCharacterSize(35);
        control1.setString("Up: 'w'");

        control2.setFont(fon);
        control2.setPosition(500, 400);
        control2.setFillColor(sf::Color::White);
        control2.setCharacterSize(35);
        control2.setString("Down: 's'");

        control3.setFont(fon);
        control3.setPosition(500, 450);
        control3.setFillColor(sf::Color::White);
        control3.setCharacterSize(35);
        control3.setString("Left: 'a'");

        control4.setFont(fon);
        control4.setPosition(500, 500);
        control4.setFillColor(sf::Color::White);
        control4.setCharacterSize(35);
        control4.setString("Right: 'd'");

        control5.setFont(fon);
        control5.setPosition(500, 550);
        control5.setFillColor(sf::Color::White);
        control5.setCharacterSize(35);
        control5.setString("Press 'Backspace' to go the menu.");
    }
    void animation()
    {
        sf::SoundBuffer buffer;
        sf::Sound gamestart, gamesound;
        if (!buffer.loadFromFile("audio/game_start.wav"))
            ;
        gamestart.setBuffer(buffer);
        gamestart.play();
        sf::Sprite dummy1;
        sf::Sprite dummy2;
        sf::Sprite dummy3;
        sf::Sprite dummy4;
        sf::Sprite eye2;
        sf::Sprite eye3;
        sf::Sprite eye4;
        sf::Texture eyetexture;
        sf::Texture textureghost;
        sf::Texture texturepacman;
        textureghost.loadFromFile("img/Ghost16.png");
        texturepacman.loadFromFile("img/Pacman16.png");
        eyetexture.loadFromFile("img/Ghost16.png");
        eye2.setTexture(textureghost);
        eye3.setTexture(eyetexture);
        eye4.setTexture(eyetexture);
        eye2.setTextureRect(sf::IntRect(0, 16, 16, 16));
        eye2.setPosition(-250, 350);
        eye2.setScale(5, 5);
        eye3.setTextureRect(sf::IntRect(0, 16, 16, 16));
        eye3.setPosition(-400, 350);
        eye3.setScale(5, 5);
        eye4.setTextureRect(sf::IntRect(0, 16, 16, 16));
        eye4.setPosition(-550, 350);
        eye4.setScale(5, 5);
        dummy1.setTexture(texturepacman);
        dummy1.setScale(5, 5);
        dummy1.setPosition(-100, 350);
        dummy2.setTexture(textureghost);
        dummy2.setScale(5, 5);
        dummy2.setColor(sf::Color(250, 50, 10));
        dummy2.setPosition(-250, 350);
        dummy3.setTexture(textureghost);
        dummy3.setScale(5, 5);
        dummy3.setColor(sf::Color(250, 100, 245));
        dummy3.setPosition(-400, 350);
        dummy4.setTexture(textureghost);
        dummy4.setScale(5, 5);
        dummy4.setColor(sf::Color(100, 200, 250));
        dummy4.setPosition(-550, 350);
        for (int i = 1; i < 500; i++)
        {
            int select = i % 15;
            select = select / 3;
            dummy1.setTextureRect(sf::IntRect((select + 1) * 16, 0, 16, 16));
            dummy2.setTextureRect(sf::IntRect((select) * 16, 0, 16, 16));
            dummy3.setTextureRect(sf::IntRect((select) * 16, 0, 16, 16));
            dummy4.setTextureRect(sf::IntRect((select) * 16, 0, 16, 16));
            window.clear();
            window.draw(dummy1);
            window.draw(dummy2);
            window.draw(dummy3);
            window.draw(dummy4);
            window.draw(eye2);
            window.draw(eye3);
            window.draw(eye4);
            window.display();
            dummy1.move(4, 0);
            dummy2.move(4, 0);
            dummy3.move(4, 0);
            dummy4.move(4, 0);
            eye2.move(4, 0);
            eye3.move(4, 0);
            eye4.move(4, 0);
        }
        dummy4.setColor(sf::Color::Blue);
        dummy3.setColor(sf::Color::Blue);
        dummy2.setColor(sf::Color::Blue);
        eye2.setTextureRect(sf::IntRect(32, 16, 16, 16));
        eye3.setTextureRect(sf::IntRect(32, 16, 16, 16));
        eye4.setTextureRect(sf::IntRect(32, 16, 16, 16));
        gamestart.play();
        for (int i = 1; i < 500; i++)
        {
            int select = i % 15;
            select = select / 3;
            dummy1.setTextureRect(sf::IntRect((select + 1) * 16, 32, 16, 16));
            dummy2.setTextureRect(sf::IntRect((select) * 16, 0, 16, 16));
            dummy3.setTextureRect(sf::IntRect((select) * 16, 0, 16, 16));
            dummy4.setTextureRect(sf::IntRect((select) * 16, 0, 16, 16));
            window.clear();
            window.draw(dummy1);
            window.draw(dummy2);
            window.draw(dummy3);
            window.draw(dummy4);
            window.draw(eye2);
            window.draw(eye3);
            window.draw(eye4);
            window.display();
            dummy1.move(-4, 0);
            dummy2.move(-4, 0);
            dummy3.move(-4, 0);
            dummy4.move(-4, 0);
            eye2.move(-4, 0);
            eye3.move(-4, 0);
            eye4.move(-4, 0);
        }
    }
    void display_life(int l)
    {
        sf::Sprite life;
        sf::Texture life_texture;
        life_texture.loadFromFile("img/Pacman16.png");
        life.setTexture(life_texture);
        life.setTextureRect(sf::IntRect(32, 16, 16, 16));
        life.setScale(2, 2);
        for (int i = 0; i < l; i++)
        {
            life.setPosition(670, 660 - 50 * i);
            window.draw(life);
        }
    }
    void game_over(int x, int y, int s)
    {

        sf::SoundBuffer buffer;
        sf::Sound gamestart;
        if (!buffer.loadFromFile("audio/death_1.wav"))
            ;
        gamestart.setBuffer(buffer);
        gamestart.play();
        sf::Sprite death;
        sf::Texture death_texture;
        death_texture.loadFromFile("img/PacmanDeath16.png");
        death.setTexture(death_texture);
        death.setScale(2, 2);
        death.setPosition(x * 32, y * 32);
        for (int i = 0; i < 120; i++)
        {
            window.clear();
            death.setTextureRect(sf::IntRect((i / 10) * 16, 0, 16, 16));
            window.draw(death);
            window.display();
        }
        window.clear();
        std::string str1, str2;
        str1 = std::to_string(s);
        str2 = "YOUR SCORE: " + str1;
        sf::Font font;
        font.loadFromFile("font/Minecraft.ttf");
        sf::Text text;
        text.setFont(font);
        text.setCharacterSize(75);
        text.setFillColor(sf::Color::Magenta);
        text.setString(str2);
        text.setPosition(300, 300);
        window.clear();
        window.draw(text);
        window.display();
        sf::sleep(sf::seconds(2));
        startfun();
    }
    int vertical_direction()
    {
        return looking_vertical;
    }
    int horizontal_direction()
    {
        return looking_horizontal;
    }
    int x_coordinate()
    {
        return pos_x;
    }
    int y_coordinate()
    {
        return pos_y;
    }
    void update_coordinate(int x, int y)
    {
        pos_x = x;
        pos_y = y;
    }
    void update_looking_direction(int x, int y)
    {
        looking_horizontal = x;
        looking_vertical = y;
    }
    bool is_colliding_left()
    {
        if (map[pos_y][pos_x - 1] == '#')
        {
            return true;
        }
        return false;
    }
    bool is_colliding_right()
    {
        if (map[pos_y][pos_x + 1] == '#')
        {
            return true;
        }
        return false;
    }
    bool is_colliding_up()
    {
        if (map[pos_y - 1][pos_x] == '#')
        {
            return true;
        }
        return false;
    }
    bool is_colliding_down()
    {
        if (map[pos_y + 1][pos_x] == '#')
        {
            return true;
        }
        return false;
    }
};
class Pacman : public Game_components
{
private:
    int score = 0, highscore = 0;

public:
    sf::Font font;
    sf::Text username;
    Pacman()
    {
        texture.loadFromFile("img/Pacman16.png");
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
        sprite.setScale(2, 2);
    }
    void design_me()
    {
        sprite.setPosition(pos_x * 32, pos_y * 32);
    }
    void reset_score()
    {
        score = 0;
    }
    int get_score()
    {
        return score;
    }
    void update_Score(int a)
    {
        score += (10 * a);
    }
    void update_highscore()
    {
        std::ifstream infile("highscore.txt");
        infile >> highscore;
        infile.close();
        if (score > highscore)
        {
            std::ofstream outfile("highscore.txt");
            outfile << score;
            outfile.close();
        }
    }
    sf::Sprite draw_me(int select)
    {

        select = select / 3;
        if (looking_horizontal == -1)
        {
            sprite.setTextureRect(sf::IntRect((select + 1) * 16, 32, 16, 16));
        }
        if (looking_horizontal == 1)
        {
            sprite.setTextureRect(sf::IntRect((select + 1) * 16, 0, 16, 16));
        }
        if (looking_vertical == -1)
        {
            sprite.setTextureRect(sf::IntRect((select + 1) * 16, 16, 16, 16));
        }
        if (looking_vertical == 1)
        {
            sprite.setTextureRect(sf::IntRect((select + 1) * 16, 48, 16, 16));
        }
        if (looking_horizontal == 0 && looking_vertical == 0)
        {
            sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
        }

        return sprite;
    }

    void move_me()
    {
        sprite.move(looking_horizontal, looking_vertical);
    }
    friend class Ghost;
};
class Ghost : public Game_components
{
private:
    int scatter;
    int mode;
    bool frightened_status;
    int count;
    int target_x, target_y;
    sf::Sprite eyes;
    sf::Texture eyetexture;
    bool tile_travelled;
    int red, blue, green;
    bool going_home;
    bool eaten;

public:
    Ghost(int r = 0, int b = 0, int g = 0) : red(r), blue(b), green(g)
    {
        mode = 0;
        frightened_status = false;
        texture.loadFromFile("img/Ghost16.png");
        tile_travelled = true;
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
        sprite.setScale(2, 2);
        count = 0;
        eyes.setTexture(texture);
        eyes.setScale(2, 2);
        sprite.setColor(sf::Color(r, b, g));
        going_home = false;
        scatter = 0;
    }
    int get_scatter(int lev)
    {
        scatter++;
        scatter = scatter % (static_cast<int>(3 / 20.0 * red * lev));
        return scatter;
    }
    void set_target(int x, int y)
    {
        target_x = x;
        target_y = y;
        if (target_x == 11 && target_y == 10)
        {
            going_home = true;
        }
        else
        {
            going_home = false;
        }
    }
    void update_sprite()
    {
        sprite.setColor(sf::Color::Blue);
    }
    void update_count()
    {
        count++;
        if (count == 10)
        {
            count = 0;
            if (!(mode == 2))
            {
                frightened_status = false;
                sprite.setColor(sf::Color(red, blue, green));
                mode = 0;
            }
        }
    }
    bool target_is_home()
    {
        return going_home;
    }
    bool frightened()
    {
        return frightened_status;
    }
    void set_frightened()
    {
        count = 0;
        frightened_status = true;
    }
    bool full_tile_travelled()
    {
        return tile_travelled;
    }
    void update_tile_travel()
    {
        tile_travelled = !tile_travelled;
    }
    void set_mode(int x)
    {
        if (mode == 0 && x == 1)
        {
            looking_horizontal = looking_horizontal + 2 * x * -1 * looking_horizontal;
            looking_vertical = looking_vertical + 2 * x * -1 * looking_vertical;
        }
        mode = x;
    }
    void design_me()
    {
        sprite.setPosition(pos_x * 32, pos_y * 32);
        eyes.setPosition(pos_x * 32, pos_y * 32);
    }
    sf::Sprite draw_me(int select)
    {
        select = select / 3;
        sprite.setTextureRect(sf::IntRect((select) * 16, 0, 16, 16));
        if (mode == 1)
        {
            sprite.setColor(sf::Color::Blue);
        }
        if (mode == 2)
        {
            sprite.setColor(sf::Color::Black);
        }
        return sprite;
    }
    sf::Sprite draw_my_eyes()
    {
        if (mode == 1 || sprite.getColor() == sf::Color::Blue)
        {
            eyes.setTextureRect(sf::IntRect(64, 16, 16, 16));
        }
        else
        {
            if (looking_horizontal == -1)
            {
                eyes.setTextureRect(sf::IntRect(32, 16, 16, 16));
            }
            if (looking_horizontal == 1)
            {
                eyes.setTextureRect(sf::IntRect(0, 16, 16, 16));
            }
            if (looking_vertical == -1)
            {
                eyes.setTextureRect(sf::IntRect(16, 16, 16, 16));
            }
            if (looking_vertical == 1)
            {
                eyes.setTextureRect(sf::IntRect(48, 16, 16, 16));
            }
        }
        if (mode == 2)
        {
            if (looking_horizontal == -1)
            {
                eyes.setTextureRect(sf::IntRect(32, 32, 16, 16));
            }
            if (looking_horizontal == 1)
            {
                eyes.setTextureRect(sf::IntRect(0, 32, 16, 16));
            }
            if (looking_vertical == -1)
            {
                eyes.setTextureRect(sf::IntRect(16, 32, 16, 16));
            }
            if (looking_vertical == 1)
            {
                eyes.setTextureRect(sf::IntRect(48, 32, 16, 16));
            }
        }

        return eyes;
    }

    void calculate_move(Pacman pacman)
    {
        srand(time(0));

        if ((pos_x == 1) && (looking_horizontal == -1))
        {
            update_coordinate(21, pos_y);
            design_me();
        }
        if ((pos_x == 21) && (looking_horizontal == 1))
        {
            update_coordinate(1, pos_y);
            design_me();
        }
        int dist_new_position[4] = {3000, 3000, 3000, 3000};
        if (mode == 0)
        {
            if (looking_horizontal == 1)
            {
                if (!is_colliding_right())
                {
                    dist_new_position[1] = pow((pos_x + 1 - target_x), 2) + pow((pos_y - target_y), 2);
                }
                if (!is_colliding_down())
                {
                    dist_new_position[2] = pow((pos_y + 1 - target_y), 2) + pow((pos_x - target_x), 2);
                }
                if (!is_colliding_up())
                {
                    dist_new_position[3] = pow((pos_y - 1 - target_y), 2) + pow((pos_x - target_x), 2);
                }
            }
            if (looking_horizontal == -1)
            {
                if (!is_colliding_left())
                {
                    dist_new_position[0] = pow((pos_x - 1 - target_x), 2) + pow((pos_y - target_y), 2);
                }
                if (!is_colliding_down())
                {
                    dist_new_position[2] = pow((pos_y + 1 - target_y), 2) + pow((pos_x - target_x), 2);
                }
                if (!is_colliding_up())
                {
                    dist_new_position[3] = pow((pos_y - 1 - target_y), 2) + pow((pos_x - target_x), 2);
                }
            }
            if (looking_vertical == -1)
            {
                if (!is_colliding_right())
                {
                    dist_new_position[1] = pow((pos_x + 1 - target_x), 2) + pow((pos_y - target_y), 2);
                }
                if (!is_colliding_left())
                {
                    dist_new_position[0] = pow((pos_x - 1 - target_x), 2) + pow((pos_y - target_y), 2);
                }

                if (!is_colliding_up())
                {
                    dist_new_position[3] = pow((pos_y - 1 - target_y), 2) + pow((pos_x - target_x), 2);
                }
            }
            if (looking_vertical == 1)
            {

                if (!is_colliding_down())
                {
                    dist_new_position[2] = pow((pos_y + 1 - target_y), 2) + pow((pos_x - target_x), 2);
                }
                if (!is_colliding_right())
                {
                    dist_new_position[1] = pow((pos_x + 1 - target_x), 2) + pow((pos_y - target_y), 2);
                }

                if (!is_colliding_left())
                {
                    dist_new_position[0] = pow((pos_x - 1 - target_x), 2) + pow((pos_y - target_y), 2);
                }
            }
            if (!((pos_x == 11) && (pos_y == 8)))
            {

                int least = 0;
                for (int i = 1; i < 4; i++)
                {
                    if (dist_new_position[i] <= dist_new_position[0])
                    {
                        dist_new_position[0] = dist_new_position[i];
                        least = i;
                    }
                }
                if (least == 0)
                {
                    looking_vertical = 0;
                    looking_horizontal = -1;
                }
                if (least == 1)
                {
                    looking_horizontal = 1;
                    looking_vertical = 0;
                }
                if (least == 2)
                {
                    looking_vertical = 1;
                    looking_horizontal = 0;
                }
                if (least == 3)
                {
                    looking_vertical = -1;
                    looking_horizontal = 0;
                }
            }
            if ((pos_y == 10) && (pos_x == 11))
            {
                looking_horizontal = 0;
                looking_vertical = -1;
            }
            if ((pos_y == 8) && (pos_x == 11) && looking_vertical == -1)
            {
                looking_horizontal = pow(-1, rand()) * 1;
                looking_vertical = 0;
            }
        }
        if (mode == 1)
        {
            if (looking_horizontal == 1)
            {
                if (!is_colliding_right())
                {
                    dist_new_position[1] = pow((pos_x + 1 - target_x), 2) + pow((pos_y - target_y), 2) - mode * rand();
                }
                if (!is_colliding_down())
                {
                    dist_new_position[2] = pow((pos_y + 1 - target_y), 2) + pow((pos_x - target_x), 2) - mode * rand();
                }
                if (!is_colliding_up())
                {
                    dist_new_position[3] = pow((pos_y - 1 - target_y), 2) + pow((pos_x - target_x), 2) - mode * rand();
                }
            }
            if (looking_horizontal == -1)
            {
                if (!is_colliding_left())
                {
                    dist_new_position[0] = pow((pos_x - 1 - target_x), 2) + pow((pos_y - target_y), 2) - mode * rand();
                }
                if (!is_colliding_down())
                {
                    dist_new_position[2] = pow((pos_y + 1 - target_y), 2) + pow((pos_x - target_x), 2) - mode * rand();
                }
                if (!is_colliding_up())
                {
                    dist_new_position[3] = pow((pos_y - 1 - target_y), 2) + pow((pos_x - target_x), 2) - mode * rand();
                }
            }
            if (looking_vertical == -1)
            {
                if (!is_colliding_right())
                {
                    dist_new_position[1] = pow((pos_x + 1 - target_x), 2) + pow((pos_y - target_y), 2) - mode * rand();
                }
                if (!is_colliding_left())
                {
                    dist_new_position[0] = pow((pos_x - 1 - target_x), 2) + pow((pos_y - target_y), 2) - mode * rand();
                }

                if (!is_colliding_up())
                {
                    dist_new_position[3] = pow((pos_y - 1 - target_y), 2) + pow((pos_x - target_x), 2) - mode * rand();
                }
            }
            if (looking_vertical == 1)
            {

                if (!is_colliding_down())
                {
                    dist_new_position[2] = pow((pos_y + 1 - target_y), 2) + pow((pos_x - target_x), 2) - mode * rand();
                }
                if (!is_colliding_right())
                {
                    dist_new_position[1] = pow((pos_x + 1 - target_x), 2) + pow((pos_y - target_y), 2) - mode * rand();
                }

                if (!is_colliding_left())
                {
                    dist_new_position[0] = pow((pos_x - 1 - target_x), 2) + pow((pos_y - target_y), 2) - mode * rand();
                }
            }
            if (!((pos_x == 11) && (pos_y == 8)))
            {

                int least = 0;
                for (int i = 1; i < 4; i++)
                {
                    if (dist_new_position[i] <= dist_new_position[0])
                    {
                        dist_new_position[0] = dist_new_position[i];
                        least = i;
                    }
                }
                if (least == 0)
                {
                    looking_vertical = 0;
                    looking_horizontal = -1;
                }
                if (least == 1)
                {
                    looking_horizontal = 1;
                    looking_vertical = 0;
                }
                if (least == 2)
                {
                    looking_vertical = 1;
                    looking_horizontal = 0;
                }
                if (least == 3)
                {
                    looking_vertical = -1;
                    looking_horizontal = 0;
                }
            }
            if ((pos_y == 10) && (pos_x == 11))
            {
                looking_horizontal = 0;
                looking_vertical = -1;
            }
            if ((pos_y == 8) && (pos_x == 11) && looking_vertical == -1)
            {
                looking_horizontal = pow(-1, rand()) * 1;
                looking_vertical = 0;
            }
        }
        if (mode == 2)
        {
            if (looking_horizontal == 1)
            {
                if (!is_colliding_right())
                {
                    dist_new_position[1] = pow((pos_x + 1 - target_x), 2) + pow((pos_y - target_y), 2);
                }
                if (!is_colliding_down())
                {
                    dist_new_position[2] = pow((pos_y + 1 - target_y), 2) + pow((pos_x - target_x), 2);
                }
                if (!is_colliding_up())
                {
                    dist_new_position[3] = pow((pos_y - 1 - target_y), 2) + pow((pos_x - target_x), 2);
                }
            }
            if (looking_horizontal == -1)
            {
                if (!is_colliding_left())
                {
                    dist_new_position[0] = pow((pos_x - 1 - target_x), 2) + pow((pos_y - target_y), 2);
                }
                if (!is_colliding_down())
                {
                    dist_new_position[2] = pow((pos_y + 1 - target_y), 2) + pow((pos_x - target_x), 2);
                }
                if (!is_colliding_up())
                {
                    dist_new_position[3] = pow((pos_y - 1 - target_y), 2) + pow((pos_x - target_x), 2);
                }
            }
            if (looking_vertical == -1)
            {
                if (!is_colliding_right())
                {
                    dist_new_position[1] = pow((pos_x + 1 - target_x), 2) + pow((pos_y - target_y), 2);
                }
                if (!is_colliding_left())
                {
                    dist_new_position[0] = pow((pos_x - 1 - target_x), 2) + pow((pos_y - target_y), 2);
                }

                if (!is_colliding_up())
                {
                    dist_new_position[3] = pow((pos_y - 1 - target_y), 2) + pow((pos_x - target_x), 2);
                }
            }
            if (looking_vertical == 1)
            {

                if (!is_colliding_down())
                {
                    dist_new_position[2] = pow((pos_y + 1 - target_y), 2) + pow((pos_x - target_x), 2);
                }
                if (!is_colliding_right())
                {
                    dist_new_position[1] = pow((pos_x + 1 - target_x), 2) + pow((pos_y - target_y), 2);
                }

                if (!is_colliding_left())
                {
                    dist_new_position[0] = pow((pos_x - 1 - target_x), 2) + pow((pos_y - target_y), 2);
                }
            }

            int least = 0;
            for (int i = 1; i < 4; i++)
            {
                if (dist_new_position[i] <= dist_new_position[0])
                {
                    dist_new_position[0] = dist_new_position[i];
                    least = i;
                }
            }
            if (least == 0)
            {
                looking_vertical = 0;
                looking_horizontal = -1;
            }
            if (least == 1)
            {
                looking_horizontal = 1;
                looking_vertical = 0;
            }
            if (least == 2)
            {
                looking_vertical = 1;
                looking_horizontal = 0;
            }
            if (least == 3)
            {
                looking_vertical = -1;
                looking_horizontal = 0;
            }

            if ((pos_y == 10) && (pos_x == 11))
            {
                looking_horizontal = 0;
                looking_vertical = -1;
                mode = 0;
                frightened_status = false;
                going_home = false;
                sprite.setColor(sf::Color(red, blue, green));
            }
            if ((pos_y == 8) && (pos_x == 11) && looking_vertical == -1)
            {
                looking_horizontal = pow(-1, rand()) * 1;
                looking_vertical = 0;
            }
        }
    }
    int getmode()
    {
        return mode;
    }
    bool succeded_in_touching(Pacman pacman, int i)
    {
        if (((pacman.pos_x * 32 + pacman.looking_horizontal * i) == (pos_x * 32 + i * looking_horizontal)) && (((pacman.pos_y * 32 + pacman.looking_vertical * i) == (pos_y * 32 + i * looking_vertical))))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void move_me()
    {
        sprite.move(looking_horizontal, looking_vertical);
        eyes.move(looking_horizontal, looking_vertical);
    }
    void move_me_slow()
    {
        sprite.move(looking_horizontal * 0.5, looking_vertical * 0.5);
        eyes.move(looking_horizontal * 0.5, looking_vertical * 0.5);
    }
    void move_me_fast()
    {
        sprite.move(looking_horizontal * 2, looking_vertical * 2);
        eyes.move(looking_horizontal * 2, looking_vertical * 2);
    }
};
int level = 1;
int life = 3;
int no_of_dots = 150;

int main()
{
    std::string str1, str2;
    str1 = std::to_string(level);
    str2 = "LEVEL: " + str1;
    sf::Font font;
    font.loadFromFile("font/Minecraft.ttf");
    sf::Text show_level;
    show_level.setFont(font);
    show_level.setCharacterSize(75);
    show_level.setFillColor(sf::Color::Magenta);
    show_level.setString(str2);
    show_level.setPosition(850, 350);
    window.setFramerateLimit(100);
    char map_original[][23] =
        {
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', ' '},
            {' ', ' ', '#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '#', ' ', ' '},
            {' ', ' ', '#', 'o', '#', '#', '.', '#', '#', '#', '.', '#', '.', '#', '#', '#', '.', '#', '#', 'o', '#', ' ', ' '},
            {' ', ' ', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', ' ', ' '},
            {' ', ' ', '#', '.', '#', '#', '.', '#', '.', '#', '#', '#', '#', '#', '.', '#', '.', '#', '#', '.', '#', ' ', ' '},
            {' ', ' ', '#', '.', '.', '.', '.', '#', '.', '.', '.', '#', '.', '.', '.', '#', '.', '.', '.', '.', '#', ' ', ' '},
            {' ', ' ', '#', '#', '#', '#', '.', '#', '#', '#', ' ', '#', ' ', '#', '#', '#', '.', '#', '#', '#', '#', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', '#', '.', '#', ' ', ' ', ' ', '0', ' ', ' ', ' ', '#', '.', '#', ' ', ' ', ' ', ' ', ' '},
            {' ', '#', '#', '#', '#', '#', '.', '#', ' ', '#', '#', '=', '#', '#', ' ', '#', '.', '#', '#', '#', '#', '#', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', '.', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', '.', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', '#', '#', '#', '#', '#', '.', '#', ' ', '#', '#', '#', '#', '#', ' ', '#', '.', '#', '#', '#', '#', '#', ' '},
            {' ', ' ', ' ', ' ', ' ', '#', '.', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '.', '#', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', '#', '#', '#', '#', '.', '#', ' ', '#', '#', '#', '#', '#', ' ', '#', '.', '#', '#', '#', '#', ' ', ' '},
            {' ', ' ', '#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '.', '.', '#', ' ', ' '},
            {' ', ' ', '#', '.', '#', '#', '.', '#', '#', '#', '.', '#', '.', '#', '#', '#', '.', '#', '#', '.', '#', ' ', ' '},
            {' ', ' ', '#', 'o', '.', '#', '.', '.', '.', '.', '.', 'P', '.', '.', '.', '.', '.', '#', '.', 'o', '#', ' ', ' '},
            {' ', ' ', '#', '#', '.', '#', '.', '#', '.', '#', '#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '#', ' ', ' '},
            {' ', ' ', '#', '.', '.', '.', '.', '#', '.', '.', '.', '#', '.', '.', '.', '#', '.', '.', '.', '.', '#', ' ', ' '},
            {' ', ' ', '#', '.', '#', '#', '#', '#', '#', '#', '.', '#', '.', '#', '#', '#', '#', '#', '#', '.', '#', ' ', ' '},
            {' ', ' ', '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#', ' ', ' '},
            {' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        };

    sf::SoundBuffer buffer, buffer1, buffer2, buffer3, buffer4, buffer5;
    sf::Sound sound, ghost, fruit, siren, gamestart, level_up, i_die;

    if (!buffer.loadFromFile("audio/pm.wav"))
        ;
    if (!buffer1.loadFromFile("audio/eat_ghost.wav"))
        ;
    if (!buffer2.loadFromFile("audio/power_pellet.wav"))
        ;
    if (!buffer3.loadFromFile("audio/siren_3.wav"))
        ;
    if (!buffer4.loadFromFile("audio/extend.wav"))
        ;
    if (buffer5.loadFromFile("audio/death_2.wav"))
        ;
    sound.setBuffer(buffer);
    ghost.setBuffer(buffer1);
    fruit.setBuffer(buffer2);
    siren.setBuffer(buffer3);
    level_up.setBuffer(buffer4);
    i_die.setBuffer(buffer5);
    siren.setVolume(70);
    sound.setVolume(40);
    ghost.setVolume(100);
    fruit.setVolume(400);
    level_up.setVolume(300);
    i_die.setVolume(400);
    Game_components game_component;
    game_component.animation();
    sf::CircleShape food[23][23];

    sf::Texture texture;
    texture.loadFromFile("img/map16.png");
    sf::IntRect image1(0, 0, 16, 16);
    sf::IntRect image2(16, 0, 16, 16);
    sf::IntRect image3(32, 0, 16, 16);
    sf::IntRect image4(48, 0, 16, 16);
    sf::IntRect image5(64, 0, 16, 16);
    sf::IntRect image6(80, 0, 16, 16);
    sf::IntRect image7(96, 0, 16, 16);
    sf::IntRect image8(112, 0, 16, 16);
    sf::IntRect image9(128, 0, 16, 16);
    sf::IntRect image10(144, 0, 16, 16);
    sf::IntRect image11(160, 0, 16, 16);
    sf::IntRect image12(176, 0, 16, 16);
    sf::IntRect image13(192, 0, 16, 16);
    sf::IntRect image14(208, 0, 16, 16);
    sf::IntRect image15(224, 0, 16, 16);
    sf::IntRect image16(240, 0, 16, 16);
    sf::Sprite sprite[23][23];
    for (int i = 1; i < 23; i++)
    {
        for (int j = 1; j < 23; j++)
        {
            if (map[i][j] == '.')
            {
                food[i][j].setRadius(3);
                food[i][j].setPosition(32 * j + 15, 32 * i + 15);
                food[i][j].setPointCount(5);
                food[i][j].setFillColor(sf::Color::Magenta);
                window.draw(food[i][j]);
            }
            if (map[i][j] == 'o')
            {
                food[i][j].setRadius(8);
                food[i][j].setPosition(32 * j + 10, 32 * i + 10);
                food[i][j].setPointCount(5);
                food[i][j].setFillColor(sf::Color::Green);
                window.draw(food[i][j]);
            }
            if (map[i][j] == '#')
            {
                sprite[i][j].setTexture(texture);
                sprite[i][j].setPosition(32 * j, 32 * i);
                sprite[i][j].setScale(2, 2);
                if ((map[i - 1][j] == '#') && (map[i + 1][j] == '#') && (map[i][j + 1] == '#') && (map[i][j - 1] == '#'))
                {
                    sprite[i][j].setTextureRect(image16);
                }
                else if ((map[i - 1][j] == '#') && (map[i][j + 1] == '#') && (map[i][j - 1] == '#'))
                {
                    sprite[i][j].setTextureRect(image15);
                }
                else if ((map[i - 1][j] == '#') && (map[i + 1][j] == '#') && (map[i][j - 1] == '#'))
                {
                    sprite[i][j].setTextureRect(image12);
                }
                else if ((map[i - 1][j] == '#') && (map[i + 1][j] == '#') && (map[i][j + 1] == '#'))
                {
                    sprite[i][j].setTextureRect(image14);
                }
                else if ((map[i + 1][j] == '#') && (map[i][j + 1] == '#') && (map[i][j - 1] == '#'))
                {
                    sprite[i][j].setTextureRect(image8);
                }
                else if ((map[i - 1][j] == '#') && (map[i][j + 1] == '#'))
                {
                    sprite[i][j].setTextureRect(image13);
                }
                else if ((map[i - 1][j] == '#') && (map[i][j - 1] == '#'))
                {
                    sprite[i][j].setTextureRect(image11);
                }
                else if ((map[i + 1][j] == '#') && (map[i][j + 1] == '#'))
                {
                    sprite[i][j].setTextureRect(image6);
                }
                else if ((map[i + 1][j] == '#') && (map[i][j - 1] == '#'))
                {
                    sprite[i][j].setTextureRect(image4);
                }
                else if ((map[i][j + 1] == '#') && (map[i][j - 1] == '#'))
                {
                    sprite[i][j].setTextureRect(image7);
                }
                else if ((map[i - 1][j] == '#') && (map[i + 1][j] == '#'))
                {
                    sprite[i][j].setTextureRect(image10);
                }
                else if (map[i + 1][j] == '#')
                {
                    sprite[i][j].setTextureRect(image2);
                }
                else if (map[i][j - 1] == '#')
                {
                    sprite[i][j].setTextureRect(image3);
                }
                else if (map[i][j + 1] == '#')
                {
                    sprite[i][j].setTextureRect(image5);
                }
                else if (map[i - 1][j] == '#')
                {
                    sprite[i][j].setTextureRect(image9);
                }
                else
                {
                    sprite[i][j].setTextureRect(image1);
                }
            }
            window.draw(sprite[i][j]);
        }
    }
    Pacman pacman;
escape:
    pacman.startfun();
start:
    Ghost blinky(250, 50, 10);
    pacman.update_coordinate(11, 16);
    pacman.update_looking_direction(-1, 0);
    pacman.design_me();
    blinky.update_coordinate(11, 8);
    blinky.update_looking_direction(-1, 0);
    blinky.design_me();
    Ghost pinky(250, 100, 245);
    pinky.update_coordinate(10, 10);
    pinky.update_looking_direction(1, 0);
    pinky.design_me();
    Ghost inky(100, 200, 250);
    inky.update_coordinate(12, 10);
    inky.update_looking_direction(-1, 0);
    inky.design_me();
    Ghost clyde(220, 200, 30);
    clyde.update_coordinate(11, 10);
    clyde.update_looking_direction(0, -1);
    clyde.design_me();
    window.draw(pacman.draw_me(1));
    window.draw(blinky.draw_me(1));
    window.draw(inky.draw_me(1));
    window.draw(pinky.draw_me(1));
    window.draw(clyde.draw_me(1));
    window.display();
    sf::sleep(sf::seconds(2));
    int power = 1;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                goto escape;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) && (!pacman.is_colliding_left()))
        {
            pacman.update_looking_direction(-1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) && (!pacman.is_colliding_down()))
        {
            pacman.update_looking_direction(0, 1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && (!pacman.is_colliding_right()))
        {
            pacman.update_looking_direction(1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && (!pacman.is_colliding_up()))
        {
            pacman.update_looking_direction(0, -1);
        }
        if (map[pacman.y_coordinate() + pacman.vertical_direction()][pacman.x_coordinate() + pacman.horizontal_direction()] == '#')
        {
            pacman.update_looking_direction(0, 0);
        }
        if ((pacman.x_coordinate() == 1) && (pacman.horizontal_direction() == -1))
        {
            pacman.update_coordinate(21, pacman.y_coordinate());
            pacman.design_me();
        }
        if ((pacman.x_coordinate() == 21) && (pacman.horizontal_direction() == 1))
        {
            pacman.update_coordinate(1, pacman.y_coordinate());
            pacman.design_me();
        }
        if (map[pacman.y_coordinate()][pacman.x_coordinate()] == '.')
        {
            map[pacman.y_coordinate()][pacman.x_coordinate()] = ' ';
            no_of_dots--;
            sound.play();
            pacman.update_Score(1);
            if (no_of_dots == 0)
            {
                pacman.update_Score(200);
                level_up.play();
                for (int a = 0; a < 23; a++)
                {
                    for (int b = 0; b < 23; b++)
                    {
                        map[a][b] = map_original[a][b];
                    }
                }
                level++;
                str2 = "LEVEL: " + std::to_string(level);
                show_level.setString(str2);
                no_of_dots = 150;
                goto start;
            }
        }
        sf::Font op;
        if (!op.loadFromFile("font/Minecraft.ttf"))
        {
            throw("NAHHH");
        }
        if (map[pacman.y_coordinate()][pacman.x_coordinate()] == 'o')
        {
            fruit.play();
            map[pacman.y_coordinate()][pacman.x_coordinate()] = ' ';
            no_of_dots--;
            blinky.update_sprite();
            inky.update_sprite();
            pinky.update_sprite();
            clyde.update_sprite();
            if (!pinky.target_is_home())
            {
                pinky.set_mode(1);
                pinky.set_frightened();
            }
            if (!blinky.target_is_home())
            {
                blinky.set_mode(1);
                blinky.set_frightened();
            }
            if (!inky.target_is_home())
            {
                inky.set_mode(1);
                inky.set_frightened();
            }
            if (!clyde.target_is_home())
            {
                clyde.set_mode(1);
                clyde.set_frightened();
            }
        }
        if (blinky.full_tile_travelled())
        {
            if (!blinky.target_is_home())
            {
                if (blinky.get_scatter(level) > 0 && blinky.get_scatter(level) < 5)
                {
                    blinky.set_target(20, 2);
                }
                else
                {
                    blinky.set_target(pacman.x_coordinate(), pacman.y_coordinate());
                }
            }
            blinky.calculate_move(pacman);
        }
        if (inky.full_tile_travelled())
        {
            if (!inky.target_is_home())
            {
                if (inky.get_scatter(level) >= 0 && inky.get_scatter(level) < 10)
                {
                    inky.set_target(2, 20);
                }
                else
                {
                    int x_p = blinky.x_coordinate() - pacman.x_coordinate();
                    int y_p = blinky.y_coordinate() - pacman.y_coordinate();
                    inky.set_target(pacman.x_coordinate() - x_p, pacman.y_coordinate() - y_p);
                }
            }
            inky.calculate_move(pacman);
        }
        if (pinky.full_tile_travelled())
        {
            if (!pinky.target_is_home())
            {
                if (pinky.get_scatter(level) >= 0 && pinky.get_scatter(level) < 10)
                {
                    pinky.set_target(2, 2);
                }
                else
                {
                    pinky.set_target((pacman.x_coordinate() + pacman.horizontal_direction() * 4), (pacman.y_coordinate() + pacman.vertical_direction() * 4));
                }
            }
            pinky.calculate_move(pacman);
        }
        if (clyde.full_tile_travelled())
        {
            if (!clyde.target_is_home())
            {
                if (clyde.get_scatter(level) >= 0 && clyde.get_scatter(level) < 15)
                {
                    clyde.set_target(20, 20);
                }
                else
                {
                    clyde.set_target((pacman.x_coordinate() + pacman.horizontal_direction() - 8), (pacman.y_coordinate() - pacman.vertical_direction() * 8));
                }
            }
            clyde.calculate_move(pacman);
        }
        std::string str;
        str = std::to_string(pacman.get_score());
        sf::Text text;
        text.setFont(op);
        text.setCharacterSize(100);
        text.setFillColor(sf::Color::White);
        text.setString(str);
        text.setPosition(700, 100);
        for (int i = 0; i < 32; i++)
        {
            if (map[pacman.y_coordinate()][pacman.x_coordinate()] == 'o')
            {
                food[pacman.y_coordinate()][pacman.x_coordinate()].setFillColor(sf::Color::Black);
            }
            if (blinky.succeded_in_touching(pacman, i))
            {
                if (blinky.frightened() && blinky.getmode() == 1)
                {
                    ghost.play();
                    pacman.update_Score(20);
                    blinky.set_target(11, 10);
                    blinky.set_mode(2);
                }
                else if (blinky.getmode() == 0)
                {
                    life--;
                    i_die.play();
                    if (life == 0)
                    {
                        level = 1;
                        life = 3;
                        for (int a = 0; a < 23; a++)
                        {
                            for (int b = 0; b < 23; b++)
                            {
                                map[a][b] = map_original[a][b];
                            }
                        }
                        no_of_dots = 150;
                        pacman.update_highscore();
                        game_component.game_over(pacman.x_coordinate(), pacman.y_coordinate(), pacman.get_score());
                        pacman.reset_score();
                    }
                    goto start;
                }
            }
            if (inky.succeded_in_touching(pacman, i))
            {
                if (inky.frightened() && inky.getmode() == 1)
                {
                    ghost.play();
                    pacman.update_Score(20);
                    inky.set_target(11, 10);
                    inky.set_mode(2);
                }
                else if (inky.getmode() == 0)
                {
                    i_die.play();
                    life--;
                    if (life == 0)
                    {
                        level = 1;
                        life = 3;
                        for (int a = 0; a < 23; a++)
                        {
                            for (int b = 0; b < 23; b++)
                            {
                                map[a][b] = map_original[a][b];
                            }
                        }
                        no_of_dots = 150;
                        pacman.update_highscore();
                        game_component.game_over(pacman.x_coordinate(), pacman.y_coordinate(), pacman.get_score());
                        pacman.reset_score();
                    }
                    goto start;
                }
            }
            if (pinky.succeded_in_touching(pacman, i))
            {
                if (pinky.frightened() && pinky.getmode() == 1)
                {
                    ghost.play();
                    pacman.update_Score(20);
                    pinky.set_target(11, 10);
                    pinky.set_mode(2);
                }
                else if (pinky.getmode() == 0)
                {
                    i_die.play();
                    life--;
                    if (life == 0)
                    {
                        level = 1;
                        life = 3;
                        for (int a = 0; a < 23; a++)
                        {
                            for (int b = 0; b < 23; b++)
                            {
                                map[a][b] = map_original[a][b];
                            }
                        }
                        no_of_dots = 150;
                        pacman.update_highscore();
                        game_component.game_over(pacman.x_coordinate(), pacman.y_coordinate(), pacman.get_score());
                        pacman.reset_score();
                    }
                    goto start;
                }
            }
            if (clyde.succeded_in_touching(pacman, i))
            {
                if (clyde.frightened() && clyde.getmode() == 1)
                {
                    ghost.play();
                    pacman.update_Score(20);
                    clyde.set_target(11, 10);
                    clyde.set_mode(2);
                }
                else if (clyde.getmode() == 0)
                {
                    i_die.play();
                    life--;
                    if (life == 0)
                    {
                        level = 1;
                        life = 3;
                        for (int a = 0; a < 23; a++)
                        {
                            for (int b = 0; b < 23; b++)
                            {
                                map[a][b] = map_original[a][b];
                            }
                        }
                        no_of_dots = 150;
                        pacman.update_highscore();
                        game_component.game_over(pacman.x_coordinate(), pacman.y_coordinate(), pacman.get_score());
                        pacman.reset_score();
                    }
                    goto start;
                }
            }
            if (blinky.frightened())
            {
                if (blinky.target_is_home() && blinky.full_tile_travelled())
                {
                    blinky.move_me();
                }
                else
                {
                    blinky.move_me_slow();
                }
            }
            else
            {
                blinky.move_me();
            }
            if (inky.frightened())
            {
                if (inky.target_is_home() && inky.full_tile_travelled())
                {
                    inky.move_me();
                }
                else
                {
                    inky.move_me_slow();
                }
            }
            else
            {
                inky.move_me();
            }
            if (pinky.frightened())
            {
                if (pinky.target_is_home() && pinky.full_tile_travelled())
                {
                    pinky.move_me();
                }
                else
                {
                    pinky.move_me_slow();
                }
            }
            else
            {
                pinky.move_me();
            }
            if (clyde.frightened())
            {
                if (clyde.target_is_home() && clyde.full_tile_travelled())
                {
                    clyde.move_me();
                }
                else
                {
                    clyde.move_me_slow();
                }
            }
            else
            {
                clyde.move_me();
            }
            pacman.move_me();
            window.clear(sf::Color::Black);
            for (int i = 1; i < 23; i++)
            {
                for (int j = 1; j < 23; j++)
                {
                    if (map[i][j] == '#')
                    {
                        window.draw(sprite[i][j]);
                    }
                    if (map[i][j] == '.')
                    {
                        window.draw(food[i][j]);
                    }
                    if (map[i][j] == 'o')
                    {
                        if ((power == 1))
                        {
                            food[i][j].setRadius(12);
                            food[i][j].setFillColor(sf::Color::Green);
                            food[i][j].setPosition(32 * j + 6, 32 * i + 6);
                            window.draw(food[i][j]);
                        }
                        else
                        {
                            food[i][j].setFillColor(sf::Color::Green);
                            food[i][j].setRadius(8);
                            food[i][j].setPosition(32 * j + 10, 32 * i + 10);
                            window.draw(food[i][j]);
                        }
                    }
                }
            }
            game_component.display_life(life);
            window.draw(inky.draw_me(i % 15));
            window.draw(inky.draw_my_eyes());
            window.draw(blinky.draw_me(i % 15));
            window.draw(blinky.draw_my_eyes());
            window.draw(pinky.draw_me(i % 15));
            window.draw(pinky.draw_my_eyes());
            window.draw(clyde.draw_me(i % 15));
            window.draw(clyde.draw_my_eyes());
            window.draw(pacman.draw_me(i % 15));
            window.draw(show_level);
            window.draw(text);
            window.display();
        }
        power = (power + 1) % 3;
        if (blinky.frightened())
        {
            if (!(blinky.full_tile_travelled() && blinky.target_is_home()))
            {
                blinky.update_tile_travel();
                blinky.update_count();
            }
        }
        if (pinky.frightened())
        {
            if (!(pinky.full_tile_travelled() && pinky.target_is_home()))
            {
                pinky.update_tile_travel();
                pinky.update_count();
            }
        }
        if (inky.frightened())
        {
            if (!(inky.full_tile_travelled() && inky.target_is_home()))
            {
                inky.update_tile_travel();
                inky.update_count();
            }
        }
        if (clyde.frightened())
        {
            if (!(clyde.full_tile_travelled() && clyde.target_is_home()))
            {
                clyde.update_tile_travel();
                clyde.update_count();
            }
        }
        if (blinky.full_tile_travelled())
        {
            blinky.update_coordinate((blinky.x_coordinate() + blinky.horizontal_direction()), (blinky.y_coordinate() + blinky.vertical_direction()));
        }
        if (inky.full_tile_travelled())
        {
            inky.update_coordinate((inky.x_coordinate() + inky.horizontal_direction()), (inky.y_coordinate() + inky.vertical_direction()));
        }
        if (pinky.full_tile_travelled())
        {
            pinky.update_coordinate((pinky.x_coordinate() + pinky.horizontal_direction()), (pinky.y_coordinate() + pinky.vertical_direction()));
        }
        if (clyde.full_tile_travelled())
        {
            clyde.update_coordinate((clyde.x_coordinate() + clyde.horizontal_direction()), (clyde.y_coordinate() + clyde.vertical_direction()));
        }
        siren.play();
        pacman.update_coordinate((pacman.x_coordinate() + pacman.horizontal_direction()), (pacman.y_coordinate() + pacman.vertical_direction()));
    }
    return 0;
}
