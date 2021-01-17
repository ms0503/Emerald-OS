#!/bin/sh
autoreconf --install --force || exit 1
printf "Please run ./configure, make and make install.\n"
exit 0
