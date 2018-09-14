CONFIG(tvShow){

    CONFIG(release){
        message(Building TVShow release)
        PRE_TARGETDEPS+= ../TVShow/release/libTVShow.a
        LIBS+= -L../TVShow/release -lTVShow
    }
    else{
        message(Building TVShow debug)
        PRE_TARGETDEPS+= ../TVShow/debug/libTVShowd.a
        LIBS+= -L../TVShow/debug -lTVShowd
    }

    INCLUDEPATH += ../TVShow \
}

CONFIG(all){
    DEFINES+= ALL_TESTS
}
