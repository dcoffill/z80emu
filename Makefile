SHELL = /bin/bash
CXXFLAGS = -std=c++11 -pedantic -Wall -Wextra -I$(INCLUDEDIR)
DEBUGFLAGS = -O0 -g -D _DEBUG
RELEASEFLAGS = -O2 -D _RELEASE

TARGET = z80emu.exe
INCLUDEDIR = z80emu/include
SRCDIR = z80emu/src
SOURCES = $(shell echo z80emu/src/*.cpp)
HEADERS = $(shell echo z80emu/include/*.h)
OBJECTS = $(SOURCES:.cpp=.o)

PREFIX = $(DESTDIR)/usr/local
BINDIR = $(PREFIX)/bin
default: all

all: $(TARGET) z80emu/stdafx.h.gch

$(TARGET): $(OBJECTS) z80emu/stdafx.h.gch
	$(CXX) $(CXXFLAGS) $(DEBUGFLAGS) $(OBJECTS) -o $(TARGET)

release: $(SOURCES) $(HEADERS) z80emu/stdafx.h.gch
	$(CXX) $(CXXFLAGS) $(RELEASEFLAGS) $(SOURCES) -o $(TARGET)

debug: $(SOURCES) $(HEADERS) z80emu/stdafx.h.gch
	$(CXX) $(CXXFLAGS) $(DEBUGFLAGS) $(SOURCES) -o $(TARGET)

z80emu/stdafx.h.gch: $(INCLUDEDIR)/stdafx.h
	$(CXX) $(CXXFLAGS) -x c++-header $(INCLUDEDIR)/stdafx.h -o z80emu/stdafx.h.gch

clean:
	-rm -f $(OBJECTS)
	-rm -f $(shell echo z80emu/*.d)
	-rm -f $(shell echo z80emu/*.gch)
	-rm -f z80emu.exe

