
#include <Python.h>

int main(int, char**argv)
{
    wchar_t *program = Py_DecodeLocale(argv[0], NULL);
    if (program == NULL) {
        fprintf(stderr, "Fatal error: cannot decode argv[0]\n");
        exit(1);
    }
    Py_SetProgramName(program);  /* optional but recommended */
    Py_Initialize();
    auto cmd = "from time import time, ctime\n"
        "print('Today is', ctime(time()))\n";
    // auto cmd = "import IPython\n"
    //     "IPython.embed()\n";
    PyRun_SimpleString(cmd);
    if (Py_FinalizeEx() < 0) {
        exit(120);
    }
    PyMem_RawFree(program);
    return 0;
}
