#!/bin/sh

make a && ((cd push_index; ./push_index) | ./trade | (cd server; ./main.py))
