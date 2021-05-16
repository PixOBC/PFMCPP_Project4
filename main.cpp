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

[DONE]
 3) modify those add/subtract/divide/multiply member functions from chapter 2 on it (your primitive type - modify how?)
         a) make them (member functions) modify the owned numeric type - [DONE]
         b) set them up so they can be chained together.
             i.e.
             DoubleType dt(3.5);
             dt.add(3.0).multiply(-2.5).divide(7.2); //an example of chaining
 
 4) write add/subtract/divide/multiply member functions for each type that take your 3 UDTs (FloatType, DoubleType, IntType)
        THESE ARE IN ADDITION TO YOUR MEMBER FUNCTIONS THAT TAKE PRIMITIVES
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

// forward declarations so that I can use not-yet implemented UDTs
struct FloatType;
struct DoubleType;
struct IntType;

struct FloatType
{
    // owned float type
    float* value;
    // New operator syntax <type>* <variable> = new <type>(optional arguments)
    FloatType(float floatValue) // value given by user at declaration
        : value(new float(floatValue)) // optional argument floatValue in new operator syntax is used to initialise the memory of 'value' pointer
    {
    }
    ~FloatType()
    {
        delete value;
        value = nullptr;
    }

    // @18:58 Modifying the member functions so that they return a reference
    // We dereference 'this' pointer to get access to get our class instance from inside each one of it's functions
    FloatType& add(float fValue);
    FloatType& subtract(float fValue);
    FloatType& multiply(float fValue);
    FloatType& divide(float fValue);

    // Functions that return the result of the above functions taking primitives
    FloatType& add(const FloatType& dVal);
    FloatType& subtract(const FloatType& dVal);
    FloatType& multiply(const FloatType& dVal);
    FloatType& divide(const FloatType& dVal);

    FloatType& add(const DoubleType& dVal);
    FloatType& subtract(const DoubleType& dVal);
    FloatType& multiply(const DoubleType& dVal);
    FloatType& divide(const DoubleType& dVal);

    FloatType& add(const IntType& iVal);
    FloatType& subtract(const IntType& iVal);
    FloatType& multiply(const IntType& iVal);
    FloatType& divide(const IntType& iVal);
};

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

    // Member functions that return a reference to the class type
    DoubleType& add(double dValue);
    DoubleType& subtract(double dValue);
    DoubleType& multiply(double dValue);
    DoubleType& divide(double dValue);

    // Functions that return the result of the above functions taking primitives
    DoubleType& add(const DoubleType& fVal);
    DoubleType& subtract(const DoubleType& fVal);
    DoubleType& multiply(const DoubleType& fVal);
    DoubleType& divide(const DoubleType& fVal);

    DoubleType& add(const FloatType& fVal);
    DoubleType& subtract(const FloatType& fVal);
    DoubleType& multiply(const FloatType& fVal);
    DoubleType& divide(const FloatType& fVal);

    DoubleType& add(const IntType& fVal);
    DoubleType& subtract(const IntType& fVal);
    DoubleType& multiply(const IntType& fVal);
    DoubleType& divide(const IntType& fVal);

};

struct IntType
{
    int* value;

    IntType(int intValue)
            : value(new int(intValue))
    {
    }
    ~IntType()
    {
        delete value;
        value = nullptr;
    }

    IntType& add(int iValue);
    IntType& subtract(int iValue);
    IntType& multiply(int iValue);
    IntType& divide(int iValue);

    // Functions that return the result of the above functions taking primitives
    IntType& add(const IntType& fVal);
    IntType& subtract(const IntType& fVal);
    IntType& multiply(const IntType& fVal);
    IntType& divide(const IntType& fVal);

    IntType& add(const FloatType& fVal);
    IntType& subtract(const FloatType& fVal);
    IntType& multiply(const FloatType& fVal);
    IntType& divide(const FloatType& fVal);

    IntType& add(const DoubleType& dVal);
    IntType& subtract(const DoubleType& dVal);
    IntType& multiply(const DoubleType& dVal);
    IntType& divide(const DoubleType& dVal);


};

