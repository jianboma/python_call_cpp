"""
    This is just an example that copied from https://pybind11.readthedocs.io/en/stable/advanced/cast/eigen.html
"""

from pythonCallCpp_eigen_matrix.eigen_matrix_bar import MyClass


def main():
    a = MyClass()
    m = a.get_matrix()  # flags.writeable = True,  flags.owndata = False
    v = a.view_matrix()  # flags.writeable = False, flags.owndata = False
    c = a.copy_matrix()  # flags.writeable = True,  flags.owndata = True
    # m[5,6] and v[5,6] refer to the same element, c[5,6] does not.
    print(m)
    print(v)
    print(c)


if __name__=='__main__':
    main()