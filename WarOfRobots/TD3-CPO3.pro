TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        bonstate.cpp \
        faiblestate.cpp \
        fortstate.cpp \
        game.cpp \
        main.cpp \
        mortstate.cpp \
        moyenstate.cpp \
        player.cpp \
        state.cpp

HEADERS += \
    bonstate.h \
    faiblestate.h \
    fortstate.h \
    game.h \
    mortstate.h \
    moyenstate.h \
    player.h \
    state.h
