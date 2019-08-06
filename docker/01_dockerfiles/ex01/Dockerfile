FROM debian:jessie
RUN apt-get update -y && apt-get install wget -y && apt-get install bzip2 -y
RUN mkdir /home/teamspeak && cd /home/teamspeak
RUN wget https://files.teamspeak-services.com/releases/server/3.9.1/teamspeak3-server_linux_amd64-3.9.1.tar.bz2
RUN tar -jxvf teamspeak3-server_linux_amd64-3.9.1.tar.bz2
RUN rm teamspeak3-server_linux_amd64-3.9.1.tar.bz2
RUN cd teamspeak3-server_linux_amd64 && touch .ts3server_license_accepted && sh ts3server_minimal_runscript.sh
