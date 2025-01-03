// Fig. 10.19: Employee.h
// Employee abstract base class.
#pragma once // prevent multiple inclusions of header
#include <string> 
#include <string_view> 

class Employee {
public:
   Employee(std::string_view name);
   virtual ~Employee() = default; 

   void setName(std::string_view name); 
   std::string getName() const; 

   double earnings() const; // not virtual 
   std::string toString() const; // not virtual 
protected:
   virtual std::string getString() const; // virtual
private:
   std::string m_name;
   virtual double getPay() const = 0; // pure virtual
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
