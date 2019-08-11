FROM ubuntu:16.04

RUN apt-get update -y && apt-get install -y python3 python3-pip
COPY EDGrPol /opt/EDGrPol
WORKDIR /opt/EDGrPol
RUN pip3 install --upgrade pip
RUN pip3 install -r requirements.txt
CMD python3 /opt/EDGrPol/WebApp/manage.py runserver
