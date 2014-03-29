#include <Python.h>

#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[]) {
  Py_SetProgramName(argv[0]);
  Py_Initialize();

  QApplication app (argc, argv);

  PyRun_SimpleString("from time import time,ctime\n"
                   "print 'Today is',ctime(time())\n");

  QPushButton button ("Hello world !");
  button.show();

  app.exec();
  Py_Finalize();

  return 0;
}