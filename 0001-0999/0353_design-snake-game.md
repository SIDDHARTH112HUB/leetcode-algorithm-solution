[353.design-snake-game](https://leetcode.com/problems/design-snake-game/)  

Design a [Snake game](https://en.wikipedia.org/wiki/Snake_(video_game)) that is played on a device with screen size = _width_ x _height_. [Play the game online](http://patorjk.com/games/snake/) if you are not familiar with the game.

The snake is initially positioned at the top left corner (0,0) with length = 1 unit.

You are given a list of food's positions in row-column order. When a snake eats the food, its length and the game's score both increase by 1.

Each food appears one by one on the screen. For example, the second food will not appear until the first food was eaten by the snake.

When a food does appear on the screen, it is guaranteed that it will not appear on a block occupied by the snake.

**Example:**

  
Given width = 3, height = 2, and food = \[\[1,2\],\[0,1\]\].  
  
Snake snake = new Snake(width, height, food);  
  
Initially the snake appears at position (0,0) and the food at (1,2).  
  
|S| | |  
| | |F|  
  
snake.move("R"); -> Returns 0  
  
| |S| |  
| | |F|  
  
snake.move("D"); -> Returns 0  
  
| | | |  
| |S|F|  
  
snake.move("R"); -> Returns 1 (Snake eats the first food and right after that, the second food appears at (0,1) )  
  
| |F| |  
| |S|S|  
  
snake.move("U"); -> Returns 1  
  
| |F|S|  
| | |S|  
  
snake.move("L"); -> Returns 2 (Snake eats the second food)  
  
| |S|S|  
| | |S|  
  
snake.move("U"); -> Returns -1 (Game over because snake collides with border)  



**Solution:**  

```cpp
class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    deque<pair<int, int> > dq;
    int w = 0;
    int h = 0;
    vector<vector<int>> foods;
    int foodIdx = 0;
    map<char, pair<int, int> > dir;
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        dq.push_back({0, 0});
        w = width;
        h = height;
        this->foods = food;
        dir['U'] = { -1, 0 };
        dir['D'] = { 1, 0 };
        dir['R'] = { 0, 1 };
        dir['L'] = { 0, -1 };
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        auto p = dir[direction[0]];
        int nx = dq.back().first + p.first;
        int ny = dq.back().second + p.second;
        if(nx < 0 || ny < 0 || nx >= h || ny >= w) {
            return -1;
        }
        for(int i = 1; i < dq.size(); ++i) {
            auto body = dq[i];
            if(nx == body.first && ny == body.second) {
                return -1;
            }
        }
        dq.push_back({nx, ny});
        if(foodIdx < foods.size()) {
            auto &food = foods[foodIdx];
            if(nx == food[0] && ny == food[1]) {
                ++foodIdx;
                return dq.size() - 1;
            }
        }
        dq.pop_front();
        return dq.size() - 1;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
```
      