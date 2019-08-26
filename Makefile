BINARY = tsareigo
SRCDIR = src
DOCDIR = doc
 
CXX = g++
CXXFLAGS = -Wall -pedantic -Wno-long-long -O0 -ggdb

LD = g++
LIBS = -lncurses

DOXY = Doxyfile
 
OBJECTS =\
		$(SRCDIR)/PMMenu.o\
		$(SRCDIR)/fields/PMField.o\
		$(SRCDIR)/PMMap.o\
		$(SRCDIR)/units/PMUnit.o\
		$(SRCDIR)/units/PMPacman.o\
		$(SRCDIR)/fields/PMWall.o\
		$(SRCDIR)/fields/PMFood.o\
		$(SRCDIR)/fields/PMGreatFood.o\
		$(SRCDIR)/fields/PMBonus.o\
		$(SRCDIR)/fields/PMTeleport.o\
		$(SRCDIR)/fields/PMGround.o\
		$(SRCDIR)/PMMapReader.o\
		$(SRCDIR)/units/PMMonster.o\
		$(SRCDIR)/units/PMBlinky.o\
		$(SRCDIR)/units/PMPinky.o\
		$(SRCDIR)/units/PMInky.o\
		$(SRCDIR)/units/PMClyde.o\
		$(SRCDIR)/PMGame.o\
		$(SRCDIR)/main.o        
         
# Compile and create documentation
all: compile doc
 
# Compile
compile: $(BINARY)

# Run the program
run:
		./$(BINARY)
		
