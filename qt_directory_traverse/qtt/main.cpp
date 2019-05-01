
#include <stdio.h>
#include <QtCore>

#define QSTXT(qs) ( (qs).toUtf8().constData() )

void traverse(const QString &path, const QString &indent=QString());

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  QStringList pathList;
  int ii;

  if(argc == 1) { pathList.append("."); }
  for(ii=1 ; ii<argc ; ii++) { pathList.append(QString(argv[ii])); }

  for(ii=0 ; ii<pathList.count() ; ii++) { traverse(pathList[ii]); }
}

void traverse(const QString &path, const QString &indent)
{
  if(indent.isEmpty() || (indent == "")) { printf(">> traverse: %s\n", QSTXT(path)); }
  int ii;
  QFileInfo fi(path);
  if(!(fi.exists    ())) { printf("path %s does not exist\n" , QSTXT(path)); return; }
  if(!(fi.isReadable())) { printf("path %s is not readable\n", QSTXT(path)); return; }
  if(fi.isDir())
  {
    printf("   %sdirectory: %s\n", QSTXT(indent), QSTXT(path));
    QDir qd(path);
    QFileInfoList fil = qd.entryInfoList();
    for(ii=0 ; ii<fil.count() ; ii++)
    {
      if((fil[ii].fileName() == ".") || (fil[ii].fileName() == "..")) { continue; }
      traverse(fil[ii].filePath(), QString(indent + "  "));
    }
  }
  else
  {
    printf("   %sfile     : %s\n", QSTXT(indent), QSTXT(path));
  }
}
