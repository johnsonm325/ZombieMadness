#
# Project Name
#
PROJ = Game

#
# Compiler
#
$(CXX) = g++

#
# Compiler Flags
#
CFLAGS = -g -Wall -pedantic -std=c++11

#
# Source Files
#
SRC  = Main.cpp School.cpp

#
# Create an object for each source file
#
OBJ = $(SRC:.cpp=.o)

#
# Output binary
#
BIN = $(PROJ)
#
# Default Behavior:
#     1. Remove everything to start from screatch
#     2. Compile the binary
#     3. Run it through valgrind for quicker debugging
#

all: build_folders $(BIN) 

build_folders: clean $(OBJ)
	$(MAKE) -C Rooms
	$(MAKE) -C Items
	$(MAKE) -C Creatures
	$(MAKE) -C CommandParser
	$(MAKE) -C GameState


ROOMS_OBJS  = Rooms/Space.o Rooms/Biology.o Rooms/Cafeteria.o Rooms/ComputerScience.o Rooms/FirstFloorHallway.o 
ROOMS_OBJS += Rooms/Football.o Rooms/FrontLobby.o Rooms/FrontOffice.o Rooms/GymnasiumFloor1.o Rooms/GymnasiumFloor2.o  
ROOMS_OBJS += Rooms/History.o Rooms/Infirmary.o Rooms/Library.o Rooms/Literature.o Rooms/LockerRoom.o Rooms/Math.o 
ROOMS_OBJS += Rooms/MensBathroom.o Rooms/PrincipalsOffice.o Rooms/SecondFloorHallway.o Rooms/WomensBathroom.o
ROOMS_OBJS += Rooms/Chemistry.o

ITEMS_OBJS = Items/Inventory.o Items/BaseballBat.o Items/BiteCure.o Items/Bookbag.o Items/EnergyDrink.o
ITEMS_OBJS += Items/FireExtinguisher.o Items/FirstAid.o Items/Gun.o Items/Jersey.o Items/Key.o
ITEMS_OBJS += Items/Knife.o Items/Map.o Items/Object.o Items/Paperclip.o Items/PlayerInventory.o
ITEMS_OBJS += Items/Rocks.o Items/SteelLid.o Items/Sword.o

CREATURE_OBJS = Creatures/Creature.o Creatures/Player.o Creatures/Zombie.o

CMD_PARSER_OBJS = CommandParser/CmdWord.o CommandParser/CmdList.o CommandParser/CmdParser.o

SAVE_STATE_OBJS = GameState/GameState.o GameState/StateManager.o

#
# % is a wildcard. Anything that ends in ".o" will match this tag, and each
# tag depends on the same matching wildcard, but ending in ".cpp"
#
%.o: %.cpp
	@echo "CC	$^"
	@$(CXX) $(CFLAGS) -c $^

$(BIN): $(OBJ) $(ROOMS_OBJS) $(ITEMS_OBJS) $(CREATURE_OBJS) $(CMD_PARSER_OBJS) 
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
