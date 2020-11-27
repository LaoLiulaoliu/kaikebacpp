
#include <Python.h>
#include <stdlib.h>

long binary_section_search(long *arr, long length, long target) {
    long low = 0;
    long high = length;

    if (target < arr[low] || target > arr[high]) {
        return -1;
    }

    long middle = (high + low) >> 1;
    while (low < high) {
        if (low == middle) { // low < target < high, low + 1 = high
            if (abs(target - arr[middle]) > abs(target - arr[middle + 1])) {
                return middle + 1;
            } else {
                return middle;
            }
    
        }

        if (target < arr[middle]) {
            high = middle;
            middle = (high + low) >> 1;
        } else if (target > arr[middle + 1]) {
            low = middle + 1;
            middle = (high + low) >> 1;
        } else {
            if (abs(target - arr[middle]) > abs(target - arr[middle + 1])) {
                return middle + 1;
            } else {
                return middle;
            }
        }
    }

}

static PyObject * _binary_section_search(PyObject *self, PyObject *args)
{
    PyObject *_arr;
    long _len;
    long _target;
    long ret;
    long i = 0;

    if (!PyArg_ParseTuple(args, "Oll", &_arr, &_len, &_target))
        return NULL;

    long _array[_len+1];
    PyObject *iter = PyObject_GetIter(_arr);
    while (1) {
        PyObject *next = PyIter_Next(iter);
        if (!next) {
            break;
        }
        _array[i] = PyLong_AsLong(next);
        i += 1;
    }
    //printf("length: %ld, target: %ld\n", i, _target);
    ret = binary_section_search(_array, _len, _target);
    return Py_BuildValue("l", ret);
    //return PyLong_FromLong(ret);
}

static PyMethodDef BinaryMethods[] = {
    {
        "binary_section_search",
        _binary_section_search,
        METH_VARARGS,
        "binary section search func"
    },
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef binarymodule =
{
    PyModuleDef_HEAD_INIT,
    "binary section search", /* name of module */
    "",          /* module documentation, may be NULL */
    -1,          /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    BinaryMethods
};

PyMODINIT_FUNC PyInit_binary_module(void) {
    return PyModule_Create(&binarymodule);
}