#generate documentation in '<login>/doc' folder
doc: $(DOXY) src/*
		rm -Rf $(DOCDIR)
		mkdir $(DOCDIR)
		doxygen Doxyfile
 
# Delete binary, object files and created documentation
clean:
		rm -Rf $(BINARY) $(OBJECTS) $(DOCDIR)

# Count all lines in all files
count:
		wc -l $(SRCDIR)/*.cpp $(SRCDIR)/*.h $(SRCDIR)/fields/*.cpp $(SRCDIR)/fields/*.h $(SRCDIR)/units/*.cpp $(SRCDIR)/units/*.h

# Rules to compile 
$(BINARY): $(OBJECTS)
		$(LD) -o $(BINARY) $(OBJECTS) $(LIBS)
 
$(SRCDIR)/PMMenu.o: $(SRCDIR)/PMMenu.cpp $(SRCDIR)/PMMenu.h
		$(CXX) $(CXXFLAGS) -c -o $@ $< $(LIBS) 

$(SRCDIR)/fields/PMField.o: $(SRCDIR)/fields/PMField.cpp $(SRCDIR)/fields/PMField.h
		$(CXX) $(CXXFLAGS) -c -o $@ $< $(LIBS)
		
$(SRCDIR)/PMMap.o: $(SRCDIR)/PMMap.cpp $(SRCDIR)/PMMap.h\
		$(SRCDIR)/fields/PMField.h
		$(CXX) $(CXXFLAGS) -c -o $@ $< $(LIBS)
		
$(SRCDIR)/units/PMUnit.o: $(SRCDIR)/units/PMUnit.cpp $(SRCDIR)/units/PMUnit.h\
		$(SRCDIR)/PMMap.h
		$(CXX) $(CXXFLAGS) -c -o $@ $< $(LIBS)
		
$(SRCDIR)/units/PMPacman.o: $(SRCDIR)/units/PMPacman.cpp $(SRCDIR)/units/PMPacman.h\
		$(SRCDIR)/fields/PMField.h $(SRCDIR)/units/PMUnit.h
		$(CXX) $(CXXFLAGS) -c -o $@ $< $(LIBS)

$(SRCDIR)/fields/PMWall.o: $(SRCDIR)/fields/PMWall.cpp $(SRCDIR)/fields/PMWall.h\
		$(SRCDIR)/units/PMPacman.h $(SRCDIR)/fields/PMField.h
		$(CXX) $(CXXFLAGS) -c -o $@ $< $(LIBS)
		
$(SRCDIR)/fields/PMFood.o: $(SRCDIR)/fields/PMFood.cpp $(SRCDIR)/fields/PMFood.h\
		$(SRCDIR)/units/PMPacman.h $(SRCDIR)/fields/PMField.h
		$(CXX) $(CXXFLAGS) -c -o $@ $< $(LIBS)
		
$(SRCDIR)/fields/PMGreatFood.o: $(SRCDIR)/fields/PMGreatFood.cpp $(SRCDIR)/fields/PMGreatFood.h\
		$(SRCDIR)/units/PMPacman.h $(SRCDIR)/fields/PMField.h
		$(CXX) $(CXXFLAGS) -c -o $@ $< $(LIBS)
		
$(SRCDIR)/fields/PMBonus.o: $(SRCDIR)/fields/PMBonus.cpp $(SRCDIR)/fields/PMBonus.h\
		$(SRCDIR)/units/PMPacman.h $(SRCDIR)/fields/PMField.h
		$(CXX) $(CXXFLAGS) -c -o $@ $< $(LIBS)

$(SRCDIR)/fields/PMTeleport.o: $(SRCDIR)/fields/PMTeleport.cpp $(SRCDIR)/fields/PMTeleport.h\
		$(SRCDIR)/units/PMPacman.h $(SRCDIR)/fields/PMField.h $(SRCDIR)/PMMap.h
		$(CXX) $(CXXFLAGS) -c -o $@ $< $(LIBS)

$(SRCDIR)/fields/PMGround.o: $(SRCDIR)/fields/PMGround.cpp $(SRCDIR)/fields/PMGround.h\
		$(SRCDIR)/units/PMPacman.h $(SRCDIR)/fields/PMField.h
		$(CXX) $(CXXFLAGS) -c -o $@ $< $(LIBS)

$(SRCDIR)/PMMapReader.o: $(SRCDIR)/PMMapReader.cpp $(SRCDIR)/PMMapReader.h\
		$(SRCDIR)/PMMap.h $(SRCDIR)/fields/PMField.h $(SRCDIR)/fields/PMWall.h\
		$(SRCDIR)/fields/PMFood.h $(SRCDIR)/fields/PMGreatFood.h $(SRCDIR)/fields/PMBonus.h\
		$(SRCDIR)/fields/PMTeleport.h $(SRCDIR)/fields/PMGround.h
		$(CXX) $(CXXFLAGS) -c -o $@ $< $(LIBS)

$(SRCDIR)/units/PMMonster.o: $(SRCDIR)/units/PMMonster.cpp $(SRCDIR)/units/PMMonster.h\
		$(SRCDIR)/units/PMUnit.h $(SRCDIR)/units/PMPacman.h
		$(CXX) $(CXXFLAGS) -c -o $@ $< $(LIBS)

$(SRCDIR)/units/PMBlinky.o: $(SRCDIR)/units/PMBlinky.cpp $(SRCDIR)/units/PMBlinky.h\
		$(SRCDIR)/units/PMMonster.h $(SRCDIR)/units/PMPacman.h
		$(CXX) $(CXXFLAGS) -c -o $@ $< $(LIBS)

$(SRCDIR)/units/PMPinky.o: $(SRCDIR)/units/PMPinky.cpp $(SRCDIR)/units/PMPinky.h\
		$(SRCDIR)/units/PMMonster.h $(SRCDIR)/units/PMPacman.h
		$(CXX) $(CXXFLAGS) -c -o $@ $< $(LIBS)

$(SRCDIR)/units/PMInky.o: $(SRCDIR)/units/PMInky.cpp $(SRCDIR)/units/PMInky.h\
		$(SRCDIR)/units/PMMonster.h $(SRCDIR)/units/PMPacman.h
		$(CXX) $(CXXFLAGS) -c -o $@ $< $(LIBS)

$(SRCDIR)/units/PMClyde.o: $(SRCDIR)/units/PMClyde.cpp $(SRCDIR)/units/PMClyde.h\
		$(SRCDIR)/units/PMMonster.h $(SRCDIR)/units/PMPacman.h
		$(CXX) $(CXXFLAGS) -c -o $@ $< $(LIBS)

$(SRCDIR)/PMGame.o: $(SRCDIR)/PMGame.cpp $(SRCDIR)/PMGame.h\
		$(SRCDIR)/units/PMPacman.h $(SRCDIR)/PMMapReader.h $(SRCDIR)/units/PMMonster.h\
		$(SRCDIR)/units/PMBlinky.h $(SRCDIR)/units/PMPinky.h $(SRCDIR)/units/PMInky.h\
		$(SRCDIR)/units/PMClyde.h $(SRCDIR)/PMMap.h $(SRCDIR)/PMMenu.h
		$(CXX) $(CXXFLAGS) -c -o $@ $< $(LIBS)

$(SRCDIR)/main.o: $(SRCDIR)/main.cpp\
		$(SRCDIR)/PMGame.h
		$(CXX) $(CXXFLAGS) -c -o $@ $< $(LIBS)
