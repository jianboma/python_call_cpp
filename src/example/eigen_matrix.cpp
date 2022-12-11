#include <pybind11/pybind11.h>
#include <pybind11/eigen.h> // this links between numpy (python) with eigen (C++) https://pybind11.readthedocs.io/en/stable/advanced/cast/eigen.html

#include <Eigen/Dense>
namespace py = pybind11;


class MyClass {
    Eigen::MatrixXd big_mat = Eigen::MatrixXd::Zero(10000, 10000);
public:
    Eigen::MatrixXd &getMatrix() { return big_mat; }
    const Eigen::MatrixXd &viewMatrix() { return big_mat; }
};

PYBIND11_MODULE(eigen_matrix_bar, m){
    py::class_<MyClass>(m, "MyClass")
        .def(py::init<>())
        .def("copy_matrix", &MyClass::getMatrix) // Makes a copy!
        .def("get_matrix", &MyClass::getMatrix, py::return_value_policy::reference_internal)
        .def("view_matrix", &MyClass::viewMatrix, py::return_value_policy::reference_internal)
        ;
}
