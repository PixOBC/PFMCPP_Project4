/*
 Project 4 - Part 2 / 9
 Video: Chapter 3 Part 6

 Create a branch named Part2

New/This/Pointers/References conclusion

    Build/Run often with this task to make sure you're not breaking the code with each step.
    I recommend committing after you get each step working so you can revert to a working version easily if needed.
 
 0) in the blank space below, declare/define an empty struct named 'A' on a single Line. [DONE]
     on the lines below it, write a struct named 'HeapA' that correctly shows how to own an instance of 'A' ON THE HEAP without leaking, without using smart pointers.
 */

// With pointers and new keyword
struct A { };

struct HeapA
{
    A* pointerToA = new A();
    ~HeapA()
    {
        delete pointerToA;
        pointerToA = nullptr;
    }
};
//Questions
 /*
  * [DONE]
 1) Edit your 3 structs so that they own a heap-allocated primitive type without using smart pointers named 'value'
         IntType should own a heap-allocated int, for example.
 [DONE]
  2) give it (your struct) a constructor that takes the appropriate primitive type.
    This argument will initialize the owned primitive's ('*value') value.
         i.e. if you're owning an int on the heap, your constructor argument will initialize that heap-allocated int's value.


 3) modify those add/subtract/divide/multiply member functions from chapter 2 on it (your primitive type - modify how?)
         a) make them (member functions) modify the owned numeric type - NOT SURE
         b) set them up so they can be chained together.
             i.e.
             DoubleType dt(3.5);
             dt.add(3.0).multiply(-2.5).divide(7.2); //an example of chaining
 
 4) write add/subtract/divide/multiply member functions for each type that take your 3 UDTs
        These are in addition to your member functions that take primitives
        for example, IntType::divide(const DoubleType& dt);
        These functions should return the result of calling the function that takes the primitive.
     
 5) Don't let your heap-allocated owned type leak!
 
 6) REPLACE YOUR MAIN() WITH THE MAIN() BELOW.
    It has some intentional mistakes that you need to fix to match the expected output
    i.e. don't forget to dereference your pointers to get the value they hold.

 7) click the [run] button.  Clear up any errors or warnings as best you can.
 */

// Warnings
/*
your program should generate the following output EXACTLY.
This includes the warnings.
Use a service like https://www.diffchecker.com/diff to compare your output. 
you'll learn to solve the conversion warnings in the next project part.

18 warnings generated.
FloatType add result=4
FloatType subtract result=2
FloatType multiply result=4
FloatType divide result=0.25

DoubleType add result=4
DoubleType subtract result=2
DoubleType multiply result=4
DoubleType divide result=0.8

IntType add result=4
IntType subtract result=2
IntType multiply result=4
IntType divide result=1

Chain calculation = 590
New value of ft = (ft + 3.0f) * 1.5f / 5.0f = 0.975
---------------------

Initial value of dt: 0.8
Initial value of it: 590
Use of function concatenation (mixed type arguments) 
New value of dt = (dt * it) / 5.0f + ft = 95.375
---------------------

Intercept division by 0 
New value of it = it / 0 = error: integer division by zero is an error and will crash the program!
590
New value of ft = ft / 0 = warning: floating point division by zero!
inf
New value of dt = dt / 0 = warning: floating point division by zero!
inf
---------------------

good to go!


*/

// When finished
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].

 If you didn't already:
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

//============================================================================================================

#include <iostream>

struct FloatType
{
    // owned float type
    float* value;
    // New operator syntax <type>* <variable> = new <type>(optional arguments)
    FloatType(float floatValue)
        : value(new float(floatValue)) // optional argument floatValue in new operator syntax is used to initialise the memory of 'value' pointer
    {
    }
    ~FloatType()
    {
        delete value;
        value = nullptr;
    }

    // 4. In addition to your member functions that take primitives Write add/subtract...member functions for each type that take your 3 UDTs
    // These functions should return the result of calling the function that takes the primitive (i.e. float, double int)
    FloatType& add(float lhs, float rhs);
    FloatType& subtract(float lhs, float rhs);
    FloatType& multiply(float lhs,float rhs);
    FloatType& divide(float lhs,float rhs);

};

// 3. make member functions modify the numeric type or modify the member functions?
// Member functions that return a reference to the class type - Chaining
//Ch3.6 @17:30
// Currently the only way to call a member function is via an existing object
// @18:58 Modifying the member functions so that they return a reference
FloatType& FloatType::add( float lhs, float rhs ) // am I changing the return type because float is owned by it?
{
    return *this; // @19:15 returns a reference to a FloatType so we can use member variables and call member functions of that returned reference
}

FloatType& FloatType::subtract( float lhs, float rhs )
    {
        return *this;
    }

FloatType& FloatType::multiply( float lhs,float rhs )
{
    return lhs * rhs;
}

