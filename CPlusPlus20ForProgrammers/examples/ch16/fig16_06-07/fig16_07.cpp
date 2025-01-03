// fig16_07.cpp
// Using the deitel.math module's average function.
import <algorithm>;
import <iostream>;
import <iterator>;
import <vector>;
import deitel.math; // import the deitel.math module

int main() {
   std::ostream_iterator<int> output(std::cout, " ");
   std::vector integers{ 1, 2, 3, 4 };

   std::cout << "vector integers: ";
   std::copy(integers.begin(), integers.end(), output);

   std::cout << "\naverage of integer's elements: "
      << deitel::math::average(integers) << '\n';
}




 /*************************************************************************
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
