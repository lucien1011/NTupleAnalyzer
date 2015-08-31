COMP=g++
FLAGS=-std=c++11
ROOTINC= -I`root-config --incdir`
ROOTLIBS=  `root-config --glibs --cflags | sed 's/-pthread//g'` -lMinuit 
INC= -I./include 
LIBS= ${ROOTLIBS} 
SRC= ./src
BASE_OBJECTS=$(SRC)/analysisClass_HFPrefiring.o $(SRC)/analysisClass.o $(SRC)/baseClass.o
TREE_OBJECTS=$(SRC)/L1Tree.o $(SRC)/L1ExtraTree.o 
OBJECTS=$(BASE_OBJECTS) $(TREE_OBJECTS)

default: main

main: $(SRC)/main.o $(OBJECTS) 
	$(COMP) $(INC) $(ROOTINC) $(LIBS) $(FLAGS) $(CFLAGS) -o $@ $(OBJECTS) $(SRC)/$@.o

.cc.o:
	$(COMP) -c $(INC) $(ROOTINC) $(FLAGS) $(CFLAGS) -o $@ $<

.C.o:
	$(COMP) -c $(INC) $(ROOTINC) $(FLAGS) $(CFLAGS) -o $@ $<

clean:
	rm -rf main
	rm -rf $(SRC)/*.o

