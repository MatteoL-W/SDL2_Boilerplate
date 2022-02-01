# *****************************************************
# Variables

CC=g++
I_FOLDER=include
S_FOLDER=src
B_FOLDER=build

ifeq ($(OS),Windows_NT)
    CXX_FLAGS=-Wall
    SDL2_FLAGS=-lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf
    RM = del
    MKDIR = -mkdir
    SEP=\\
else
	# NOT CHECKED YET
    CXX_FLAGS = -Wall -O2 -g
    SDL2_FLAGS = -lSDL2 -lGLU -lGL -lm -lSDL2_image -lSDL2_ttf
    RM = rm -rf
    MKDIR = mkdir -p
    SEP=\/
endif

# _____________________________________________________



# *****************************************************
# Make

render: Main.o Game.o Text.o MenuInterface.o Menu.o
	$(CC) -o bin/$@ build/main.o build/Game.o build/Text.o build/MenuInterface.o build/Menu.o $(SDL2_FLAGS)

#render: build/main.o build/Utils.o build/Game.o build/StarterInterface.o build/ExplorationInterface.o build/AttackInterface.o build/InventoryInterface.o build/EndingInterface.o build/Starter.o build/Map.o build/Pokemon.o build/Text.o build/Battle.o build/Inventory.o build/Ending.o
 #	$(CC) -o bin/$@ $^ $(SDLFLAGS)
 #$(BFOLDER)/%.o: $(SFOLDER)/%.cpp $(IFOLDER)/%.hpp
 #	$(CC) -o $@ -c $< $(CXXFLAGS)

%.o: $(S_FOLDER)/%.cpp $(I_FOLDER)/%.hpp
	$(CC) -o build/$@ -c $< $(CXX_FLAGS)

# _____________________________________________________


# *****************************************************
# More commands

clean:
	$(RM) build$(SEP)*.o
	$(RM) bin$(SEP)render

st:
	./bin/render

init:
	$(MKDIR) build;
	$(MKDIR) bin;

# _____________________________________________________