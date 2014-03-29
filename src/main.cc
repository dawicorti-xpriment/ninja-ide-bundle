#include <stdlib.h>
#include <Python.h>

#include <QApplication>
#include <QTextEdit>
#include <QDir>
#include <QString>

int main(int argc, char *argv[]) {
  QApplication app (argc, argv);

  QDir bundleDir (app.applicationDirPath());
  bundleDir.cdUp();
  bundleDir.cdUp();
  
  QDir resourceDir (bundleDir);
  resourceDir.cd("Contents");
  resourceDir.cd("Resources");

  QDir pythonRoot (resourceDir);
  pythonRoot.cd("Python-2.7.6");

  QDir pythonLib (pythonRoot);
  pythonLib.cd("Lib");

  QString libPathEnv ("PYTHONPATH=");
  libPathEnv += pythonLib.absolutePath();

  putenv(libPathEnv.toLocal8Bit().data());

  Py_SetPythonHome(pythonRoot.absolutePath().toLocal8Bit().data());
  Py_Initialize();

  QString script = "from PyQt4 import QtGui, QtCore;import sys;";
  script += "sys.path.append('" + libPathEnv + "');";
  script += "app = QtGui.QApplication([]);hello = QtGui.QPushButton(\"Hello World!\", None);hello.show();app.exec_();";

  PyRun_SimpleString(script.toLocal8Bit().data());


  Py_Finalize();

  return 0;
}