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


CONFIG(learningPortal){

    CONFIG(release){
        PRE_TARGETDEPS+= ../LearningPortal/release/libLearningPortal.a
        LIBS+= -L../LearningPortal/release -lLearningPortal
    }
    else{
        PRE_TARGETDEPS+= ../LearningPortal/debug/libLearningPortald.a
        LIBS+= -L../LearningPortal/debug -lLearningPortald
    }

    INCLUDEPATH += ../LearningPortal \
}
