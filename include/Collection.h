#ifndef COLLECTION_H
#define COLLECTION_H

#include <boost/shared_ptr.hpp>
#include <memory>
#include <vector>
#include <algorithm>
#include <iostream>
#include <ostream> 
#include <TRandom3.h>
#include <TLorentzVector.h>
#include "CustomTree.h"

class Collection;
typedef boost::shared_ptr<Collection> CollectionPtr;


class Collection {
 public:
  
  //-------------------------------------------------------------
  // Constructors and destructors
  //-------------------------------------------------------------
  
  Collection ( CustomTree & d, size_t size );
  Collection ( Collection & c );
  
  //-------------------------------------------------------------
  // Set functions
  //-------------------------------------------------------------
  
  void SetRawIndices( std::vector<unsigned short> & i ) { m_raw_indices  = i; }
  void SetLeadNConstituents ( unsigned short n ) {
    m_raw_indices.clear();
    for (unsigned short i = 0; i < n; ++i) 
      m_raw_indices.push_back ( i );
  }
  
  //-------------------------------------------------------------
  // Get functions
  //-------------------------------------------------------------
  
  template<class Object1> Object1 GetConstituent(unsigned short i) { 
    if ( m_hlt_filter_index > 0 ) return Object1 (*this, m_raw_indices[i], m_hlt_filter_index ); 
    else                          return Object1 (*this, m_raw_indices[i]);
  }
  
  std::vector<unsigned short> * GetRawIndices() { return &m_raw_indices; } 
  unsigned short                GetSize()       { return  m_raw_indices.size();  } 
  CustomTree *               GetData()       { return  m_data; } 

  //------------------------------------------------------------------------------------------
  // Member variables
  //------------------------------------------------------------------------------------------
  
 protected:
  short m_hlt_filter_index;
  std::vector<unsigned short> m_raw_indices; 
  CustomTree * m_data;
  
};

#endif 

