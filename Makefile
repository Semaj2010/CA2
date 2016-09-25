CC = gcc 
CXX=g++
RM=rm -f
CPPFLAGS=-g -Wall
TARGETS = linkedList
SRCS = linkedList.cpp
OBJS = linkedList.o 
HEADER = Node.h List.h secureList.h

.SUFFIXES : .cpp .o 

all : $(TARGETS)


$(TARGETS) : $(OBJS)
	$(CXX) $(CPPFLAGS) -o $@ $<

$(OBJS) : $(SRCS) $(HEADER)

clean :
	rm -f $(TARGETS) $(OBJS)
