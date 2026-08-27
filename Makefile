# 1. Detect the Operating System
OS := $(shell uname -s)

# 2. Linux-only rule
ifneq ($(OS), Linux)
$(error ERROR: This program is strictly for Linux OS). Compilation aborted.
endif

# 3. Super user only rule
ifneq ($(shell id -u), 0)
$(error ERROR: You must run 'sudo make' to build and install this project.)
endif

.DEFAULT_GOAL := install

ccsrc = $(wildcard src/aegisdecryption/*.cpp) \
		$(wildcard src/aegisencryption/*.cpp) \
		$(wildcard src/cipher/*.cpp) \
		$(wildcard src/helper_function/*.cpp) \
		$(wildcard src/password/*.cpp) \
		$(wildcard src/driverProgram/*.cpp) 
		
CXX = g++
# 1. Fallback to basic C++17 (if c++20 or 23 not available)
STD_FLAG := -std=c++17

# 2. Check if the compiler supports C++23 or C++20 instead
ifeq ($(shell $(CXX) -std=c++23 -E - < /dev/null > /dev/null 2>&1 && echo m),m)
    STD_FLAG := -std=c++23
else ifeq ($(shell $(CXX) -std=c++20 -E - < /dev/null > /dev/null 2>&1 && echo m),m)
    STD_FLAG := -std=c++20
endif

CXXFLAGS = -Wall -Wextra $(STD_FLAG) -MMD -MP

obj = $(ccsrc:.cpp=.o)
deps = $(obj:.o=.d)

LDFLAGS = -L/usr/local/lib -lcryptopp -lpthread #= -lcryptopp -lpthread
#LDLIBS = -lcryptopp -lpthread

aegis: $(obj)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# install
install: aegis
	mkdir -p /usr/local/bin
	cp -f aegis /usr/local/bin/aegis

-include $(deps)

.PHONY: clean
clean:
	rm -f /usr/local/bin/aegis
	rm -f $(obj) $(deps) aegis


