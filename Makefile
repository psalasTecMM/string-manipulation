
SHELL = /bin/sh

srcdir = .

target = cadenas 
builddir := $(srcdir)/build
csrcs := $(wildcard *.c)
cxxsrcs := $(wildcard *.cpp)
objects := $(addprefix $(builddir)/,$(csrcs:.c=.o))
objects += $(addprefix $(builddir)/,$(cxxsrcs:.cpp=.o))

$(target): $(objects)
	$(CXX) $(LDFLAGS) $(LDLIBS) $^ $(OUTPUT_OPTION)

$(builddir)/%.o : %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< $(OUTPUT_OPTION)

$(builddir)/%.o : %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< $(OUTPUT_OPTION)

$(objects):|$(builddir)

$(builddir):
	mkdir $(builddir)

.PHONY : clean
clean:
	rm -rf $(target) $(builddir)
