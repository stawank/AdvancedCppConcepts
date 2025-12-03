#include<iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main(){
    // Pendulum Example
    float friction_coeff = 0.1;
    MatrixXf Ad(2, 2);
    Ad<< 0, 1, -1, -friction_coeff;
    std::cout << "Here is the matrix Ad:\n" << Ad << std::endl;

    VectorXcf eival_d = Ad.eigenvalues();
    std::cout << "Here are the Eigenvalues of Ad :\n" << eival_d << std::endl;

    MatrixXf Au(2,2);
    Au << 0, 1, 1, -friction_coeff;
    std::cout << "Here is the matrix Au:\n" << Au << std::endl;

    VectorXcf eival_u = Au.eigenvalues();
    std::cout << "Here are the Eigenvalues of Au :\n" << eival_u << std::endl;


    return 0;
}