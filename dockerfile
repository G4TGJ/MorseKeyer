FROM opthomasprime/avr-gcc

RUN git clone https://github.com/G4TGJ/TARL.git

COPY TMK TMK

WORKDIR TMK/TMK

