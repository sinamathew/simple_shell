#!/bin/bash

pidMax=$(cat $ROOT/proc/sys/kernel/pid_max)
echo "$pidMax"