FloatType& FloatType::divide( float lhs,float rhs )
{
    if (rhs == 0.0f)
    {
        std::cout << "\n" << "warning, floating point division by zero returns 'inf' !" << std::endl;
    }
    return *this;
}

//============================================================================================================

struct DoubleType
{
    double* value; // create pointer here

    DoubleType(double doubleValue)
        : value(new double(doubleValue)) // allocate heap memory here and pass in optional argument 'doubleValue'
    {
    }
    ~DoubleType()
    {
        delete value;
        value = nullptr;
    }

    DoubleType& add( double lhs, double rhs);
    DoubleType& subtract( double lhs, double rhs);
    DoubleType& multiply( double lhs, double rhs);
    DoubleType& divide( double lhs, double rhs);

};

DoubleType& DoubleType::add( double lhs, double rhs )
{
    return *this;
}
DoubleType& DoubleType::subtract( double lhs, double rhs )
{
    return *this;
}

DoubleType& DoubleType::multiply( double lhs,double rhs )
{
    return *this;
}

DoubleType& DoubleType::divide( double lhs,double rhs )
{
    if (rhs == 0.0)
        std::cout << "\n" << "warning, floating point division by zero returns 'inf' !" << std::endl;
        
    return *this;
}

//============================================================================================================

struct IntType
{
    int* value;

    IntType(int intValue)
        : value(new(intValue))
    {
    }
    ~IntType()
    {
        delete value;
        value = nullptr;
    }

    IntType& add(int lhs, int rhs);
    IntType& subtract(int lhs, int rhs);
    IntType& multiply(int lhs, int rhs);
    IntType& divide(int lhs, int rhs);

};

IntType& IntType::add( int lhs, int rhs )
{
    return *this;
}

IntType& IntType::subtract( int lhs, int rhs )
{
    return *this;
}

IntType& IntType::multiply( int lhs,int rhs )
{
    return *this;
}

IntType& IntType::divide( int lhs,int rhs )
{
    if (rhs == 0)
    {
        std::cout << "error, integer division by zero will crash the program!" << std::endl;
        std::cout << "returning lhs" << std::endl;
        return lhs;
    }
    return *this;
}

//============================================================================================================

// NEW MAIN FUNCTION
int main()
{
    //testing instruction 0
    HeapA heapA;

    //assign heap primitives
    FloatType ft ( 2.0f );
    DoubleType dt ( 2.0 );
    IntType it ( 2 ) ;

    std::cout << "FloatType add result=" << ft.add( 2.0f ).value << std::endl;
    std::cout << "FloatType subtract result=" << ft.subtract( 2.0f ).value << std::endl;
    std::cout << "FloatType multiply result=" << ft.multiply( 2.0f ).value << std::endl;
    std::cout << "FloatType divide result=" << ft.divide( 16.0f).value << std::endl << std::endl;

    std::cout << "DoubleType add result=" << dt.add(2.0).value << std::endl;
    std::cout << "DoubleType subtract result=" << dt.subtract(2.0).value << std::endl;
    std::cout << "DoubleType multiply result=" << dt.multiply(2.0).value << std::endl;
    std::cout << "DoubleType divide result=" << dt.divide(5.f).value << std::endl << std::endl;

    std::cout << "IntType add result=" << it.add(2).value << std::endl;
    std::cout << "IntType subtract result=" << it.subtract(2).value << std::endl;
    std::cout << "IntType multiply result=" << it.multiply(2).value << std::endl;
    std::cout << "IntType divide result=" << it.divide(3).value << std::endl << std::endl;
    std::cout << "Chain calculation = " << (it.multiply(1000).divide(2).subtract(10).add(100)).value << std::endl;

    // FloatType object instanciation and method tests
    // --------
    std::cout << "New value of ft = (ft + 3.0f) * 1.5f / 5.0f = " << ft.add( 3.0f ).multiply(1.5f).divide(5.0f).value << std::endl;

    std::cout << "---------------------\n" << std::endl;

    // DoubleType/IntType object instanciation and method tests
    // --------
    std::cout << "Initial value of dt: " << dt.value << std::endl;
    std::cout << "Initial value of it: " << it.value << std::endl;
    // --------
    std::cout << "Use of function concatenation (mixed type arguments) " << std::endl;
    std::cout << "New value of dt = (dt * it) / 5.0f + ft = " << (dt.multiply(it).divide(5.0f).add(ft).value) << std::endl;

    std::cout << "---------------------\n" << std::endl;

    // Intercept division by 0
    // --------
    std::cout << "Intercept division by 0 " << std::endl;
    std::cout << "New value of it = it / 0 = " << it.divide(0).value << std::endl;
    std::cout << "New value of ft = ft / 0 = " << ft.divide(0).value << std::endl;
    std::cout << "New value of dt = dt / 0 = " << dt.divide(0).value << std::endl;

    std::cout << "---------------------\n" << std::endl;

    std::cout << "good to go!\n";

    return 0;
}
