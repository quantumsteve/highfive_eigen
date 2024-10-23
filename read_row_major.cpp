#include "Eigen/Core"

#include "highfive/eigen.hpp"
#include "highfive/highfive.hpp"

#include <chrono>
#include <iostream>

int main(int argc, char **argv) {

  {
    HighFive::File rows_file("../pos_rows.h5", HighFive::File::ReadOnly);
    auto rows_dataset = rows_file.getDataSet("positions");
    Eigen::Matrix<float, 3, Eigen::Dynamic, Eigen::RowMajor> pos_rows;
    auto dims = rows_dataset.getDimensions();
    pos_rows.resize(dims[0], dims[1]);
    auto start = std::chrono::high_resolution_clock::now();
    rows_dataset.read(pos_rows);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration_total =
        std::chrono::duration<double, std::chrono::seconds::period>(stop -
                                                                    start)
            .count();
    std::cout << "rows: " << pos_rows.rows() << " cols: " << pos_rows.cols() << '\n';
    std::cout << "rows time: " << duration_total << "s\n";
  }
  {
    HighFive::File cols_file("../pos_cols.h5", HighFive::File::ReadOnly);
    auto cols_dataset = cols_file.getDataSet("positions");
    Eigen::Matrix<float, Eigen::Dynamic, 3, Eigen::RowMajor> pos_cols;
    auto dims = cols_dataset.getDimensions();
    pos_cols.resize(dims[0], dims[1]);
    auto start = std::chrono::high_resolution_clock::now();
    cols_dataset.read(pos_cols);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration_total =
        std::chrono::duration<double, std::chrono::seconds::period>(stop -
                                                                    start)
            .count();
    std::cout << "rows: " << pos_cols.rows() << " cols: " << pos_cols.cols() << '\n';
    std::cout << "cols time: " << duration_total << "s\n";
  }
}
