.PHONY: lint clean

CXXFLAGS=-std=c++14 -Wall -Wextra -Wshadow -Wswitch-default -Wconversion \
	-Winit-self -pedantic -I"${CURRENT_DIR}"

PRGM  = project
SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)
LOG_TO = valgrind.log

all: $(PRGM)

$(PRGM): $(OBJS)
		$(CXX) $(OBJS) $(LDLIBS) -o $@

%.o: %.cpp
		$(CXX) $(CXXFLAGS) -MP -c $< -o $@

lint:
	oclint ${FILE} -- -c

memcheck:
	valgrind --log-file=$(LOG_TO) --tool=memcheck --leak-check=yes \
	    --show-leak-kinds=all ./$(PRGM) ${TXT_FILE}

clean:
		rm -rf $(OBJS) $(PRGM)


#  vim: set ts=8 sw=4 tw=79 ft=make noet :
