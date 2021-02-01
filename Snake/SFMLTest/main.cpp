// Знаю что очень просто. Я даже не смог сделать нормально проигрыш (сьедание себя) Но простите, сейчас это мой предел.
// Структуры я использовал. В принципе все работает корректно. Интерфейс и индикаторы я так же не осилил сделать.
// Есть что есть, извините.


#include <SFML/Graphics.hpp>
#include <ctime>
using namespace sf;

int mapHeight = 40, mapWidth = 40;
int  size = 14;
int w = size * mapHeight;
int h = size * mapWidth;

int direction = 2 , num = 4;

struct Snake
    {
        int x,y;
    }
    s[100];

struct Fruct
    {
        int x,y;
    }
    f;



void Tick()
    {
        for (int i = num; i > 0; --i)
            {
                s[i].x=s[i-1].x;
                s[i].y=s[i-1].y;
            }

        if (direction == 0) s[0].y+=1;
        if (direction == 1) s[0].x-=1;
        if (direction == 2) s[0].x+=1;
        if (direction == 3) s[0].y-=1;

        if ((s[0].x==f.x) && (s[0].y==f.y))
            {
                num++;
                f.x= rand() % mapHeight;
                f.y= rand() % mapWidth;
            }

        if (s[0].x > mapHeight) s[0].x=0;
        if (s[0].x < 0) s[0].x = mapHeight;

        if (s[0].y > mapWidth) s[0].y=0;
        if (s[0].y < 0) s[0].y = mapWidth;

        for (int i = 1; i < num;i++)
            if (s[0].x==s[i].x && s[0].y==s[i].y)  num=i;
    }

int checkReverse (int &prevdir, int &nextdir)
    {
        if (prevdir == 2 && nextdir == 1)
            {
                return prevdir;
            }
        if (prevdir == 1 && nextdir == 2)
            {
                return prevdir;
            }
        if (prevdir == 3 && nextdir == 0)
            {
                return prevdir;
            }
        if (prevdir == 0 && nextdir == 3)
            {
                return prevdir;
            }
        else
                return nextdir;

    }

int main()
    {
        srand(time(0));

        RenderWindow window(VideoMode(w, h), "Snake");

        Texture snake,board,point;
        snake.loadFromFile("images/white.png");
        board.loadFromFile("images/red.png");

        Sprite snakeSprite(snake);
        Sprite boardSprite(board);

        Clock clock;
        float timer = 0, delay = 0.1;

        f.x=10;
        f.y=10;

        int prevDir = direction;

        while (window.isOpen())
            {
                float time = clock.getElapsedTime().asSeconds();
                clock.restart();
                timer+=time;

                Event action;
                while (window.pollEvent(action))
                    {
                        if (action.type == Event::Closed)
                            window.close();
                    }

                if (Keyboard::isKeyPressed(Keyboard::Left)) direction=1;
                if (Keyboard::isKeyPressed(Keyboard::Right)) direction=2;
                if (Keyboard::isKeyPressed(Keyboard::Up)) direction=3;
                if (Keyboard::isKeyPressed(Keyboard::Down)) direction=0;

                direction = checkReverse(prevDir,direction);
                prevDir = direction;

                if (timer>delay)
                {
                    timer = 0;
                    Tick();
                }

                window.clear();

                for (int i = 0; i < mapHeight; i++)
                    for (int j = 0; j < mapWidth; j++)
                        {
                            snakeSprite.setPosition(i * size, j * size);  window.draw(snakeSprite);
                        }

                for (int i = 0; i < num;i++)
                    {
                        boardSprite.setPosition(s[i].x * size, s[i].y * size);  window.draw(boardSprite);
                    }

                boardSprite.setPosition(f.x * size, f.y * size);  window.draw(boardSprite);

                window.display();
            }
        return 0;
    }