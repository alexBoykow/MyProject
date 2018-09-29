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


CONFIG(tennisBukmeker){

    CONFIG(release){
        message(Building TennisBukmeker release)
        PRE_TARGETDEPS+= ../TennisBukmeker/release/libTennisBukmeker.a
        LIBS+= -L../TennisBukmeker/release -lTennisBukmeker
    }
    else{
        message(Building TVShow debug)
        PRE_TARGETDEPS+= ../TennisBukmeker/debug/libTennisBukmekerd.a
        LIBS+= -L../TennisBukmeker/debug -lTennisBukmekerd
    }

    INCLUDEPATH += ../TennisBukmeker \
}
