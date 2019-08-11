FROM debian:9

RUN apt-get update && apt-get upgrade -y && apt-get install -y curl ca-certificates openssh-server postfix

RUN curl -o script.deb.sh https://packages.gitlab.com/install/repositories/gitlab/gitlab-ce/script.deb.sh
RUN chmod 777 script.deb.sh && ./script.deb.sh 
RUN apt-get install -y gitlab-ce

EXPOSE 4242 42

ENTRYPOINT (/opt/gitlab/embedded/bin/runsvdir-start &) && gitlab-ctl reconfigure && tail -f /dev/null

# docker run -it --rm -p 8080:4242 -p 8022:42 --privileged ex03
