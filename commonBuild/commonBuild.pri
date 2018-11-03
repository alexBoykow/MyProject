CONFIG(release){
    PRE_TARGETDEPS+= ../DatabaseInterface/release/libDatabaseInterface.a
    LIBS+= -L../DatabaseInterface/release -lDatabaseInterface
}
else{
    PRE_TARGETDEPS+= ../DatabaseInterface/debug/libDatabaseInterfaced.a
    LIBS+= -L../DatabaseInterface/debug -lDatabaseInterfaced
}

    INCLUDEPATH += ../DatabaseInterface

    include(../definesBuild/definesBuild.pri)
