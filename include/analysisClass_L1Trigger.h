#ifndef analysisClass_L1Trigger_h
#define analysisClass_L1Trigger_h

#include "analysisClass.h"

class analysisClass_L1Trigger : public analysisClass {
 
 public:
  analysisClass_L1Trigger (std::string inputList, std::string treeList, std::string out_file): 
  analysisClass(inputList, treeList, out_file) {};

  ~analysisClass_L1Trigger(){};
  void loop();
  bool checkTriggerBit(const int & ibit,const int & ibx);
  void loadTrigMap();
 

private :

  std::map<std::string,int> L1TriggerBitMap;
  std::map<std::string,int>::iterator trigbit_iter;
  std::map<int,std::vector<std::string>> preTrigEvent;
  std::map<int,int> eventLumiMap;
  std::vector<ULong64_t> tw1;
  std::vector<ULong64_t> tw2;

};

#endif

