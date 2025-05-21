#!/bin/bash


PACKAGES=("dconf-cli" "uuid-runtime")

for package in ${PACKAGES[@]}; do
        if ! dpkg -s $package &> /dev/null; then
                sudo apt install -y $package 
        else
                echo "$package already installed"
        fi
done

bash -c "$(wget -qO- https://git.io/vQgMr)"
