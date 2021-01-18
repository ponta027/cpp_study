#include <iostream>
#include <map>


void mapSample()
{
   std::cout << "[START]map Sample" << std::endl;
   std::map<std::string,int> accessCount;
   accessCount.insert( std::make_pair("192.168.0.10",1));
   accessCount.insert( std::make_pair("192.168.0.20",1));

   for( auto& it : accessCount)
   {
       std::cout << it.first<< ":";
       std::cout << it.second << std::endl;
   }


   std::string sample="192.168.0.20";
   auto it = accessCount.find( sample );
   if( it != accessCount.end() )
   {
       std::cout << "found" << std::endl;
   }

   std::cout << accessCount["192.168.0.20"] << std::endl;
   std::cout << accessCount["192.168.0.30"] << std::endl;

   std::cout << "empty:" << accessCount.empty() << std::endl;
   std::cout << "size:" << accessCount.size() << std::endl;

   accessCount.erase("192.168.0.10");

   for( auto& it : accessCount)
   {
       std::cout << it.first<< ":";
       std::cout << it.second << std::endl;
   }


}


