#define PY_SSIZE_T_CLEAN
#include <python.h>

Py_ssize_t len_item(PyObject *Item)
{
    Py_ssize_t length = 0;

    if (PyUnicode_Check(Item))
    {
        length = PyUnicode_GET_LENGTH(Item);
        wchar_t *str = PyUnicode_AsWideCharString(Item, &length);
        size_t len = wcslen(str);
        for (size_t i = 0; i < len; i++)
            if (str[i] >= 0x80)
                length++;
    }
    else if (PyLong_Check(Item))
    {
        PyObject *Number = PyObject_Str(Item);
        length = PyUnicode_GET_LENGTH(Number);
        length += (length - 1) / 3;
    }
    else if (PyFloat_Check(Item))
    {
        PyObject *Float = PyObject_Str(Item);
        PyObject *List = PyUnicode_Split(Float, PyUnicode_FromString("."), 2);
        PyObject *Number = PyList_GetItem(List, 0);
        length = PyUnicode_GET_LENGTH(Number);
        length += (length - 1) / 3 + 3;
    }
    else {
        PyObject *Number = PyObject_Str(Item);
        length = PyUnicode_GET_LENGTH(Number);
    }
    return length;
}

PyObject *len(PyObject *self, PyObject *args, PyObject *kwargs)
{
    PyObject *Item;
    char *kw_list[] = {"item", NULL};
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O", kw_list, &Item))
        return NULL;

    Py_ssize_t length = len_item(Item);
    return PyLong_FromSize_t(length);
}

PyObject *lens(PyObject *self, PyObject *args, PyObject *kwargs)
{
    PyObject *Items;
    char *kw_list[] = {"items", NULL};
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O", kw_list, &Items))
        return NULL;

    Py_ssize_t max_length = 0;

    Py_ssize_t count = PyList_GET_SIZE(Items);
    for (Py_ssize_t i = 0; i < count; i++)
    {
        PyObject *Item = PyList_GetItem(Items, i);
        Py_ssize_t length = len_item(Item);
        if (length > max_length)
            max_length = length;
    }
    return PyLong_FromSize_t(max_length);
}

const char len_doc[] = "calculate length of CJK characters or Integers and Floats or other Objects.\nlen(item: str | int | float | any) -> int";
const char lens_doc[] = "calculate a list containing python objects\nlens(items: list[str | int | float | any]) -> int";

static PyMethodDef PrintLengthMethods[] = {
    {"len", (PyCFunction)len, METH_VARARGS | METH_KEYWORDS, len_doc},
    {"lens", (PyCFunction)lens, METH_VARARGS | METH_KEYWORDS, lens_doc},
    {NULL, NULL, 0, NULL}};

static struct PyModuleDef PrintLength_module = {
    PyModuleDef_HEAD_INIT,
    "PrintLength",
    "calculate the length of CJK characters or Integers and Floats",
    -1,
    PrintLengthMethods};

PyMODINIT_FUNC PyInit_PrintLength(void)
{
    PyObject *module;
    module = PyModule_Create(&PrintLength_module);
    if (module == NULL)
        return NULL;
    return module;
}