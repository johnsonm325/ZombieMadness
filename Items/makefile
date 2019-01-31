#
# Project Name
#
PROJ = Items

#
# Compiler
#
$(CXX) = g++

#
# Source Files
#
SRC  = Object.cpp BaseballBat.cpp BiteCure.cpp Bookbag.cpp EnergyDrink.cpp FireExtinguisher.cpp 
SRC += FirstAid.cpp Gun.cpp Jersey.cpp Key.cpp Knife.cpp Map.cpp Paperclip.cpp Rocks.cpp
SRC += SteelLid.cpp Sword.cpp
SRC += Inventory.cpp PlayerInventory.cpp

#
# Create an object for each source file
#
OBJ = $(SRC:.cpp=.o)

#
# Output binary
#
# BIN = $(PROJ)

#
# Compiler Flags
#
CFLAGS = -g -Wall -pedantic -std=c++11

#
# Default Behavior:
#     1. Remove everything to start from screatch
#     2. Compile the binary
#     3. Run it through valgrind for quicker debugging
#
default: clean $(OBJ) 

$(BIN): $(OBJ)
	@echo "CC	$@"
	@$(CXX) $(CFLAGS) $^ -o $@

#
# % is a wildcard. Anything that ends in ".o" will match this tag, and each
# tag depends on the same matching wildcard, but ending in ".cpp"
#
%.o: %.cpp
	@echo "CC	$^"
	@$(CXX) $(CFLAGS) -c $^

zip:
	zip $(PROJ).zip *.cpp *.h makefile 

clean: $(CLEAN)
	@echo "RM	*.o"
	@echo "RM  $(BIN)"
	@rm -f *.o $(BIN)
