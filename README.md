# Develop in Visual Studio (requires 'Linux development with C++ workload')
## Prepare target Linux machine (using Docker)
The following Dockerfile is about SSH Linux server for Visual Studio to connect and deploy / build code. The server support buider tool (g++) and debugging tool (gdb, gdbserver)

Build the image, run into container. Then connect Visual Studio to it via Tools > Options > Cross Platform > Connection Manager. Username is `root`, pass is `screencast`.
```Dockerfile
FROM ubuntu:16.04

# Packages for VC++ to build and debug
RUN apt-get update && apt-get install -y openssh-server g++ gdb gdbserver

# Setup SSH credential
RUN mkdir /var/run/sshd
RUN echo 'root:screencast' | chpasswd
RUN sed -i 's/PermitRootLogin prohibit-password/PermitRootLogin yes/' /etc/ssh/sshd_config

# SSH login fix. Otherwise user is kicked off after login
RUN sed 's@session\s*required\s*pam_loginuid.so@session optional pam_loginuid.so@g' -i /etc/pam.d/sshd

ENV NOTVISIBLE "in users profile"
RUN echo "export VISIBLE=now" >> /etc/profile

# Launch SSH server
EXPOSE 22
CMD ["/usr/sbin/sshd", "-D"]
```

# Build to Docker image (don't need Visual Studio)
Execute the following commands
```CMD
docker-compose up
docker container prune -f
```
You will receive .so file in folder /BuildOutput
