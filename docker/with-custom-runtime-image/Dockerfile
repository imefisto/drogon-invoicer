FROM ubuntu:20.04 as common

RUN apt-get update -yqq && \
        apt-get install -y libssl-dev libjsoncpp-dev uuid-dev zlib1g-dev libc-ares-dev

FROM common as builder

ENV TZ=UTC
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt-get install -yqq --no-install-recommends software-properties-common \
    curl wget cmake make pkg-config locales git gcc-10 g++-10 \
    openssl \
    && rm -rf /var/lib/apt/lists/* \
    && locale-gen en_US.UTF-8

ENV LANG=en_US.UTF-8 \
    LANGUAGE=en_US:en \
    LC_ALL=en_US.UTF-8 \
    CC=gcc-10 \
    CXX=g++-10 \
    AR=gcc-ar-10 \
    RANLIB=gcc-ranlib-10 \
    IROOT=/install

ENV DROGON_ROOT="$IROOT/drogon"

ADD https://api.github.com/repos/an-tao/drogon/git/refs/heads/master $IROOT/version.json
RUN git clone https://github.com/an-tao/drogon $DROGON_ROOT

WORKDIR $DROGON_ROOT

RUN ./build.sh

COPY . /code
WORKDIR /code

RUN rm -rf build \
  && mkdir build \
  && cd build \
  && cmake .. \
  && make

FROM common as runtime

WORKDIR /app
COPY --from=builder /code/build /app

EXPOSE 80

ENTRYPOINT ["./invoicer"]
