FROM drogonframework/drogon:latest

COPY . /code
WORKDIR /code

RUN rm -rf build \
  && mkdir build \
  && cd build \
  && cmake .. \
  && make

EXPOSE 80

ENTRYPOINT ["/code/docker/with-official-image/entrypoint.sh"]
