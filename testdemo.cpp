#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <Eigen/Dense>
#include <Eigen/SVD>
#include <numeric>
#include <iostream>

using namespace std;
using namespace Eigen;

std::array<std::array<double, 4>, 4> least_squares_transform(std::vector<std::array<double, 3>>& X, std::vector<std::array<double, 3>>& Y) {
    int n = X.size();

    // ����������ʵ��ѵ��ɾ���
    MatrixXd X_prime(n, 3);
    MatrixXd Y_prime(n, 3);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            X_prime(i, j) = X[i][j];
            Y_prime(i, j) = Y[i][j];
        }
    }

    // ��������
    Vector3d x0 = X_prime.colwise().mean();
    Vector3d y0 = Y_prime.colwise().mean();

    // ��ȥ����
    MatrixXd X_hat = X_prime.rowwise() - x0.transpose();
    MatrixXd Y_hat = Y_prime.rowwise() - y0.transpose();

    // ����Э�������
    Matrix3d C = X_hat.transpose() * Y_hat;

    // ����ֵ�ֽ�
    JacobiSVD<MatrixXd> svd(C, ComputeFullU | ComputeFullV);
    Matrix3d U = svd.matrixU();
    Matrix3d V = svd.matrixV();

    // ������ת�����ƽ������
    Matrix3d R = V.transpose() * U.transpose();
    Vector3d t = y0 - R * x0;

    // �����任����
    std::array<std::array<double, 4>, 4> T;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            T[i][j] = R(i, j);
        }
        T[i][3] = t(i);
    }
    T[3][0] = T[3][1] = T[3][2] = 0.0;
    T[3][3] = 1.0;
   /* for (const auto& i : T)
        std::cout << i[0] << " ";*/

    return T;
}

std::array<double, 2> calculate_position_accuracy(std::vector<std::array<double, 3>>& Y, std::vector<std::array<double, 3>>& Z) {
    int n = Y.size();

    // ����ŷ����þ���
    std::vector<double> distance(n);
    for (int i = 0; i < n; i++) {
        std::array<double, 3> diff;
        for (int j = 0; j < 3; j++) {
            diff[j] = Y[i][j] - Z[i][j];
        }
        distance[i] = std::sqrt(std::pow(diff[0], 2) + std::pow(diff[1], 2) + std::pow(diff[2], 2));
    }

    // ����ƽ��λ���������λ�����
    double mean_accuracy = std::accumulate(distance.begin(), distance.end(), 0.0) / n;
    double max_accuracy = *std::max_element(distance.begin(), distance.end());

    return { mean_accuracy, max_accuracy };
}

int main() {
    std::vector<std::array<double, 3>> X = {
        { -677.656250, -256.364655, 301.512695 },
        { -590.407715, -264.166199, 267.914368 },
        { -486.351685, -266.401886, 230.177734 }
    };  // ����ֵ
    std::vector<std::array<double, 3>> Y = {
        { -650.089, -259.193, 406.821 },
        { -551.739, -267.743, 371.454 },
        { -437.584, -268.739, 330.577 }
    };  // ��ʵֵ

    auto T = least_squares_transform(X, Y);  // �任����
    std::cout << "�任����" << std::endl;
    for (auto row : T) {
        for (auto elem : row) {
            std::cout << elem << "\t";
        };
    }
}