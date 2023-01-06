#!/bin/bash

cwd=$1
all_args=("$@")
rest_args=("${all_args[@]:2}")
#timeout 3 stdbuf -o0  ./main "${rest_args[@]}"

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
        gcc -pthread -o main main.c
        popd
        ret=$?
fi

if [ $2 == "2" ]
    then
        pushd $cwd
        timeout 0.2 stdbuf -o0  ./main  ../1-10.txt ../3-10.txt
        ret=$?
        popd
fi

if [ $2 == "3" ]
    then
        pushd $cwd
        timeout 0.2 stdbuf -o0 ./main ../5-10.txt ../4-10.txt
        ret=$?
        popd
fi

if [ $2 == "4" ]
    then
        pushd $cwd
        timeout 0.2 stdbuf -o0 ./main ../8-10.txt
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
        timeout 2 stdbuf -o0 ./main ../1-10M.txt ../2-10M.txt ../4-10M.txt
        ret=$?
        popd
fi

if [ $2 == "7" ]
    then
        pushd $cwd
        timeout 0.2 stdbuf -o0 ./main ../8-10.txt ../xyzqw.txt
        ret=$?
        popd
fi

if [ $2 == "8" ]
    then
        pushd $cwd
        timeout 0.2 stdbuf -o0 ./main ../*-10.txt
        ret=$?
        popd
fi

if [ $2 == "9" ]
    then
        pushd $cwd
        timeout 2 stdbuf -o0 ./main ../*-10M.txt
        ret=$?
        popd
fi

if [ $2 == "10" ]
    then
        pushd $cwd
        timeout 0.2 stdbuf -o0 ./main ../[134589]-10.txt
        ret=$?
        popd
fi

if [ $2 == "11" ]
    then
        pushd $cwd
        perf stat -r 10 -d timeout 2 stdbuf -o0 ./main ../*-10M.txt
        ret=$?
        popd
fi


exit $ret











