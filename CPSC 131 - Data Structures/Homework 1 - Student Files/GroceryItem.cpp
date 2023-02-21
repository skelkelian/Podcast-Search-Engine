#include <cmath>                                                      // abs(), pow()
#include <compare>                                                    // weak_ordering
#include <iomanip>                                                    // quoted()
#include <iostream>
#include <string>
#include <type_traits>                                                // is_floating_point_v, common_type_t
#include <utility>                                                    // move()

#include "GroceryItem.hpp"



/*******************************************************************************
**  Implementation of non-member private types, objects, and functions
*******************************************************************************/
namespace    // unnamed, anonymous namespace
{
  // Avoid direct equality comparisons on floating point numbers. Two values are equal if they are "close enough", which is
  // represented by Epsilon.  Usually, this is a pretty small number, but since we are dealing with money (only two, maybe three
  // decimal places) we can be a bit more tolerant.  Two floating point values are considered equal if they are within EPSILON of
  // each other.
  template< typename T,  typename U >   requires std::is_floating_point_v<std::common_type_t<T, U> >
  constexpr bool floating_point_is_equal( T const lhs,  U const rhs,  double const EPSILON = 1e-4 ) noexcept
  {
    ///////////////////////// TO-DO (1) //////////////////////////////
      ///  Write the lines of code that compare two floating point numbers.  Return true when the left hand side (lhs) and the right
      ///  hand side (rhs) are within Epsilon, and false otherwise.
      ///
      ///  See: "Floating point equality" in https://www.learncpp.com/cpp-tutorial/relational-operators-and-floating-point-comparisons/
      ///
      ///  Hint:  Avoid writing code that looks like this:
      ///           if( some expression that is true ) return the constant "true"
      ///           else                               return the constant "false"
      ///         for example, avoid:
      ///           if (a < b) return true;
      ///           else       return false;
      ///         do this instead:
      ///           return a < b;
    return std::abs(lhs - rhs) <= EPSILON; // maybe use fabs()
    /////////////////////// END-TO-DO (1) ////////////////////////////
  }
}    // unnamed, anonymous namespace







/*******************************************************************************
**  Constructors, assignments, and destructor
*******************************************************************************/

// Default and Conversion Constructor
GroceryItem::GroceryItem( std::string productName, std::string brandName, std::string upcCode, double price )
///////////////////////// TO-DO (2) //////////////////////////////
  /// Copying the parameters into the object's attributes (member variables) "works" but is not correct.  Be sure to move the parameters into the object's attributes
{
    _productName = std::move(productName);
    _brandName   = std::move(brandName);
    _upcCode     = std::move(upcCode);
    _price       = std::move(price);
}
/////////////////////// END-TO-DO (2) ////////////////////////////




// Copy constructor
GroceryItem::GroceryItem( GroceryItem const & other )
///////////////////////// TO-DO (3) //////////////////////////////
{
    _productName = other._productName;              // double check
    _brandName = other._brandName;                  // double check
    _upcCode = other._upcCode;                      // double check
    _price = other._price;                          // double check
}
/////////////////////// END-TO-DO (3) ////////////////////////////




// Move constructor
GroceryItem::GroceryItem( GroceryItem && other ) noexcept
///////////////////////// TO-DO (4) //////////////////////////////
    : _upcCode{std::move(other._upcCode)}
    , _brandName{std::move(other._brandName)}
    , _productName{std::move(other._productName)}
    , _price{std::move(other._price)}
{}
/////////////////////// END-TO-DO (4) ////////////////////////////




// Copy Assignment Operator
GroceryItem & GroceryItem::operator=( GroceryItem const & rhs ) &
///////////////////////// TO-DO (5) //////////////////////////////
{
    if (this != &rhs)
    {
        _upcCode = rhs._upcCode;
        _brandName = rhs._brandName;
        _productName = rhs._productName;
        _price = rhs._price;
    }
    return *this;
}
/////////////////////// END-TO-DO (5) ////////////////////////////




// Move Assignment Operator
GroceryItem & GroceryItem::operator=( GroceryItem && rhs ) & noexcept
///////////////////////// TO-DO (6) //////////////////////////////
{
    if (this != &rhs)
    {
        _upcCode = std::move(rhs._upcCode);
        _brandName = std::move(rhs._brandName);
        _productName = std::move(rhs._productName);
        _price = std::move(rhs._price);
    }
    return *this;
}
/////////////////////// END-TO-DO (6) ////////////////////////////



// Destructor
GroceryItem::~GroceryItem() noexcept
///////////////////////// TO-DO (7) //////////////////////////////
{}
/////////////////////// END-TO-DO (7) ////////////////////////////








