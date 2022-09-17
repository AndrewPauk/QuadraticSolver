#ifndef header_h
#define header_h

//!--------------------------------
//! @brief Used to input the coefficients
//! @param[in] a Coefficient of x^2 in the equation
//! @param[in] b Coefficient of x in the equation
//! @param[in] c Free coefficient of the equation
//!--------------------------------
void Input(double *a, double *b, double *c);

//!--------------------------------
//! @brief Used for output of roots
//! @param[in] nRoots Number of roots of the equation
//! @param[in] x Root of the equation if one root
//! @param[in] x1 First, lesser root of the equation
//! @param[in] x2 Second, bigger root of the equation
//!--------------------------------
void Output(int nRoots, double x, double x1, double x2);

//!--------------------------------
//! @brief Used for comparing double numbers with 0
//! @param[in] n Number to compare
//! @return True or False, depending on the number
//!--------------------------------
int isZero (double n);

//!--------------------------------
//! @brief Used for deleting the input buffer
//!--------------------------------
void BuferDelete();

//!--------------------------------
//! @brief Solving linear equations
//! @param[in] b Coefficient of x in the equation
//! @param[in] c Free coefficient of the equation
//! @param[out] x Root of the equation
//! @return Number of roots of the equation
//!--------------------------------
int SolveLinear(double b, double c, double *x);

//!--------------------------------
//! @brief Solving square equations
//! @param[in] a Coefficient of x^2 in the equation
//! @param[in] b Coefficient of x in the equation
//! @param[in] c Free term of the equation
//! @param[out] x Root of the equation if one root
//! @param[out] x1 First root of the equation if two roots
//! @param[out] x2 Second root of the equation if two roots
//! @return Number of roots
//!--------------------------------
int SolveQuadratic(double a, double b, double c, double *x, double *x1, double *x2);

//!--------------------------------
//! @brief Testing the solver of square equations
//! @param[in] Test_Number The number of test
//! @param[in] a Coefficient of x^2 in the equation
//! @param[in] b Coefficient of x in the equation
//! @param[in] c Free term of the equation
//! @param[in] real_nRoots Number of roots of the equation
//! @param[in] real_x Root of the equation if one root
//! @param[in] real_x1 First root of the equation if two roots
//! @param[in] real_x2 Second root of the equation if two roots
//!--------------------------------
void Test(int Test_Number, double a, double b, double c, int real_nRoots, double real_x, double real_x1, double real_x2);

//!--------------------------------
//! @brief Function that contains all the tests and starts the testing
//!--------------------------------
void StartTests();

#endif //header_h
