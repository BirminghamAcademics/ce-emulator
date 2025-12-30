#!/bin/bash
set -e

sudo apt update
sudo apt install -y build-essential git curl

# Install CE C SDK
git clone https://github.com/CE-Programming/toolchain.git ~/toolchain
cd ~/toolchain
sudo ./install.sh

echo 'export CEDEV=/opt/CEdev' >> ~/.bashrc
source ~/.bashrc
