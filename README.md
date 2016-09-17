This example code was written to see how to get a QAction in C++ and an Action in QML to work together. Especially in the context of a QActionGroup (C++) or ExclusiveGroup (QML). 

The short of it: barely.
You cannot use a QAction from QML nor an Action from C++, but you can get them to communicate a bit using signals and slots.

Too bad that there is state duplication: both ends maintain state about who's checked. (and C++ updates QML for state changes, but not reverse).
