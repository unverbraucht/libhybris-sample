FROM unverbraucht/libhybris:latest

ENV LC_ALL C.UTF-8
ENV LANG en_US.UTF-8
ENV LANGUAGE en_US:en
ENV TERM screen

RUN mkdir -p /usr/share/man/man1/

RUN set -eux; \
    \
    savedAptMark="$(apt-mark showmanual)"; \
    \
    apt-get update; \
    apt-get install -y --no-install-recommends \
           openjdk-11-jdk-headless cmake maven; \
    \
    # Cleanup the Dockerfile
    apt-get clean && \
    rm -rf /var/lib/apt/lists


RUN rm -r /src
RUN mkdir -p /src/hellojni

# Cache maven stuff
COPY sources/pom.xml /src/hellojni
RUN cd /src/hellojni && mvn dependency:go-offline

# Determine JAVA_HOME
# RUN bash (export JAVA_DIR=`update-alternatives --list java`; printf 'JAVA_HOME=%s\n' "${JAVA_DIR/\/bin\/java/}" >> /etc/profile)
# RUN export JAVA_HOME="$(dirname $(dirname $(readlink -f $(which java))))"

COPY sources /src/hellojni

# Compile bridge JNI so
RUN cd /src/hellojni/cpp && export JAVA_HOME="$(dirname $(dirname $(readlink -f $(which java))))" && cmake . && cmake --build . && make install

# Build java
RUN cd /src/hellojni && mvn compile

# Copy to android lib dir. Unfortunately we have to copy all shared libs
COPY lib /src/lib
# And then within container we can determine the current architecture
RUN cp /src/lib/`uname -m`/*so /system/lib

# RUN mvn exec:java -Dexec.mainClass="com.kevinread.hellojni.Main"