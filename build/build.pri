CONFIG(tvShow){

    INCLUDEPATH += ../TVShow/

    CONFIG(release){
        LIBS+= -L/../TVShow/release/ -lTVShow
    }
    else{
        LIBS+= -L/../TVShow/debug/ -lTVShowd
    }
}

CONFIG(algorithmic){

    INCLUDEPATH += ../algorithmic/

    CONFIG(release){
        LIBS += -L../algorithmic/release/ -lalgorithmic
    }
    else{
        LIBS += -L../algorithmic/debug/ -lalgorithmicd
    }
}

CONFIG(all){
    DEFINES+= ALL_TESTS
}
