OBJS = *.o
CC = g++ -Wall -g -lncurses -std=c++14 -I /usr/local/Cellar/xerces-c/3.2.3/lib -L /usr/local/Cellar/xerces-c/3.2.3/include *.cpp -o GameXML -lxerces-c
INCLUDE =
LIBS = 
CFLAGS = -Wall -g
EXECUTABLE = Project
COMMANDLINE = GameXML
SRCS = *.cpp

.PHONY : run
run :
	$(CC) && ./GameXML

cleanmake : clean Project

.PHONY : $(EXECUTABLE)
$(EXECUTABLE) :  $(OBJS)
	$(CC) $(CFLAGS) -o $(EXECUTABLE) $(OBJS) $(INCLUDE) $(LIBS)

%.o : %.c 
	$(CC) $(CFLAGS) -c $@ $(INCLUDE) $(LIBS)

clean :
	rm $(EXECUTABLE) ${OBJS} 