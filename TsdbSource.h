/******************************************************************************
  file:          TsdbSource.h                     
  author:        Philip Scott                
  verson:        1.0                         
  date:          26/05/2009        
  description:   Class to access data directly from a Goldman Sachs TSDB
                 data file.
  
  This source code copyright (C) 2009
  All rights reserved.  
******************************************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include <vector>
#include "RealTimeStamp.h"
#include "Knot.h"

template<class KnotType>
class TsdbSource
{
    public:
        TsdbSource(std::string filename)
        {
            fileStream_m.open(filename.c_str(), std::ios::binary);
            isOk_m = !fileStream_m.fail();
       }
    
        void seekToBeginning()
        {
            
        }
        
        KnotType getValue()
        {
            KnotType k;
            double foo;
            fileStream_m.read((char*) &k.index_m.value_m, sizeof(foo));
            fileStream_m.read((char*) &k.value_m, sizeof(foo));            
            return k;
        }
        
        void readAll()
        {
            fileStream_m.seekg(0, std::ios::beg);
            while(!fileStream_m.eof())
            {
                getValue();
            }
        }

    private:
        std::ifstream fileStream_m;
        std::vector<KnotType> cache_m;
        bool isOk_m;
};

typedef Knot<RealTimeStamp, double> RTKnot;
typedef TsdbSource<RTKnot> RTTsdbSource;