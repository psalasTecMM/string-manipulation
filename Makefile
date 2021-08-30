SHELL = /bin/sh

CC = gcc
CXX = g++

srcdir = .

unames := $(shell uname -s)

# Target Variables
target := cadenas
testtarget := testcadenas
# Directories
builddir := $(srcdir)/build
testdir := $(srcdir)/tests

# Source files
csrcs := $(wildcard src/*.c)
cxxsrcs := $(wildcard *.cpp)

# Object files
objects := $(addprefix $(builddir)/,$(csrcs:src/%.c=%.o))
objects += $(addprefix $(builddir)/,$(cxxsrcs:src/%.cpp=%.o))

# Headers files
headers := $(wildcard src/*.h)
headers += $(wildcard src/*.hpp)

# Test files
ctestsrcs := $(wildcard tests/*.c)
cxxtestsrcs := $(wildcard tests/*.cpp)
testobjects := $(ctestsrcs:%.c=%.o)
testobjects += $(cxxtestsrcs:%.cpp=%.o)

ifeq ($(unames),Linux)
	CPPUTEST_HOME:=/usr/local
	LDFLAGS += -L$(CPPUTEST_HOME)/lib -lstdc++ -lCppUTest -lCppUTestExt
	CPPFLAGS += -I$(CPPUTEST_HOME)/include
	CXXFLAGS += -include $(CPPUTEST_HOME)/include/CppUTest/MemoryLeakDetectorNewMacros.h
	CFLAGS += -include $(CPPUTEST_HOME)/include/CppUTest/MemoryLeakDetectorMallocMacros.h
endif
ifeq ($(unames),Darwin)
	LDFLAGS := `pkg-config --libs cpputest`
	CPPFLAGS := `pkg-config --cflags cpputest`
	CXXFLAGS += -include /usr/local/Cellar/cpputest/4.0/include/CppUTest/MemoryLeakDetectorNewMacros.h
	CFLAGS += -include /usr/local/Cellar/cpputest/4.0/include/CppUTest/MemoryLeakDetectorMallocMacros.h
endif

# Make commands

all: $(target)

test: $(testtarget)

.PHONY : clean
clean:
	rm -rf $(target) $(builddir) $(testtarget) $(testobjects)

# Build rules

$(target): $(objects)
	$(CXX) $(LDFLAGS) $(LDLIBS) $^ $(OUTPUT_OPTION)

$(builddir)/%.o : src/%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< $(OUTPUT_OPTION)

$(builddir)/%.o : src/%.cpp $(headers)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< $(OUTPUT_OPTION)

$(objects):| $(builddir)

$(builddir):
	mkdir $(builddir)

# Tests Rules

$(testtarget): $(testobjects) $(filter-out $(builddir)/main.o,$(objects))
	$(CXX) $(LDFLAGS) $(LDLIBS) $^ $(OUTPUT_OPTION)

$(testdir)/%.o : $(testdir)/%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -Isrc -c $< $(OUTPUT_OPTION)

$(testdir)/%.o : $(testdir)/%.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< $(OUTPUT_OPTION)

$(testobjects):| $(testdir)

$(testdir):
	mkdir $(testdir)