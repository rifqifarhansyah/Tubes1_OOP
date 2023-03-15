# Compiler
CPP           = g++

# Directory
ABILITY		  = ./lib/Ability/*.cpp
CARD		  = ./lib/Card/*.cpp
COMBINATION	  = ./lib/Combination/*.cpp
EXCEPTION	  = ./lib/Exception/*.cpp
GAME		  = ./lib/Game/*.cpp
IO			  = ./lib/IO/*.cpp
MAINDECK	  = ./lib/MainDeck/*.cpp
PLAYER		  = ./lib/Player/*.cpp
TABLECARD	  = ./lib/TableCard/*.cpp

# Flags
CFLAGS		  = $(ABILITY) $(CARD) $(EXCEPTION) $(GAME) $(IO) $(MAINDECK) $(PLAYER) $(TABLECARD)

.ONESHELL:
test:
	@clear
	@read -p "Enter Folder: " folder;
	@echo Compiling $$folder\Test...
	@$(CPP) -o lib/$$folder/test/$$folder\Test lib/$$folder/test/$$folder\Test.cpp $(CFLAGS)
	./lib/$$folder/test/$$folder\Test
	rm -rf lib/$$folder/test/$$folder\Test
tablecard:
	$(CPP) -o lib/TableCard/test/TableCardTest lib/TableCard/test/TableCardTest.cpp $(CFLAGS)
	cd lib/TableCard/test/
	TableCardTest.exe
	del TableCardTest.exe
game:
	$(CPP) -o lib/Game/test/GameTest lib/Game/test/GameTest.cpp $(CFLAGS)
	cd lib/Game/test/
	GameTest.exe
	del GameTest.exe
