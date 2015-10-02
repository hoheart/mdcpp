BINPATH = $(HOME)/lib/
SONAME = libhfc.so.1
TARGET =  $(BINPATH)$(SONAME)

INCDIR = $(HOME)/ThirdPart/include

CC = g++
#-fPIC生成位置无关代码
CFLAGS = -c -fPIC -ggdb3 -D_LINUX -I$(INCDIR)

%.o : src/Concurrent/%.cpp
	$(CC) $(CFLAGS) -o Debug/$@ $<
	
%.o : src/Crypto/%.cpp
	$(CC) $(CFLAGS) -o Debug/$@ $<
	
%.o : src/Encoder/%.cpp
	$(CC) $(CFLAGS) -o Debug/$@ $<
	
%.o : src/IO/%.cpp
	$(CC) $(CFLAGS) -o Debug/$@ $<

%.o : src/Lang/%.cpp
	$(CC) $(CFLAGS) -o Debug/$@ $<

%.o : src/Net/%.cpp
	$(CC) $(CFLAGS) -o Debug/$@ $<
	
%.o : src/Util/%.cpp
	$(CC) $(CFLAGS) -o Debug/$@ $<

LDPATH			= -L$(HOME)/lib

LFLAGS1 = -shared -Wl,-soname,$(SONAME)
LFLAGS2 = $(LDPATH) -lcrypto -lpthread

concurrent = Condition Locker ThreadPool
#crypto = Rsa Sha1 #新版openssl，md5被禁使用了
encoder = Base64 HexString
io = AbstractFile Directory EPoll File 
lang = Character Integer String
net = Connection Socket TCPServer UDPSocket
util = DateTime Random Logger
all = $(concurrent) $(crypto) $(encoder) $(io) $(lang) $(net) $(util)
OBJS = $(foreach n,$(all),$n.o)

outObjs = $(foreach n,$(OBJS),Debug/$n)

$(TARGET) : $(OBJS)
	$(CC) $(LFLAGS1) -o $(TARGET) $(outObjs) $(LFLAGS2)

#$(SRCPREV)/%.cpp : $(SRCPREV)/%.hpp

install:
	ln -s $(TARGET) $(BINPATH)libhfc.so
	
clean:
	rm -f Debug/*




