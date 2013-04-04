#!/bin/bash
set -e

# deploy APR config file
sudo cp apr.conf /etc/ld.so.conf.d

# go somewhere safe
cd /tmp

# get the source to base APR 1.4.6
curl -L -O http://archive.apache.org/dist/apr/apr-1.4.6.tar.gz

# extract it and go into the source
tar -xzvf apr-1.4.6.tar.gz
cd apr-1.4.6

# configure, make, make install
./configure
make
sudo make install

# reset and cleanup
cd /tmp
rm -rf apr-1.4.6 apr-1.4.6.tar.gz

# do the same for apr-util
curl -L -O http://archive.apache.org/dist/apr/apr-util-1.5.2.tar.gz

# extract
tar -xzvf apr-util-1.5.2.tar.gz
cd apr-util-1.5.2

# configure, make, make install
./configure --with-apr=/usr/local/apr
make
sudo make install

# cleanup
cd /tmp
rm -rf apr-util-1.4.1* apr-1.4.6*

# make APR libraries visible to compilers
sudo ldconfig

