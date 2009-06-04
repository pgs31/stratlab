/******************************************************************************
  file:          RealTimeStamp.h                     
  author:        Philip Scott                
  verson:        1.0                         
  date:          26/05/2009        
  description:   Wrapper class for a tuple of an index type and a value type
                 e.g. RealTimeStamp -> Double
                 Which represents a point on a curve.
  
  This source code copyright (C) 2009
  All rights reserved.  
******************************************************************************/

template<class IndexType, class ValueType>
class Knot
{
    public:
        Knot(IndexType index, IndexType value) : index_m(index), value_m(value) {} 
        Knot() {}
        
        std::string toString()
        {
            std::ostringstream ss;
            ss << index_m.toString();
            ss << " -> ";
            ss << value_m;
            return ss.str(); 
        }
        
        IndexType index_m;
        ValueType value_m;
};
