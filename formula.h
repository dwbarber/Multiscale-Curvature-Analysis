#ifndef FORMULAS_H
#define FORMULAS_H

class Formula{
    /* Formulas used to calculate the curvature across three different points */

    double herons (double x1, double z1, double x2, double z2, double x3, double z3);
    double parabola (double x1, double z1, double x2, double z2, double x3, double z3);
    double diffOfSlopes (double x1, double z1, double x2, double z2, double x3, double z3);
    double lagrangian (double x1, double z1, double x2, double z2, double x3, double z3);
    double finiteDiffAnalysis (double x1, double z1, double x2, double z2, double x3, double z3);
    bool isAcute (double x1, double z1, double x2, double z2, double x3, double z3);

}

#endif