/*******************************************************************************
**  Accessors
*******************************************************************************/

// upcCode() const
std::string const & GroceryItem::upcCode() const &
{
  ///////////////////////// TO-DO (8) //////////////////////////////
    return _upcCode;
  /////////////////////// END-TO-DO (8) ////////////////////////////
}




// brandName() const
std::string const & GroceryItem::brandName() const &
{
  ///////////////////////// TO-DO (9) //////////////////////////////
    return _brandName;
  /////////////////////// END-TO-DO (9) ////////////////////////////
}




// productName() const
std::string const & GroceryItem::productName() const &
{
  ///////////////////////// TO-DO (10) //////////////////////////////
    return _productName;
  /////////////////////// END-TO-DO (10) ////////////////////////////
}



// price() const
double GroceryItem::price() const &
{
  ///////////////////////// TO-DO (11) //////////////////////////////
    return _price;
  /////////////////////// END-TO-DO (11) ////////////////////////////
}




// upcCode()
std::string GroceryItem::upcCode() &&
{
  ///////////////////////// TO-DO (12) //////////////////////////////
    return std::move(_upcCode);
  /////////////////////// END-TO-DO (12) ////////////////////////////
}




// brandName()
std::string GroceryItem::brandName() &&
{
  ///////////////////////// TO-DO (13) //////////////////////////////
    return std::move(_brandName);
  /////////////////////// END-TO-DO (13) ////////////////////////////
}




// productName()
std::string GroceryItem::productName() &&
{
  ///////////////////////// TO-DO (14) //////////////////////////////
    return std::move(_productName);
  /////////////////////// END-TO-DO (14) ////////////////////////////
}








/*******************************************************************************
**  Modifiers
*******************************************************************************/

// upcCode()
GroceryItem & GroceryItem::upcCode( std::string newUpcCode ) &
{
  ///////////////////////// TO-DO (15) //////////////////////////////
    /// Copy assignment "works" but is not correct.  Be sure to move newUpcCode into _upcCode
    _upcCode = std::move(newUpcCode);
    return *this;
    /////////////////////// END-TO-DO (15) ////////////////////////////
}




// brandName()
GroceryItem & GroceryItem::brandName( std::string newBrandName ) &
{
  ///////////////////////// TO-DO (16) //////////////////////////////
    _brandName = std::move(newBrandName);
    return *this;
    /////////////////////// END-TO-DO (16) ////////////////////////////
}




// productName()
GroceryItem & GroceryItem::productName( std::string newProductName ) &
{
  ///////////////////////// TO-DO (17) //////////////////////////////
    _productName = std::move(newProductName);           // double check
    return *this;
    /////////////////////// END-TO-DO (17) ////////////////////////////
}




// price()
GroceryItem & GroceryItem::price( double newPrice ) &
{
  ///////////////////////// TO-DO (18) //////////////////////////////
    _price = std::move(newPrice);                 // double check
    return *this;
  /////////////////////// END-TO-DO (18) ////////////////////////////
}








/*******************************************************************************
**  Relational Operators
*******************************************************************************/

// operator<=>
std::weak_ordering GroceryItem::operator<=>( const GroceryItem & rhs ) const noexcept
{
  // Design decision:  A very simple and convenient defaulted 3-way comparison operator
  //                         auto operator<=>( const GroceryItem & ) const = default;
  //                   in the class definition (header file) would get very close to what is needed and would allow both the <=> and
  //                   the == operators defined here to be skipped.  The physical ordering of the attributes in the class definition
  //                   would have to be changed (easy enough in this case) but the default directly compares floating point types
  //                   (price) for equality, and that should be avoided, in general. For example, if x and y are of type double,
  //                   then  x < y  is okay but  x == y  is not.  So these (operator<=> and operator==) explicit definitions are
  //                   provided.
  //
  //                   Also, many ordering (sorting) algorithms, like those used in std::map and std::set, require at least a weak
  //                   ordering of elements. operator<=> provides only a partial ordering when comparing floating point numbers.
  //
  // Weak order:       Objects that compare equal but are not substitutable (identical).  For example, since _price can be within
  //                   EPSILON, GroceryItem("ProductName", "BrandName", "UPC", 9.99999) and GroceryItem("ProductName", "BrandName",
  //                   "UPC", 10.00001) are equal but they are not identical.  If you ignore case when comparing strings, as another
  //                   example, GroceryItem("ProductName") and GroceryItem("productName") are equal but they are not identical.
  //
  // See std::weak_ordering    at https://en.cppreference.com/w/cpp/utility/compare/weak_ordering and
  //     std::partial_ordering at https://en.cppreference.com/w/cpp/utility/compare/partial_ordering
  //     The Three-Way Comparison Operator at  http://modernescpp.com/index.php/c-20-the-three-way-comparison-operator
  //     Spaceship (Three way comparison) Operator Demystified https://youtu.be/S9ShnAFmiWM
  //
  //
  // Grocery items are equal if all attributes are equal (or within Epsilon for floating point numbers, like price). Grocery items are ordered
  // (sorted) by UPC code, product name, brand name, then price.

  ///////////////////////// TO-DO (19) //////////////////////////////
    if(auto result = _upcCode <=> rhs._upcCode; result != 0) return result;
    if(auto result = _productName <=> rhs._productName; result != 0) return result;
    if(auto result = _brandName <=> rhs._brandName; result != 0) return result;

    if(floating_point_is_equal(_price, rhs._price)) return std::weak_ordering::equivalent;
    if(_price < rhs._price) return std::weak_ordering::less;
    else return std::weak_ordering::greater;
    /////////////////////// END-TO-DO (19) ////////////////////////////
}




