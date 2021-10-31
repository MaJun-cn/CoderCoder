# TOOLCHAIN_ROOT=/opt/compiler/
# TOOLCHAIN=/opt/compiler/gcc-8.2
# GXX4=/opt/compiler/gcc-8.2/bin/c++ -std=c++11
CC = /opt/compiler/gcc-8.2/bin/c++ -std=c++11
SRCS = ./main_sort.cpp
OBJS = $(SRCS:.cpp=.o)
MAIN=sort_bin
.PHONY: clean
all:$(MAIN)
	@echo  sort_bin has been compiled
$(MAIN): $(OBJS)
	$(CC) -o $(MAIN) $(OBJS)
.cpp.o:
	$(CC) -std=c++11 -c $<  -o $@
clean:
	$(RM) *.o *~ $(MAIN)
