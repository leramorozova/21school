FROM debian:jessie
RUN apt-get update -y && apt-get install wget -y
RUN mkdir /home/teamspeak && cd /home/teamspeak
RUN wget http://dl.4players.de/ts/releases/3.1.1/teamspeak3-server_linux_amd64-3.1.1.tar.bz2 && \
	tar xvf teamspeak3-server_linux_amd64-3.1.1.tar.bz2 && \
	rm teamspeak3-server_linux_amd64-3.1.1.tar.bz2 && \
	cd teamspeak3-server_linux_amd64 && \
	touch .ts3server_license_accepted
RUN echo "[Unit]\nDescription=TeamSpeak 3 Server\nAfter=network.target\n[Service]\nWorkingDirectory=/home/teamspeak/\nUser=teamspeak\nGroup=teamspeak\nType=forking\nExecStart=/home/teamspeak/ts3server_startscript.sh start inifile=ts3server.ini\nExecStop=/home/teamspeak/ts3server_startscript.sh stop\nPIDFile=/home/teamspeak/ts3server.pid\nRestartSec=15\nRestart=always\n[Install]\nWantedBy=multi-user.target" >> /lib/systemd/system/teamspeak.service
RUN systemctl enable teamspeak.service && systemctl start teamspeak.service