// operator==
bool GroceryItem::operator==( const GroceryItem & rhs ) const noexcept
{
  // All attributes must be equal for the two grocery items to be equal to the other.  This can be done in any order, so put the
  // quickest and then the most likely to be different first.

  ///////////////////////// TO-DO (20) //////////////////////////////
    return floating_point_is_equal(_price, rhs._price)
            && _upcCode == rhs._upcCode
            && _brandName == rhs._brandName
            && _productName == rhs._productName;
  /////////////////////// END-TO-DO (20) ////////////////////////////
}








/*******************************************************************************
**  Insertion and Extraction Operators
*******************************************************************************/

// operator>>
std::istream & operator>>( std::istream & stream, GroceryItem & groceryItem )
{
  ///////////////////////// TO-DO (21) //////////////////////////////
    /// A lot can go wrong when reading from streams - no permission, wrong types, end of file, etc. Minimal exception guarantee says
    /// there should be no side affects if an error or exception occurs, so let's do our work in a local object and move it into place
    /// at the end if all goes well.
    ///
    /// This function should be symmetrical with operator<< below.  Read what your write, and write what you read
    ///
    ///
    /// Assume fields are separated by commas & optional spaces, and string attributes are enclosed with double quotes.  For example:
    ///    UPC Code         | Brand Name | Product Name                                                  | Price
    ///    -----------------+------------+---------------------------------------------------------------+-------
    ///    "00034000020706",  "York",      "York Peppermint Patties Dark Chocolate Covered Snack Size"  ,  12.64
    ///
    ///
    /// Hint:  Use std::quoted to read and write quoted strings.  See
    ///        1) https://en.cppreference.com/w/cpp/io/manip/quoted
    ///        2) https://www.youtube.com/watch?v=Mu-GUZuU31A
//    stream >> groceryItem._upcCode >> groceryItem._brandName >> groceryItem._productName >> groceryItem._price;


    GroceryItem localVariable;

    // Null character
    char delimiter = '\0';

    if
    (
        stream >> std::ws >> std::quoted(localVariable._upcCode) && stream >> std::ws >> delimiter && delimiter &&
        stream >> std::ws >> std::quoted(localVariable._brandName) && stream >> std::ws >> delimiter && delimiter &&
        stream >> std::ws >> std::quoted(localVariable._productName) && stream >> std::ws >> delimiter && delimiter &&
        stream >> std::ws >> localVariable._price
    )
    // Only move if above is true
    {
        groceryItem = std::move(localVariable);
    }
    //
    else stream.setstate(std::ios::failbit);

    return stream;
  /////////////////////// END-TO-DO (21) ////////////////////////////
}




// operator<<
std::ostream & operator<<( std::ostream & stream, const GroceryItem & groceryItem )
{
  ///////////////////////// TO-DO (22) //////////////////////////////
    /// This function should be symmetrical with operator>> above.  Read what your write, and write what you read
    ///
    /// Hint:  Brand and product names may have quotes, which need to escaped when printing.  Use std::quoted to read and write quoted strings.  See
    ///        1) https://en.cppreference.com/w/cpp/io/manip/quoted
    ///        2) https://www.youtube.com/watch?v=Mu-GUZuU31A
//    stream << groceryItem._upcCode << '/' << groceryItem._brandName << '/' << groceryItem._productName << '/' << groceryItem._price;

    stream  << std::quoted(groceryItem._upcCode) << ", "
            << std::quoted(groceryItem._brandName) << ", "
            << std::quoted(groceryItem._productName) << ", "
            << groceryItem._price;

    return stream;
  /////////////////////// END-TO-DO (22) ////////////////////////////
}
