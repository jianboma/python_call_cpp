# python_call_cpp
This is an example to show how to call cpp function in python

## Get started
- create virtual environment if you have [virtualenv](https://pypi.org/project/virtualenv/) installed
```sh
virtualenv env
source env/bin/activate
```

You can also use conda or venv to create your virtual environment.

- install requirements
```sh
pip install -r requirements.txt
```
- build and install the package
```sh
python setup.py install
```
- run the simple example
```sh
python example/call_cpp_example.py
```

## A bit more depth about setup
The package name in setup.py is the folder to contain the built library. The library is built through cmake and make. The project name in [CMakeLists.txt](CMakeLists.txt) is the name of the built library.

In [C++ wrapper](src/example/eigen_matrix.cpp) need to have a pybind11 module to ellaborate the functions in the exposed classes. The method 'eigen_matrix_bar' should be the same name as the cmake project name, which is also the same name of the built library.
```C++
PYBIND11_MODULE(eigen_matrix_bar, m){
    py::class_<MyClass>(m, "MyClass")
        .def(py::init<>())
        .def("copy_matrix", &MyClass::getMatrix) // Makes a copy!
        .def("get_matrix", &MyClass::getMatrix, py::return_value_policy::reference_internal)
        .def("view_matrix", &MyClass::viewMatrix, py::return_value_policy::reference_internal)
        ;
}
```

## Acknowledge
This repo is just show an example to call cpp in python by using [pybind11](https://pybind11.readthedocs.io/en/stable/index.html). The [Eigen](https://eigen.tuxfamily.org/index.php?title=Main_Page) is used in order to show a concrete example. The [MyClass](src/example/eigen_matrix.cpp) example is copied from [pybind11 example](https://pybind11.readthedocs.io/en/stable/advanced/cast/eigen.html). 

The setup script is also inspired from the talk in [this vedio](https://www.youtube.com/watch?v=YReJ3pSnNDo).