FloatType& FloatType::add(float fValue)
{
    if(this->value != nullptr)
    {
        *this->value += fValue;
    }
    return *this; // @19:15 returns a reference to a FloatType so we can use member variables and call member functions of that returned reference
}

FloatType& FloatType::subtract(float fValue) // need const to take in an rvalue?
{
    if(this->value != nullptr)
    {
        *this->value -= fValue;
    }
    return *this;
}

FloatType& FloatType::multiply(float fValue)
{
    if(this->value != nullptr)
    {
        *this->value *= fValue;
    }
    return *this;
}

FloatType& FloatType::divide(float fValue)
{
    
    if(fValue == 0.0f)
    {
        std::cout << "warning: floating point division by zero!" << std::endl;
        *this->value /= fValue;
    }
    else
    {
        *this->value /= fValue;
    }
    
    return *this;
}

// THESE FUNCTIONS SHOULD RETURN THE RESULT OF THE RESPECTIVE FUNCTION THAT TAKES THE PRIMITIVE.
// e.g. getting the results from returned value of call add(float value)

FloatType& FloatType::add(const FloatType& fVal)
{
    return add(*fVal.value);
}

FloatType& FloatType::subtract(const FloatType& fVal)
{
    return subtract(*fVal.value);
}

FloatType& FloatType::multiply(const FloatType& fVal)
{
    return multiply(*fVal.value);
}

FloatType& FloatType::divide(const FloatType& fVal)
{
    return divide(*fVal.value);
}

FloatType& FloatType::add(const DoubleType& dVal)
{
    return add(*dVal.value);
}

FloatType& FloatType::subtract(const DoubleType& dVal)
{
    return subtract(*dVal.value);
}

FloatType& FloatType::multiply(const DoubleType& dVal)
{
    return multiply(*dVal.value);
}

FloatType& FloatType::divide(const DoubleType& dVal)
{
    return divide(*dVal.value);
}

FloatType& FloatType::add(const IntType& iVal)
{
    return add(*iVal.value);
}

FloatType& FloatType::subtract(const IntType& iVal)
{
    return add(*iVal.value);
}

FloatType& FloatType::multiply(const IntType& iVal)
{
    return multiply(*iVal.value);
}

FloatType& FloatType::divide(const IntType& iVal)
{
    return divide(*iVal.value);
}

//============================================================================================================

DoubleType& DoubleType::add(double dValue)
{
    if(this->value != nullptr)
    {
        *this->value += dValue;
    }
    return *this;
}
DoubleType& DoubleType::subtract(double dValue)
{
    if(this->value != nullptr)
    {
        *this->value -= dValue;
    }
    return *this;
}

DoubleType& DoubleType::multiply(double dValue)
{
    if(this->value != nullptr)
    {
        *this->value *= dValue;
    }
    return *this;
}

DoubleType& DoubleType::divide(double dValue)
{
    if(dValue == 0.0)
    {
        std::cout << "warning: floating point division by zero!" << std::endl;
        *this->value /= dValue;
    }
    else
    {
        *this->value /= dValue;
    }
    return *this;
}

//UDT arguments

DoubleType& DoubleType::add(const FloatType& fVal)
{
    return add(*fVal.value);
}

DoubleType& DoubleType::subtract(const FloatType& fVal)
{
    return subtract(*fVal.value);
}

DoubleType& DoubleType::multiply(const FloatType& fVal)
{
    return multiply(*fVal.value);
}

DoubleType& DoubleType::divide(const FloatType& fVal)
{
    return divide(*fVal.value);
}

DoubleType& DoubleType::add(const IntType& iVal)
{
    return add(*iVal.value);
}

DoubleType& DoubleType::subtract(const IntType& iVal)
{
    return subtract(*iVal.value);
}

DoubleType& DoubleType::multiply(const IntType& iVal)
{
    return multiply(*iVal.value);
}

DoubleType& DoubleType::divide(const IntType& iVal)
{
    return divide(*iVal.value);
}
//============================================================================================================

