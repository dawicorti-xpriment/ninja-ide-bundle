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

  setenv("PYTHONPATH", pythonLib.absolutePath().toLocal8Bit().data(), 1);

  Py_SetPythonHome(pythonRoot.absolutePath().toLocal8Bit().data());
  Py_Initialize();

  PySys_SetArgv(argc, argv);

  QString setupPath = "import sys\n";
  setupPath += "sys.path.append('" + resourceDir.absolutePath() + "')\n";
  setupPath += "sys.path.append('" + pythonLib.absolutePath() + "')\n";
  setupPath += "import ninja_ide\n";
  setupPath += "ninja_ide.setup_and_run()\n";

  PyRun_SimpleString(setupPath.toLocal8Bit().data());

  Py_Finalize();

  return 0;
}