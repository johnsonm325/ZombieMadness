#
# Project Name
#
PROJ = Game

BIN = $(PROJ)
#
# Compiler
#
CXX = g++

#
# Compiler Flags
#
CFLAGS = -g -Wall -pedantic -std=c++11

#
# Source and Object Files
#
#

ITEM_SRC = $(wildcard Items/*.cpp)
ITEM_OBJ = $(patsubst Items/%.cpp, Items/%.o, $(ITEM_SRC))

ROOM_SRC = $(wildcard Rooms/*.cpp)
ROOM_OBJ = $(patsubst Rooms/%.cpp, Rooms/%.o, $(ROOM_SRC))

CREATURE_SRC = $(wildcard Creatures/*.cpp)
CREATURE_OBJ = $(patsubst Creatures/%.cpp, Creatures/%.o, $(CREATURE_SRC))

PARSER_SRC = CommandParser/CmdWord.cpp CommandParser/CmdList.cpp CommandParser/CmdParser.cpp
PARSER_OBJ = $(patsubst CommandParser/%.cpp, CommandParser/%.o, $(PARSER_SRC))

STATE_SRC = GameState/GameState.cpp GameState/StateManager.cpp 
STATE_OBJ = $(patsubst GameState/%.cpp, GameState/%.o, $(STATE_SRC))

MAIN_SRC = Main.cpp School.cpp 
MAIN_OBJ = $(patsubst %.cpp, %.o, $(MAIN_SRC))

default: clean $(BIN) 

# Create an object for each source file
#

Items/%.o: Items/%.cpp
	@echo "  CC $@"
	@$(CC) $(CFLAGS) -c $< -o $@

Rooms/%.o: Rooms/%.cpp
	@echo "  CC $@"
	@$(CC) $(CFLAGS) -c $< -o $@

Creatures/%.o: Creatures/%.cpp
	@echo "  CC $@"
	@$(CC) $(CFLAGS) -c $< -o $@

CommandParser/%.o: CommandParser/%.cpp
	@echo "  CC $@"
	@$(CC) $(CFLAGS) -c $< -o $@

GameState/%.o: GameState/%.cpp
	@echo "  CC $@"
	@$(CC) $(CFLAGS) -c $< -o $@

%.o: %.cpp
	@echo "  CC $@"
	@$(CC) $(CFLAGS) -c $< -o $@

#
# Output binary
#
$(BIN): $(ITEM_OBJ) $(ROOM_OBJ) $(CREATURE_OBJ) $(PARSER_OBJ) $(STATE_OBJ) $(MAIN_OBJ)
	@echo "CC	$@"
	@$(CXX) $(CFLAGS) $^ -o $@

zip:
	zip $(PROJ).zip *.cpp *.h makefile 

clean: $(CLEAN)
	@echo "RM	*.o"
	@echo "RM  $(BIN)"
	@rm -f *.o $(BIN)
	rm -rf Rooms/*.o
	rm -rf Items/*.o
	rm -rf Creatures/*.o
	rm -rf CommandParser/*.o
	rm -rf GameState/*.o
	rm -rf ./save.*