#!/bin/bash

cwd=$1

pushd () {
    command pushd "$@" > /dev/null
}

popd () {
    command popd "$@" > /dev/null
}

ret=0

if [ $2 == "1" ]
    then
        pushd $cwd
        [ -e main ] && rm main
        gcc -o main main.c
        popd
        ret=$?
fi

if [ $2 == "2" ]
    then
        pushd $cwd
        timeout 0.2 stdbuf -o0  ./main $(pidof cupsd)
        ret=$?
        popd
fi

if [ $2 == "3" ]
    then
        pushd $cwd
        timeout 0.2 stdbuf -o0 ./main $(pidof plasmashell)
        ret=$?
        popd
fi

if [ $2 == "4" ]
    then
        pushd $cwd
        timeout 0.2 stdbuf -o0 ./main $(pidof plasmashell)
        ret=$?
        popd
fi

if [ $2 == "5" ]
    then
        pushd $cwd
        timeout 0.2 stdbuf -o0 ./main
        ret=$?
        popd
fi

if [ $2 == "6" ]
    then
        pushd $cwd
        timeout 0.2 stdbuf -o0 ./main $(pidof plasmashell) $(pidof plasmashell)
        ret=$?
        popd
fi

if [ $2 == "7" ]
    then
        pushd $cwd
        timeout 0.2 stdbuf -o0 ./main plasmashell
        ret=$?
        popd
fi

if [ $2 == "8" ]
    then
        pushd $cwd
        perf stat -r 10 -d timeout 0.2 stdbuf -o0 ./main plasmashell
        ret=$?
        popd
fi


exit $ret











