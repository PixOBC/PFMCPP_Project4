/*
 Project 4 - Part 3 / 9
 Video: Chapter 4 Part 3 
 Casting

 Create a branch named Part3
 
 do not remove anything from main().  you'll be revising your main() to work with these new code changes.
 
    Build/Run often with this task to make sure you're not breaking the code with each step.
    I recommend committing after you get each step working so you can revert to a working version easily if needed.

 1) remove your functions that accepted a User-Defined Type
 
 2) remove any getValue() functions if you added them
 
 3) move all of your add/subtract/multiply/divide implementations out of the class.
  
 4) add user-defined conversion functions that convert to the numeric type your object holds.
        i.e. if your type holds an int, you'll need an operator int() function.
 
 5) make your member variable private.
         this conversion function should be the ONLY WAY to access the held value.
         use the proper casting technique to invoke this conversion function
 
 6) make sure it compiles & runs without errors.
 
 7) use your knowledge of casting to remove any conversion warnings. 

 8) insert 'part3();' before the 'good to go' at the end of your main(); 
        move this part3 function to before main()

 9) click the [run] button.  Clear up any errors or warnings as best you can.

 */

void part3()
{
    FloatType ft( 5.5f );
    DoubleType dt( 11.1 );
    IntType it ( 34 );
    DoubleType pi( 3.14 );

    std::cout << "The result of FloatType^4 divided by IntType is: " << ft.multiply( ft ).multiply( ft ).divide( it ) << std::endl;
    std::cout << "The result of DoubleType times 3 plus IntType is : " << dt.multiply( 3 ).add( it ) << std::endl;
    std::cout << "The result of IntType divided by 3.14 multiplied by DoubleType minus FloatType is: " << it.divide( pi ).multiply( dt ).subtract( ft ) << std::endl;
    std::cout << "An operation followed by attempts to divide by 0, which are ignored and warns user: " << std::endl;
    std::cout << it.multiply(it).divide(0).divide(0.0f).divide(0.0) << std::endl;
    
    std::cout << "FloatType x IntType  =  " << it.multiply( ft ) << std::endl;
    std::cout << "(IntType + DoubleType + FloatType) x 24 = " << it.add( dt ).add( ft ).multiply( 24 ) << std::endl;
}

/*
your program should generate the following output EXACTLY.
This includes the warnings.
The output should have zero warnings.
Use a service like https://www.diffchecker.com/diff to compare your output. 

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

The result of FloatType^4 divided by IntType is: 26.9136
The result of DoubleType times 3 plus IntType is : 67.3
The result of IntType divided by 3.14 multiplied by DoubleType minus FloatType is: 711
An operation followed by attempts to divide by 0, which are ignored and warns user: 
error: integer division by zero is an error and will crash the program!
error: integer division by zero is an error and will crash the program!
error: integer division by zero is an error and will crash the program!
505521
FloatType x IntType  =  13143546
(IntType + DoubleType + FloatType) x 24 = 315447336
good to go!




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

    }
    *this->value /= fValue;

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
    return subtract(*iVal.value);
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
        
    }
    
    *this->value /= dValue;

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
    std::cout << "DoubleType divide result=" << *dt.divide(5.f).value << std::endl << std::endl; // This used to be 5.f returning a DoubleType

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
