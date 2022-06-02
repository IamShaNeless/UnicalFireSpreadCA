#!/usr/bin/perl
system("g++ main.cpp && ./a.out");
qx(rm a.out);


