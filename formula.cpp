#include <iostream>
#include <cmath>
#include <Eigen/Dense> // https://gitlab.com/libeigen/eigen/-/releases/3.4.0 // to download library

const double PI = 3.14159265358979323846;

class Formula{
// 1's correspond to first coordinate pair, 2's belong to second coordinate pair, 3's belong to third coordinate pair-----
// this fucntion follows Heron's formula for cuvature---------------------------------------------------------------------
    double herons (double x1, double z1, double x2, double z2, double x3, double z3){
        double curve, ABX, ABZ, BCX, BCZ, SlopeAB, SlopeBC, yfor, sideA, sideB, sideC, SP;

        ABX = x1-x2;
        ABZ = z1-z2;
        BCX = x2-x3;
        BCZ = z2-z3;
        SlopeAB = (ABZ/ABX);
        SlopeBC = (BCZ/BCX);

        //----------------------------------------------------------------------------------------------------------------
        // formula to determine sign of curvature

        yfor = (SlopeAB * x3) + (z1 - (SlopeAB*x1));

        //----------------------------------------------------------------------------------------------------------------
        // comparing slopes, if slopes are identical, no curvature to calculate in the first place

        if(SlopeAB == SlopeBC){ // straight line
            return 0;
        }
        else{
            sideA = pow((pow(ABX, 2) + pow((ABZ), 2)), 0.5);
            sideB = pow((pow((BCX), 2) + pow((BCZ), 2)), 0.5);
            sideC = pow((pow((x1-x3), 2) + pow((z1-z3), 2)), 0.5);
        }

        // required for herons formula
        SP = ((sideA + sideB + sideC)/2); // Semi Perimeter 
        
        curve = 4*(SP * pow((SP - sideA), 2) * (SP - sideB) * (SP - sideC))/(sideA * sideB * sideC);

        if(z3 < yfor){
            curve = (curve * -1);
        }
        return curve;
    }

// 1's correspond to first coordinate pair, 2's belong to second coordinate pair, 3's belong to third coordinate pair-----
// this function follows a calculus method for determining curvature------------------------------------------------------
    double parabola (double x1, double z1, double x2, double z2, double x3, double z3){
        double curve, result_a, result_b, first_deriv, second_deriv;
        
        // Defining the matrix Equations (MatrixA)
        Eigen::MatrixXd Equations(3, 3);
        Equations << pow(x1, 2), x1, 1, // x1^2 + x1 + 1
                     pow(x2, 2), x2, 1, // x2^2 + x2 + 1
                     pow(x3, 2), x3, 1; // x3^2 + x3 + 1

        //----------------------------------------------------------------------------------------------------------------
        // Define the vector or matrix SolveFor (B)
        Eigen::VectorXd SolveFor(3);
        SolveFor << z1, z2, z3;

        //----------------------------------------------------------------------------------------------------------------
        // Solve for Result (x) in Equation result (MatrixA x) = SolveFor (B)
        Eigen::VectorXd Result = Equations.colPivHouseholderQr().solve(SolveFor);
        
        // Visual representation of equation being solved:
        // [x1^2  x1  1 ] [xa]  [z1]
        // [x2^2  x2  1 ] [xb] =[z2]
        // [x3^2  x3  1 ] [xc]  [z3]

        //----------------------------------------------------------------------------------------------------------------
        // extracting needed values for for equation
        
        result_a = Result(0);
        result_b = Result(1);

        //----------------------------------------------------------------------------------------------------------------
        // finding first and second derivative equivalents to find curvature value

        first_deriv = 2 * result_a * x2 + result_b;
        second_deriv = 2 * result_a;
        curve = (4 * ((std::abs(second_deriv))/(pow((1 + pow(first_deriv, 2)), 1.5))));

        //----------------------------------------------------------------------------------------------------------------
        // sign of curvature determined by comparing the average of extreme heights with the central height

        if (((z3 + z1) / 2) < z2){ // curve is negative
            return -1 * curve;
        }

        else if (((z3 + z1) / 2) == z2){ // there is no curve 
            return 0;
        }

        return curve; // curve is positive
    }

// 1's correspond to first coordinate pair, 2's belong to second coordinate pair, 3's belong to third coordinate pair-----
// this function follows difference of slopes method for determining curvature--------------------------------------------
    double diffOfSlopes (double x1, double z1, double x2, double z2, double x3, double z3){
        double curve, ABX, ABZ, BCX, BCZ, SlopeAB, SlopeBC, yfor, sideA, sideB, sideC, SP;
        
        ABX = x1-x2;
        ABZ = z1-z2;
        BCX = x2-x3;
        BCZ = z2-z3;

        //----------------------------------------------------------------------------------------------------------------
        // checking if there is a calculatable slope between points 1 and 2

        if(ABX == 0){ // if x position is the same, slope is undefined
            std::cout << "Slope = undifiend" << std::endl;
        }
        else{ // otherwise compute slope
            SlopeAB = (ABZ/ABX);
        }

        //----------------------------------------------------------------------------------------------------------------
        // checking if there is a calculatable slope between points 2 and 3
        
        if(BCX == 0){ // if x position is the same, slope is undefined
            std::cout << "Slope = undifiend" << std::endl;
        }
        else{
            SlopeBC = (BCZ/BCX);
        }

        //----------------------------------------------------------------------------------------------------------------
        // comparing slopes, if slopes are identical, no curvature to calculate in the first place

        if(SlopeAB == SlopeBC){ // straight line
            return 0;
        }
        return (SlopeAB - SlopeBC)/(x3-x1);
    }

// 1's correspond to first coordinate pair, 2's belong to second coordinate pair, 3's belong to third coordinate pair-----
// this function follows the 3-ordinate Lagrangian method in order to determine curvature---------------------------------
    double lagrangian (double x1, double z1, double x2, double z2, double x3, double z3){
        // Proper data hould never divide by 0
        return  (2*(z1)-(z2)-(z3))/pow((((x3) - (x1))/2), 2);
    }

// 1's correspond to first coordinate pair, 2's belong to second coordinate pair, 3's belong to third coordinate pair-----
// this function follows the Finite Difference Analysis method in order to determine curvature----------------------------
    double finiteDiffAnalysis (double x1, double z1, double x2, double z2, double x3, double z3){
        double zPrime, zDoublePrime;
        // Proper data hould never divide by 0

        //----------------------------------------------------------------------------------------------------------------

        zPrime = (z3-z1)/(x3-x1);

        //----------------------------------------------------------------------------------------------------------------

        zDoublePrime = (((z3-z2)/(x3-x2))-((z2-z1)/(x2-x1)))/((x3-x2)*(x2-x1));
    
        return  zDoublePrime/(pow((1 + pow(zPrime, 2)), 1.5));
    }

// 1's correspond to first coordinate pair, 2's belong to second coordinate pair, 3's belong to third coordinate pair-----
// this function follows will run a formula to determine if the overall angle between points is acute or not -------------
    bool isAcute (double x1, double z1, double x2, double z2, double x3, double z3){
        double slope1, slope2, angle;

        //----------------------------------------------------------------------------------------------------------------
        // calculating both slopes through this formula: (y2 - y1) / (x2 - x1)

        slope1 = (z2 - z1)/(x2 - x1);
        slope2 = (z3 - z2)/(x3 - x2);
        
        //----------------------------------------------------------------------------------------------------------------
        // Calculate the angle, multiplied by 180/PI to translate to degrees

        angle = (std::atan(std::abs((slope2 - slope1) / (1 + slope1 * slope2)))) * (180/PI);;

        return (angle < 90.00);
    }

};
