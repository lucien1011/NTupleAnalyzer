#include "CustomTree.h"
#include "analysisClass.h"

void analysisClass::loop(){


  CustomTree * tuple_tree = getTree<CustomTree>("tuple_tree");
  int n_events = tuple_tree -> fChain -> GetEntries();
  std::cout << "n events = " << n_events << std::endl;

  tuple_tree -> fChain -> SetBranchStatus("*", kFALSE);

  tuple_tree -> fChain -> SetBranchStatus("run", kTRUE);
  tuple_tree -> fChain -> SetBranchStatus("event", kTRUE);
  tuple_tree -> fChain -> SetBranchStatus("bx", kTRUE);

  for (int i = 0; i < n_events; ++i){
    tuple_tree -> GetEntry(i);
    if ( (i + 1) % 1000 == 0 ) std::cout << "Processing event " << i + 1 << "/" << n_events << std::endl;

    int RunNumber = tuple_tree -> run ;
    int bunchNumber = tuple_tree -> bx ;
    int eventNumber = tuple_tree -> event;

    // std::cout << "Run: " << RunNumber << std::endl;
    // std::cout << "Event: " << eventNumber << std::endl;
    // std::cout << "Bunch Number: " << bunchNumber << std::endl;

    

  };
  

}
