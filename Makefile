SHELL = /bin/bash
CXXFLAGS = -std=c++11 -pedantic -Wall -Wextra -I$(INCLUDEDIR) -Winvalid-pch
DEBUGFLAGS = -O0 -g -D _DEBUG
RELEASEFLAGS = -O2 -D _RELEASE

TARGET = $(BUILDDIR)/z80emu.exe
INCLUDEDIR = z80emu/include
SRCDIR = z80emu/src
BUILDDIR = z80emu/build
SOURCES = $(shell echo $(SRCDIR)/*.cpp)
HEADERS = $(shell echo $(INCLUDEDIR)/*.h)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))
.PHONY: release debug clean build

default: all

all: $(TARGET) $(INCLUDEDIR)/stdafx.h.gch

$(TARGET): $(OBJECTS) $(INCLUDEDIR)/stdafx.h.gch
	$(CXX) $(CXXFLAGS) $(DEBUGFLAGS) $(OBJECTS) -o $(TARGET)

$(OBJECTS): $(BUILDDIR)/%.o: $(SRCDIR)/%.cpp $(INCLUDEDIR)/stdafx.h.gch | $(BUILDDIR)
	$(CXX) $(CXXFLAGS) $(DEBUGFLAGS) -c $< -o $@

release: $(SOURCES) $(HEADERS) $(INCLUDEDIR)/stdafx.h.gch
	$(CXX) $(CXXFLAGS) $(RELEASEFLAGS) $(SOURCES) -o $(TARGET)

debug: $(SOURCES) $(HEADERS) $(INCLUDEDIR)/stdafx.h.gch
	$(CXX) $(CXXFLAGS) $(DEBUGFLAGS) $(SOURCES) -o $(TARGET)

$(INCLUDEDIR)/stdafx.h.gch: $(INCLUDEDIR)/stdafx.h
	$(CXX) $(CXXFLAGS) $(DEBUGFLAGS) -x c++-header $(INCLUDEDIR)/stdafx.h -o $(INCLUDEDIR)/stdafx.h.gch

clean:
	-rm -r $(BUILDDIR)
	-rm -f $(INCLUDEDIR)/stdafx.h.gch

$(BUILDDIR):
	@mkdir -p $(BUILDDIR)
