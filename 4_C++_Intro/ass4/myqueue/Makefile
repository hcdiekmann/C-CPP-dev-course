PRODUCT=my_queue

INC_DIC= ../mystack/product
CPPFLAGS=-Iproduct -Itest -I$(INC_DIC)
CXXFLAGS=-Wall -Werror -Wextra -pedantic -ggdb -O0 $(CPPFLAGS)


SOURCES=$(wildcard product/*.cpp) \
		$(wildcard ../mystack/product/*.cpp) \
        $(wildcard test/*.cpp)

HEADERS=$(wildcard product/*.h) \
        $(wildcard test/*.h)

LDFLAGS=-lgtest -lgmock -lgmock_main -lpthread

CXX=g++

.PHONY: all clean test

all: $(PRODUCT)

$(PRODUCT): $(SOURCES) $(HEADERS)
	@$(CXX) $(CXXFLAGS) $(SOURCES) -o $@ $(LDFLAGS)

clean:
	@rm -rf $(PRODUCT)

test: $(PRODUCT)
	@./$(PRODUCT)
