CONFIG(tvShow){

    CONFIG(release){
        PRE_TARGETDEPS+= ../TVShow/release/libTVShow.a
        LIBS+= -L../TVShow/release -lTVShow
    }
    else{
        PRE_TARGETDEPS+= ../TVShow/debug/libTVShowd.a
        LIBS+= -L../TVShow/debug -lTVShowd
    }

    INCLUDEPATH += ../TVShow \
}

CONFIG(all){
    DEFINES+= ALL_TESTS
}
