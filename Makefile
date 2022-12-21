
all:
	make build && make run && make clean

build:
	g++ src/main.cpp src/game_objects/snake/snake.cpp src/game_objects/cell.cpp src/game_objects/empty.cpp src/game_objects/food.cpp src/window/ncurses_window.cpp src/controller/main_menu.cpp src/controller/play.cpp -lncurses -o final

run:
	./final
		
clean:
	rm -rf final
