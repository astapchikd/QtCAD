set MOC=D:/Qt/5.12.9/msvc2017/bin/moc.exe
%MOC% -o moc_CodeEditor.cpp CodeEditor.h
%MOC% -o moc_Editor.cpp Editor.h
%MOC% -o moc_MyWindow.cpp MyWindow.h
exit