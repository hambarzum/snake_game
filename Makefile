
build:
	g++ main.cpp src/controller/game.cpp src/game_objects/snake/snake.cpp src/game_objects/drawable.cpp src/game_objects/empty.cpp src/game_objects/food.cpp src/view/board.cpp src/view/scoreboard.cpp -lncurses -o final

run:
	./final
clean:
	rm -rf final
# src/board.cpp src/game.cpp src/drawable.cpp src/food.cpp src/empty.cpp src/snake.cpp
