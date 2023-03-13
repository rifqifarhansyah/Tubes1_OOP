# Compiler
CPP           = g++

# Directory
CARD		  = lib/Card/*.cpp
COMBINATION	  = lib/Combination/*.cpp
EXCEPTION	  = lib/Exception/*.cpp
IO			  = lib/IO/*.cpp
MAINDECK	  = lib/MainDeck/*.cpp
PLAYER		  = lib/Player/*.cpp
TABLECARD	  = lib/TableCard/*.cpp

# Flags
CFLAGS		  = $(CARD) $(COMBINATION) $(EXCEPTION) $(IO) $(MAINDECK) $(PLAYER) $(TABLECARD)
TEMPFLAGS	  = $(CARD) $(TABLECARD)

.ONESHELL:
test:
	@read -p "Enter Folder: " folder;
	@$(CPP) -o lib/$$folder/test/$$folder\Test lib/$$folder/test/$$folder\Test.cpp $(CFLAGS)
	./lib/$$folder/test/$$folder\Test
	rm -rf lib/$$folder/test/$$folder\Test
tablecard:
	$(CPP) -o lib/TableCard/test/TableCardTest lib/TableCard/test/TableCardTest.cpp $(TEMPFLAGS)
	cd lib/TableCard/test/
	TableCardTest.exe
	del TableCardTest.exe