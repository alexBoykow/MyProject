CONFIG(win32){
    CONFIG(release){
        LIBS+= -L/$$PWD/../TVShow/release -lTVShow
    }
    else{
        LIBS+= -L/$$PWD/../TVShow/debug -lTVShow
    }
}

CONFIG(all){
    DEFINES+= ALL_TESTS
}
