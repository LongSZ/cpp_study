// Fig. 10.29: Salaried.h
// Salaried implements the CompensationModel interface.
#pragma once
#include <string> 
#include "CompensationModel.h" // CompensationModel definition

class Salaried : public CompensationModel {
public:
   Salaried(double salary);
   double earnings() const override;      
   std::string toString() const override; 
private:
   double m_salary{0.0}; 
}; 



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
