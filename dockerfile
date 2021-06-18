FROM ubuntu:18.04

RUN apt-get update && apt-get install -y \
    git \
    gcc-avr \
    avr-libc \
    make

RUN git clone https://github.com/G4TGJ/TARL.git

COPY TMK TMK

WORKDIR TMK/TMK