IntType& IntType::add(int iValue)
{
    if(this->value)
    {
        *this->value += iValue;
    }
    return *this;
}

IntType& IntType::subtract(int iValue)
{
    if(this->value)
    {
        *this->value -= iValue;
    }
    return *this;
}

IntType& IntType::multiply(int iValue)
{
    if(this->value != nullptr)
    {
        *this->value *= iValue;
    }
    return *this;
}

IntType& IntType::divide(int iValue)
{
    if(iValue == 0)
    {
        std::cout << "error: integer division by zero is an error and will crash the program!" << std::endl;
    }
    else
    {
        *this->value /= iValue;
    }

    return *this;
}

IntType& IntType::add(const FloatType& fVal)
{
    return add(*fVal.value);
}

IntType& IntType::subtract(const FloatType& fVal)
{
    return subtract(*fVal.value);
}

IntType& IntType::multiply(const FloatType& fVal)
{
    return multiply(*fVal.value);
}

IntType& IntType::divide(const FloatType& fVal)
{
    return divide(*fVal.value);
}

IntType& IntType::add(const DoubleType& dVal)
{
    return add(*dVal.value);
}

IntType& IntType::subtract(const DoubleType& dVal)
{
    return subtract(*dVal.value);
}

IntType& IntType::multiply(const DoubleType& dVal)
{
    return multiply(*dVal.value);
}

IntType& IntType::divide(const DoubleType& dVal)
{
    return divide(*dVal.value);
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

    std::cout << "FloatType add result=" << *ft.add(2.0f ).value << std::endl;
    std::cout << "FloatType subtract result=" << *ft.subtract( 2.0f ).value << std::endl;
    std::cout << "FloatType multiply result=" << *ft.multiply( 2.0f ).value << std::endl;
    std::cout << "FloatType divide result=" << *ft.divide( 16.0f).value << std::endl << std::endl;

    std::cout << "DoubleType add result=" << *dt.add(2.0).value << std::endl;
    std::cout << "DoubleType subtract result=" << *dt.subtract(2.0).value << std::endl;
    std::cout << "DoubleType multiply result=" << *dt.multiply(2.0).value << std::endl;
    std::cout << "DoubleType divide result=" << *dt.divide(5.0).value << std::endl << std::endl;

    std::cout << "IntType add result=" << *it.add(2).value << std::endl;
    std::cout << "IntType subtract result=" << *it.subtract(2).value << std::endl;
    std::cout << "IntType multiply result=" << *it.multiply(2).value << std::endl;
    std::cout << "IntType divide result=" << *it.divide(3).value << std::endl << std::endl;
    std::cout << "Chain calculation = " << *it.multiply(1000).divide(2).subtract(10).add(100).value << std::endl;

    // FloatType object instanciation and method tests
    // --------
    std::cout << "New value of ft = (ft + 3.0f) * 1.5f / 5.0f = " << *(ft.add( 3.0f ).multiply(1.5f).divide(5.0f)).value << std::endl;

    std::cout << "---------------------\n" << std::endl;

    // DoubleType/IntType object instanciation and method tests
    // --------
    std::cout << "Initial value of dt: " << *dt.value << std::endl;
    std::cout << "Initial value of it: " << *it.value << std::endl;
    // --------
    std::cout << "Use of function concatenation (mixed type arguments) " << std::endl;
    std::cout << "New value of dt = (dt * it) / 5.0f + ft = " << *dt.multiply(it).divide(5.0f).add(ft).value << std::endl;

    std::cout << "---------------------\n" << std::endl;

    // Intercept division by 0
    // --------
    std::cout << "Intercept division by 0 " << std::endl;
    std::cout << "New value of it = it / 0 = " << *it.divide(0).value << std::endl;
    std::cout << "New value of ft = ft / 0 = " << *ft.divide(0).value << std::endl;
    std::cout << "New value of dt = dt / 0 = " << *dt.divide(0).value << std::endl;

    std::cout << "---------------------\n" << std::endl;

    std::cout << "good to go!\n";

    return 0;
}
