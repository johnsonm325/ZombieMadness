#
# Project Name
#
PROJ = Rooms

#
# Compiler
#
$(CXX) = g++

#
# Source Files
#
SRC  = Biology.cpp
SRC += Cafeteria.cpp
SRC += Chemistry.cpp
SRC += ComputerScience.cpp
SRC += FirstFloorHallway.cpp
SRC += Football.cpp
SRC += FrontLobby.cpp
SRC += FrontOffice.cpp
SRC += GymnasiumFloor1.cpp
SRC += GymnasiumFloor2.cpp
SRC += History.cpp
SRC += Infirmary.cpp
SRC += Library.cpp
SRC += Literature.cpp
SRC += LockerRoom.cpp
SRC += Math.cpp
SRC += MensBathroom.cpp
SRC += PrincipalsOffice.cpp
SRC += SecondFloorHallway.cpp
SRC += Space.cpp
SRC += WomensBathroom.cpp

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
CFLAGS = -Wall -pedantic -std=c++11

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