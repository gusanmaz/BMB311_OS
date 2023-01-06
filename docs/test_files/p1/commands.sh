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

if [ $2 == "2" ] || [ $2 == "3" ] || [ $2 == "4" ] || [ $2 == "5" ] || [ $2 == "6" ] || [ $2 == "7" ] || [ $2 == "8" ] || [ $2 == "9" ]
    then
        pushd $cwd
        timeout 2 stdbuf -o0 strace -cf ./main
        ret=$?
        popd
fi


if [ $2 == "10" ]
    then
        pushd $cwd
        perf stat -r 10 -d timeout 0.2 stdbuf -o0 ./main
        ret=$?
        popd
fi


exit $ret











