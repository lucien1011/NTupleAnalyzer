#ifndef analysisClass_PrefireRate_h
#define analysisClass_PrefireRate_h

#include "analysisClass.h"

class analysisClass_PrefireRate : public analysisClass {
 
 public:
  analysisClass_PrefireRate (std::string inputList, std::string treeList, std::string out_file): 
  analysisClass(inputList, treeList, out_file) {};

  ~analysisClass_PrefireRate(){};
  void loop();
  bool checkTriggerBit(const int & ibit,const int & ibx);
  void loadTrigMap();
  bool isSelectedBx(int bunchNumber);

private :

  std::map<std::string,int> HFPrefiringBitMap;
  std::map<std::string,int>::iterator trigbit_iter;
  std::map<std::string,TH1F*> histoMap;
  std::vector<ULong64_t> tw1;
  std::vector<ULong64_t> tw2;

};

#endif

