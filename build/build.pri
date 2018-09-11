CONFIG(tvShow){

    CONFIG(release){
        LIBS+= -L../TVShow/release -lTVShow
    }
    else{
        LIBS+= -L../TVShow/debug -lTVShowd
    }

    INCLUDEPATH += ../TVShow \
}

CONFIG(algorithmic){

    CONFIG(release){
        LIBS += -L../algorithmic/release -lalgorithmic
    }
    else{
        LIBS += -L../algorithmic/debug -lalgorithmicd
    }

    INCLUDEPATH += ../algorithmic \
}

CONFIG(all){
    DEFINES+= ALL_TESTS
}
