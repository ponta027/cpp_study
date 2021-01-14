#include <iostream>
#include <vector>
#include <map>

void intVectorSample( void )
{
    std::cout << "[START]vector sample" << std::endl;
    std::vector<int> intList;

    intList.push_back(1);
    intList.push_back(3);
    intList.push_back(5);
    intList.push_back(7);

    // iterator  
    for( std::vector<int>::const_iterator it = intList.begin() , e = intList.end() ;it != e ; it++)
    {
        std::cout << *it << ",";
    }
    std::cout << std::endl;
    for( const auto& it:intList)
    {
        std::cout << it << ",";
    }
    std::cout << std::endl;

    int size = intList.size();
    std::cout << "vector size:" << size<< std::endl;
    std::cout << "element[" << size << "]:"<<intList.at(size-1) << std::endl;
    for( int i =0 ; i < size ; i++)
    {
       intList.pop_back();
    }
    if( intList.empty()){
        std::cout << "empty " << std::endl;
    }


}

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


int main(int argc, char** argv)
{
    intVectorSample();
    mapSample();
    return 0;
}
