/******************************************************************************
  file:          RealTimeStamp.h                     
  author:        Philip Scott                
  verson:        1.0                         
  date:          26/05/2009        
  description:   Wrapper class for a double which represents a realtime time-
                 stamp stored as a number of seconds since the UNIX epoch
                 (non-integer values are used to represent non-whole numebrs
                 of seconds)
 
  This source code copyright (C) 2009  
  All rights reserved.  
******************************************************************************/

#include "DateTimeHelper.h"

class RealTimeStamp
{
    public:
        std::string toString()
        {
            int numSeconds = static_cast<int>( floor(value_m) );
            int numMinutes = numSeconds / 60;
            int numHours   = numMinutes / 60;
            int numDays    = numHours / 24;

            int year   = 1970;
            int month  = 0;
   
            int daysInYear = DateTimeHelper::numDaysInYear(year);
            while ( daysInYear < numDays )
            {
                numDays -= daysInYear;
                year++;
                daysInYear = DateTimeHelper::numDaysInYear(year);
            } 

            int daysInMonth = DateTimeHelper::numDaysInMonth(month, year);
            while (daysInMonth < numDays)
            {
                numDays -= daysInMonth;
                month = (month + 1) % 12;
                daysInMonth = DateTimeHelper::numDaysInMonth(month, year);
            } 
                            
            std::ostringstream ss;
            ss << numDays << DateTimeHelper::shortMonthName(month) << year
               << " " << numHours % 24
               << ":" << numMinutes % 60
               << ":" << numSeconds % 60 
               << "." << floor((value_m - numSeconds)*1000);
            return ss.str();
        }

        double value_m;
};
