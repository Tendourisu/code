FROM ubuntu:20.04

# Copy hello.c and hello.txt to /al1s/zhd directory
COPY hello.c hello.txt /al1s/zhd/

# Install necessary build tools
RUN apt-get update && \
    apt-get install -y gcc

# Compile hello.c to hello executable
RUN gcc /al1s/zhd/hello.c -o /al1s/zhd/hello

# Set the working directory
WORKDIR /al1s/zhd

# Run the hello executable
CMD ["./hello"]