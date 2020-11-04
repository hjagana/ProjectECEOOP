CXX = g++
CXX_FLAGS = -std=c++14 -g -I /usr/local/Cellar/xerces-c/3.2.3/include/ -L /usr/local/Cellar/xerces-c/3.2.3/lib/
SRC = *.cpp
INCLUDE =
LIBS =

WARNING = -Wall
ERROR = -Wvla -lxerces-c -lncurses #-Wvla -Werror -lxerces-c
VAL = valgrind --tool=memcheck --log-file=memcheck.txt --leak-check=full --verbose
TESTFLAGS =
INPUTS =

main:
	$(CXX) $(CXX_FLAGS) $(WARNING) $(ERROR) $(TESTFLAGS) $(SRC) -o main
	# $(CXX) $(CXX_FLAGS) $(WARNING) $(ERROR) $(TESTFLAGS) $(SRC) -o main && ./main $(INPUTS)

badScroll: badScroll
	./main ../xmlFiles/badScroll.xml

death: death
	./main ../xmlFiles/death.xml

dropPack: dropPack
	./main ../xmlFiles/dropPack.xml

dungeon: dungeon
	./main ../xmlFiles/dungeon.xml

hallucinate: hallucinate
	./main ../xmlFiles/hallucinate.xml

testDrawing: testDrawing
	./main ../xmlFiles/testDrawing.xml

wear: wear
	./main ../xmlFiles/wear.xml

clean:
	-rm -f main
