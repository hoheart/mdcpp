BINPATH = $(HOME)/lib/
SONAME = liblog_receiver.so.1
TARGET =  $(BINPATH)$(SONAME)

INCDIR = $(HOME)/ThirdPart/include 
INCDIR1 = $(HOME)/logger/HFC/include

CC = g++
#-fPIC生成位置无关代码
CFLAGS = -c -fPIC -ggdb3 -D_LINUX -I$(INCDIR) -I$(INCDIR1)

%.o : src/%.cpp
	$(CC) $(CFLAGS) -o Debug/$@ $<
	
LDPATH			= -L$(HOME)/lib

LFLAGS1 = -shared -Wl,-soname,$(SONAME)
LFLAGS2 = $(LDPATH) -lhfc

all = LogReceiver
OBJS = $(foreach n,$(all),$n.o)

outObjs = $(foreach n,$(OBJS),Debug/$n)

$(TARGET) : $(OBJS)
	$(CC) $(LFLAGS1) -o $(TARGET) $(outObjs) $(LFLAGS2) 

#$(SRCPREV)/%.cpp : $(SRCPREV)/%.hpp


install:
	ln -s $(TARGET) $(BINPATH)liblog_receiver.so
	
clean:
	rm -f Debug/*




