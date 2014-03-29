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

  QString pathEnv ("PYTHONPATH=");
  pathEnv += pythonLib.absolutePath();

  putenv(pathEnv.toLocal8Bit().data());

  Py_SetPythonHome(pythonRoot.absolutePath().toLocal8Bit().data());
  Py_Initialize();



  app.exec();
  Py_Finalize();

  return 0;
}