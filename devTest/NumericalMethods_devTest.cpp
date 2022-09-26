#include "NumericalMethods.h"
#include "NumericalMethodsUtilities.h"

double function_1(double x)   { return pow(x,3) + 4 * pow(x, 2) - 10; }
double function_1p(double x)  { return 3 * pow(x,2) + 8 * x; }
double function_1pp(double x) { return 6 * x + 8; }
double function_2(double x)   { return pow( 3 * (pow(x,2) + 1 ), 0.25); }
double function_3(double x)   { return cos(x) - x; }
double function_3p(double x)  { return  -sin(x) - 1; }
double function_4(double x)   { return 0.5 * (x + (3/x)); }

int main( int argc, char *argv[] ) {

    // Inputs
    printf("You made it to test function for NumericalMethods!\n\n");

    std::vector<NumericalMethods::RootSolvers::rootSolver_ret> ans1, ans2, ans3, ans4, ans5, ans6, ans7;

    printf("NM Bisection Method Test\n");
    ans1 = NumericalMethods::RootSolvers::bisection_method(&function_1, 1, 2, 1e-04);
    std::string res1 = Utilities::rootSolver_results(ans1);
    printf("%s\n", res1.c_str());
    
    printf("NM Fixed-Point Iteration Method Test\n");
    ans2 = NumericalMethods::RootSolvers::fixedPointIteration_method(&function_2, 1, 1e-02);
    std::string res2 = Utilities::rootSolver_results(ans2);
    printf("%s\n", res2.c_str());
    
    printf("NM Newton's Method Test\n");
    ans3 = NumericalMethods::RootSolvers::newtons_method(&function_3, &function_3p, M_PI/4.0, 1e-08, 20);
    std::string res3 = Utilities::rootSolver_results(ans3);
    printf("%s\n", res3.c_str());
    
    printf("NM Secant Method Test\n");
    ans4 = NumericalMethods::RootSolvers::secant_method(&function_3, 0.5, M_PI/4.0, 1e-08, 20);
    std::string res4 = Utilities::rootSolver_results(ans4);
    printf("%s\n", res4.c_str());
    
    printf("NM Method of False Position Test\n");
    ans5 = NumericalMethods::RootSolvers::falsePosition_method(&function_3, 0.5, M_PI/4.0, 1e-08, 20);
    std::string res5 = Utilities::rootSolver_results(ans5);
    printf("%s\n", res5.c_str());
    
    printf("NM Modified Newton's Method Test\n");
    ans6 = NumericalMethods::RootSolvers::ModifiedNewtons_method(&function_1, &function_1p, &function_1pp, 1.5, 1e-10, 20);
    std::string res6 = Utilities::rootSolver_results(ans6);
    printf("%s\n", res6.c_str());
    
    printf("NM Steffenson's Method Test\n");
    ans7 = NumericalMethods::RootSolvers::steffensens_method(&function_4, 0.5, 1e-04);
    std::string res7 = Utilities::rootSolver_results(ans7);
    printf("%s\n", res7.c_str());

    return 0;
}
