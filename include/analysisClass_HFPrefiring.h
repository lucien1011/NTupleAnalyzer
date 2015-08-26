#ifndef analysisClass_HFPrefiring_h
#define analysisClass_HFPrefiring_h

#include "analysisClass.h"

class analysisClass_HFPrefiring : public analysisClass {
 
 public:
  analysisClass_HFPrefiring (std::string inputList, std::string treeList, std::string out_file): 
  analysisClass(inputList, treeList, out_file) {};

  ~analysisClass_HFPrefiring(){};
  void loop();
  bool checkTriggerBit(const int & ibit,const int & ibx);
  void loadTrigMap();
  bool isSelectedBx(int bunchNumber);

private :

  std::map<std::string,int> HFPrefiringBitMap;
  std::map<std::string,int>::iterator trigbit_iter;
  std::vector<ULong64_t> tw1;
  std::vector<ULong64_t> tw2;

};

#endif

