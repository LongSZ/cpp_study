// fig12_09.cpp
// binarySearch function with a precondition and a postcondition.
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

template <typename T>                                
int binarySearch(const vector<T>& items, const T& key)
   [[pre audit: is_sorted(begin(items), end(items))]]
   [[post loc: loc == -1 || (loc >= 0 && loc < items.size())]];

int main() {
   // sorted vector v1 satisfies binarySearch's precondition
   vector v1{10, 20, 30, 40, 50, 60, 70, 80, 90};
   int result1 = binarySearch(v1, 70);
   cout << "70 was " << (result1 != -1 ? "" : "not ") << "found in v1\n";
    
   // unsorted vector v2 violates binarySearch's precondition
   vector v2{60, 70, 80, 90, 10, 20, 30, 40, 50};
   int result2 = binarySearch(v2, 60);
   cout << "60 was " << (result2 != -1 ? "" : "not ") << "found in v2\n";
}

// perform a binary search
template <typename T>                                
int binarySearch(const vector<T>& items, const T& key) {     
   size_t low{0}; // low index of elements to search                 
   size_t high{items.size() - 1}; // high index
   size_t middle{(low + high + 1) / 2}; // middle element            
   int loc{-1}; // key's index; -1 if not found              

   do { // loop to search for element                             
      // if the element is found at the middle                
      if (key == items[middle]) {                             
         loc = middle; // loc is the current middle 
      }                                                       
      else if (key < items[middle]) { // middle is too high   
         high = middle - 1; // eliminate the higher half      
      }                                                       
      else { // middle element is too low                     
         low = middle + 1; // eliminate the lower half        
      }                                                       

      middle = (low + high + 1) / 2; // recalculate the middle
   } while ((low <= high) && (loc == -1));               

   return loc; // return location of key
} 


/**************************************************************************
 * (C) Copyright 1992-2021 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
