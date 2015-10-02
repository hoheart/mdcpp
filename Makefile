BINPATH = $(HOME)/bin/
SONAME = logger
TARGET =  $(BINPATH)$(SONAME)

INCDIR = ./
INCDIR1 = HFC/include

CC = g++
CFLAGS = -c -fPIC -ggdb -D_LINUX -I$(INCDIR) -I$(INCDIR1)

%.o : %.cpp
	$(CC) $(CFLAGS) -o Debug/$@ $<

LDPATH			= -L$(HOME)/lib

LFLAGS1 = -Wl 
LFLAGS2 = $(LDPATH) -llog_receiver -lhfc

frame = main
all = $(frame)
OBJS = $(foreach n,$(all),$n.o)

outObjs = $(foreach n,$(OBJS),Debug/$n)

$(TARGET) : $(OBJS)
	$(CC) $(LFLAGS1) -o $(TARGET) $(outObjs) $(LFLAGS2)

#$(SRCPREV)/%.cpp : $(SRCPREV)/%.hpp
	
clean:
	rm -f Debug/*.o




